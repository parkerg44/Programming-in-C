/*
Author: Parker Guillen
2/27/18
Description: PA 5, function files, function prototypes are listed along with include and define statement.
CPTS 121
*/
#include "header.h"


/*
*Function name: void print_game_rules(void)
*Date: 2/28/18
*Description: Prints the rules for the game Yahtzee
*Input parameters: None
*Returns: None
*Preconditions: None
*Post conditions: None
*/

void print_game_rules(void)
{
	printf("\t\t\t\t\tGAME RULES\n");
	printf("The challenge of the game is to outduel the other player by scoring the most points.\n");
	printf(" Points are obtained by rolling five 6-sided die across thirteen rounds.\n");
	printf("During each round, each player may roll the dice up to three times to make one of the possible scoring combinations.\n");
	printf("Once a combination has been achieved by the player, it may not be used again in future rounds,\n");
	printf(" except for the Yahtzee combination may be used as many times as the player makes the combination.\n");
	printf("Each scoring combination has different point totals.\n");
	printf("Some of these totals are achieved through the accumulation of points across rolls and some are obtained as fixed sequences of values.\n\n");
	printf("The scorecard used for Yahtzee is composed of two sections.\n");
	printf("A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63,\n");
	printf("then 35 more points are added to the players overall score as a bonus. \n");
	printf("The lower section contains a number of poker like combinations. See the table provided below:\n\n");
	printf("Name\t\t\tCombination\t\t\t\tScore\n");
	printf("Three-of-a-kind\t\tThree dice with the same face\t\tSum of all face values on the 5 dice\n");
	printf("Four-of-a-kind\t\tFour dice with the same face\t\tSum of all face values on the 5 dice\n");
	printf("Full house\t\tOne pair and a three-of-a-kind\t\t25\n");
	printf("Small straight\t\tA sequence of four dice\t\t\t30\n");
	printf("Large straight\t\tA sequence of five dice\t\t\t40\n");
	printf("Yahtzee \t\tFive dice with the same face\t\t50\n");
	printf("Chance \t\t\tMay be used for any sequence of dice\tSum of all face values on the 5 dice\n\n\n");
	return 0;
}

/*
*Function name: int roll_die(void)
*Date: 2/28/18
*Description: Rolls one die will be used in later loops
*Input parameters: None
*Returns: Value of one die
*Preconditions: None
*Post conditions: die is returned
*/

int roll_die(void)
{
	int die400 = 0;
	die400 = rand() % 6 + 1;
	return die400;
}

/*
*Function name: int* roll_5_die(int dice5[])
*Date: 2/28/18
*Description: Rolls 5 dice for the player
*Input parameters: dice5[]
*Returns: values of 5 dice in an array 
*Preconditions: None
*Post conditions: dice5 is returned
*/
int* roll_5_die(int dice5[])
{	
	int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
	d1 = roll_die();		//Rolls all the five die
	d2 = roll_die();
	d3 = roll_die();
	d4 = roll_die();
	d5 = roll_die();
	dice5[0] = d1;			//Places the rolled day within an array
	dice5[1] = d2;
	dice5[2] = d3;
	dice5[3] = d4;
	dice5[4] = d5;
	return dice5;

}

/*
*Function name: void print_dice_roll(int dice5[])
*Date: 2/28/18
*Description: Prints the dice values for the players roll
*Input parameters: int dice5[]
*Returns: None
*Preconditions: None
*Post conditions: None
*/

void print_dice_roll(int dice5[])
{
	
	for (int i = 1; i < 6; ++i)		//runs threw loop five times to print out each die value
	{
		printf("Die%d: %d\n", i, dice5[i-1]);
	}

}

/*
*Function name: calculate_sum_dice(int die1_value, int die2_value)
*Date: 3/1/18
*Description: calculates the sum of the five die.
*Input parameters: int die1_value, int die2_value, int die3_value, int die4_value, int die5_value
*Returns: The sum of the five die
*Preconditions: Must have five die values
*Post conditions: Sum must be returned
*/

int calculate_sum_dice(int die1_value, int die2_value, int die3_value, int die4_value, int die5_value)
{
	int sum5 = 0;
	sum5 = die1_value + die2_value + die3_value + die4_value + die5_value;		//Not used
	return sum5;

}

