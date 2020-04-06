#ifndef ParkerGuillenPA4
/*
Author: Parker Guillen
Description: PA 4, header file, function prototypes are listed along with include and define statement.
Cpts 121
2/14/18
*/

#include <stdio.h>
#include <math.h>
#include <time.h> //time() 
#include <stdlib.h>	//Rand and srand



//Function prototypes
void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);
int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_loss_or_point(int sum_dice);
void win_or_loss(int firstrollscore);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);
//double test_first_roll(int is_wager_use, double bankbal, double wagera);
void chatter_messages(int win_loss_neither, double initial_bank_balance, double current_bank_balance);
double get_newwager(int success, double wager1, double bankbal);




#endif // !ParkerGuillenPA4



