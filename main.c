/*
Author: Parker Guillen
2/27/18
Description: The following function allows for a two player game of yahtzee, try it out!
CPTS 121
*/

#include "header.h"

int main(void)
{	//defining variables
	int option = 0, roll = 0, roll2 = 0, reroll_t_f = 0, reroll_t_f2 = 0, pointselection = 0, pointselection2 = 0;
	int new_selection = 0, new_selection2 = 0, player1points = 0, player2points = 0;
	int diceroll5[5] = { 0 };		// defining arrays
	int diceroll6[5] = { 0 };
	int scores1[13] = { 0 };
	int scores2[13] = { 0 };
	int scoreorder[6] = { 0 };		
	int scoreorder2[6] = { 0 };
	int dicecount1[7] = { 0 };
	int player1final1 = 0, player2final = 0;
	

	printf("1. Display Rules\n2. Play Game\n3. Exit\nEnter 1,2 or 3: \n");		//Prints out an option menu
	scanf("%d", &option);														//Scans in the users options

	while (option == 1 || option == 2 || option == 3)							//while loop for the three options
	{
		while (option == 1)			//Prints the game rules if the player enters the game rules functions
		{
			print_game_rules();
			system("pause");	//Allows player to remove the rules from the screen
			system("cls");
			printf("1. Display Rules\n2. Play Game\n3. Exit\nEnter 1,2 or 3: \n");
			scanf("%d", &option);	//get a new option
		}
		while (option == 2)		//while loop for game play
		{
			for (int index = 1; index < 14; index++)	//Allows the game to be player for 13 rounds for both players
			{
				//Player 1 turn 

				srand(time(NULL));		// Allows die to change each roll 
				srand((unsigned int)(time(NULL)));
				roll_5_die(diceroll5);

				printf("\t\t\t\t\t***ROUND %d***\n\t\t\t\t   (Player 1: Points: %d)\n", index, player1points);
				printf("Player 1 Enter 1 to roll your dice!: ");	//User presses button to roll 
				scanf("%d", &roll);
				while (roll = 1)	//Rolls die when user presses the roll die button
				{
					print_dice_roll(diceroll5);	//Prints the result of the dice roll
					break;
				}

				printf("Enter 1 to reroll enter 0 to keep your roll: ");	//Asks if player one wants to reoll die
				scanf("%d", &reroll_t_f);

				if (reroll_t_f == 1)		//Allow the die to be rerolled
				{
					reroll(reroll_t_f, diceroll5);
					print_dice_roll(diceroll5);

					printf("Enter 1 to reroll enter 0 to keep your roll: ");	//asks for the second time, making it three chances for the player to roll
					scanf("%d", &reroll_t_f);

					if (reroll_t_f == 1)
					{
						reroll(reroll_t_f, diceroll5);
						print_dice_roll(diceroll5);
					}
				}

				pointselection = choose_selection();
				printf("Selection: %d\n", pointselection); // Prints the players selection 

				new_selection = block_selection(pointselection, scores1);		//If the selection is invalid asks the user for a new one

				//for (int i = 1; i < 14; ++i)			//Printing if combinations have been used in the game so far Remove
				//{
				//	printf("%d.: %d\n", i, scores1[i - 1]);
				//}
				printf("%d\n\n", new_selection);

				count_num_of_occurences(diceroll5, scoreorder); //counts the occurence of values in the dice roll

				player1points = add_points_check_selection(player1points, new_selection, scoreorder);
				printf("Player 1 points: %d\n\n", player1points);



				int scoreorder[6] = { 0 };	//resets player ones values back to zero for the next round
				int diceroll5[5] = { 0 };
				system("Pause");		//Allows the player to press any button when ready to continue 
				system("cls");			// clears out player ones round

				//player 2 
				roll_5_die(diceroll6);

				printf("\t\t\t\t\t***ROUND %d***\n\t\t\t\t   (Player 2: Points: %d)\n", index, player2points);

				printf("Player 2 Enter 1 to roll your dice!: ");	//User presses button to roll more dice player two
				scanf("%d", &roll2);
				while (roll2 = 1)
				{
					print_dice_roll(diceroll6);
					break;
				}

				printf("Enter 1 to reroll enter 0 to keep your roll: ");		//Asks user for a value if die should be rerolled or not
				scanf("%d", &reroll_t_f2);

				if (reroll_t_f2 == 1)		//Following if statements allow the user to choose die to reroll
				{
					reroll(reroll_t_f2, diceroll6);
					print_dice_roll(diceroll6);

					printf("Enter 1 to reroll enter 0 to keep your roll: ");
					scanf("%d", &reroll_t_f2);

					if (reroll_t_f2 == 1)
					{
						reroll(reroll_t_f2, diceroll6);
						print_dice_roll(diceroll6);
					}
				}

				pointselection2 = choose_selection();		// Prints the selection combo player can choosw 
				printf("Selection: %d\n", pointselection2); // Prints players selection

				new_selection2 = block_selection(pointselection2, scores2); // Checks to see if selection is valid

				printf("%d\n\n", new_selection2);		//Prints the new combo player wants to use if the first choice was invalid

				count_num_of_occurences(diceroll6, scoreorder2); //counts the occurence of values in the dice roll

				player2points = add_points_check_selection(player2points, new_selection2, scoreorder2); //Checks if the player has the wanted combo
				printf("Player 2 points: %d\n\n", player2points);		// Prints the points for player two



				int scoreorder2[6] = { 0 };		//resets the die and score values to zero so a new roll can be insured next round
				int diceroll6[5] = { 0 };
				system("Pause");
				system("cls");


			}
			// End of four loop for rounds
			player1final1 = player1final(player1points);		// Checks to see if the final points for each player are greater than 63
			player2final = player2fin(player2points);
			
			if (player1final1 >player2final)			// Prints scores and winner player 1
			{
				printf("PLAYER 1 WINS!!!!!\n\n");
				printf("Player 1 score: %d \tPlayer 2 score: %d\n", player1final1, player2final);
			}
			else if (player1final1 < player2final)		// Prints scores and winner player 2
			{
				printf("PLAYER 2 WINS!!!!!\n\n");
				printf("Player 2 score: %d \tPlayer 1 score: %d\n", player2final, player1final1);
			}
			else
			{
				printf("Tie!");		// Prints tie if the player scores equal each other
			}

			system("pause");		// Screen stays up until user wants to continue 
			system("cls");
			player1points = 0;		// Sets both players point values back to zeros for the next game
			player2points = 0;

			printf("1. Display Rules\n2. Play Game\n3. Exit\nEnter 1,2 or 3: \n");
			scanf("%d", &option);

		}
		if (option == 3)			//Takes the option from the user to execute the final statement
		{
			printf("Thank you for playing!\nGoodbye!\n\n");
			break;
		}
		
	}
	system("pause");
	return 0;
}