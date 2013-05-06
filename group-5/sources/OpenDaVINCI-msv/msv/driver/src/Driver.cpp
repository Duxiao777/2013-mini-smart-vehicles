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
    bool psfound = false, psfonlyonce = false, move2units = false, twmb2 = false; // parking space found, 0 means not found as 1 found
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
	psfound = true;
	printf("ps found");
      }
      
      printf("PS printing %d\n", (int)psfound );
      
      if((psfound == true)){ // Parking space found
	if(psfonlyonce == false){ // functions which has to execute only once after found
	  psfonlyonce = true;
	  desiredPosition = vd.getPosition(); // position of car when found parking space
	  //desiredHeading = vd.getHeading();
	  printf("only once");
	    	  
	}
	/*Start move two units forward i.e. Y + 2 */ 
	if((move2units == false)&&(desiredPosition.getY() + 2 > vd.getPosition().getY())){
	  vc.setSpeed(1);
	  
	}
	else if((move2units == false)&&(desiredPosition.getY() + 2 < vd.getPosition().getY())){
	  move2units = true;
	   printf("moving 2 units");
	  vc.setAcceleration(0);
	  vc.setSpeed(0);
	}
	/* end move two uints */
	
 	// Turn wheel to right and move back two units
	else if( (((twmb2 == false) && (move2units == true)) && (psfonlyonce == true)) && (desiredPosition.getX() + 2 > vd.getPosition().getX())){
	  vc.setSteeringWheelAngle(25);
	  vc.setSpeed(-1);
	  printf("WTF !!!!!!!!!!!");
	}

	else if( (((twmb2 == false) && (move2units == true)) && (psfonlyonce == true)) && (desiredPosition.getX() + 2 < vd.getPosition().getX())){
	  vc.setSteeringWheelAngle(0);
	  vc.setSpeed(-1);
	  twmb2 = 1;
	  printf("WTFFFFFFFFFFF");
	}



	
      }
      
      else if(!(psfound == true)){
	printf("normal");
	vc.setSpeed(2);
      }
      
      
      printf("Desired X %f\n", desiredPosition.getX()+3); // position.getX() + 3 = desired X position
      printf("Result X %f\n\n", vd.getPosition().getX());
      
      printf("IRFR %f\n", sbd.getDistance(0)); 
      printf("IRBR %f\n", sbd.getDistance(2)); 
      printf("****USF**** %f\n", sbd.getDistance(3));
      printf("****IRB**** %f\n", sbd.getDistance(1));
      printf("USFR %f\n", sbd.getDistance(4));
      printf("USBR %f\n", sbd.getDistance(5));
      printf("Heading %f\n",vd.getHeading());
      
      
      
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

