/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_DATA_SCENARIO_LAYER_H_
#define HESPERIA_CORE_DATA_SCENARIO_LAYER_H_

#include <string>
#include <vector>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "core/data/SerializableData.h"
#include "hesperia/data/scenario/Road.h"
#include "hesperia/data/scenario/Zone.h"
#include "hesperia/data/scenario/ScenarioNode.h"
#include "hesperia/data/scenario/ScenarioVisitor.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;

            /**
             * This class represents a layer.
             */
            class HESPERIA_API Layer : public core::data::SerializableData, public ScenarioNode {
                public:
                    Layer();

                    virtual ~Layer();

                    /**
                     * Copy constructor.
                     *
                     * @param obj Reference to an object of this class.
                     */
                    Layer(const Layer &obj);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Reference to an object of this class.
                     * @return Reference to this instance.
                     */
                    Layer& operator=(const Layer &obj);

                    virtual void accept(scenario::ScenarioVisitor &visitor);

                    /**
                     * This method returns the layer's name.
                     *
                     * @return Layer's name.
                     */
                    const string getName() const;

                    /**
                     * This method sets the layer's name.
                     *
                     * @param name The layer's name.
                     */
                    void setName(const string &name);

                    /**
                     * This method returns the ID.
                     *
                     * @return ID.
                     */
                    uint32_t getID() const;

                    /**
                     * This method sets the ID.
                     *
                     * @param id ID to be set.
                     */
                    void setID(const uint32_t &id);

                    /**
                     * This method returns the height of this layer.
                     *
                     * @return Height of this layer.
                     */
                    double getHeight() const;

                    /**
                     * This method sets the height of this layer.
                     *
                     * @param h Height of this layer.
                     */
                    void setHeight(const double &h);

                    /**
                     * This method returns the list of roads.
                     *
                     * @return List of roads.
                     */
                    const vector<Road>& getListOfRoads() const;

                    /**
                     * This method adds a road.
                     *
                     * @param r Road to be added.
                     */
                    void addRoad(const Road &r);

                    /**
                     * This method returns the list of zones.
                     *
                     * @return List of zones.
                     */
                    const vector<Zone>& getListOfZones() const;

                    /**
                     * This method adds a zone.
                     *
                     * @param z Zone to be added.
                     */
                    void addZone(const Zone &z);

                    virtual ostream& operator<<(ostream &out) const;
                    virtual istream& operator>>(istream &in);

                    virtual const string toString() const;

                private:
                    string m_name;
                    uint32_t m_id;
                    double m_height;
                    vector<Road> m_listOfRoads;
                    vector<Zone> m_listOfZones;

                    /**
                     * This method creates a deep copy.
                     *
                     * @param obj Object of another instance of this class.
                     */
                    void deepCopy(const Layer &obj);
            };

        }
    }
} // hesperia::data::scenario

#endif /*HESPERIA_CORE_DATA_SCENARIO_LAYER_H_*/