/*
*Function name: int  reroll(int roll_or_nah, int dice5[])
*Date: 3/1/18
*Description: lets user pick which dice to reroll
*Input parameters: int roll_or_nah, int dice5[]
*Returns: The updated array of 5 dice
*Preconditions: roll_or_nah must be defined as well as dice5[]
*Post conditions: dice5 must be returned
*/
int  reroll(int roll_or_nah, int dice5[])
{
	int dieval_or_quit = -1;
	if (roll_or_nah == 1)
	{
		printf("Enter 1 to start picking dice to reroll: ");
		scanf("%d", &dieval_or_quit);
		while (dieval_or_quit != 0)
		{
			printf("\nChoose die to reroll(Enter 1 for die 1, 2 for die 2, ect. Enter values one at a time)*Enter 0 to Roll again!*: ");
			scanf("%d", &dieval_or_quit);
			if (dieval_or_quit == 1)
			{
				dice5[0] = roll_die();
			}
			if (dieval_or_quit == 2)
			{
				dice5[1] = roll_die();
			}
			if (dieval_or_quit == 3)
			{
				dice5[2] = roll_die();
			}
			if (dieval_or_quit == 4)
			{
				dice5[3] = roll_die();
			}
			if (dieval_or_quit == 5)
			{
				dice5[4] = roll_die();
			}
		}
	}
	return dice5;
}

/*
*Function name: int choose_selection(void)
*Date: 3/5/18
*Description: gets selection number for a score value from the user
*Input parameters:  none
*Returns: selection
*Preconditions: none
*Post conditions: selection is returned as an int
*/

int choose_selection(void)
{
	int selection = 0;
	printf("Please enter your selection: (Enter 1 for sum of one's, 13 for chance, ect.)\n");
	printf("1. Sum of One's: \t\t5. Sum of Five's: \t\t8. Four of a kind: \t\t11. Large Straight:  \n");
	printf("2. Sum of Two's: \t\t6. Sum of Six's: \t\t9. Full House: \t\t\t12. Yahtzee:  \n");
	printf("3. Sum of Three's: \t\t7. Three of a kind: \t\t10. Small Straight: \t\t13. Chance:   \n");
	printf("4. Sum of Four's: \n");
	scanf("%d", &selection);
	return selection; 

}
/*
*Function name: int block_selection(int selection_num, int scores[])
*Date: 3/5/18
*Description: blocks user from choosing an score selection if it has already been used in previous rounds
*Input parameters:  int selection_num, int scores[]
*Returns: selection_num
*Preconditions: paramters are defined
*Post conditions: selection_num is returned as an int
*/

int block_selection(int selection_num, int scores[])
{
	int success = 0;
	while (success == 0)
	{
		//if (selection_num == 12 && (scores[11] == 0 || scores[11] == 1 || scores[11] == 2 || scores[11] == 3 || scores[11] == 4 || scores[11] == 5 || scores[11] == 6))
		//{
		//	//printf("Your selection is valid!(Has not been choosen this game)\n");
		//	scores[11] += 1;
		//	success = 1;
		//}
		if (scores[selection_num - 1] == 0 )
		{
			scores[selection_num - 1] = 1;
			printf("Your selection is valid!(Has not been choosen this game)\n");
			success = 1;
		}
		else if (selection_num == 12)			//Allows for the yahtzee combo to be used many times
		{
			scores[11] = scores[11] + 1;
			printf("Your selection is valid!(Yahtzee combination used as many times as needed)\n");
			success = 1;
		}
		else
		{
			printf("Sorry your selection is invalid, please enter a new selection:\n ");
			success = 0;
			selection_num = choose_selection();
		}
	}
	return selection_num;
}

