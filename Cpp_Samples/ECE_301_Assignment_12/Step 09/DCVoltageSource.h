/*
 * 	DCVoltageSource.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		DCVoltageSource class.
 * 
 * 	This program contains the code required for submission at step 9
 * 		in the assignment.
 */
 
#ifndef DCVOLTAGESOURCE_H
#define DCVOLTAGESOURCE_H
 
#include <iostream>
#include <fstream>

#include "Component.cpp"

using namespace std ;

class DCVoltageSource : public Component
{
	private :
		//variables
			double sourceVoltage ;
			double current ;
	public :
		//constructors
			DCVoltageSource() ;
		//accessors	
			const double getSourceVoltage() ;
			const double getCurrent() ;
			const double getPowerSupplied() ;
		//mutators
			void setSourceVoltage(double) ;
			void setCurrent(double) ;
		//other members
			void reportSourceInformation(ofstream &) ;
} ;

#endif
