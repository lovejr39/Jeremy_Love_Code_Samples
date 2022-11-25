/*
 * 	ece0301_ICA_NOT_gate.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/25/21
 * 	Assignment #7
 * 	
 *	This program will create and define the NOTGate class. It
 * 		also provide a main function to test the usability of the 
 * 		NOTGate class.
 */
 
#include <iostream>
 
using namespace std ;
 
class NOTGate
{
	private :
		string inputLabel ;
		bool inputLogicValue ;
	public :
		void setInputLabel(string str);
		void setInputLogicValue(bool truthVal) ;
		string getInputLabel() ;
		bool getInputLogicValue() ;
		string getOutputLabel() ;
		bool getOutputLogicValue() ;
} ;
 
//variable mutators 

//this function will assign the inputLabel member variable
//@param string str
	void NOTGate::setInputLabel(string str)
	{	inputLabel = str ;	}
	
//this function will assign the inputLogicValue member variable
//@param bool truthVal
	void NOTGate::setInputLogicValue(bool truthVal)
	{	inputLogicValue = truthVal ;	}
	
//variable accessors

//function will return the inputLabel member variable
//@return string inputLabel
	string NOTGate::getInputLabel()
	{	return inputLabel ;	}

//function will return the inputLogicValue member variable
//@return bool inputLogicValue
	bool NOTGate::getInputLogicValue()
	{	return inputLogicValue ;	}
 
 //calculatory functions
	
//this method will calculate and return the output label string
//@return string outputLabel
	string NOTGate::getOutputLabel()
	{	return inputLabel + "_not" ;	}
	
//this method will calculate and return the output logic value bool
//@return bool outputLogicValue
	bool NOTGate::getOutputLogicValue()
	{	return !inputLogicValue ;	}
	
//*********************************************************************
	
int main()
{
	//declare variables
		NOTGate gate ;
		string inputStr ;
		bool inputBool ;
		
	//display introductory message
		cout << "This program will simulate a not gate." << endl ;
		
	//ask for and assign input label
		cout << "What is the label for the gate input? " ;
		cin >> inputStr ;
		gate.setInputLabel(inputStr) ;
		
	//ask for and assign input logic value
		cout << "What is the logic value at the input (0/1)? " ;
		cin >> inputBool ;
		gate.setInputLogicValue(inputBool) ;
		
	//output gate information
		cout << "Here are the data on the not gate:" << endl 
			 << "Input label: " << gate.getInputLabel() << endl 
			 << "Output label: " << gate.getOutputLabel() << endl
			 << "Logic value at input: " << gate.getInputLogicValue() 
			 << endl
			 << "Logic value at output: " << gate.getOutputLogicValue()
			 << endl ;
}
