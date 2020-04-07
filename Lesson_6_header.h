#ifndef Lesson6

/*
Author: Parker Guillen
3/28/18
Description: Lesson 6,  file, function prototypes are listed along with include and define statement.
*/


#include <stdio.h>
#include <math.h>
#include <time.h> //time() 
#include <stdlib.h>	//Rand and srand
#include <string.h>
#define MAX_R 10
#define MAX_C 10

typedef struct stats
{
	int total_shots;
	int total_hits;
	int total_misses;
	double hits_misses_ratio;
	char win_lose[25];
}Stats;


void start_screen();
void fill_board(char board[][MAX_C], int num_rows, int num_cols);
void print_board(char board[][MAX_C], int num_rows, int num_cols, int player);
char manually_place_ships(char board[][MAX_C]);
char randomly_place_ships(char board[][MAX_C]);
int starter(void);
int player1_turn(int *shotx, char board[][MAX_C]);
int player_comp_turn(int *shotx, char board[][MAX_C]);
char check_shot(char playerboard[][MAX_C], int targetx, int targety, int *misses,int *tot_hits, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num);	//May need to include hit or miss values as pointers
void check_ship_sunk(int shotx, int shoty, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num);
int check_for_winner(int p1_hits, int comp_hits);
void output_stats(Stats player, FILE*outfile);

#endif //!Lesson6
