/*
Author: Parker Guillen
4/4/18
Description: Write a simple verison of the game poker using arrays for cards
*/

#include "Header.h"

int main(void)
{
	// initialize suit array 
	const char *suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	// initialize face array 
	const char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	

	Card hand1[5] = { {0,0} }, hand2[5] = { {0,0} };
	//Card hand1[5] = { { 1,12}, {1,12}, {1, 12}, {2,12}, {1, 2} }, hand2[5] = { { 0,0 } }; //FOR TESTING VALUES

	int deck[4][13] = { 0 };		//initalize deck array

	srand((unsigned)time(NULL));		// Random-number generator

	shuffle(deck);
	printf("Player 1's deck: \n");
	deal(deck, face, suit, hand1, 1, 1);	//Deals the players hand (hand1) at a starting card value of 1
	printf("\nDealers deck: \n");	//Don't want to show the dealers deck REMOVE LATER
	deal(deck, face, suit, hand2, 6, 2);	//Deals the dealers hand (hand2) at a starting card value of 1

	//printf("\n\n");
	//for (int i = 0; i <= 4; i++)
	//{
	//	printf("Row: %d\tColumn: %d\n", hand1[i].cardr, hand1[i].cardc);
	//}

	/*printf("\n\n");
	for (int i = 0; i <= 4; i++)
	{
		printf("Row: %d\tColumn: %d\n", hand2[i].cardr, hand2[i].cardc);
	}
*/
	int pairtest = 0, p1pairtest = 0, fourtest = 0, triptest = 0, flushtest = 0,straighttest = 0, player1total = 0; //player 1
	//Determines the hand of player 1 and the point value
	pairtest = is_pair(hand1);
	//printf("Pair: %d\n", pairtest);
	p1pairtest = is_pair_pair(hand1);
	//printf("2 Pairs: %d\n", p1pairtest);
	triptest = is_triple(hand1);
	//printf("triple: %d\n", triptest);		//DELETE ALL PRINT STATEMENTS
	fourtest = is_four_of_kind(hand1);
	//printf("Four of a kind: %d\n", fourtest);
	flushtest = is_flush(hand1);
	//printf("Flush: %d\n", flushtest);
	straighttest = is_straight(hand1);
	//printf("straight: %d\n", straighttest);
	player1total = pairtest + p1pairtest + triptest + fourtest + flushtest;
	//printf("Player 1: %d\n\n", player1total);

	int dpairtest = 0, dp1pairtest = 0, dfourtest = 0, dtriptest = 0, dflushtest = 0, dstraighttest = 0, dtotal = 0;
	dpairtest = is_pair(hand2);
	//printf("Pair: %d\n", dpairtest);
	dp1pairtest = is_pair_pair(hand2);
	//printf("2 Pairs: %d\n", dp1pairtest);
	dtriptest = is_triple(hand2);
	//printf("triple: %d\n", dtriptest);
	dfourtest = is_four_of_kind(hand2);
	//printf("Four of a kind: %d\n", dfourtest);
	dflushtest = is_flush(hand2);
	//printf("Flush: %d\n", dflushtest);
	dstraighttest = is_straight(hand2);
	//printf("straight: %d\n", dstraighttest);
	dtotal = dpairtest + dp1pairtest + dtriptest + dfourtest + dflushtest;
	//printf("Dealer: %d\n", dtotal);


	/*int redraw = 0; 
	printf("Player 1 enter 1 to redraw cards: ");
	scanf("%d", redraw);*/

	redraw_cards_p1(hand1, deck, face, suit);		//Allows the player to redraw more cards


	//printf("\n\n");
	//for (int i = 0; i <= 4; i++)
	//{
	//	printf("Row: %d\tColumn: %d\n", hand1[i].cardr, hand1[i].cardc);
	//}

	pairtest = is_pair(hand1);
	//printf("Pair: %d\n", pairtest);
	p1pairtest = is_pair_pair(hand1);
	//printf("2 Pairs: %d\n", p1pairtest);
	triptest = is_triple(hand1);
	//printf("triple: %d\n", triptest);		//DELETE ALL PRINT STATEMENTS
	fourtest = is_four_of_kind(hand1);
	//printf("Four of a kind: %d\n", fourtest);
	flushtest = is_flush(hand1);
	//printf("Flush: %d\n", flushtest);
	straighttest = is_straight(hand1);
	//printf("straight: %d\n", straighttest);
	player1total = pairtest + p1pairtest + triptest + fourtest + flushtest;
	//printf("Player 1: %d\n\n", player1total);





	dealer_redraw(hand2, dpairtest, dp1pairtest, dtriptest, dstraighttest, dflushtest, dfourtest, suit, face, deck);

	//printf("\n\n");
	//for (int i = 0; i <= 4; i++)
	//{
	//	printf("Row: %d\tColumn: %d\n", hand2[i].cardr, hand2[i].cardc);
	//}
	dpairtest = is_pair(hand2);
	//printf("Pair: %d\n", dpairtest);
	dp1pairtest = is_pair_pair(hand2);
	//printf("2 Pairs: %d\n", dp1pairtest);
	dtriptest = is_triple(hand2);
	//printf("triple: %d\n", dtriptest);
	dfourtest = is_four_of_kind(hand2);
	//printf("Four of a kind: %d\n", dfourtest);
	dflushtest = is_flush(hand2);
	//printf("Flush: %d\n", dflushtest);
	dstraighttest = is_straight(hand2);
	//printf("straight: %d\n", dstraighttest);
	dtotal = dpairtest + dp1pairtest + dtriptest + dfourtest + dflushtest;
	//printf("Dealer: %d\n", dtotal);


	printf("Player 1 cards:\n");
	print_cards(hand1, deck, face, suit);

	printf("\n\nDealer's cards: \n");
	print_cards(hand2, deck, face, suit);

	int winner_of_now = 0;
	winner_of_now = calculate_better_hand(hand1, hand2, player1total, dtotal);
	
 

	system("pause");
	return 0;
}

