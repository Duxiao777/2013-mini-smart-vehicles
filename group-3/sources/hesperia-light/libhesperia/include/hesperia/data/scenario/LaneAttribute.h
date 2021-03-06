/*
 * Copyright (c) Christian Berger and Bernhard Rumpe, Rheinisch-Westfaelische Technische Hochschule Aachen, Germany.
 *
 * The Hesperia Framework.
 */

#ifndef HESPERIA_CORE_DATA_SCENARIO_LANEATTRIBUTE_H_
#define HESPERIA_CORE_DATA_SCENARIO_LANEATTRIBUTE_H_

#include <string>

// native.h must be included as first header file for definition of _WIN32_WINNT.
#include "core/native.h"

#include "core/data/SerializableData.h"
#include "hesperia/data/scenario/ScenarioNode.h"
#include "hesperia/data/scenario/ScenarioVisitor.h"

namespace hesperia {
    namespace data {
        namespace scenario {

            using namespace std;

            /**
             * This class represents additional lane attributes.
             */
            class HESPERIA_API LaneAttribute : public core::data::SerializableData, public ScenarioNode {
                public:
                    enum BOUNDARYSTYLE {
                        UNDEFINED,
                        DOUBLE_YELLOW,
                        SOLID_YELLOW,
                        SOLID_WHITE,
                        BROKEN_WHITE,
                        CROSSWALK
                    };

                public:
                    LaneAttribute();

                    /**
                     * Copy constructor.
                     *
                     * @param obj Reference to an object of this class.
                     */
                    LaneAttribute(const LaneAttribute &obj);

                    virtual ~LaneAttribute();

                    virtual void accept(scenario::ScenarioVisitor &visitor);

                    /**
                     * Assignment operator.
                     *
                     * @param obj Reference to an object of this class.
                     * @return Reference to this instance.
                     */
                    LaneAttribute& operator=(const LaneAttribute &obj);

                    /**
                     * This method returns the lane's width.
                     *
                     * @return Lane's width.
                     */
                    double getWidth() const;

                    /**
                     * This method sets the lane's width.
                     *
                     * @param w Lane's width.
                     */
                    void setWidth(const double &w);

                    /**
                     * This method returns the left lane's marking.
                     *
                     * @return Left lane marking.
                     */
                    enum BOUNDARYSTYLE getLeftLaneMarking() const;

                    /**
                     * This method sets the left lane's marking.
                     *
                     * @param bs Left lane's marking.
                     */
                    void setLeftLaneMarking(const enum BOUNDARYSTYLE &bs);

                    /**
                     * This method returns the right lane's marking.
                     *
                     * @return Right lane marking.
                     */
                    enum BOUNDARYSTYLE getRightLaneMarking() const;

                    /**
                     * This method sets the right lane's marking.
                     *
                     * @param bs Right lane's marking.
                     */
                    void setRightLaneMarking(const enum BOUNDARYSTYLE &bs);

                    virtual ostream& operator<<(ostream &out) const;
                    virtual istream& operator>>(istream &in);

                    virtual const string toString() const;

                private:
                    double m_width;
                    enum BOUNDARYSTYLE m_leftLaneMarking;
                    enum BOUNDARYSTYLE m_rightLaneMarking;
            };

        }
    }
} // hesperia::data::scenario

#endif /*HESPERIA_CORE_DATA_SCENARIO_LANEATTRIBUTE_H_*/
