/*
 * 	VoltageDivider.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		VoltageDivider class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H
 
#include <iostream>
#include <fstream>

#include "Network.cpp"
#include "DCVoltageSource.cpp"
#include "Resistor.cpp"


using namespace std ;

class VoltageDivider : public Network
{
	private :
		//variables
			DCVoltageSource source ;
			Resistor r1 ;
			Resistor r2 ;
	public :
		//constructors
			VoltageDivider() ;
			VoltageDivider(double, double, double) ;
		//mutators
			void setSourceVoltage(double) ;
			void setResistances(double, double) ;
		//other members
			void reportDividerInformation(ofstream &) ;
			void determineVoltagesAndCurrents() ;
} ;

#endif