/*
*Function name: count_num_of_occurences(int dice5[], int scoreorder1[])
*Date: 3/5/18
*Description: using loops and if statements to count backwards the number of occurances in the die roll
*Input parameters:  int dice5[], int scoreorder1[]
*Returns: scoreorder1
*Preconditions: paramters are defined
*Post conditions: array scoreorder1 is returned as an int
*/
int count_num_of_occurences(int dice5[], int scoreorder1[])
{
	int i = 0;

	scoreorder1[0] = dice5[0];		//sets the values of the scoreorder to the values from the die roll
	scoreorder1[1] = dice5[1];
	scoreorder1[2] = dice5[2];
	scoreorder1[3] = dice5[3];
	scoreorder1[4] = dice5[4];
	scoreorder1[5] = 0;
	while (i < 6)		//Goes into loop six times to get values for dice one to six
	{
		if (scoreorder1[i] <= 0)		//uses various if statements to count the values backwards
		{
			i++;
			continue;
		}
		int index = scoreorder1[i] - 1;
		if (scoreorder1[index] > 0)
		{
			scoreorder1[i] = scoreorder1[index];
			scoreorder1[index] = -1;
		}
		else
		{
			scoreorder1[index]--;
			scoreorder1[i] = 0;
			i++;
		}
	}
	scoreorder1[0] = scoreorder1[0] * -1;	//turns the values back into positive numbers
	scoreorder1[1] = scoreorder1[1] * -1;
	scoreorder1[2] = scoreorder1[2] * -1;
	scoreorder1[3] = scoreorder1[3] * -1;
	scoreorder1[4] = scoreorder1[4] * -1;
	scoreorder1[5] = scoreorder1[5] * -1;

	//printf("Counts of all elements: \n");
	//for (int i = 0; i < 6; i++)
	//{
	//	printf("Number of %d's : %d\n", i + 1, scoreorder1[i]);
	//}
	/*int correctscore[7] = { 0 };
	
	for (int i = 0; i < 5; i++)
	{
		int temp = dice5[i];
		scoreorder1[temp] += 1;

	}
	for (int i = 0; i < 6; i++)
	{
		printf("Die %d: %d\n", i+1 , scoreorder1[i+1]);
	}
	correctscore[0] = scoreorder1[1];
	correctscore[1] = scoreorder1[2];
	correctscore[2] = scoreorder1[3];
	correctscore[3] = scoreorder1[4];
	correctscore[4] = scoreorder1[5];
	correctscore[5] = scoreorder1[6];

	for (int i = 0; i < 6; i++)
	{
		printf("Number of %d's : %d\n", i + 1, correctscore[i]);
	}
	*/


	return scoreorder1;
}

/*
*Function name: int add_points_check_selection(int player_points, int selection, int score[])
*Date: 3/2/18
*Description: Checks to see if the user has the selected choice, if so returns the correct amount of points
*Input parameters:  int player_points, int selection, int score[]
*Returns: player points for that round
*Preconditions: all input parameters are defined
*Post conditions: player_points is returned as an int
*/

