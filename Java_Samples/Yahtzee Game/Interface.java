/*	Jeremy Love
	Yahtzee Project
	This program will create the Interface class, which will be used to create and display
		the gui interfaces for the functioning of the game. It will manage the two main
		interfaces, the scoring interface and the reroll interface. It will also read and
		determine the user's selected button and assign it to the public variable selectedValue,
		where it can be use in other programs freely to allow for easier scoring.	*/

import javax.swing.JFrame ;
import javax.swing.JPanel ;
import javax.swing.JLabel ;
import javax.swing.JButton ;
import javax.swing.JCheckBox ;
import javax.swing.ImageIcon ;

import java.awt.event.ActionListener ;
import java.awt.event.ActionEvent ;

import java.awt.Dimension ;
import java.awt.GridLayout ;
import java.awt.FlowLayout ;

import java.util.ArrayList ;
import java.util.Arrays ;

public class Interface extends JFrame
{
/********************************************************************************************************************
	DECLARE VARIABLES 	*/

	//private variables
		private static JFrame frameScoring = fullFrame("Yahtzee Roll Results", 598, 690) ;
		private static JFrame frameReroll = fullFrame("Yahtzee Reroll", 598, 276) ;

		private static ArrayList<JPanel> socringPanels = new ArrayList<JPanel>() ;
		private static ArrayList<JPanel> rerollPanels = new ArrayList<JPanel>() ;

		private static JCheckBox[] checkBoxes ;

	//public variables
		public static boolean rerollResetNeeded = false ;
		public static int selectedValue ;

/********************************************************************************************************************
	PUBLIC METHODS	 	*/

	//this method will create and display the scoring gui and determine the selected values
		public static void createFrameScoringGUI(Player player)
		{
			//begin run
				Run.b = true ;

			//create panels
				socringPanels.add(textPanel(player.getName().toUpperCase() + "'S ROLL:")) ;
				socringPanels.add(diceIconPanel(player.getDiceValues())) ;
				socringPanels.add(textPanel("SCORING OPTIONS:")) ;
				socringPanels.add(scoringButtonsPanel(player)) ;
				socringPanels.add(buttonPanel("YAHTZEE!", 12, 161, 46, 2, player)) ;
				socringPanels.add(buttonPanel("Roll Again", -1, 322, 46, 2, player)) ;

			//add panels
				for(JPanel panel : socringPanels)
					frameScoring.add(panel) ;

			//show frame
				frameScoring.setVisible(true) ;
		}

	//this method will create and display the reroll gui and determine which dice are selected to be saved
		public static void createRerollGUI(Player player)
		{
			//begin run
				Run.b = true ;

			//create panels
				rerollPanels.add(textPanel("SELECT DICE TO SAVE")) ;
				rerollPanels.add(diceIconPanel(player.getDiceValues())) ;
				rerollPanels.add(checkBoxPanel(player)) ;
				rerollPanels.add(buttonPanel("ROLL", -1, 184, 46, 3, player)) ;

			//add panels
				for(JPanel panel : rerollPanels)
					frameReroll.add(panel) ;

			//show frame
				frameReroll.setVisible(true) ;

			//determind reroll
				determineSaved(player) ;
		}

	//this method will update and display the scoring gui and determine the selected value
		public static void updateFrameScoringGUI(Player player)
		{
			//begin run
				Run.b = true ;

			//update panels
				for(JPanel panel : socringPanels)
					frameScoring.remove(panel) ;

				socringPanels.remove(1) ;
				socringPanels.add(1, diceIconPanel(player.getDiceValues())) ;

				if(rerollResetNeeded)
				{
					socringPanels.remove(5) ;
					socringPanels.add(buttonPanel("Roll Again", -1, 322, 46, 2, player)) ;
					rerollResetNeeded = false ;
				}

				for(JPanel panel : socringPanels)
					frameScoring.add(panel) ;

			//show frame
				frameScoring.setVisible(true) ;
		}

	//this method will update nad display the reroll gui and determine which dice are selected
		public static void updateRerollGUI(Player player)
		{
			//begin run
				Run.b = true ;

			//remove panels from frame
				for(JPanel panel : rerollPanels)
					frameReroll.remove(panel) ;

			//update panels
				rerollPanels.remove(1) ;
				rerollPanels.add(1, diceIconPanel(player.getDiceValues())) ;

			//add panels
				for(JPanel panel : rerollPanels)
					frameReroll.add(panel) ;

			//uncehck all
				for(JCheckBox box : checkBoxes)
					box.setSelected(false) ;

			//set visible
				frameReroll.setVisible(true) ;

			//determind reroll
				determineSaved(player) ;
		}

/********************************************************************************************************************
	PRIVATE METHODS	 	*/

	//this method will create and return a JPanel with a single JButton
	//@param String text on JButton, int actionValue value to be returned when JButton pressed
	//		 int hDimension of JButton, int vDimension of JButton, int interfaceValue of specific JFrame
	//		 Player player
	//@return JPanel with JButton
		private static JPanel buttonPanel(String text, int actionValue, int hDimension, int vDimension, int interfaceValue, Player player)
		{
			JPanel panel = new JPanel() ;
			panel.setPreferredSize(new Dimension(598, 69)) ;

			JButton button = new JButton(text) ;
			button.setPreferredSize(new Dimension(hDimension, vDimension)) ;

			createActionListener(button, actionValue, interfaceValue, player) ;

			panel.add(button) ;

			return panel ;
		}

