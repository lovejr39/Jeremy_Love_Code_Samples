/*	Jeremy Love
	Yahtzee Project
	This program will create the ScoreBoard class which will be used to create and display
		the all time score board of the Yahtzee game. It will read in and write to the
		"scoreboard.txt" file to show and store the player scores. It will store all the
		scores, but only display the top 5.	*/

import java.io.FileReader ;
import java.io.BufferedReader ;
import java.io.FileWriter ;
import java.io.PrintWriter ;
import java.io.IOException ;

import java.util.ArrayList ;

import static javax.swing.JOptionPane.* ;

public class ScoreBoard
{
/********************************************************************************************************************
	PUBLIC METHODS		*/

	//this method will read in a file and display the info as a score card
	//@param Player player
		public static void display(Player player) throws IOException
		{
			//variables
				BufferedReader br = new BufferedReader(new FileReader("scoreboard.txt")) ;
				PrintWriter pw ;

				ArrayList<String> fileReadIn = new ArrayList<String>() ;
				String[] names ;
				int[] scores ;
				int num ;
				String str ;

			//determine number of scores
				str = br.readLine() ;
				while(str != null)
				{
					fileReadIn.add(str) ;
					str = br.readLine() ;
				}

			//close
				br.close() ;

			//convert to standard arrays
				names = new String[(fileReadIn.size() / 2) + 1] ;
				scores = new int[(fileReadIn.size() / 2) + 1] ;

				for(int i = 0 ; i <  names.length - 1 ; i++)
				{
					names[i] = fileReadIn.remove(0) ;
					scores[i] = Integer.parseInt(fileReadIn.remove(0)) ;
				}
				names[names.length - 1] = player.getName() ;
				scores[scores.length - 1] = player.totalScore ;

			//sort
				for (int i = 0 ; i < scores.length ; i++)
		    		for (int j = 1 ; j < scores.length ; j++)
    				  	if (scores[j] > scores[j - 1])
    				  	{
							num = scores[j] ;
							scores[j] = scores[j - 1] ;
							scores[j - 1] = num ;

							str = names[j] ;
							names[j] = names[j - 1] ;
							names[j - 1] = str ;
    	   				 }

    	   	//create string to display
				if(scores.length >= 5)
					num = 5 ;
				else
					num = scores.length ;

				str = "Congradulations " + player.getName() + "!\nYour Score Was: " + player.totalScore + "\n\nCurrent Leaders:" ;

				for(int i = 0 ; i < num ; i++)
					str += "\n" + names[i] + " : " + scores[i] ;

			//display
				showMessageDialog(null, str, player.getName() + " Yahtzee Game", INFORMATION_MESSAGE) ;

			//write score to file
				pw = new PrintWriter(new FileWriter("scoreboard.txt")) ;

				for(int i = 0 ; i < names.length ; i++)
					pw.println(names[i] + "\n" + scores[i]) ;

			//close
				pw.close() ;

			//exit
				System.exit(0) ;
		}
}