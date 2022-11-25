/*
 * 	Resistor.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		Resistor class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef RESISTOR_H
#define RESISTOR_H
 
#include <iostream>
#include <fstream>

#include "Component.cpp"

using namespace std ;

class Resistor : public Component
{
	private :
		//variables
			double resistance ;
	public :
		//constructors
			Resistor() ;
		//accessors	
			const double getResistance() ;
			const double getCurrent() ;
			const double getPowerDissipated() ;
		//mutators
			void setResistance(double) ;
		//other members
			void reportResistorInformation(ofstream &) ;
} ;

#endif
