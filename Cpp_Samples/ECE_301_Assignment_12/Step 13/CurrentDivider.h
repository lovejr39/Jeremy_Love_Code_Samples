/*
 * 	CurrentDivider.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		CurrentDivider class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef CURRENTDIVIDER_H
#define CURRENTDIVIDER_H
 
#include <iostream>
#include <fstream>

#include "Network.cpp"
#include "DCCurrentSource.cpp"
#include "Resistor.cpp"


using namespace std ;

class CurrentDivider : public Network
{
	private :
		//variables
			DCCurrentSource source ;
			Resistor r1 ;
			Resistor r2 ;
	public :
		//constructors
			CurrentDivider() ;
			CurrentDivider(double, double, double) ;
		//mutators
			void setSourceCurrent(double) ;
			void setResistances(double, double) ;
		//other members
			void reportDividerInformation(ofstream &) ;
			void determineVoltagesAndCurrents() ;
} ;

#endif
