/*
 * 	Resistor.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		Resistor class.
 * 
 * 	This program contains the code required for submission at step 9
 * 		in the assignment.
 */

#ifndef RESISTOR_CPP
#define RESISTOR_CPP

#include <iostream>
#include <fstream>

#include "Resistor.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will set the restistance member variable to 1
	Resistor::Resistor()
	{	resistance = 1000 ;	}

//**********************************************************************
//	ACCESSORS
//**********************************************************************
	
//this accessor will return the resistance member variable
//@return double resistance
	const double Resistor::getResistance()
	{	return resistance ;	}
	
//this accessor will caculate and return the current through the 
//	resistor using ohm's law
//@return double current
	const double Resistor::getCurrent()
	{	return getTerminalVoltage() / resistance ;	}
	
//this accessor will calculate and return the power dissipated through
//	the risistor
//@return double power dissipated
	const double Resistor::getPowerDissipated()
	{	return getCurrent() * getTerminalVoltage() ;	}
	
//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the resistance member variable from a parameter
//	double
//@param double resistance
	void Resistor::setResistance(double resistance)
	{	this -> resistance = resistance ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************

//this member will report information about the resistor to a parameter
//	ofstream output file
//@param ofstream outFile
	void Resistor::reportResistorInformation(ofstream & outFile)
	{
		outFile << "\nComponent # " << getComponentIndex() 
				<< " is a Resistor, R = " << resistance	<< " Ohms." ;
		reportComponentInformation(outFile) ;
		outFile << "\nThe current in this Resistor = " 
				<< abs(getCurrent()) << " Amps,\n"
				<< "flowing from Node " ;
		if(getCurrent() < 0)
			outFile << getTerminalANodeIndex() << " to Node "
					<< getTerminalBNodeIndex() << "." ;
		else
			outFile << getTerminalBNodeIndex() << " to Node "
					<< getTerminalANodeIndex() << "." ;
		outFile << "\nThe power dissipated in this Resistor = "
				<< getPowerDissipated() << " Watts.\n" ;
	}

#endif
