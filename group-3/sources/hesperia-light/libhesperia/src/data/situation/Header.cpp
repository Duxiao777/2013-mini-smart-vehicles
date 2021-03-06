/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#include "core/base/Hash.h"
#include "core/base/Deserializer.h"
#include "core/base/SerializationFactory.h"
#include "core/base/Serializer.h"
#include "hesperia/data/situation/Header.h"

namespace hesperia {
    namespace data {
        namespace situation {

            using namespace std;
            using namespace core::base;

            Header::Header() :
                    m_name(""),
                    m_version(""),
                    m_date(""),
                    m_scenario("") {}

            Header::Header(const Header &obj) :
                    SerializableData(),
                    m_name(obj.m_name),
                    m_version(obj.m_version),
                    m_date(obj.m_date),
                    m_scenario(obj.m_scenario) {}

            Header::~Header() {}

            Header& Header::operator=(const Header &obj) {
                setName(obj.getName());
                setVersion(obj.getVersion());
                setDate(obj.getDate());
                setScenario(obj.getScenario());
                return (*this);
            }

            void Header::accept(SituationVisitor &visitor) {
                visitor.visit(*this);
            }

            const string Header::getName() const {
                return m_name;
            }

            void Header::setName(const string &name) {
                m_name = name;
            }

            const string Header::getVersion() const {
                return m_version;
            }

            void Header::setVersion(const string &v) {
                m_version = v;
            }

            const string Header::getDate() const {
                return m_date;
            }

            void Header::setDate(const string &d) {
                m_date = d;
            }

            const string Header::getScenario() const {
                return m_scenario;
            }

            void Header::setScenario(const string &scenario) {
                m_scenario = scenario;
            }

            const string Header::toString() const {
                stringstream s;
                s << "Situation: '" << m_name << "', Version: " << m_version << ", Date: " << m_date << ", Scenario: " << m_scenario;
                return s.str();
            }

            ostream& Header::operator<<(ostream &out) const {
                SerializationFactory sf;

                Serializer &s = sf.getSerializer(out);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL4('n', 'a', 'm', 'e') >::RESULT,
                        m_name);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL7('v', 'e', 'r', 's', 'i', 'o', 'n') >::RESULT,
                        m_version);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL4('d', 'a', 't', 'e') >::RESULT,
                        m_date);

                s.write(CRC32 < HESPERIA_CORE_STRINGLITERAL3('s', 'c', 'n') >::RESULT,
                        m_scenario);

                return out;
            }

            istream& Header::operator>>(istream &in) {
                SerializationFactory sf;

                Deserializer &d = sf.getDeserializer(in);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL4('n', 'a', 'm', 'e') >::RESULT,
                       m_name);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL7('v', 'e', 'r', 's', 'i', 'o', 'n') >::RESULT,
                       m_version);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL4('d', 'a', 't', 'e') >::RESULT,
                       m_date);

                d.read(CRC32 < HESPERIA_CORE_STRINGLITERAL3('s', 'c', 'n') >::RESULT,
                       m_scenario);

                return in;
            }

        }
    }
} // hesperia::data::situation
