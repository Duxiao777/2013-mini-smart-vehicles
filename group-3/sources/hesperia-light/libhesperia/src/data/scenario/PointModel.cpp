/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/macros.h"
#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"
#include "hesperia/data/scenario/PointModel.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;
            using namespace core::base;
            using namespace scenario;

            PointModel::PointModel() :
                    m_listOfIdentifiableVertices() {
                LaneModel::setType(LaneModel::POINTMODEL);
            }

            PointModel::PointModel(const PointModel &obj) :
                    LaneModel(obj),
                    m_listOfIdentifiableVertices() {
                // Create deep copy.
                deepCopy(obj);
            }

            PointModel::~PointModel() {}

            PointModel& PointModel::operator=(const PointModel &obj) {
                LaneModel::operator=(obj);

                // Create deep copy.
                deepCopy(obj);

                return (*this);
            }

            void PointModel::deepCopy(const PointModel &obj) {
                m_listOfIdentifiableVertices.clear();
                const vector<IDVertex3>& list = obj.getListOfIdentifiableVertices();
                vector<IDVertex3>::const_iterator it = list.begin();
                while (it != list.end()) {
                    addIdentifiableVertex((*it++));
                }
            }

            void PointModel::accept(ScenarioVisitor &visitor) {
                LaneModel::accept(visitor);
                visitor.visit(*this);

                vector<IDVertex3>::iterator it = m_listOfIdentifiableVertices.begin();
                while (it != m_listOfIdentifiableVertices.end()) {
                    (*it++).accept(visitor);
                }
            }

            const vector<IDVertex3>& PointModel::getListOfIdentifiableVertices() const {
                return m_listOfIdentifiableVertices;
            }

            const IDVertex3 PointModel::getIDVertex3(const uint32_t &id) const throw (core::exceptions::InvalidArgumentException) {
                bool found = false;
                IDVertex3 retVal;
                vector<IDVertex3>::const_iterator it = m_listOfIdentifiableVertices.begin();
                while (it != m_listOfIdentifiableVertices.end()) {
                    retVal = (*it++);
                    if (retVal.getID() == id) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    HESPERIA_CORE_THROW_EXCEPTION(InvalidArgumentException, "Invalid ID given.");
                }
                return retVal;
            }


            void PointModel::addIdentifiableVertex(const IDVertex3 &idV) {
                m_listOfIdentifiableVertices.push_back(idV);
            }

            const string PointModel::toString() const {
                return "";
            }

            ostream& PointModel::operator<<(ostream &out) const {
                // Serializer super class.
                LaneModel::operator<<(out);

                SerializationFactory sf;

                Serializer &s = sf.getSerializer(out);

                uint32_t numberOfIdentifiableVertices = static_cast<uint32_t>(m_listOfIdentifiableVertices.size());
                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL7('n', 'u', 'm', 'i', 'd', 'v', 's') >::RESULT,
                        numberOfIdentifiableVertices);

                // Write identifiable vertices to stringstream.
                stringstream sstr;
                for (uint32_t i = 0; i < numberOfIdentifiableVertices; i++) {
                    // Write data to stringstream.
                    sstr << m_listOfIdentifiableVertices.at(i);
                }

                // Write identifiable vertices.
                if (numberOfIdentifiableVertices > 0) {
                    s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL4('i', 'd', 'v', 's') >::RESULT,
                            sstr.str());
                }

                return out;
            }

            istream& PointModel::operator>>(istream &in) {
                // Deserializer super class.
                LaneModel::operator>>(in);

                SerializationFactory sf;

                Deserializer &d = sf.getDeserializer(in);

                // Clean up.
                m_listOfIdentifiableVertices.clear();

                uint32_t numberOfIdentifiableVertices = 0;
                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL7('n', 'u', 'm', 'i', 'd', 'v', 's') >::RESULT,
                       numberOfIdentifiableVertices);

                if (numberOfIdentifiableVertices > 0) {
                    string str;
                    // Read identifiable vertices into stringstream.
                    d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL4('i', 'd', 'v', 's') >::RESULT,
                           str);

                    stringstream sstr(str);

                    // Read identifiable vertices from stringstream.
                    for (uint32_t i = 0; i < numberOfIdentifiableVertices; i++) {
                        IDVertex3 idV;
                        sstr >> idV;
                        addIdentifiableVertex(idV);
                    }
                }

                return in;
            }

        }
    }
} // hesperia::data::scenario
