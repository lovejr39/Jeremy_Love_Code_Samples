/*
 * 	Network.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class implementation file for the 
 * 		Network class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef NETWORK_CPP
#define NETWORK_CPP
 
#include <iostream>

#include "Network.h"

using namespace std ;

//**********************************************************************
//	CONSTRUCTORS
//**********************************************************************

//default constructor
//this constructor will assign the networkIndex, increment the
//	networkAmount, and set the totalNodesInNetwork with a parameter
//	value
//@param int totalNodesInNetwork = 2
	Network::Network(int totalNodesInNetwork = 2)
	{
		networkIndex = networkAmount ;
		networkAmount++ ;
		this -> totalNodesInNetwork = totalNodesInNetwork ;
		nodeArrayPointer = new Node[totalNodesInNetwork] ;
	}


//**********************************************************************
//	ACCESSORS
//**********************************************************************

//this accessor will return the networkIndex member variable
//@return networkIndex
	const int Network::getNetworkIndex()
	{	return networkIndex ;	}
	
//this accessor will return the totalNodesInNetwork member variable
//@return totalNodesInNetwork
	const int Network::getTotalNodesInNetwork()
	{	return totalNodesInNetwork ;	}

//this accessor will return the total number of nodes in existance by
//	calling the getNodeAmount member function for the Node object at 
//	index 0 within the Node array represented by the nodeArrayPointer
//@return int nodeAmount
	const int Network::getTotalNodesInExistance()
	{	return (*nodeArrayPointer).getNodeAmount() ;	}
	
//this accessor will return the a node pointer determined by the int
//	parameter value
//@param int index
//@return Node pointer
	Node* Network::getNodePointer(int index)
	{	return nodeArrayPointer + index ;	}

//**********************************************************************
//	MUTATORS
//**********************************************************************

//this mutator will set the voltage for a Node object within the Node 
//	array represented by the nodeArrayPointer at the parameter index 
//	to the paramter voltage value
//@param int index, double voltage
	void Network::setSpecificNodeVoltage(int index, double voltage)
	{	(*(nodeArrayPointer + index)).setNodeVoltage(voltage) ;	}

//**********************************************************************
//	OTHER MEMBERS
//**********************************************************************

//this member will report the information about the network to a 
//	parameter ofstream output file
//@param ofstream outFile
	void Network::reportNetworkInformation(ofstream & outFile)
	{
		outFile << "At present, there are " << networkAmount 
				<< " Networks in existence.\n"
				<< "At present, there are " 
				<< getTotalNodesInExistance() 
				<< " nodes in existence.\n"
				<< "Network # " << networkIndex << " contains "
				<< totalNodesInNetwork << " nodes." ;
		for(int i = 0 ; i < totalNodesInNetwork ; i++)
			(*(nodeArrayPointer + i)).reportNodeInformation(outFile) ;
	}

//this member will set the node pointers of a component object equal to
//	the nodes of two network nodes indicated by int index parameters
//@param Component* componentptr, int indexA, int indexB
	void Network::connectComponent(Component* componentptr, int indexA,
								   int indexB)
	{
		(*(componentptr)).setTerminalA(nodeArrayPointer + indexA) ;
		(*(componentptr)).setTerminalB(nodeArrayPointer + indexB) ;
	}

//**********************************************************************
//	DESTRUCTORS
//**********************************************************************

//default destructor
//this destructor will release memory allocated for the 
//	nodeArrayPointer member variable
	Network::~Network()
	{	delete [] nodeArrayPointer ;	}

#endif
