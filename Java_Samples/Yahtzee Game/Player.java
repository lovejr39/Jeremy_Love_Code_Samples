/*	Jeremy Love
	Yahtzee Project
	This program will create the Player class to be used with the YahtzeeGame class.
		It will be used to manage the user's information, including their player name,
		current score, score remaining until left bonus, and the DiceCup containing the
		values of the dice that will be used for the game.	*/

public class Player
{
/********************************************************************************************************************
	DECLARE VARIABLES	*/

	//private variables
		private DiceCup playerCup = new DiceCup() ;
		private String playerName = null ;
		private int currentRerolls = 2 ;
		private int[] scores = new int[13] ;

	//public variables
		public static int totalScore = 0 ;
		public static int currentLeftTotal = 0 ;

/********************************************************************************************************************
	CONSTRUCTOR METHOD	*/

	//this method will act as the Player class constructor
	//@param String player name
		public Player(String playerName)
		{	this.playerName = playerName ;	}

/********************************************************************************************************************
	PUBLIC METHODS 		*/

	//this method will return the value of the currentReroll variable
	//@return int currentReroll value
		public int getCurrentRerolls()
		{	return currentRerolls ;	}

	//this method will return diceValues int array from the playerCup
	//@return int[] playerCup dice values
		public int[] getDiceValues()
		{	return playerCup.getDiceValues() ;	}

	//this method will return the name of the player
	//@return string playerName
		public String getName()
		{	return playerName ;	}

	//this method will remove a roll from the currentRolls variable
		public void removeRoll()
		{	currentRerolls-- ;	}

	//this method will call the rollAll method from the playerCup
		public void rollAll()
		{	playerCup.rollAll() ;	}

	//this method will roll one specific die in the playerCup
	//@param int index of die to roll
		public void rollOne(int num)
		{	playerCup.rollOne(num) ;	}

	//this method will set the currentRerolls variables
	//@param int value to set currentRerolls to
		public void setCurrentRerolls(int currentRerolls)
		{	this.currentRerolls = currentRerolls ;	}

	//this method will call the sortDice method from the playerCup
		public void sortDice()
		{	playerCup.sortValues() ;	}
}