	//this method will create and return a JPanel containing JCheckBoxes
	//@param Player player
	//@return JPanel with JCheckBoxes
		private static JPanel checkBoxPanel(Player player)
		{
			checkBoxes = new JCheckBox[player.getDiceValues().length] ;

			for(int i = 0 ; i < checkBoxes.length ; i++)
				checkBoxes[i] = new JCheckBox() ;

			JPanel panel = new JPanel() ;
			panel.setLayout(new FlowLayout(FlowLayout.CENTER, 92, 0)) ;

			for(JCheckBox cb : checkBoxes)
				panel.add(cb) ;

			return panel ;
		}

	//this method will create and ActionListener for a given JButton
	//@param JButton to create ActionListener for, int actionValue value to be returned when JButton pressed
	//		 int interfaceValue of specific JFrame, Player player
		private static void createActionListener(JButton button, int actionValue, int interfaceValue, Player player)
		{
			//set action command value to JButton
				button.setActionCommand("" + actionValue) ;

			//create and add ActionListener to JButton
				button.addActionListener(new ActionListener()
				{
					public void actionPerformed(ActionEvent event)
					{
						//get returned int from button
							selectedValue = Integer.parseInt(button.getActionCommand()) ;

						//if frameScoring JFrame
							if(interfaceValue == 2)
							{
								frameScoring.setVisible(false) ;

								if(selectedValue >= 0)
									button.setEnabled(false) ;
								else if(selectedValue < 0)
								{
									player.removeRoll() ;

									if(player.getCurrentRerolls() == 0)
										button.setEnabled(false) ;
								}
							}
						//else if frameReroll JFrame
							else if(interfaceValue == 3)
								frameReroll.setVisible(false) ;

						//end run
							Run.b = false ;
					}
				}) ;
		}

	//this method will determine the saved dice and reroll the other dice
	//@param Player player with DiceCup to roll
		private static void determineSaved(Player player)
		{
			//delay until selection
				Run.delay() ;

			//determine locked dice
				boolean[] lockedDice = new boolean[player.getDiceValues().length] ;

				for(int i = 0 ; i < lockedDice.length ; i++)
					lockedDice[i] = !checkBoxes[i].isSelected() ;

			//reroll selected dice
				for(int i = 0 ; i < lockedDice.length ; i++)
					if(lockedDice[i])
						player.rollOne(i) ;

			//sort
				player.sortDice() ;
		}

	//this method will create and return a JPanel containin ImageIcons representing diceValues
	//@param int[] diceValues to displaye
	//@return JPanel with images
		private static JPanel diceIconPanel(int[] diceValues)
		{
			JPanel panel = new JPanel() ;
			panel.setLayout(new FlowLayout(FlowLayout.LEADING, 23, 0)) ;

			for(int i : diceValues)
			{
				if(i == 1)
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_One.PNG"))) ;
				else if(i == 2)
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_Two.PNG"))) ;
				else if(i == 3)
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_Three.PNG"))) ;
				else if(i == 4)
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_Four.PNG"))) ;
				else if(i == 5)
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_Five.PNG"))) ;
				else
					panel.add(new JLabel(new ImageIcon("dice_images\\Dice_Six.PNG"))) ;
			}

			return panel ;
		}

	//this method will create and return the JFrame for the gui interface
	//@param String title of JFrame, int hDimension of JFrame, int vDimension of JFrame
	//@return JFrame created
		private static JFrame fullFrame(String title, int hDimension, int vDimension)
		{
			JFrame frame = new JFrame() ;
			frame.setLayout(new FlowLayout()) ;

			frame.setTitle(title) ;

			frame.setSize(hDimension, vDimension) ;
			frame.setLocationRelativeTo(null) ;

			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE) ;

			return frame ;
		}

	//this method will create and return a JPanel containing text
	//@param text for JPanel
	//@return JPanel with text
		private static JPanel textPanel(String text)
		{
			JPanel panel = new JPanel();
			panel.setPreferredSize(new Dimension(598, 46)) ;

			JLabel label = new JLabel(text) ;
			label.setFont(label.getFont().deriveFont(30.0f)) ;

			panel.add(label) ;

			return panel ;
		}

	//this method will create and return a JPanel containing the scoring JButtons for Yahtzee
	//@param Player player
	//@return JPanel with JButtons
		private static JPanel scoringButtonsPanel(Player player)
		{
			JPanel panel = new JPanel() ;
			panel.setLayout(new GridLayout(6, 2, 92, 0)) ;
			panel.setPreferredSize(new Dimension(368, 299)) ;

			String[] leftLabels = {"Aces", "Twos", "Threes", "Fours", "Fives", "Sixes"} ;
			String[] rightLabels = {"3 of a Kind", "4 of a Kind", "Full House", "Sm. Straight", "Lg. Straight", "Chance"} ;

			for(int i = 0 ; i < leftLabels.length ; i++)
			{
				JButton leftButton = new JButton(leftLabels[i]) ;
				createActionListener(leftButton, i, 2, player) ;

				panel.add(leftButton) ;

				JButton rightButton = new JButton(rightLabels[i]) ;
				createActionListener(rightButton, i + 6, 2, player) ;

				panel.add(rightButton) ;
			}

			return panel ;
		}
}