int add_points_check_selection(int player_points, int selection, int score[])
{
	int summ = 0;			//Goes into an if statement for each possible value the user could've selected and checks to see if the user has it
	if (selection == 1)
	{
		summ = score[0] * 1;
		player_points = player_points + summ;
	}

	else if (selection == 2)
	{
		summ = score[1] * 2;
		player_points = player_points + summ;
	}

	else if (selection == 3)
	{
		summ = score[2] * 3;
		player_points = player_points + summ;
	}

	else if (selection == 4)
	{
		summ = score[3] * 4;
		player_points = player_points + summ;
	}

	else if (selection == 5)
	{
		summ = score[4] * 5;
		player_points = player_points + summ;
	}

	else if (selection == 6)
	{
		summ = score[5] * 6;
		player_points = player_points + summ;
	}

	else if (selection == 7)
	{
		if (score[0] >= 3 || score[1] >= 3 || score[2] >= 3 || score[3] >= 3 || score[4] >= 3 || score[5] >= 3)
		{
			summ = (score[0] * 1) + (score[1] * 2) + (score[2] * 3) + (score[3] * 4) + (score[4] * 5) + (score[5] * 6);
			player_points = player_points + summ;
		}
		else
		{
			summ = 0;
			player_points = player_points + summ;
		}
	}

	else if (selection == 8)
	{
		if (score[0] >= 4 || score[1] >= 4 || score[2] >= 4 || score[3] >= 4 || score[4] >= 4 || score[5] >= 4)
		{
			summ = (score[0] * 1) + (score[1] * 2) + (score[2] * 3) + (score[3] * 4) + (score[4] * 5) + (score[5] * 6);
			player_points = player_points + summ;
		}
		else
		{
			summ = 0;
			player_points = player_points + summ;
		}
	}

	else if (selection == 9)
	{
		if (score[0] == 5 || score[0] == 3 && score[1] == 2 || score[0] == 3 && score[2] == 2 ||		//Every possible combination for a full house
			score[0] == 3 && score[3] == 2 || score[0] == 3 && score[4] == 2 || score[0] == 3 && score[5] == 2 ||
			score[1] == 5 || score[1] == 3 && score[0] == 2 || score[1] == 3 && score[2] == 2 || score[1] == 3 && score[3] == 2 ||
			score[1] == 3 && score[4] == 2 || score[1] == 3 && score[5] == 2 || score[2] == 5 || score[2] == 3 && score[0] == 2 ||
			score[2] == 3 && score[1] == 2 || score[2] == 3 && score[3] == 2 || score[2] == 3 && score[4] == 2 || score[2] == 3 && score[5] == 2 ||
			score[3] == 5 || score[3] == 3 && score[0] == 2 || score[3] == 3 && score[1] == 2 || score[3] == 3 && score[2] == 2 ||
			score[3] == 3 && score[4] == 2 || score[3] == 3 && score[5] == 2 || score[4] == 5 || score[4] == 3 && score[0] == 2 ||
			score[4] == 3 && score[1] == 2 || score[4] == 3 && score[2] == 2 || score[4] == 3 && score[3] == 2 || score[4] == 3 && score[5] == 2 ||
			score[5] == 5 || score[5] == 3 && score[0] == 2 || score[5] == 3 && score[1] == 2 || score[5] == 3 && score[2] == 2 ||
			score[5] == 3 && score[3] == 2 || score[5] == 3 && score[4] == 2)
		{
			summ = 25;
			player_points = player_points + summ;
		}
		else
		{
			summ = 0;
			player_points = player_points + summ; 
		}
	}

	else if (selection == 10)
	{
		if ((score[0] >= 1 && score[1] >= 1 && score[2] >= 1 && score[3] >= 1) || (score[1] >= 1 && score[2] >= 1 && score[3] >= 1 &&
			score[4] >= 1) || (score[2] >= 1 && score[3] >= 1 && score[4] >= 1 && score[5] >= 1))
		{
			summ = 30;
			player_points = player_points + summ;
		}
		else
		{
			summ = 0;
			player_points = player_points + summ;
		}
	}
	else if (selection == 11)
	{
		if ((score[0] == 1 && score[1] == 1 && score[2] == 1 && score[3] == 1 && score[4] == 1) || (score[1] == 1 && score[2] == 1 && score[3] == 1
			&& score[4] == 1 && score[5] == 1))
		{
			summ = 40;
			player_points = player_points + summ;
		}
		else
		{
			summ = 0;
			player_points = player_points + summ;
		}
	}

	else if (selection == 12)
	{
		if (score[0] == 5 || score[1] == 5 || score[2] == 5 || score[3] == 5 || score[4] == 5 || score[5] == 5)
		{
			summ = 50;
			player_points = player_points + summ; 
		}

		else
		{
			summ = 0;
			player_points = player_points + summ;
		}
	}

	else if (selection == 13)
	{
		summ = (score[0] * 1) + (score[1] * 2) + (score[2] * 3) + (score[3] * 4) + (score[4] * 5) + (score[5] * 6);
		player_points = player_points + summ;
	}



	return player_points; 
}

/*
*Function name: int player1final(int play1points)
*Date: 3/3/18
*Description: Adds 35 to player 1's score if its greater than  or equal 63
*Input parameters:  play1points (player 1's points)
*Returns: player 1's updated points
*Preconditions: play1points is defined
*Post conditions: play1points is returned as an int
*/
int player1final(int play1points)
{
	if (play1points >= 63)
	{
		play1points = play1points + 35;
	}
	else
	{
		play1points = play1points;
	}
	return play1points;
}

/*
*Function name: int player2fin(int player2p)
*Date: 3/3/18
*Description: Adds 35 to player 2's score if its greater than  or equal 63
*Input parameters: player2p (player 2's points)
*Returns: player 2's updated points
*Preconditions: player2p is defined
*Post conditions: player2p is returned as an int
*/
int player2fin(int player2p)
{
	if (player2p >= 63)
	{
		player2p = player2p + 35;
	}
	else
	{
		player2p = player2p;
	}
	return player2p;
}