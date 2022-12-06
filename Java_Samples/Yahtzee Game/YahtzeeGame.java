/*	Jeremy Love
	Yahtzee Project
	This program will create the YahtzeeGame class, which will act as the driver program
		for the game of yahtzee. It will use the Interface, Scoring, Player, DiceCup, and
		Run classes to function the game. It will greet the user, ask them for their name,
		then use JFrame window to play the game. When the game is over they will be shown
		their score and the program will end.	*/

import static javax.swing.JOptionPane.* ;

import java.io.IOException ;

public class YahtzeeGame
{
	public static void main(String[] args) throws IOException
	{
		//game variables
			final int TURN_AMOUNT = 13 ;
			int selectedValue ;
			boolean createScoring = true ;
			boolean createReroll = true ;
			String name ;
			String dialogText ;
			Player player = new Player("Jeremy") ;

		//get player information
			do
			{
				name = showInputDialog(null, "Welcome to Yahtzee!\nWhat is your name?", "Yahtzee Game", QUESTION_MESSAGE) ;

				if(name == null)
					System.exit(0) ;
			}
			while(name.equals("")) ;

		//create player object
			player = new Player(name) ;

		//siulate yahtzee turn
			for(int i = TURN_AMOUNT ; i > 0 ; i--)
			{
					//determine if the reroll button must be reset
						if(player.getCurrentRerolls() == 0)
							Interface.rerollResetNeeded = true ;

					//reset currentRerolls variable
						player.setCurrentRerolls(2) ;

					//output preroll message
						if(Player.currentLeftTotal >= 63)
						{
							player.totalScore += 35 ;
							dialogText = "Player Name: " + player.getName() + "\nCurrent Score: " + player.totalScore + "\nBonus Earned\nTurns Remaining: " + i ;
						}
						else
							dialogText = "Player Name: " + player.getName() + "\nCurrent Score: " + player.totalScore + "\nPoints Until Bonus: " + (63 - player.currentLeftTotal) + "\nTurns Remaining: " + i ;

						showMessageDialog(null, dialogText, player.getName() + " Yahtzee Game", INFORMATION_MESSAGE) ;

					//roll
						player.rollAll() ;

					//rerun if reroll
						do
						{
							//display scoring panel
								if(createScoring)
								{
									Interface.createFrameScoringGUI(player) ;
									createScoring = false ;
								}
								else
									Interface.updateFrameScoringGUI(player) ;

							//delay for interface
								Run.delay() ;

							//determine scoring action
								switch(Interface.selectedValue)
								{
									case -1 :
										if(createReroll)
										{
											Interface.createRerollGUI(player) ;
											createReroll = false ;
										}
										else
											Interface.updateRerollGUI(player) ;
									break ;

									case 0 :
										Player.totalScore += Scoring.getAces(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getAces(player.getDiceValues()) ;
									break ;

									case 1 :
										Player.totalScore += Scoring.getTwos(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getTwos(player.getDiceValues()) ;
									break ;

									case 2 :
										Player.totalScore += Scoring.getThrees(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getThrees(player.getDiceValues()) ;
									break ;

									case 3 :
										Player.totalScore += Scoring.getFours(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getFours(player.getDiceValues()) ;
									break ;

									case 4 :
										Player.totalScore += Scoring.getFives(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getFives(player.getDiceValues()) ;
									break ;

									case 5 :
										Player.totalScore += Scoring.getSixes(player.getDiceValues()) ;
										Player.currentLeftTotal += Scoring.getSixes(player.getDiceValues()) ;
									break ;

									case 6 :
										Player.totalScore += Scoring.getThreeOfAKind(player.getDiceValues()) ;
									break ;

									case 7 :
										Player.totalScore += Scoring.getFourOfAKind(player.getDiceValues()) ;
									break ;

									case 8 :
										Player.totalScore += Scoring.getFullHouse(player.getDiceValues()) ;
									break ;

									case 9 :
										Player.totalScore += Scoring.getSmallStraight(player.getDiceValues()) ;
									break ;

									case 10 :
										Player.totalScore += Scoring.getLargeStraight(player.getDiceValues()) ;
									break ;

									case 11 :
										Player.totalScore += Scoring.getChance(player.getDiceValues()) ;
									break ;

									case 12 :
										Player.totalScore += Scoring.getYahtzee(player.getDiceValues()) ;
									break ;
								}
						}
						while(Interface.selectedValue < 0) ;
			}

		//display scoreboard and terminate program
			ScoreBoard.display(player) ;
	}
}