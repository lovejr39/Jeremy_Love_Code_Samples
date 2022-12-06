/*	Jeremy Love
	Yahtzee Project
	This program will create the Scoring class for the game of yahtzee.	It will
		be used to determine the score of each score option selection when
		given an int[] of the dice values.	*/

import java.util.Collections ;
import java.util.ArrayList ;

public class Scoring
{
/********************************************************************************************************************
	LEFT COLUMN METHODS	 	*/

	//this method will return the total of the aces
	//@param int[] dice values to score
	//@return score total of aces
		public static int getAces(int[] diceValues)
		{	return totalValue(diceValues, 1) ;	}

	//this method will return the total of the twos
	//@param int[] dice values to score
	//@return score total of twos
		public static int getTwos(int[] diceValues)
		{	return totalValue(diceValues, 2) ;	}

	//this method will return the total of the threes
	//@param int[] dice values to score
	//@return score total of threes
		public static int getThrees(int[] diceValues)
		{	return totalValue(diceValues, 3) ;	}

	//this method will return the total of the fours
	//@param int[] dice values to score
	//@return score total of fours
		public static int getFours(int[] diceValues)
		{	return totalValue(diceValues, 4) ;	}

	//this method will return the total of the fives
	//@param int[] dice values to score
	//@return score total of fives
		public static int getFives(int[] diceValues)
		{	return totalValue(diceValues, 5) ;	}

	//this method will return the total of the sixes
	//@param int[] dice values to score
	//@return score total of threes
		public static int getSixes(int[] diceValues)
		{	return totalValue(diceValues, 6) ;	}

/********************************************************************************************************************
	RIGHT COLUMN METHODS 	*/

	//this method will determine if there are three of a kind
	//@paran int[] dice values
	//@return int total of all dice if three of a kind, 0 if not
		public static int getThreeOfAKind(int[] diceValues)
		{
			int matches = 0 ;
			for(int i = 0 ; i < diceValues.length ; i++)
			{
				for(int j = 0 ; j < diceValues.length ; j++)
				{
					if(diceValues[i] == diceValues[j])
						matches++ ;
					if(matches >= 3)
						return getTotal(diceValues) ;
				}
				matches = 0 ;
			}
			return 0 ;
		}

	//this method will determine if there are four of a kind
	//@param int[] dice values
	//@return int total of all dice if four of a kind, 0 if not
		public static int getFourOfAKind(int[] diceValues)
		{
			int matches = 0 ;
			for(int i = 0 ; i < diceValues.length ; i++)
			{
				for(int j = 0 ; j < diceValues.length ; j++)
				{
					if(diceValues[i] == diceValues[j])
						matches++ ;
					if(matches >= 4)
						return getTotal(diceValues) ;
				}
				matches = 0 ;
			}
			return 0 ;
		}

	//this method will determine if there is a full house
	//@param int[] dice values
	//@return 25 if full house, 0 if not
		public static int getFullHouse(int[] diceValues)
		{
			if(((diceValues[0] == diceValues[1]) && (diceValues[2] == diceValues[3]) && (diceValues[2] == diceValues[4])) ||
			   ((diceValues[3] == diceValues[4]) && (diceValues[0] == diceValues[1]) && (diceValues[0] == diceValues[2])))
				return 25 ;
			else
				return 0 ;
		}

	//this method will determine if there is a small straight
	//@param int[] dice values
	//@return 30 if small straight, 0 if not
		public static int getSmallStraight(int[] diceValues)
		{
			ArrayList<Integer> diceValuesList = new ArrayList<Integer>() ;

			for(int i : diceValues)
				diceValuesList.add(i) ;

			for(int i = 0 ; i < diceValuesList.size() - 1 ; i++)
				if(Collections.frequency(diceValuesList, diceValuesList.get(i)) > 1)
					diceValuesList.remove(i) ;

			if((diceValuesList.size() == 4) && (diceValuesList.get(0) + 1 == diceValuesList.get(1)) &&
			   (diceValuesList.get(0) + 2 == diceValuesList.get(2)) && (diceValuesList.get(0) + 3 == diceValuesList.get(3)))
				return 30 ;
			else
				return 0 ;
		}

	//this method will determine if there is a large straight
	//@param int[] dice values
	//@return 40 if large straight, 0 if not
		public static int getLargeStraight(int[] diceValues)
		{
			if((diceValues[0] + 1 == diceValues[1]) && (diceValues[0] + 2 == diceValues[2]) &&
			   (diceValues[0] + 3 == diceValues[3]) && (diceValues[0] + 4 == diceValues[4]))
				return 40 ;
			else
				return 0 ;
		}

	//this method will determine the score for chance
	//@param int[] dice values
	//@return total of all dice
		public static int getChance(int[] diceValues)
		{	return getTotal(diceValues) ;	}

/********************************************************************************************************************
	MIDDLE COLUMN METHODS	*/

	//this mehtod will return the total of all dice if a yahtzee is scored
	//@param int[] dice values
	//@return int 50 if yahtzee, 0 if not
		public static int getYahtzee(int[] diceValues)
		{
			int num = diceValues[0] ;
			boolean yahtzee = true ;
			for(int i = 1 ; i < diceValues.length ; i++)
				if(diceValues[i] != num)
					yahtzee = false ;
			if(yahtzee)
				return 50 ;
			else
				return 0 ;
		}

/********************************************************************************************************************
	PRIVATE METHODS	 	*/

	//this method will return the total of all the dice
	//@param int[] dice values
	//@return int total of dice
		private static int getTotal(int[] diceValues)
		{
			int total = 0 ;
			for(int i : diceValues)
				total+=i ;
			return total ;
		}

	//this method will total a specific value contained in the diceValues array
	//@param diceValues values to assess, int num to total
	//@return total of all num
		private static int totalValue(int[] diceValues, int num)
		{
			int total = 0 ;
			for(int i : diceValues)
				if(i == num)
					total += num ;
			return total ;
		}
}