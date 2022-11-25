/*
 *	ece0301_ICA04_step08.cpp
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
 * 	This program contains the code required for submission at Step 8
 *		in the assignment.
 */
 
#include <iostream>
#include <fstream>
#include <string>

using namespace std ;

double loopCurrentDivider (double v, double r1, double r2) ;
double resistorVoltageDivider (double v, double r1, double r2) ;
double resistorCurrentWheat (double i, double r) ;

int main()
{			 
	//declare filestreams
		ifstream inFile ;
		inFile.open("divider_wheatstone_circuits.txt") ;
		ofstream outFile ; 
		outFile.open("divider_wheatstone_solutions.txt") ;
		
	//declare variables
		double voltageSource, resistor1, resistor2 ;
		double currentSource, resistor3, resistor4, resistor5 ;
		
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
					    << loopCurrentDivider(voltageSource, resistor1, 
						   resistor2) << " Amperes." << endl
						<< "Resistor voltage: V1 = "
						<< resistorVoltageDivider(voltageSource, 
						   resistor1, resistor2) << " Volts." << endl
						<< "Resistor voltage: V2 = "
						<< resistorVoltageDivider(voltageSource, 
						   resistor2, resistor1) << " Volts." << endl ;
		}
	//else if "Wheatstone" 
		else if (line1 == "Wheatstone")
		{
			//read in values
				inFile >> voltageSource >> currentSource >> resistor1
					   >> resistor2 >> resistor3 >> resistor4
					   >> resistor5 ;
					   
			//output section header
				outFile << "-----" << endl
						<< "Circuit #1 (Wheatstone Bridge)" << endl
						<< "---" << endl ;
					   
			//calculate resistor voltage using read values, ohm's law
			//	and algebra explained in assignment overview
			
				//declare variables
					double a, b, c, d, e, f ;
					double w, x, y, z ;
					double voltage1, voltage2, voltage3, voltage4, 
						   voltage5 ;
					
				//solve for a, b, c, d, e, and f
					a = 1 + (resistor4 / resistor2) ;
					b = voltageSource - (currentSource * resistor4) ;
					c = 1 + (resistor5 / resistor3) ;
					d = voltageSource + (currentSource * resistor5) ;
					e = resistor1 / resistor2 ;
					f = resistor1 / resistor3 ;
					
				//validate for unstable floating-point division
					if(resistor2 == 0 || resistor3 == 0 || 
					  (b > -0.0000000000001 && b < 0.0000000000001) ||
					  (d > -0.0000000000001 && d < 0.0000000000001))
					{
						cout << "ERROR! Unstable floating-point" 
							 << " division." << endl ;
						return -1 ;
					}
						
				//solve for w, x, y, and z
					w = (a + e) / b ;
					x = f / b ;
					y = e / d ;
					z = (c + f) / d ;
				
				//solve for v1, v2, v3, v4, and v5
					voltage3 = (y - w) / ((x * y) - (w * z)) ;
					voltage2 = (1 - x * voltage3) / w ;
					voltage1 = (e * voltage2) + (f * voltage3) ;
					voltage4 = voltageSource - voltage1 - voltage2 ;
					voltage5 = voltageSource - voltage1 - voltage3 ;
					
			//output initial values
				outFile << "Source voltage: Vs = " << voltageSource
						<< " Volts." << endl 
						<< "Source current: Is = " << currentSource
						<< " Amperes." << endl
						<< "Resistor: R1 = " << resistor1 << " Ohms."
						<< endl
						<< "Resistor: R2 = " << resistor2 << " Ohms."
						<< endl
						<< "Resistor: R3 = " << resistor3 << " Ohms."
						<< endl
						<< "Resistor: R4 = " << resistor4 << " Ohms."
						<< endl
						<< "Resistor: R5 = " << resistor5 << " Ohms."
						<< endl
						<< endl ;
						
			//output calculated values
				outFile << "Resistor voltage: V1 = " << voltage1 
						<< " Volts." << endl
						<< "Resistor current: I1 = " 
						<< resistorCurrentWheat(voltage1, resistor1)
						<< " Amperes." << endl
						<< "Resistor voltage: V2 = " << voltage2 
						<< " Volts." << endl
						<< "Resistor current: I2 = " 
						<< resistorCurrentWheat(voltage2, resistor2)
						<< " Amperes." << endl
						<< "Resistor voltage: V3 = " << voltage3 
						<< " Volts." << endl
						<< "Resistor current: I3 = " 
						<< resistorCurrentWheat(voltage3, resistor3)
						<< " Amperes." << endl
						<< "Resistor voltage: V4 = " << voltage4 
						<< " Volts." << endl
						<< "Resistor current: I4 = " 
						<< resistorCurrentWheat(voltage4, resistor4)
						<< " Amperes." << endl
						<< "Resistor voltage: V5 = " << voltage5 
						<< " Volts." << endl
						<< "Resistor current: I5 = " 
						<< resistorCurrentWheat(voltage5, resistor5)
						<< " Amperes." << endl ;
		}
	//else exit
		else
		{
			cout << "ERROR! Invalid header." ;
			return -1 ;
		}
}

//this method will calculate current using ohm's law and two resistance
//	values in a divider circuit layout
//@param double v, double r1, double r2
//@return double
	double loopCurrentDivider (double v, double r1, double r2)
	{
		return v / (r1 + r2) ;
	}

//this method will calculate resistor voltage using ohm's law and two
//	two resistance values in a divider circuit layout
//@param double v, double r1, double r2
//@return double
	double resistorVoltageDivider (double v, double r1, double r2)
	{
		return v * (r1 / (r1 + r2)) ;
	}

//this method will calculate current using ohm's law, resistance 
//	values, and current values in the wheatstone curcuit layout
//@param double i, double r
//@return double
	double resistorCurrentWheat (double v, double r)
	{
		return v / r ;
	}
