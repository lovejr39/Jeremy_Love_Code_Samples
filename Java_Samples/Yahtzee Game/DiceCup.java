/*	Jeremy Love
	Yahtzee Project
	This program will create the DiceCup class to ast a player's dice cup
		in the game of Yahtzee.	*/

import java.util.Arrays ;

public class DiceCup
{
/********************************************************************************************************************
	DECLARE VARIABLES	*/

	//private variables
		private int[] diceValues = new int[5] ;

/********************************************************************************************************************
	CONSTRUCTOR METHOD 	*/

	//this method will act as the DiceCup constructor, it will roll all the dice
		public DiceCup()
		{	rollAll() ;	}

/********************************************************************************************************************
	PUBLIC METHODS	 	*/

	//this method will return the diceValues array
	//@return int[] diceValues
		public int[] getDiceValues()
		{	return diceValues ;	}

	//this method will roll all the dice
		public void rollAll()
		{
			for(int i = 0 ; i < diceValues.length ; i++)
				rollOne(i) ;
			sortValues() ;
		}

	//this method will roll one die
	//@param index of dice to roll
		public void rollOne(int num)
		{	diceValues[num] = (int)(Math.random() * 6) + 1 ;	}

	//this method will sort the dice values from lowest to highest
		public void sortValues()
		{	Arrays.sort(diceValues) ;	}
}