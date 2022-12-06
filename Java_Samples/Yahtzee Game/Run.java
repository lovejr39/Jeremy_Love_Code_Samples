/*	Jeremy Love
	Yahtzee Project
	This program will create the Run class which will be used to delay other
		classes and programs while JFrame windows are being displayed.	*/

public class Run
{
/********************************************************************************************************************
	DECLARE VARIABLES	*/

	//public variables
		public static boolean b = true ;

/********************************************************************************************************************
	PUBLIC METHODS		*/

	//this method will delay a program until the boolean b is set false
		public static void delay()
		{
			while(b)
				try
				{	Thread.sleep(1) ;	}
				catch(InterruptedException e)
				{	}
		}
}