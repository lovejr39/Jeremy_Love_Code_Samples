/*
 * 	Flashlight.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/25/21
 * 	Assignment #7
 * 	
 *	This program will create the Flashlight class and provides all 
 *		function prototypes.
 */
 
#include <iostream>
 
using namespace std ;

class FlashLight 
{
		private :
			double batteryVoltage ;
			double bulbResistance ;
			bool switchState ;
		public :
			FlashLight() ;
			void setBatteryVoltage(double d) ;
			void setBulbResistance(double d) ;
			void operateSwitch() ;
			double getBatteryVoltage() ;
			double getBulbResistance() ;
			bool getSwitchStateBool() ;
			string getSwitchStateString() ;
			string getOnOff() ;
			double getBulbCurrent() ;
			double getBulbPower() ;
			void displayAll() ;
} ;
