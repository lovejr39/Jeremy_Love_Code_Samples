/*
 * 	Node.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the Node
 * 		class.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */
 
#ifndef NODE_H
#define NODE_H
 
#include <iostream>
#include <fstream>

using namespace std ;

class Node
{
	private :
		//variables
			static int nodeAmount ;
			int nodeIndex ;
			double nodeVoltage ;	
	public :
		//constructors
			Node() ;
		//accessors
			const int getNodeAmount() ;
			const int getNodeIndex() ;
			const double getNodeVoltage() ;
		//mutators
			void setNodeVoltage(double) ;
		//other members
			const void reportNodeInformation(ofstream &) ;
} ;

int Node::nodeAmount = 0 ;

#endif
