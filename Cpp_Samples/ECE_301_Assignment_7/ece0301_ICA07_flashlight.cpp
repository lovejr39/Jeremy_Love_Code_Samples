/*
 * 	ece0301_ICA_flashlight.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/25/21
 * 	Assignment #7
 * 	
 *	This program will create and define the Flashlight class. It
 * 		also provide a main function to test the usability of the 
 * 		Flashlight class.
 */
 
#include <iostream>

#include "FlashLight.h"
#include "FlashLight.cpp"

using namespace std ;

int main()
{
	//declare variables
		FlashLight light ;
		int choice ;
		double input ;
		bool repeat = true ;
	
	//repeat until exit
		do
		{
			//display flashlight information
				light.displayAll() ;
			
			//display choices and read user selection
				cout << "(1) Change the battery voltage" << endl 
					 << "(2) Change the bulb resistance" << endl
					 << "(3) Toggle the switch state" << endl
					 << "(4) Exit the program" << endl ;
				cin >> choice ;
					 
			//perform selected action
				switch (choice) 
				{
					case 1 :
						cout << "Enter the new battery voltage: " ;
						cin >> input ;
						light.setBatteryVoltage(input) ;
					break ;
					
					case 2 :
						cout << "Enter the new bulb resistance: " ;
						cin >> input ;
						light.setBulbResistance(input) ;
					break ;
					
					case 3 :
						light.operateSwitch() ;
					break ;
					
					case 4 :
						repeat = false ;
					break ;
				}
		}
		while(repeat);
}
