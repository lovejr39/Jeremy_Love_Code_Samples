/*
 * 	ece0301_inclass12_step13.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	Assignment 12
 * 
 * 	This program will act as the main driver program for the circuit
 * 		network analysis program.
 * 	If will read ciruit information from a text file and report
 * 		calculated information about these circuits to a different text
 * 		file using various classes.
 * 
 * 	This program contains the code required for submission at step 13
 * 		in the assignment.
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"
#include "DCVoltageSource.cpp"
#include "DCCurrentSource.cpp"
#include "Resistor.cpp"
#include "VoltageDivider.cpp"
#include "CurrentDivider.cpp"

using namespace std ;

int main()
{
	//open filestreams
		ifstream inFile ;
		inFile.open("ECE 0301 - Circuits to Simulate.txt") ;
		ofstream outFile ;
		outFile.open("ECE 0301 - Electrical Network Reports.txt") ;
		
	//write intorductory message
		outFile << "ECE 0301 - Electrical Network Simulation\n" ;
		
	//decalare variables
		string line ;
		string str ;
		double sourceValue ;
		double resistance1 ;
		double resistance2 ;
		
	//read file information and circuit write information
		inFile >> str ;
		do
		{
			//read circuit type
				line = str + " " ;
				inFile >> str ;
				line += str ;

			//read in circuit specifications
				inFile >> sourceValue ;
				inFile >> resistance1 ;
				inFile >> resistance2 ;
			
			//determine curcuit type
				if(line == "Voltage Divider")
				{
					VoltageDivider vd(sourceValue, resistance1, 
									  resistance2) ;
					vd.reportDividerInformation(outFile) ;
				}
				else if(line == "Current Divider")
				{
					CurrentDivider cd(sourceValue, resistance1, 
									  resistance2) ;
					cd.reportDividerInformation(outFile) ;
				}
				else
				{
					cout << "ERROR! Invalid network type." ;
					inFile.close() ;
					outFile.close() ;
					exit(-1) ;
				}
				
			//read next word for loop
				str = "" ;
				inFile >> str ;
		}
		while(str == "Voltage" || str == "Current") ;

	//close filestream
		inFile.close() ;
		outFile.close() ;
}
