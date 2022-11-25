/*
 * 	DCVoltageSource.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		DCVoltageSource class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */

#ifndef DCVOLTAGESOURCE_CPP
#define DCVOLTAGESOURCE_CPP

#include <iostream>
#include <fstream>

#include "DCVoltageSource.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will set the sourceVoltage member variable to zero
	DCVoltageSource::DCVoltageSource()
	{	sourceVoltage = 0 ;	}	

//**********************************************************************
//	ACCESSORS
//**********************************************************************
	
//this accessor will return the sourceVoltage member variable
//@return double sourceVoltage
	const double DCVoltageSource::getSourceVoltage()
	{	return sourceVoltage ;	}
	
//this accessor will return the currntDrawn member variable
//@return double currentDrawn
	const double DCVoltageSource::getCurrent()
	{	return current ;	}
	
//this accessor will return the power supplied by the voltage source by
//	returning the product of the sourceVoltage and currentDrawn members
//@return double power supplied
	const double DCVoltageSource::getPowerSupplied()
	{	return sourceVoltage * current ;	}

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the sourceVoltage member variable from a 
//	parameter double
//@param double sourceVoltage
	void DCVoltageSource::setSourceVoltage(double sourceVoltage)
	{	this -> sourceVoltage = sourceVoltage ;	}

//this mutator will set the currentDrawn member variable from a 
//	parameter double
//@param double currentDrawn
	void DCVoltageSource::setCurrent(double current)
	{	this -> current = current ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************
	
//this member will report information about the voltage source to a
//	parameter ofstream output file
//@param ofstream outFile
	void DCVoltageSource::reportSourceInformation(ofstream & outFile)
	{
		outFile << "\n\nComponent # " << getComponentIndex() 
				<< " is a DC Voltage Source, Vs = " << sourceVoltage
				<< " Volts." ;
		reportComponentInformation(outFile) ;
		outFile << "\nThe current in this DC Voltage Source = "
				<< abs(current) << " Amps,\n"
				<< "flowing from Node " ;
		if(current > 0)
			outFile << getTerminalANodeIndex() << " to Node "
					<< getTerminalBNodeIndex() << "." ;
		else
			outFile << getTerminalBNodeIndex() << " to Node "
					<< getTerminalANodeIndex() << "." ;
		outFile << "\nThe power supplied by this DC Voltage Source = "
				<< getPowerSupplied() << " Watts.\n" ;
	}

#endif
