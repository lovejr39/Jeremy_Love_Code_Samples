/*
 * 	Node.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the Node
 * 		class.
 * 
 * 	This program contains the code required for submission at step 6
 * 		in the assignment.
 */

#ifndef NODE_CPP
#define NODE_CPP

#include <iostream>

#include "Node.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will set the nodeIndex and increment the nodeAmount
	Node::Node()
	{
		nodeIndex = nodeAmount ;
		nodeAmount++ ;
		nodeVoltage = 0 ;
	}
	
//**********************************************************************
//	ACCESSORS
//**********************************************************************

//this accessor will return the nodeAmount member variable
//@return int nodeAmount
	const int Node::getNodeAmount()
	{	return nodeAmount ;	}
	
//this accessor will return the nodeIndex member variable
//@return int nodeIndex
	const int Node::getNodeIndex()
	{	return nodeIndex ;	}
	
//this accessor will return the nodeVolate member variable
//@return double nodeVoltage
	const double Node::getNodeVoltage()
	{	return nodeVoltage ;	}
	
//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the value of the nodeVoltage member variable
//@param double d
	void Node::setNodeVoltage(double nodeVoltage)
	{	this -> nodeVoltage = nodeVoltage ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************

//this mutator will report information about the node to a parameter
//	output file
//@param ofstream outFile
	const void Node::reportNodeInformation(ofstream &outFile)
	{
		outFile << "\nVoltage at node " << nodeIndex << " = " 
				<< nodeVoltage << "." ;
	}

#endif
