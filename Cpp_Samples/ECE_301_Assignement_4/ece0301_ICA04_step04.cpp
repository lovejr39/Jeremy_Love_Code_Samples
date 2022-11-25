/*
 *	ece0301_ICA04_step04.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/11/2021
 * 	Assignment 4
 * 	ECE 0301
 * 
 *	This program will test the understanding of looping concepts, as 
 * 		well as reading and writing to files through the usage of ECE 
 * 		concepts resistive curcuits: KVL & KCL, Ohm's Law, voltage
 * 		dividers and the Wheatstone Bridge curcuits.
 * 
 * 	This program contains the code required for submission at Step 4 
 *		in the assignment.
 */
 
#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

double loopCurrent (double v, double r1, double r2) ;
double resistorVoltage (double v, double r1, double r2) ;

int main()
{			 
	//declare filestreams
		ifstream inFile ;
		inFile.open("divider_wheatstone_circuits.txt") ;
		ofstream outFile ; 
		outFile.open("divider_wheatstone_solutions.txt") ;
		
	//declare variables
		double voltageSource, resistor1, resistor2 ;
		
	//output introductory message
		cout << "ECE 0301: Circuit Solver for Voltage Divider" << endl
			 << "and Wheatstone bridge example circuits." << endl ;
		outFile << "ECE 0301: Circuit Solver for Voltage Divider"  
			    << endl << "and Wheatstone bridge example circuits." 
			    << endl ;
		
	//read in line 1
		string line1 ; 
		inFile >> line1 ;
	
	//determine and validate input
	//if "Divider"
		if(line1 == "Divider")
		{
			//read in values
				inFile >> voltageSource >> resistor1 >> resistor2 ;
				
			//output section header
				outFile << "-----" << endl
						<< "Circuit #1 (Voltage Divider)" << endl
						<< "---" << endl ;
						
			//output initial values 
				outFile << "Source voltage: Vs = " << voltageSource 
						<< " Volts." << endl 
						<< "Resistor: R1 = " << resistor1
						<< " Ohms." << endl
						<< "Resistor: R2 = " << resistor2 
						<< " Ohms." << endl 
						<< endl ;
						
			//output calculated values
				outFile << "Loop current: I = " 
					    << loopCurrent(voltageSource, resistor1, 
						   resistor2) << " Amperes." << endl
						<< "Resistor voltage: V1 = "
						<< resistorVoltage(voltageSource, resistor1,
						   resistor2) << " Volts." << endl
						<< "Resistor voltage: V2 = "
						<< resistorVoltage(voltageSource, resistor2,
						   resistor1) << " Volts." << endl ;
		}
	//else if "Wheatstone" 
		else if (line1 == "Wheatstone")
		{
		}
	//else exit
		else
		{
			cout << "ERROR! Invalid header." ;
			return -1 ;
		}
}

//this method will calculate current using ohm's law and two resistance
//	values
//@param double v, double r1, double r2
//@return double
	double loopCurrent (double v, double r1, double r2)
	{
		return v / (r1 + r2) ;
	}

//this method will calculate resistor voltage using ohm's law and two
//	two resistance values
//@param double v, double r1, double r2
//@return double
	double resistorVoltage (double v, double r1, double r2)
	{
		return v * (r1 / (r1 + r2)) ;
	}
