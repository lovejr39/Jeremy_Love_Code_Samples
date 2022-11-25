/*
 * 	ece0301_ICA_cmplx_nmbr.cpp
 * 
 * 	Jeremy Love
 * 	4333291
 * 	2/25/21
 * 	Assignment #7
 * 	
 *	This program will create and define the ComplexNumber class. It
 * 		also provide a main function to test the usability of the 
 * 		ComplexNumber class.
 */
 
#include <iostream>
#include <cmath>
using namespace std;

// ComplexNumber class declaration.
class ComplexNumber
{
   private:
      int real;
      int imaginary;
   public:
      void setReal(double);
      void setImaginary(double);
      int getReal() const;
      int getImaginary() const;
      int getMagnitude() const;
      double getPhaseAngle() const;
};

//************************************************
// setRaal assigns a value to the real member.   *
//************************************************

void ComplexNumber::setReal(double r)
{
   real = r;
}

//********************************************************
// setImaginary assigns a value to the imaginary member. *
//********************************************************

void ComplexNumber::setImaginary(double i)
{
   imaginary = i;
}

//**************************************************
// getReal returns the value in the real member. *
//**************************************************

int ComplexNumber::getReal() const
{
   return real;
}

//**********************************************************
// getImaginary returns the value in the imaginary member. *
//**********************************************************

int ComplexNumber::getImaginary() const
{
   return imaginary;
}

//****************************************************
// getMagnitude calculates and returns the magnitude *
//****************************************************

int ComplexNumber::getMagnitude() const
{
   return sqrt(pow(real,2)+pow(imaginary,2)) ;	
}

//******************************************************
// getPhaseAnglecalculates and returns the phase angle *
//******************************************************

double ComplexNumber::getPhaseAngle() const
{
   return atan2(imaginary,real) ;
}

//*****************************************************
// Function main                                      *
//*****************************************************

int main()
{
   ComplexNumber cmplxNum;	// Define instance of ComplexNumber class
   double localReal;  		// Local variable for real
   double localImaginary;	// Local variable for imaginary

   // Get the rectangle's width and length from the user.
   cout << "This program will calculate the magnitude and phase\n";
   cout << "angle of a complex number.\n\nWhat is the real part? ";
   cin >> localReal;
   cout << "What is the imaginary part? ";
   cin >> localImaginary;

   // Store the width and length of the rectangle
   // in the box object.
   cmplxNum.setReal(localReal);
   cmplxNum.setImaginary(localImaginary);

   // Display the rectangle's data.
   cout << "Here is the data on the complex number z:\n";
   cout << "Real part: " << cmplxNum.getReal() << endl;
   cout << "Imaginary part: " << cmplxNum.getImaginary() << endl;
   cout << "Magnitude: " << cmplxNum.getMagnitude() << endl;
   cout << "Phase angle (radians): " << cmplxNum.getPhaseAngle() 
		<< endl ;
   return 0;
}
