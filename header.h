#ifndef ParkerGuillenPA5
#pragma once
/*
Author: Parker Guillen
Description: PA 5, header file, function prototypes are listed along with include and define statement.
Cpts 121
2/27/18
*/

#include <stdio.h>
#include <math.h>
#include <time.h> //time() 
#include <stdlib.h>	//Rand and srand


void print_game_rules(void);
int roll_die(void);
int * roll_5_die(int dice5[]);
void print_dice_roll(int dice5[]);
int calculate_sum_dice(int die1_value, int die2_value, int die3_value, int die4_value, int die5_value);
int reroll(int roll_or_nah,int dice5[]);
int choose_selection(void);
int block_selection(int selection_num, int scores1[]);
int count_num_of_occurences(int dice5[], int score[]);
int add_points_check_selection(int player_points, int selection, int score[]);
int player1final(int play1points);
int player2fin(int player2p);


#endif // !ParkerGuillenPA5