/*
 * 	VoltageDivider.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		VoltageDivider class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */

#ifndef VOLTAGEDIVIDER_CPP
#define VOLTAGEDIVIDER_CPP

#include <iostream>
#include <fstream>

#include "VoltageDivider.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will create a network with three node, set the 
//	member variable for the network, and assemble the elemenets of the 
//	network into a voltage divider using the members of the 
//	VoltageDivider class
	VoltageDivider::VoltageDivider() : Network(3)
	{
	
		source.setSourceVoltage(1) ;
		r1.setResistance(1000) ;
		r2.setResistance(1000) ;
		connectComponent(&source, 0, 1) ;
		connectComponent(&r1, 1, 2) ;
		connectComponent(&r2, 2, 0) ;
		determineVoltagesAndCurrents() ;
	}

//this constructor will create a network with three node, set the 
//	member variable for the network, and assemble the elemenets of the 
//	network into a voltage divider using the members of the 
//	VoltageDivider class and parameter values
//@param double voltage, double, resistance 1, double reistance 2
	VoltageDivider::VoltageDivider(double voltage, 
								   double resistance1,
								   double resistance2) : Network(3)
	{
		source.setSourceVoltage(voltage) ;
		r1.setResistance(resistance1) ;
		r2.setResistance(resistance2) ;
		connectComponent(&source, 0, 1) ;
		connectComponent(&r1, 1, 2) ;
		connectComponent(&r2, 2, 0) ;
		determineVoltagesAndCurrents() ;
	}

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the sourceVoltage member variable of the source 
//	member object using a parameter value
//@param double sourceVoltage
	void VoltageDivider::setSourceVoltage(double sourceVoltage)
	{	
		source.setSourceVoltage(sourceVoltage) ;
		determineVoltagesAndCurrents() ;
	}
	
//this mutator will set the resistances for the Resistance member 
//	objects using paramet values
//@param double resistance 1, double resistance 2
	void VoltageDivider::setResistances(double resistance1, 
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
	void VoltageDivider::reportDividerInformation(ofstream & outFile)
	{		
		outFile << "\n" ;
		for(int i = 0 ; i < 48 ; i++)
			outFile << "-" ;
		outFile << "\n\n"
				<< "Data for Electric Network # " << getNetworkIndex()
				<< ":\n"
				<< "Network # " << getNetworkIndex() 
				<< " is a Voltage Divider.\n" ;
		reportNetworkInformation(outFile) ; 
		outFile << "\nAt present, there are " << r1.getComponentAmount()
				<< " components in existence." ;
		source.reportSourceInformation(outFile) ;
		r1.reportResistorInformation(outFile) ;
		r2.reportResistorInformation(outFile) ;
	}
	
//this member will determinethe voltages and currents of the nodes 
//	about the VoltageDivider Network.
	void VoltageDivider::determineVoltagesAndCurrents()
	{
		setSpecificNodeVoltage(0, 0) ;
		setSpecificNodeVoltage(1, source.getSourceVoltage()) ;
		source.setCurrent(source.getSourceVoltage() / 
						 (r1.getResistance() + r2.getResistance())) ;
		setSpecificNodeVoltage(2, source.getCurrent() * 
								  r2.getResistance()) ; 
	}

#endif
