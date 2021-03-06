/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"
#include "hesperia/data/scenario/ComplexModel.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;
            using namespace core::base;

            ComplexModel::ComplexModel() :
                    m_modelFile(""),
                    m_position(),
                    m_rotation(),
                    m_boundingBox() {
                Shape::setType(Shape::COMPLEXMODEL);
            }

            ComplexModel::ComplexModel(const ComplexModel &obj) :
                    Shape(obj),
                    m_modelFile(obj.m_modelFile),
                    m_position(obj.m_position),
                    m_rotation(obj.m_rotation),
                    m_boundingBox(obj.m_boundingBox) {}

            ComplexModel::~ComplexModel() {}

            ComplexModel& ComplexModel::operator=(const ComplexModel &obj) {
                Shape::operator=(obj);
                setModelFile(obj.getModelFile());
                setPosition(obj.getPosition());
                setRotation(obj.getRotation());
                setBoundingBox(obj.getBoundingBox());
                return (*this);
            }

            void ComplexModel::accept(ScenarioVisitor &visitor) {
                visitor.visit(*this);

                m_position.accept(visitor);
                m_rotation.accept(visitor);
                m_boundingBox.accept(visitor);
            }

            const string ComplexModel::getModelFile() const {
                return m_modelFile;
            }

            void ComplexModel::setModelFile(const string &modelFile) {
                m_modelFile = modelFile;
            }

            const Vertex3& ComplexModel::getPosition() const {
                return m_position;
            }

            void ComplexModel::setPosition(const Vertex3 &position) {
                m_position = position;
            }

            const Vertex3& ComplexModel::getRotation() const {
                return m_rotation;
            }

            void ComplexModel::setRotation(const Vertex3 &rotation) {
                m_rotation = rotation;
            }

            const BoundingBox& ComplexModel::getBoundingBox() const {
                return m_boundingBox;
            }

            void ComplexModel::setBoundingBox(const BoundingBox &bb) {
                m_boundingBox = bb;
            }

            const string ComplexModel::toString() const {
                stringstream s;
                s << Shape::toString() << ", Modelfile: '" << m_modelFile << "', Position: " << m_position.toString() << ", Rotation:" << m_rotation.toString() << ", BoundingBox: " << m_boundingBox.toString();
                return s.str();
            }

            ostream& ComplexModel::operator<<(ostream &out) const {
                // Serializer super class.
                Shape::operator<<(out);

                SerializationFactory sf;

                Serializer &s = sf.getSerializer(out);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL5('m', 'o', 'd', 'e', 'l') >::RESULT,
                        m_modelFile);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL8('p', 'o', 's', 'i', 't', 'i', 'o', 'n') >::RESULT,
                        m_position);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL8('r', 'o', 't', 'a', 't', 'i', 'o', 'n') >::RESULT,
                        m_rotation);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL8('b', 'o', 'u', 'n', 'd', 'i', 'n', 'g') >::RESULT,
                        m_boundingBox);

                return out;
            }

            istream& ComplexModel::operator>>(istream &in) {
                // Deserializer super class.
                Shape::operator>>(in);

                SerializationFactory sf;

                Deserializer &d = sf.getDeserializer(in);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL5('m', 'o', 'd', 'e', 'l') >::RESULT,
                       m_modelFile);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL8('p', 'o', 's', 'i', 't', 'i', 'o', 'n') >::RESULT,
                       m_position);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL8('r', 'o', 't', 'a', 't', 'i', 'o', 'n') >::RESULT,
                       m_rotation);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL8('b', 'o', 'u', 'n', 'd', 'i', 'n', 'g') >::RESULT,
                       m_boundingBox);

                return in;
            }

        }
    }
} // hesperia::data::scenario
