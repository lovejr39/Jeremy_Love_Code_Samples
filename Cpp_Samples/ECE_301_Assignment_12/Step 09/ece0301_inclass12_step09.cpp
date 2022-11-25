/*
 * 	ece0301_inclass12_step09.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will 
 * 
 * 	This program contains the code required for submission at step 9
 * 		in the assignment.
 */

#include <iostream>
#include <fstream>
#include <cmath>

#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"
#include "DCVoltageSource.cpp"
#include "Resistor.cpp"

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
		
	//define voltage source
		DCVoltageSource dcvs ;
		dcvs.setSourceVoltage(12) ;
		DCVoltageSource* dcvsptr = &dcvs ;
		
	//define components
		Resistor r1 ;
		Resistor r2 ;
		r1.setResistance(200) ;
		r2.setResistance(100) ;
		Resistor* r1ptr = &r1 ;
		Resistor* r2ptr = &r2 ;
		
	//connect components
		net.connectComponent(dcvsptr, 0, 1) ;
		net.connectComponent(r1ptr, 1, 2) ;
		net.connectComponent(r2ptr, 2, 0) ;
		
	//set node voltage
		net.setSpecificNodeVoltage(1, dcvs.getSourceVoltage()) ;
		net.setSpecificNodeVoltage(2, dcvs.getSourceVoltage() / 3) ;
		
	//determine current through dcvs
		dcvs.setCurrent(dcvs.getSourceVoltage() / 
					   (r1.getResistance() + r2.getResistance())) ;
		
	//report information
		net.reportNetworkInformation(outFile) ;
		dcvs.reportSourceInformation(outFile) ;
		r1.reportResistorInformation(outFile) ;
		r2.reportResistorInformation(outFile) ;
		
	//close filestream
		outFile.close() ;
}
