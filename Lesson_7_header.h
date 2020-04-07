#ifndef ParkerGuillen7
/*
Author: Parker Guillen
Description: Lesson 7, header file, function prototypes are listed along with include and define statement.
2/27/18
*/


#include <stdio.h>
#include <math.h>
#include <time.h> //time() 
#include <stdlib.h>	//Rand and srand

typedef struct card			//introducing a struct a way to create a usable C data type
{//Tracks card numbers
	int cardr;
	int cardc;
}Card;					//struct card is now renamed Card



void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int cardnum, int flaggedval);
int is_pair(Card hand[]);
int is_pair_pair(Card hand[]);
int is_triple(Card hand[]);
int is_four_of_kind(Card hand[]);
int is_flush(Card hand[]);
int is_straight(Card hand[]);
int calculate_better_hand(Card handp[], Card handd[], int playerpoints, int  dealerpoints); 
void redraw_cards_p1( Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[]);
void dealer_draw_one(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int replacethiscard, int cardmun);
void dealer_redraw(Card hand[], int pair, int twopair, int triple, int straight, int flush, int four, const char *wSuit[], const char *wFace[], const int wDeck[][13]);
void print_cards(Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[]);
#endif // !ParkerGuillen7
