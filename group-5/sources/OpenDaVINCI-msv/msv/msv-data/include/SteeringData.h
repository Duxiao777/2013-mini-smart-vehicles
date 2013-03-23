/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef STEERINGDATA_H_
#define STEERINGDATA_H_

#ifdef PANDABOARD
#include <stdc-predef.h>
#endif

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/data/SerializableData.h"



namespace msv {

	using namespace std;
	
    /**
     * This is an example how you can send data from one component to another.
     */
	class SteeringData : public core::data::SerializableData {
		public:
			SteeringData();

			virtual ~SteeringData();

			/**
			 * Copy constructor.
			 *
			 * @param obj Reference to an object of this class.
			 */
			SteeringData(const SteeringData &obj);

			/**
			 * Assignment operator.
			 *
			 * @param obj Reference to an object of this class.
			 * @return Reference to this instance.
			 */
			SteeringData& operator=(const SteeringData &obj);

            /**
             * This method returns the example data.
             *
             * @return example data.
             */
            double getExampleData() const;

            /**
             * This method sets the example data.
             *
             * @param e Example data.
             */
            void setExampleData(const double &e);

/*	    double getDataX() const;
	    void setDataX(const double &X);

	    double getDataY() const;
	    void setDataY(const double &Y);
*/
	    virtual ostream& operator<<(ostream &out) const;
	    virtual istream& operator>>(istream &in);
	    
	    virtual const string toString() const;
	    
	private:
            double m_exampleData;
	    //	    double m_DataX;
	    //double m_DataY;
	};
	
} // msv

#endif /*STEERINGDATA_H_*/
