/*
 *	FlashLight.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/25/21
 * 	Assignment #7
 * 	
 *	This program will define all functions and constructors for the
 * 		FlashLight class.
 */
 
#include <iostream>
 
using namespace std ;

//constructors
	
//default constructor
	FlashLight::FlashLight()
	{
		batteryVoltage = 3.0 ;
		bulbResistance = 100 ;
		switchState = false ;
	}
	
//public functions

//variables mutators

//this function will set batteryVoltage
//@param double d
	void FlashLight::setBatteryVoltage(double d)
	{	batteryVoltage = d ;	}
	
//this function will set bulbResistance
//@param double d
	void FlashLight::setBulbResistance(double d)
	{	bulbResistance = d ;	}
	
//this function will change the switchState
	void FlashLight::operateSwitch()
	{	switchState = !switchState ;	}
	
//variable accessors
	
//this function will return batteryVoltage
//@return double batteryVoltage
	double FlashLight::getBatteryVoltage()
	{	return batteryVoltage ;	}
	
//this function will return bulbResistance
//@return double bulbResistance
	double FlashLight::getBulbResistance()
	{	return bulbResistance ;	}
	
//this function will return switchState
//@return bool switchState
	bool FlashLight::getSwitchStateBool()
	{	return switchState ;	}

//calculatory accessors

//this function will determine and return switchState in string form
//@return string open/closed
	string FlashLight::getSwitchStateString()
	{	
		if(switchState)
			return "closed" ;
		else
			return "open" ;
	}

//this function will determine and return the flashlight's state
//@return string on/off
	string FlashLight::getOnOff()
	{
		if(switchState)
			return "on" ;
		else
			return "off" ;
	}

//this function will calculate and return the current
//@return double bulbCurrent = batteryVoltage / bulbResistance
	double FlashLight::getBulbCurrent()
	{
		if(switchState)
			return batteryVoltage / bulbResistance ;
		else
			return 0 ;
	}
	
//this function will calculate and return the power
//@return double bulbPower = bulbCurrent * batteryVoltage
	double FlashLight::getBulbPower()
	{
		if(switchState)
			return getBulbCurrent() * batteryVoltage ;
		else
			return 0 ;
	}
	
//display functions

//this function will display all information to standard output
	void FlashLight::displayAll()
	{
		cout << "Here are the data on the Flashlight:" << endl 
			 << "The battery voltage is " << batteryVoltage 
			 << " Volts." << endl 
			 << "The bulb resistance is " << bulbResistance << " Ohms."
			 << endl 
			 << "The switch is " << getSwitchStateString() << "." 
			 << endl
			 << "The Flashlight is " << getOnOff() << "." << endl
			 << "The bulb current is " << getBulbCurrent() 
			 << " Amperes." << endl
			 << "The bulb power is " << getBulbPower() << " Watts."
			 << endl ;
	}
