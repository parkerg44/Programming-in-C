/*
Author: Parker Guillen
2/19/18
Description: PA 4, function files, function prototypes are listed along with include and define statement.
CPTS 121
*/
#include "header.h"


/*
*Function name: void print_game_rules(void)
*Date: 2/21/18
*Description: Prints the rules for the game craps
*Input parameters: None
*Returns: None
*Preconditions: None
*Post conditions: None
*/

void print_game_rules(void)
{
	printf("					******* GAME RULES ******\nA player rolls two dice. Each die has six ");
	printf("faces.These faces contain 1, 2, 3, 4, 5, and 6 spots.\nAfter the dice ");
	printf("have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins.\n If the sum is 2, 3, or ");
	printf("12 on the first throw (called 'craps'), the player loses(i.e.the 'house' wins).\n If the ");
	printf("sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's 'point.' ");
	printf("\nTo win, you must continue rolling the dice until you 'make your point.' The player loses by rolling\n");
	printf("a 7 before making the point.");
	printf("Player will enter one wager per game, if player wins wager will be added\n");
	printf(" to the bank balance, if player losses the wager will be subtracted.\n\n");
	return;
}
/*
*Function name: double get_bank_balance(void)
*Date: 2/21/18
*Description: Gets the bank balance from the player
*Input parameters: None
*Returns: Bank Balance
*Preconditions: None
*Post conditions: None
*/

double get_bank_balance(void)
{
	double bankbalance = 0.0;
	printf("Enter your bank Balance: ");
	scanf("%lf", &bankbalance);
	return bankbalance;

}
/*
*Function name: double get_wager_amount(void)
*Date: 2/21/18
*Description: Gets the wager amount from the player
*Input parameters: None
*Returns: wager
*Preconditions: None
*Post conditions: None
*/
double get_wager_amount(void)
{
	double wager1 = 0.0;
	printf("Enter your wager for this roll: ");
	scanf("%lf", &wager1);
	return wager1;
}

/*
*Function name: int check_wager_amount(double wager, double balance)
*Date: 2/21/18
*Description: checks the see if the wager is in the players bank balance.
*Input parameters: double wager, double balance
*Returns: If wager is in the players balance then 0 is returned otherwise 1 is returned.
*Preconditions:  wager and balance must be defined as doubles 
*Post conditions:
*/

int check_wager_amount(double wager, double balance)
{
	int successb = -1; 
	if (wager > balance)
	{
		successb = 0;
		/*while (wager >= balance)
		{
			printf("Please enter a smaller wager:\n");
			wager = get_wager_amount();
			if (wager <= balance)
			{
				successb = 1; 
				printf("Wager: %lf\n", wager);
				printf("Perfect time to take you money!\n");*/
		/*	
			}
		}*/
	}
	else
	{
		successb = 1;
		//printf("Perfect time to take you money!");
	}
	return successb; 
}

/*
*Function name: double get_newwager(int success, double wager1, double bankbal)
*Date: 2/21/18
*Description: checks the see if the wager is in the players bank balance. If not asks for a new wager
*Input parameters: int success, double wager1, double bankbal
*Returns: wager2 
*Preconditions:  success wager1 and bankbal must be defined
*Post conditions:
*/

double get_newwager(int success, double wager1, double bankbal)
{
	
	while (success ==0)
	{
		printf("Please enter a smaller wager:\n");
		wager1 = get_wager_amount();
		if (wager1 <= bankbal)
		{
			success = 1;
			printf("Wager: %lf\n", wager1);
			printf("Perfect time to take you money!\n");
		}
	}
	return wager1;
}

/*
*Function name: int roll_die(void)
*Date: 2/21/18
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
*Function name: calculate_sum_dice(int die1_value, int die2_value)
*Date: 2/21/18
*Description: calculates the sum of the two die.
*Input parameters: die1_value and die2_value
*Returns: The sum of the two die
*Preconditions: Must have two die values
*Post conditions: Sum must be returned
*/

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum5 = 0;
	sum5 = die1_value + die2_value; 
	return sum5;

}

