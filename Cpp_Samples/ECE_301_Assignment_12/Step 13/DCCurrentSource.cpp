/*
 * 	DCCurrentSource.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		DCCurrentSource class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */

#ifndef DCCURRENTSOURCE_CPP
#define DCCURRENTSOURCE_CPP

#include <iostream>
#include <fstream>

#include "DCCurrentSource.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will set the sourceCurrent member variable to zero
	DCCurrentSource::DCCurrentSource()
	{	sourceCurrent = 0 ;	}	

//**********************************************************************
//	ACCESSORS
//**********************************************************************
	
//this accessor will return the sourceVoltage member variable
//@return double sourceVoltage
	const double DCCurrentSource::getSourceCurrent()
	{	return sourceCurrent ;	}
	
//this accessor will return the power supplied by the voltage source by
//	returning the product of the sourceVoltage and currentDrawn members
//@return double power supplied
	const double DCCurrentSource::getPowerSupplied()
	{	return getTerminalVoltage() * sourceCurrent ;	}

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the sourceVoltage member variable from a 
//	parameter double
//@param double sourceVoltage
	void DCCurrentSource::setSourceCurrent(double sourceCurrent)
	{	this -> sourceCurrent = sourceCurrent ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************
	
//this member will report information about the voltage source to a
//	parameter ofstream output file
//@param ofstream outFile
	void DCCurrentSource::reportSourceInformation(ofstream & outFile)
	{
		outFile << "\n\nComponent # " << getComponentIndex() 
				<< " is a DC Current Source, Is = " << sourceCurrent
				<< " Amps." ;
		reportComponentInformation(outFile) ;
		outFile << "\nThe current in this DC Current Source = "
				<< abs(sourceCurrent) << " Amps,\n"
				<< "flowing from Node " ;
		if(sourceCurrent > 0)
			outFile << getTerminalANodeIndex() << " to Node "
					<< getTerminalBNodeIndex() << "." ;
		else
			outFile << getTerminalBNodeIndex() << " to Node "
					<< getTerminalANodeIndex() << "." ;
		outFile << "\nThe power supplied by this DC Current Source = "
				<< getPowerSupplied() << " Watts.\n" ;
	}

#endif
