/*
 * 	CurrentDivider.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		CurrentDivider class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */

#ifndef CURRENTDIVIDER_CPP
#define CURRENTDIVIDER_CPP

#include <iostream>
#include <fstream>

#include "CurrentDivider.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will create a network with three node, set the 
//	member variable for the network, and assemble the elemenets of the 
//	network into a current divider using the members of the 
//	CurrentDivider class
	CurrentDivider::CurrentDivider() : Network(2)
	{
		source.setSourceCurrent(1) ;
		r1.setResistance(1000) ;
		r2.setResistance(1000) ;
		connectComponent(&source, 0, 1) ;
		connectComponent(&r1, 0, 1) ;
		connectComponent(&r2, 0, 1) ;
		determineVoltagesAndCurrents() ;
	}

//this constructor will create a network with three node, set the 
//	member variable for the network, and assemble the elemenets of the 
//	network into a current divider using the members of the 
//	CurrentDivider class and parameter values
//@param double current, double, resistance 1, double reistance 2
	CurrentDivider::CurrentDivider(double current, 
								   double resistance1,
								   double resistance2) : Network(2)
	{
		source.setSourceCurrent(current) ;
		r1.setResistance(resistance1) ;
		r2.setResistance(resistance2) ;
		connectComponent(&source, 0, 1) ;
		connectComponent(&r1, 0, 1) ;
		connectComponent(&r2, 0, 1) ;
		determineVoltagesAndCurrents() ;
	}

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the sourceCurrent member variable of the source 
//	member object using a parameter value
//@param double sourceCurrent
	void CurrentDivider::setSourceCurrent(double sourceCurrent)
	{	
		source.setSourceCurrent(sourceCurrent) ;
		determineVoltagesAndCurrents() ;
	}
	
//this mutator will set the resistances for the Resistance member 
//	objects using paramet values
//@param double resistance 1, double resistance 2
	void CurrentDivider::setResistances(double resistance1, 
									    double resistance2)
	{
		r1.setResistance(resistance1) ;
		r2.setResistance(resistance2) ;
		determineVoltagesAndCurrents() ;
	}
//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************

//this member will report general infformation about the voltageDivider
//	contents to a paramer ofstream output file
//@param ofstream outFile
	void CurrentDivider::reportDividerInformation(ofstream & outFile)
	{		
		outFile << "\n" ;
		for(int i = 0 ; i < 48 ; i++)
			outFile << "-" ;
		outFile << "\n\n"
				<< "Data for Electric Network # " << getNetworkIndex()
				<< ":\n"
				<< "Network # " << getNetworkIndex() 
				<< " is a Current Divider.\n" ;
		reportNetworkInformation(outFile) ; 
		outFile << "\nAt present, there are " << r1.getComponentAmount()
				<< " components in existence." ;
		source.reportSourceInformation(outFile) ;
		r1.reportResistorInformation(outFile) ;
		r2.reportResistorInformation(outFile) ;
	}
	
//this member will determine the voltages and currents of the nodes 
//	about the CurrentDivider Network.
	void CurrentDivider::determineVoltagesAndCurrents()
	{
		setSpecificNodeVoltage(0, 0) ;
		setSpecificNodeVoltage(1, source.getSourceCurrent() * ((r1.getResistance() * r2.getResistance()) / (r1.getResistance() + r2.getResistance()))) ;
	}

#endif
