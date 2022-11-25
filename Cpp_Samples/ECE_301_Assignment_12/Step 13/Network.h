/*
 * 	Network.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		Network class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>

#include "Node.cpp"
#include "Component.cpp"

using namespace std ;
 
class Network
{
	private :
		//declare variables
			static int networkAmount ;
			int networkIndex ;
			int totalNodesInNetwork ;
			Node *nodeArrayPointer ;
	public :
		//constructors
			Network(int) ;
		//accessors
			const int getNetworkIndex() ;
			const int getTotalNodesInNetwork() ;
			const int getTotalNodesInExistance() ;
			Node* getNodePointer(int) ;
 		//mutators
			void setSpecificNodeVoltage(int, double) ;
		//other members
			void reportNetworkInformation(ofstream &) ;
			void connectComponent(Component*, int, int) ;
		//destructors
			~Network() ;
 } ;

int Network::networkAmount = 0 ;

#endif
