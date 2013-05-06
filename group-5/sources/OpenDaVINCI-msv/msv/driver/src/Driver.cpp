/*
 * Mini-Smart-Vehicles.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#include <stdio.h>
#include <math.h>

#include "core/io/ContainerConference.h"
#include "core/data/Container.h"
#include "core/data/Constants.h"
#include "core/data/control/VehicleControl.h"
#include "core/data/environment/VehicleData.h"

// Data structures from msv-data library:
#include "SteeringData.h"
#include "SensorBoardData.h"
#include "UserButtonData.h"

#include "Driver.h"

namespace msv {

        using namespace std;
        using namespace core::base;
        using namespace core::data;
        using namespace core::data::control;
        using namespace core::data::environment;

        Driver::Driver(const int32_t &argc, char **argv) :
	        ConferenceClientModule(argc, argv, "Driver") {
        }

        Driver::~Driver() {}

        void Driver::setUp() {
	        // This method will be call automatically _before_ running body().
        }

        void Driver::tearDown() {
	        // This method will be call automatically _after_ return from body().
        }
  


        // This method will do the main data processing job.
        ModuleState::MODULE_EXITCODE Driver::body() {
	  bool psfound,psfonlyonce; // parking space found, 0 means not found as 1 found
	  //	  bool frir;
	   Point3 desiredPosition;
	   //	   double desiredHeading; // if vehicle turns right the value will decrease and vice versa
	   //double i = 0;
	  while (getModuleState() == ModuleState::RUNNING) {
                // In the following, you find example for the various data sources that are available:

		        // 1. Get most recent vehicle data:
		        Container containerVehicleData = getKeyValueDataStore().get(Container::VEHICLEDATA);
		        VehicleData vd = containerVehicleData.getData<VehicleData> ();
		        // cerr << "Most recent vehicle data: '" << vd.toString() << "'" << endl;

		        // 2. Get most recent sensor board data:
		        Container containerSensorBoardData = getKeyValueDataStore().get(Container::USER_DATA_0);
		        SensorBoardData sbd = containerSensorBoardData.getData<SensorBoardData> ();
		        // cerr << "Most recent sensor board data: '" << sbd.toString() << "'" << endl;

		        // 3. Get most recent user button data:
		        Container containerUserButtonData = getKeyValueDataStore().get(Container::USER_BUTTON);
		        UserButtonData ubd = containerUserButtonData.getData<UserButtonData> ();
			// cerr << "Most recent user button data: '" << ubd.toString() << "'" << endl;

		        // 4. Get most recent steering data as fill from lanedetector for example:
		        Container containerSteeringData = getKeyValueDataStore().get(Container::USER_DATA_1);
		        SteeringData sd = containerSteeringData.getData<SteeringData> ();
		        //cerr << "Most recent steering data: '" << sd.toString() << "'" << endl;


		        VehicleControl vc;
			//double desiredSteeringWheelAngle;
			 
			//double rfsen,rbsen,fsen,bsen;
			//desiredSteeringWheelAngle = 0;
			
			// Frot Right and Back right for distance detection 0,2
			// front and back to adjust to not to hit something   // Safe Value Reading between 16 and 17

			// rfsen = sbd.getDistance(0); //FR IR 4
			// rbsen = sbd.getDistance(2); //BR IR 5
			double comp = sbd.getDistance(4) + sbd.getDistance(5);
						
			if( (16 < comp) && (comp < 18) ){ // to find parking place  
			  psfound = 1;
			}
			
			if(!(psfound == 1)){
			  vc.setSpeed(2);
			}
			
			if((psfound == 1)){ // Parking space found
			  if(psfonlyonce == 0){ // functions which has to execute only once after found
			    psfonlyonce = 1;
			    desiredPosition = vd.getPosition(); // position of car when found parking space
			    //desiredHeading = vd.getHeading();
			    vc.setAcceleration(0);
			    vc.setSpeed(0);
			    
			  }
			  // Replace below two with ,, move two units forward i.e. Y + 2 
			  // drive until you see a distance range of FRIR more than -1
			  // if((vd.getVelocity >1)){
			  //  vc.setAcceleration(0);
			  
			  if( vd.getPosition().getX() < desiredPosition.getX() ){ // if current position X is less than desired position
			    
 			    if( (sbd.getDistance(1) < 0.9) && (sbd.getDistance(3) < 0.9) ){ // If no IR front and back are having any reading values
			      if(vd.getPosition().getY() > desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(25);
				vc.setSpeed(-0.2);
			      }
			      else if(vd.getPosition().getY() < desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(-25);
				vc.setSpeed(0.2);
			      }
			      else { // if current position Y matches desired position Y
				vc.setSteeringWheelAngle(-25);
				vc.setSpeed(0.2);}
			    }
			    
			    else if((sbd.getDistance(1) < 2 ){ // it CONDITION then only go backward
			      if(vd.getPosition().getY() > desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(25);
				vc.setSpeed(0.2);
			      }
			      else if(vd.getPosition().getY() < desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(-25);
				vc.setSpeed(0.2);
			      }
			    }

			    else if((sbd.getDistance(3) + 1) > sbd.getDistance(1) ){ // it CONDITION then only go backward
			      if(vd.getPosition().getY() > desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(25);
				vc.setSpeed(-0.2);
			      }
			      else if(vd.getPosition().getY() < desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(-25);
				vc.setSpeed(-0.2);
			      }
			    }


			  }
			  
			  
			  if( vd.getPosition().getX() > desiredPosition.getX() ){ // if current position X is less than desired position
			    
			    if( (sbd.getDistance(1) < 0.9) || (sbd.getDistance(3) < 0.9) ){ // If no IR front and back are having any reading values
			      if(vd.getPosition().getY() > desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(-25);
				vc.setSpeed(-0.2);
			      }
			      else if(vd.getPosition().getY() < desiredPosition.getY()){ // if current position Y is greater than desired position
				vc.setSteeringWheelAngle(25);
				vc.setSpeed(0.2);
			      }
			    }
			    
			    
			  }
			  
			      //		    printf("XIN %f\n", position.getX()); // position.getX() + 3 = desired X position
			    //printf("YIN %f\n", position.getY()); // position.getY() = desired Y position
			  
			    //}
			    //else
			    //vc.setSpeed(1);  
			}
			
			// 4 degree but SteeringWheelAngle expects the angle in radians!

			//	        vc.setSteeringWheelAngle(1);			


						    printf("Heading %f\n",vd.getHeading());
 
			    //			    position = vd.getPosition();

			    vc.setBrakeLights(false);
			vc.setLeftFlashingLights(false);
			vc.setRightFlashingLights(false);
			
			
			
		        // Create container for finally sending the data.
		        Container c(Container::VEHICLECONTROL, vc);
		        // Send container.
		        getConference().send(c);
	        }

	        return ModuleState::OKAY;
        }
} // msv




			  /**
			    && ( (vc.getSpeed() > 0) && (vc.getSpeed() < 0) )
			   
			  vc.setSpeed(0);

			// printf("%d\n", (int)psfound);

			// printf("X %f\n", position.getX());
			// printf("Y %f\n", position.getY());
			// printf("Z %f\n", position.getZ());
			
			//printf("two %f\n", sbd.getDistance(4)+sbd.getDistance(5));
			//printf("%d\n", (int)psfound);
			// printf("FRIR %f\n", sbd.getDistance(0));
			// printf("One %f\n", sbd.getDistance(1));
			// printf("BRIR %f\n", sbd.getDistance(2));
			// printf("Three %f\n", sbd.getDistance(3));
			//	printf("Four %f\n", sbd.getDistance(4));
			//	printf("Five %f\n", sbd.getDistance(5));

 			// printf("Zero %f\n", sbd.getDistance(0));
 			// printf("One %f\n", sbd.getDistance(1));
			// printf("Two %f\n", sbd.getDistance(2));
			// printf("Three %f\n", sbd.getDistance(3));
			// printf("Four %f\n", sbd.getDistance(4));
			// printf("Five %f\n", sbd.getDistance(5));
 


			  **/

