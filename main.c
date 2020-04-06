/*
Author: Parker Guillen
2/19/18
Description: PA 4: A game of craps, allows the user to play the die game craps.
Collaborators: Andrew's code from class for rolling die and various other small pieces of code.
CPTS 121
*/
#include "header.h"

int main(void)
{


	double bankbalance = 0.0, wager = 0.0, bankbalancecurrent = 0.0, wager2=0.0;
	int wager_in_limit = -1, die1 = 0, die2 = 0, sum = 0, win_loss_pointval = 0, wagertrue = 0, option = 0;

	printf("1. Display Rules\n2. Play Game\n3. Exit\nEnter 1,2 or 3: \n");
	scanf("%d", &option);

	while (option == 1 || option == 2 || option == 3)	//Loop allows for the player to choose 3 options
	{
		while (option == 1)		//If the player enters option one then game rules will be printed
		{
			print_game_rules();
			printf("1. Display Rules\n2. Play Game\nEnter 1,2 or 3: \n");
			scanf("%d", &option);
		}

		while (option == 2)
		{
			bankbalance = get_bank_balance();		//Gets bank balance
			printf("Bank Balance for gambling: %.2lf\n", bankbalance);	

			chatter_messages(win_loss_pointval, bankbalance, bankbalancecurrent); //Prints chatter

			wager = get_wager_amount();		//Gets wager
			
			wager_in_limit = check_wager_amount(wager, bankbalance);	//Checks if wager is in limit
			wager2 = get_newwager(wager_in_limit, wager, bankbalance);	//gets new wager if pervious wager wasnt in limit
			printf("Wager is in the limit of your bank balance: Yes\n"); 

			srand(time(NULL));		// Allows die to change each roll 
			srand((unsigned int)(time(NULL)));
			die1 = roll_die();	//Die values for the first roll
			die2 = roll_die();
			printf("Die1: %d\nDie2: %d\n", die1, die2);

			sum = calculate_sum_dice(die1, die2);	//Gets sum of the first roll
			printf("Sum: %d\n", sum);	

			win_loss_pointval = is_win_loss_or_point(sum);
			/*printf("Win/Loss/Pointvalue: %d\n", win_loss_pointval);*/

			win_or_loss(win_loss_pointval);

			wagertrue = is_point_loss_or_neither(sum, win_loss_pointval);


			bankbalancecurrent = adjust_bank_balance(bankbalance, wager2, wagertrue);
			//bankbalance = test_first_roll(wager_in_limit, bankbalance, wager);
			printf("1. Display Rules\n2. Play Game\nEnter 1,2 or 3: \n");
			scanf("%d", &option);


		}
		if (option == 3)
		{
			break;
		}
	
	}


	system("pause");
	return 0;
}