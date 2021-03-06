/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <vector>

#include "hesperia/data/Constants.h"
#include "hesperia/data/environment/Point3.h"
#include "hesperia/data/scenario/ComplexModel.h"
#include "hesperia/scenario/GroundBasedComplexModelLoader.h"
#include "hesperia/threeD/Node.h"
#include "hesperia/threeD/NodeDescriptor.h"
#include "hesperia/threeD/loaders/OBJXArchive.h"
#include "hesperia/threeD/loaders/OBJXArchiveFactory.h"

namespace hesperia {
    namespace scenario {

        using namespace std;
        using namespace data::environment;
        using namespace data::scenario;
        using namespace scenario;
        using namespace threeD;
        using namespace threeD::loaders;

        GroundBasedComplexModelLoader::GroundBasedComplexModelLoader() {}

        GroundBasedComplexModelLoader::~GroundBasedComplexModelLoader() {}

        TransformGroup* GroundBasedComplexModelLoader::getGroundBasedComplexModels(const SCNXArchive &scnxArchive) const {
            TransformGroup *complexModels = new TransformGroup();

            // Get list of all ground based complex models.
            vector<ComplexModel*> listOfComplexModels = scnxArchive.getListOfGroundBasedComplexModels();

            // Iterate over all ground based complex models and try to build a transform group.
            vector<ComplexModel*>::iterator jt = listOfComplexModels.begin();
            while (jt != listOfComplexModels.end()) {
                ComplexModel *cm = (*jt++);
                istream *in = scnxArchive.getModelData(cm->getModelFile());
                if (in != NULL) {
                    Node *model = NULL;

                    // Check model.
                    OBJXArchive *objxArchive = NULL;
                    if (cm->getModelFile().find(".objx") != string::npos) {
                        objxArchive = OBJXArchiveFactory::getInstance().getOBJXArchive(*in);
                    } else if (cm->getModelFile().find(".obj") != string::npos) {
                        objxArchive = OBJXArchiveFactory::getInstance().getOBJXArchiveFromPlainOBJFile(*in);
                    }

                    if (objxArchive != NULL) {
                        model = objxArchive->createTransformGroup(NodeDescriptor(cm->getName()));

                        if (model != NULL) {
                            clog << "OBJ model successfully opened." << endl;
                            clog << "  Translation: " << cm->getPosition().toString() << endl;
                            clog << "  Rotation: " << cm->getRotation().toString() << endl;

                            TransformGroup *complexModel = new TransformGroup();

                            // Translation.
                            Point3 translation(cm->getPosition());
                            complexModel->setTranslation(translation);

                            // TODO: Achsenprüfung!!
                            Point3 rotation(cm->getRotation().getX(), cm->getRotation().getZ(), cm->getRotation().getY());
                            complexModel->setRotation(rotation);

                            complexModel->addChild(model);

                            complexModels->addChild(complexModel);

                        } else {
                            clog << "OBJ model could not be opened." << endl;
                        }

                        HESPERIA_CORE_DELETE_POINTER(objxArchive);
                    }
                }
            }

            return complexModels;
        }

    }
} // hesperia::scenario
