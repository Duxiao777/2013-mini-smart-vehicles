/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/macros.h"
#include "core/base/Lock.h"

#include "hesperia/scenario/GroundBasedComplexModelLoader.h"
#include "hesperia/scenario/ScenarioOpenGLSceneTransformation.h"
#include "hesperia/threeD/NodeDescriptor.h"
#include "hesperia/threeD/TransformGroup.h"
#include "hesperia/threeD/decorator/DecoratorFactory.h"
#include "hesperia/threeD/models/AerialImage.h"
#include "hesperia/threeD/models/HeightGrid.h"

namespace hesperia {
    namespace threeD {
        namespace decorator {

            using namespace std;
            using namespace core::base;
            using namespace data::environment;
            using namespace data::scenario;
            using namespace scenario;
            using namespace threeD::loaders;
            using namespace threeD::models;

            // Initialize singleton instance.
            Mutex DecoratorFactory::m_singletonMutex;
            DecoratorFactory* DecoratorFactory::m_singleton = NULL;

            DecoratorFactory::DecoratorFactory() {}

            DecoratorFactory::~DecoratorFactory() {
                DecoratorFactory::m_singleton = NULL;
            }

            DecoratorFactory& DecoratorFactory::getInstance() {
                {
                    Lock l(DecoratorFactory::m_singletonMutex);
                    if (DecoratorFactory::m_singleton == NULL) {
                        DecoratorFactory::m_singleton = new DecoratorFactory();
                    }
                }

                return (*DecoratorFactory::m_singleton);
            }

            Node* DecoratorFactory::decorate(scenario::SCNXArchive &scnxArchive) {
                return decorate(scnxArchive, true);
            }

            Node* DecoratorFactory::decorate(scenario::SCNXArchive &scnxArchive, const bool &showLaneConnectors) {
                TransformGroup *tg = new TransformGroup();

                Scenario &scenario = scnxArchive.getScenario();
                if (scnxArchive.getAerialImage() != NULL) {
                    clog << "AerialImage loaded." << endl;

                    Point3 origin(scenario.getGround().getAerialImage().getOriginX(), scenario.getGround().getAerialImage().getOriginY(), 0);
                    Point3 scaling(scenario.getGround().getAerialImage().getMeterPerPixelX(), scenario.getGround().getAerialImage().getMeterPerPixelY(), 0);

                    AerialImage *ai = new AerialImage(
                        NodeDescriptor("AerialImage"),
                        scnxArchive.getAerialImage(),
                        origin,
                        scaling,
                        static_cast<float> (scenario.getGround().getAerialImage().getRotationZ()));

                    tg->addChild(ai);
                }
                if (scnxArchive.getHeightImage() != NULL) {
                    clog << "HeightImage loaded." << endl;
                    Point3 origin(scenario.getGround().getHeightImage().getOriginX(), scenario.getGround().getHeightImage().getOriginY(), 0);
                    Point3 scaling(scenario.getGround().getHeightImage().getMeterPerPixelX(), scenario.getGround().getHeightImage().getMeterPerPixelY(), 0);

                    HeightGrid *hg = new HeightGrid(NodeDescriptor("HeightGrid"), scnxArchive.getHeightImage(), origin, scaling, static_cast<float>(scenario.getGround().getHeightImage().getRotationZ()), static_cast<float>(scenario.getGround().getHeightImage().getGroundHeight()), static_cast<float>(scenario.getGround().getHeightImage().getMinimumHeight()), static_cast<float>(scenario.getGround().getHeightImage().getMaximumHeight()));
                    tg->addChild(hg);
                }

                ScenarioOpenGLSceneTransformation scnOpenGL(showLaneConnectors);
                scenario.accept(scnOpenGL);

                tg->addChild(scnOpenGL.getRoot());

                // Load complex models.
                GroundBasedComplexModelLoader gbcml;
                TransformGroup *complexModels = gbcml.getGroundBasedComplexModels(scnxArchive);
                if (complexModels != NULL) {
                    tg->addChild(complexModels);
                }

                return tg;
            }

            Node* DecoratorFactory::decorate(loaders::OBJXArchive &objxArchive, const NodeDescriptor &nd) {
                return objxArchive.createTransformGroup(nd);
            }
        }
    }
} // hesperia::threeD::decorator
