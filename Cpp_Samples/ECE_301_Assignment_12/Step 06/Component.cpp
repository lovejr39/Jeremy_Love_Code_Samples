/*
 * 	Network.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		Component class.
 * 
 * 	This program contains the code required for submission at step 6
 * 		in the assignment.
 */

#ifndef COMPONENT_CPP
#define COMPONENT_CPP

#include <iostream>
#include <fstream>
#include <cmath>

#include "Component.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will assign the componentIndex member variable,
//	increment the componentAmount member variable, and intitialize the
//	Node pointers a and b to nullptr
	Component::Component()
	{
		componentIndex = componentAmount ;
		componentAmount++ ;
		terminalA = nullptr ;
		terminalB = nullptr ;
	}

//**********************************************************************
//	ACCESSORS
//**********************************************************************

//this accessor will return the componentAmount member variable
//@return int componentAmount
	const int Component::getComponentAmount()
	{	return componentAmount ;	}
	
//this accessor will return the componentIndex member variable
//@return int componentIndex
	const int Component::getComponentIndex()
	{	return componentIndex ;	}
	
//this accessor will return the nodeIndex of terminalA
//@return int nodeIndex terminalA
	const int Component::getTerminalANodeIndex()
	{	return (*terminalA).getNodeIndex() ;	}
	
//this accessor will return the nodeIndex of terminalB
//@return int nodeIndex terminalB
	const int Component::getTerminalBNodeIndex()
	{	return (*terminalB).getNodeIndex() ;	}

//this accessor will calculate and return the terminal voltage of the
//	component using the voltage of the terminal nodes
//@return terminal voltage
	double Component::getTerminalVoltage()
	{	
		return (*terminalB).getNodeVoltage() - 
			   (*terminalA).getNodeVoltage() ;
	}		   

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the Node pointer for terminal A using a 
//	parameter Node pointer
//@param Node * nodeptr
	void Component::setTerminalA(Node *nodeptr)
	{	terminalA = nodeptr ;	}
	
//this mutator will set the Node pointer for terminal B using a 
//	parameter Node pointer
//@param Node * nodeptr
	void Component::setTerminalB(Node *nodeptr)
	{	terminalB = nodeptr ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************

//this members will report the infroamtion about the component to a
//	parameter ofstream output file
//@param ofstream & outFile
	void Component::reportComponentInformation(ofstream & outFile)
	{
		outFile << "\nComponent # " << componentIndex 
				<< " is connected between node " 
				<< (*terminalA).getNodeIndex() << " and node "
				<< (*terminalB).getNodeIndex() << ".\n"
				<< "The Voltage across Component # " << componentIndex
				<< " = " << abs(getTerminalVoltage()) << " Volts,\n"
				<< "with the negative terminal at node " ;
		if(getTerminalVoltage() > 0)
			outFile << (*terminalA).getNodeIndex() << "." ;
		else
			outFile << (*terminalB).getNodeIndex() << "." ;
	}

#endif
