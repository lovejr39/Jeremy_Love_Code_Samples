/*
 * 	ece0301_inclass12_step06.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will 
 * 
 * 	This program contains the code required for submission at step 6
 * 		in the assignment.
 */

#include <iostream>
#include <fstream>

#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"

using namespace std ;

int main()
{
	//open filestream
		ofstream outFile ;
		outFile.open("ECE 0301 - Electrical Network Reports.txt") ;
		
	//introductory message
		cout << "ECE 0301 - Electrical Network Simulation" ;
		outFile << "ECE 0301 - Electrical Network Simulation" ;
		
	//define network
		Network net(3) ;
		
	//define components
		Component comp0 ;
		Component comp1 ;
		Component comp2 ;
		Component* c0ptr = &comp0 ;
		Component* c1ptr = &comp1 ;
		Component* c2ptr = &comp2 ;
		
	//connect components
		net.connectComponent(c0ptr, 0, 1) ;
		net.connectComponent(c1ptr, 1, 2) ;
		net.connectComponent(c2ptr, 2, 0) ;
		
	//set node voltage
		net.setSpecificNodeVoltage(1, -5) ;
		net.setSpecificNodeVoltage(2, 1.25) ;
		
	//report information
		net.reportNetworkInformation(outFile) ;
		comp0.reportComponentInformation(outFile) ;
		comp1.reportComponentInformation(outFile) ;
		comp2.reportComponentInformation(outFile) ;
		
	//close filestream
		outFile.close() ;
}