/*
*Function name: int is_win_loss_or_point (int sum_dice)
*Date: 2/21/18
*Description: Determines the result of the first roll
*Input parameters: sum of the dice
*Returns: 0,1, or the players point
*Preconditions: Must have two die values
*Post conditions: Sum must be returned
*/
int is_win_loss_or_point(int sum_dice)
{
	int w_l_pointv = 20;

	if (sum_dice == 7 || sum_dice == 11);
	{
		w_l_pointv = 1;
	}

	if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
	{
		w_l_pointv = 0;
	}
	if (sum_dice == 4 || sum_dice == 5 || sum_dice == 6 || sum_dice == 8 || sum_dice == 9 || sum_dice == 10)
	{
		w_l_pointv = -1;
	}

	return w_l_pointv;
}

/*
*Function name: void win_or_loss(int firstrollscore)
*Date: 2/21/18
*Description: Prints out various messages for whether or not the player won or lost
*Input parameters: firstrollscore
*Returns: nothing
*Preconditions: firstrollscore has to be defined
*Post conditions: None
*/

void win_or_loss(int firstrollscore)
{
	if (firstrollscore == 1)
	{
		printf("Congratulations you have won the game!\n\n");
	}
	if (firstrollscore == 0)
	{
		printf("Sorry you lost!\n\n");
	}
	if (firstrollscore == -1)
	{
		printf("No win or loss this time! Roll again! Your bank balance will remain the same.\n\n");
	}
	return; 
}

/*
*Function name: is_point_loss_or_neither(int sum_dice, int point_value)
*Date: 2/21/18
*Description: For testing if the player wins or loses after finding the intial point value
*Input parameters: int sum_dice, int point_value
*Returns: the new point value
*Preconditions: sum_dice and point_value must be defined as ints
*Post conditions: point value is returned
*/

int is_point_loss_or_neither(int sum_dice, int point_value) {

	while (point_value != 1 && point_value != 0)
	{
		
		int d1 = 0, d2 = 0, sum3 = 0;
		d1 = roll_die();
		d2 = roll_die();
		printf("Dice roll 1 = %d,  Dice roll 2 = %d\n", d1, d2);
		sum3 = calculate_sum_dice(d1, d2);
		printf("Sum for this roll = %d\n", sum3);
		if (sum3 == 7)
		{
			point_value = 0;
			win_or_loss(point_value);
			
		}
		else if (sum3 == sum_dice)
		{
			point_value = 1;
			win_or_loss(point_value);
			
		}
		else 
		{
			point_value = -1;
			win_or_loss(point_value);
		}
	}
	return point_value;
	
}

/*
*Function name: double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
*Date: 2/21/18
*Description: adjusts the bank balance according to win or loss
*Input parameters: double bank_balance, double wager_amount, int add_or_subtract
*Returns: bank_balance
*Preconditions: input parameters must be defined
*Post conditions: none
*/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		bank_balance += wager_amount;
		printf("Updated Bank Balance: %.2lf\n", bank_balance);
	}
	else if (add_or_subtract == 0)
	{
		bank_balance -= wager_amount;
		printf("Updated Bank Balance: %.2lf\n\n", bank_balance);
	}
	else 
	{
		bank_balance = bank_balance;

	}
	return bank_balance;
}

//double test_first_roll(int is_wager_use, double bankbal, double wagera)
//{	
//	double updatedbal = 0.0;
//	if (is_wager_use == 0 || is_wager_use == 1)
//	{
//		if (is_wager_use == 0)
//		{
//			updatedbal = adjust_bank_balance(bankbal, wagera, 0);
//		}
//		if (is_wager_use == 1)
//		{
//			updatedbal = adjust_bank_balance(bankbal, wagera, 1);
//		}
//	}
//	return updatedbal;
//}

/*
*Function name:
void chatter_messages(int win_loss_neither, double initial_bank_balance, double current_bank_balance)
*Date: 2/21/18
*Description: gives chatter messages
*Input parameters: int win_loss_neither, double initial_bank_balance, double current_bank_balance
*Returns: none
*Preconditions: input parameters must be defined
*Post conditions: none
*/

void chatter_messages(int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (initial_bank_balance >= 500)
	{
		printf("Oh so you're a big gambler huh?\n Hopefully you don't waste all of that money!\n");
	}
	if (initial_bank_balance <= 499)
	{
		printf("Come on! you can gamble more than that!\n");
	}
	if (current_bank_balance > initial_bank_balance)
	{
		printf("You won this round but the house will gain it back!\n");
	}
	/*if (current_bank_balance < initial_bank_balance)
	{
		printf("You were close that time, Keep playing!");
	}*/
}