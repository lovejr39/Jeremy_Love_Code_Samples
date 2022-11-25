/*
 * 	DCCurrentSource.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		DCCurrentSource class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef DCCURRENTSOURCE_H
#define DCCURRENTSOURCE_H
 
#include <iostream>
#include <fstream>

#include "Component.cpp"

using namespace std ;

class DCCurrentSource : public Component
{
	private :
		//variables
			double sourceCurrent ;
	public :
		//constructors
			DCCurrentSource() ;
		//accessors	
			const double getSourceCurrent() ;
			const double getPowerSupplied() ;
		//mutators
			void setSourceCurrent(double) ;
		//other members
			void reportSourceInformation(ofstream &) ;
} ;

#endif
