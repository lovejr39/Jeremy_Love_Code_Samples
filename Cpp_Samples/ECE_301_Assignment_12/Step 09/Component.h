/*
 * 	Component.h
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will create the class specification file for the 
 * 		Component class.
 * 
 * 	This program contains the code required for submission at step 9
 * 		in the assignment.
 */
 
#ifndef COMPONENT_H
#define COMPONENT_H
 
#include <iostream>
#include <fstream>

#include "Node.cpp"

using namespace std ;

class Component
{
	private :
		//variables
			static int componentAmount ;
			int componentIndex ;
			Node *terminalA ;
			Node *terminalB ;
	public :
		//constructors
			Component() ;
		//accessors	
			const int getComponentAmount() ;
			const int getComponentIndex() ;
			const int getTerminalANodeIndex() ;
			const int getTerminalBNodeIndex() ;
			double getTerminalVoltage() ;
		//mutators
			void setTerminalA(Node*) ;
			void setTerminalB(Node*) ;
		//other members
			void reportComponentInformation(ofstream &) ;
} ;

int Component::componentAmount = 0 ;

#endif
