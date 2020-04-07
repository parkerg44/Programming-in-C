/*
Author: Parker Guillen
2/27/18
Description: Poker functions file 
*/
//The main issue with these functions is speed, try and write an algorthim 
//Which can determine all of the card combinations without the use of a large number of if/else 

#include "Lesson_7_header.h"
/*
*Function name: void shuffle(int wDeck[][13])
*Date: 4/4/17
*Description: goes through the values of the deck and shuffles the deck
*Input parameters: wDeck[][13]
*Returns: None
*Preconditions: wDeck must be defined
*Post conditions: None
*/

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					// for each of the 52 cards, choose slot of deck randomly 
	for (card = 1; card <= 52; card++)
	{
		// choose new random location until unoccupied slot found 
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}


/* 
*Function name: deal(const int wDeck[][13], const char *wFace[], const char *wSuit[])
*Date: 4/4/17
*Description: deals the deck
*Input parameters: wDeck[][13]
*Returns: None, but prints the deck
*Preconditions: wDeck, *wFace, and *Wsuit all must be defined
*Post conditions: None
*/
void deal(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int cardnum, int flaggedval)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

					/* deal each of the 52 cards */
	//for (card = 1; card <= 52; card++)
	//{
	//	/* loop through rows of wDeck */
	//	for (row = 0; row <= 3; row++)
	//	{
	//		/* loop through columns of wDeck for current row */
	//		for (column = 0; column <= 12; column++)
	//		{
	//			/* if slot contains current card, display card */
	//			if (wDeck[row][column] == card)
	//			{
	//				printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
	//			}
	//		}
	//	}
	//}
	int counter = 0;
	if (flaggedval == 1)
	{
		for (card = cardnum; card <= cardnum + 4; card++)		//updating fuction to deal only five cardes
		{

			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card)
					{

						printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
						hand[counter].cardr = row;
						hand[counter].cardc = column;

					}
				}
			}
			counter++;
		}
	}
	if (flaggedval == 2)
	{
		for (card = cardnum; card <= cardnum + 4; card++)		//updating fuction to deal only five cardes
		{

			/* loop through rows of wDeck */
			for (row = 0; row <= 3; row++)
			{
				/* loop through columns of wDeck for current row */
				for (column = 0; column <= 12; column++)
				{
					/* if slot contains current card, display card */
					if (wDeck[row][column] == card)
					{

						//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
						hand[counter].cardr = row;
						hand[counter].cardc = column;
					

					}
				}
			}
			counter++;
		}
		printf("|````|\t|````|\t|````|\t|````|\t|````| \n");		//Prints the dealers cards hidden
		printf("|    |\t|    |\t|    |\t|    |\t|    | \n");
		printf("|____|\t|____|\t|____|\t|____|\t|____| \n");
	}
	printf("\n");
}


/*
*Function name: int is_pair(Card hand[])
*Date: 4/5/17
*Description: determines if there is a pair in the hand and assigns a point value based on the resulting pair combo
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/

int is_pair(Card hand[])
{
	int value = 0;			//Testing if a pair exists
	if (hand[0].cardc == hand[1].cardc || hand[0].cardc == hand[2].cardc || hand[0].cardc == hand[3].cardc || hand[0].cardc == hand[4].cardc
		|| hand[1].cardc == hand[2].cardc || hand[1].cardc == hand[3].cardc || hand[1].cardc == hand[4].cardc || hand[2].cardc == hand[3].cardc
		|| hand[2].cardc == hand[4].cardc || hand[3].cardc == hand[4].cardc)
	{
		if (hand[0].cardc == 0 && hand[1].cardc == 0 || hand[0].cardc == 0 && hand[2].cardc == 0 || hand[0].cardc == 0 && hand[3].cardc == 0 || hand[0].cardc == 0 && hand[4].cardc == 0 
			|| hand[1].cardc == 0 && hand[2].cardc == 0 || hand[1].cardc == 0 && hand[3].cardc == 0 || hand[1].cardc == 0 && hand[4].cardc == 0 || hand[2].cardc == 0 && hand[3].cardc ==0
			|| hand[2].cardc ==0 && hand[4].cardc == 0 || hand[3].cardc == 0 && hand[4].cardc == 0)
		{
			value = 1;		//Assigning a value to the pair based on ranking within cards
		}
		if (hand[0].cardc == 1 && hand[1].cardc == 1 || hand[0].cardc == 1 && hand[2].cardc == 1 || hand[0].cardc == 1 && hand[3].cardc == 1 || hand[0].cardc == 1 && hand[4].cardc == 1
			|| hand[1].cardc == 1 && hand[2].cardc == 1 || hand[1].cardc == 1 && hand[3].cardc == 1 || hand[1].cardc == 1 && hand[4].cardc == 1 || hand[2].cardc == 1 && hand[3].cardc == 1
			|| hand[2].cardc == 1 && hand[4].cardc == 1 || hand[3].cardc == 1 && hand[4].cardc == 1)
		{
			value = 2;
		}
		if (hand[0].cardc == 2 && hand[1].cardc == 2 || hand[0].cardc == 2 && hand[2].cardc == 2 || hand[0].cardc == 2 && hand[3].cardc == 2 || hand[0].cardc == 2 && hand[4].cardc == 2
			|| hand[1].cardc == 2 && hand[2].cardc == 2 || hand[1].cardc == 2 && hand[3].cardc == 2 || hand[1].cardc == 2 && hand[4].cardc == 2 || hand[2].cardc == 2 && hand[3].cardc == 2
			|| hand[2].cardc == 2 && hand[4].cardc == 2 || hand[3].cardc == 2 && hand[4].cardc == 2)
		{
			value = 3;
		}
		if (hand[0].cardc == 3 && hand[1].cardc == 3 || hand[0].cardc == 3 && hand[2].cardc == 3 || hand[0].cardc == 3 && hand[3].cardc == 3 || hand[0].cardc == 3 && hand[4].cardc == 3
			|| hand[1].cardc == 3 && hand[2].cardc == 3 || hand[1].cardc == 3 && hand[3].cardc == 3 || hand[1].cardc == 3 && hand[4].cardc == 3 || hand[2].cardc == 3 && hand[3].cardc == 3
			|| hand[2].cardc == 3 && hand[4].cardc == 3 || hand[3].cardc == 3 && hand[4].cardc == 3)
		{
			value = 4;
		}
		if (hand[0].cardc == 4 && hand[1].cardc == 4 || hand[0].cardc == 4 && hand[2].cardc == 4 || hand[0].cardc == 4 && hand[3].cardc == 4 || hand[0].cardc == 4 && hand[4].cardc == 4
			|| hand[1].cardc == 4 && hand[2].cardc == 4 || hand[1].cardc == 4 && hand[3].cardc == 4 || hand[1].cardc == 4 && hand[4].cardc == 4 || hand[2].cardc == 4 && hand[3].cardc == 4
			|| hand[2].cardc == 4 && hand[4].cardc == 4 || hand[3].cardc == 4 && hand[4].cardc == 4)
		{
			value = 5;
		}
		if (hand[0].cardc == 5 && hand[1].cardc == 5 || hand[0].cardc == 5 && hand[2].cardc == 5 || hand[0].cardc == 5 && hand[3].cardc == 5 || hand[0].cardc == 5 && hand[4].cardc == 5
			|| hand[1].cardc == 5 && hand[2].cardc == 5 || hand[1].cardc == 5 && hand[3].cardc == 5 || hand[1].cardc == 5 && hand[4].cardc == 5 || hand[2].cardc == 5 && hand[3].cardc == 5
			|| hand[2].cardc == 5 && hand[4].cardc == 5 || hand[3].cardc == 5 && hand[4].cardc == 5)
		{
			value = 6;
		}
		if (hand[0].cardc == 6 && hand[1].cardc == 6 || hand[0].cardc == 6 && hand[2].cardc == 6 || hand[0].cardc == 6 && hand[3].cardc == 6 || hand[0].cardc == 6 && hand[4].cardc == 6
			|| hand[1].cardc == 6 && hand[2].cardc == 6 || hand[1].cardc == 6 && hand[3].cardc == 6 || hand[1].cardc == 6 && hand[4].cardc == 6 || hand[2].cardc == 6 && hand[3].cardc == 6
			|| hand[2].cardc == 6 && hand[4].cardc == 6 || hand[3].cardc == 6 && hand[4].cardc == 6)
		{
			value = 7;
		}
		if (hand[0].cardc == 7 && hand[1].cardc == 7 || hand[0].cardc == 7 && hand[2].cardc == 7 || hand[0].cardc == 7 && hand[3].cardc == 7 || hand[0].cardc == 7 && hand[4].cardc == 7
			|| hand[1].cardc == 7 && hand[2].cardc == 7 || hand[1].cardc == 7 && hand[3].cardc == 7 || hand[1].cardc == 7 && hand[4].cardc == 7 || hand[2].cardc == 7 && hand[3].cardc == 7
			|| hand[2].cardc == 7 && hand[4].cardc == 7 || hand[3].cardc == 7 && hand[4].cardc == 7)
		{
			value = 8;
		}
		if (hand[0].cardc == 8 && hand[1].cardc == 8 || hand[0].cardc == 8 && hand[2].cardc == 8 || hand[0].cardc == 8 && hand[3].cardc == 8 || hand[0].cardc == 8 && hand[4].cardc == 8
			|| hand[1].cardc == 8 && hand[2].cardc == 8 || hand[1].cardc == 8 && hand[3].cardc == 8 || hand[1].cardc == 8 && hand[4].cardc == 8 || hand[2].cardc == 8 && hand[3].cardc == 8
			|| hand[2].cardc == 8 && hand[4].cardc == 8 || hand[3].cardc == 8 && hand[4].cardc == 8)
		{
			value = 9;
		}
		if (hand[0].cardc == 9 && hand[1].cardc == 9 || hand[0].cardc == 9 && hand[2].cardc == 9 || hand[0].cardc == 9 && hand[3].cardc == 9 || hand[0].cardc == 9 && hand[4].cardc == 9
			|| hand[1].cardc == 9 && hand[2].cardc == 9 || hand[1].cardc == 9 && hand[3].cardc == 9 || hand[1].cardc == 9 && hand[4].cardc == 9 || hand[2].cardc == 9 && hand[3].cardc == 9
			|| hand[2].cardc == 9 && hand[4].cardc == 9 || hand[3].cardc == 9 && hand[4].cardc == 9)
		{
			value = 10;
		}
		if (hand[0].cardc == 10 && hand[1].cardc == 10 || hand[0].cardc == 10 && hand[2].cardc == 10 || hand[0].cardc == 10 && hand[3].cardc == 10 || hand[0].cardc == 10 && hand[4].cardc == 10
			|| hand[1].cardc == 10 && hand[2].cardc == 10 || hand[1].cardc == 10 && hand[3].cardc == 10 || hand[1].cardc == 10 && hand[4].cardc == 10 || hand[2].cardc == 10 && hand[3].cardc == 10
			|| hand[2].cardc == 10 && hand[4].cardc == 10 || hand[3].cardc == 10 && hand[4].cardc == 10)
		{
			value = 11;
		}
		if (hand[0].cardc == 11 && hand[1].cardc == 11 || hand[0].cardc == 11 && hand[2].cardc == 11 || hand[0].cardc == 11 && hand[3].cardc == 11 || hand[0].cardc == 11 && hand[4].cardc == 11
			|| hand[1].cardc == 11 && hand[2].cardc == 11 || hand[1].cardc == 11 && hand[3].cardc == 11 || hand[1].cardc == 11 && hand[4].cardc == 11 || hand[2].cardc == 11 && hand[3].cardc == 11
			|| hand[2].cardc == 11 && hand[4].cardc == 11 || hand[3].cardc == 11 && hand[4].cardc == 11)
		{
			value = 12;
		}
		if (hand[0].cardc == 12 && hand[1].cardc == 12 || hand[0].cardc == 12 && hand[2].cardc == 12 || hand[0].cardc == 12 && hand[3].cardc == 12 || hand[0].cardc == 12 && hand[4].cardc == 12
			|| hand[1].cardc == 12 && hand[2].cardc == 12 || hand[1].cardc == 12 && hand[3].cardc == 12 || hand[1].cardc == 12 && hand[4].cardc == 12 || hand[2].cardc == 12 && hand[3].cardc == 12
			|| hand[2].cardc == 12 && hand[4].cardc == 12 || hand[3].cardc == 12 && hand[4].cardc == 12)
		{
			value = 13;
		}

	}
	else
	{
		value = 0;
	}
	return value; 
}

/*
*Function name: int is_pair_pair(Card hand[])
*Date: 4/5/17
*Description: determines if there is two pairs in the hand and assigns a point value based on the resulting pair combo
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/

int is_pair_pair(Card hand[])
{
	int value = 0;
	if (hand[0].cardc == hand[1].cardc && hand[2].cardc == hand[4].cardc || hand[0].cardc == hand[1].cardc &&  hand[2].cardc == hand[3].cardc	//Checks if two pairs exist
		|| hand[0].cardc == hand[1].cardc &&  hand[3].cardc == hand[4].cardc || hand[0].cardc == hand[2].cardc &&  hand[1].cardc == hand[3].cardc
		|| hand[0].cardc == hand[2].cardc &&  hand[1].cardc == hand[4].cardc || hand[0].cardc == hand[2].cardc &&  hand[4].cardc == hand[3].cardc ||
		hand[0].cardc == hand[3].cardc &&  hand[2].cardc == hand[4].cardc || hand[0].cardc == hand[3].cardc &&  hand[1].cardc == hand[2].cardc ||
		hand[0].cardc == hand[3].cardc &&  hand[1].cardc == hand[4].cardc || hand[0].cardc == hand[4].cardc &&  hand[1].cardc == hand[3].cardc
		|| hand[0].cardc == hand[4].cardc &&  hand[1].cardc == hand[2].cardc || hand[0].cardc == hand[4].cardc &&  hand[2].cardc == hand[3].cardc || 
		hand[1].cardc == hand[3].cardc && hand[2].cardc == hand[4].cardc || hand[1].cardc == hand[4].cardc && hand[2].cardc == hand[3].cardc)
	{
		if (hand[0].cardc == 0 && hand[1].cardc == 0 || hand[0].cardc == 0 && hand[2].cardc == 0 || hand[0].cardc == 0 && hand[3].cardc == 0 || hand[0].cardc == 0 && hand[4].cardc == 0
			|| hand[1].cardc == 0 && hand[2].cardc == 0 || hand[1].cardc == 0 && hand[3].cardc == 0 || hand[1].cardc == 0 && hand[4].cardc == 0 || hand[2].cardc == 0 && hand[3].cardc == 0
			|| hand[2].cardc == 0 && hand[4].cardc == 0 || hand[3].cardc == 0 && hand[4].cardc == 0)
		{
			value = 15; //Gives a value based on the rank of the card pair
		}
		if (hand[0].cardc == 1 && hand[1].cardc == 1 || hand[0].cardc == 1 && hand[2].cardc == 1 || hand[0].cardc == 1 && hand[3].cardc == 1 || hand[0].cardc == 1 && hand[4].cardc == 1
			|| hand[1].cardc == 1 && hand[2].cardc == 1 || hand[1].cardc == 1 && hand[3].cardc == 1 || hand[1].cardc == 1 && hand[4].cardc == 1 || hand[2].cardc == 1 && hand[3].cardc == 1
			|| hand[2].cardc == 1 && hand[4].cardc == 1 || hand[3].cardc == 1 && hand[4].cardc == 1)
		{
			value = 16;
		}
		if (hand[0].cardc == 2 && hand[1].cardc == 2 || hand[0].cardc == 2 && hand[2].cardc == 2 || hand[0].cardc == 2 && hand[3].cardc == 2 || hand[0].cardc == 2 && hand[4].cardc == 2
			|| hand[1].cardc == 2 && hand[2].cardc == 2 || hand[1].cardc == 2 && hand[3].cardc == 2 || hand[1].cardc == 2 && hand[4].cardc == 2 || hand[2].cardc == 2 && hand[3].cardc == 2
			|| hand[2].cardc == 2 && hand[4].cardc == 2 || hand[3].cardc == 2 && hand[4].cardc == 2)
		{
			value = 17;
		}
		if (hand[0].cardc == 3 && hand[1].cardc == 3 || hand[0].cardc == 3 && hand[2].cardc == 3 || hand[0].cardc == 3 && hand[3].cardc == 3 || hand[0].cardc == 3 && hand[4].cardc == 3
			|| hand[1].cardc == 3 && hand[2].cardc == 3 || hand[1].cardc == 3 && hand[3].cardc == 3 || hand[1].cardc == 3 && hand[4].cardc == 3 || hand[2].cardc == 3 && hand[3].cardc == 3
			|| hand[2].cardc == 3 && hand[4].cardc == 3 || hand[3].cardc == 3 && hand[4].cardc == 3)
		{
			value = 18;
		}
		if (hand[0].cardc == 4 && hand[1].cardc == 4 || hand[0].cardc == 4 && hand[2].cardc == 4 || hand[0].cardc == 4 && hand[3].cardc == 4 || hand[0].cardc == 4 && hand[4].cardc == 4
			|| hand[1].cardc == 4 && hand[2].cardc == 4 || hand[1].cardc == 4 && hand[3].cardc == 4 || hand[1].cardc == 4 && hand[4].cardc == 4 || hand[2].cardc == 4 && hand[3].cardc == 4
			|| hand[2].cardc == 4 && hand[4].cardc == 4 || hand[3].cardc == 4 && hand[4].cardc == 4)
		{
			value = 19;
		}
		if (hand[0].cardc == 5 && hand[1].cardc == 5 || hand[0].cardc == 5 && hand[2].cardc == 5 || hand[0].cardc == 5 && hand[3].cardc == 5 || hand[0].cardc == 5 && hand[4].cardc == 5
			|| hand[1].cardc == 5 && hand[2].cardc == 5 || hand[1].cardc == 5 && hand[3].cardc == 5 || hand[1].cardc == 5 && hand[4].cardc == 5 || hand[2].cardc == 5 && hand[3].cardc == 5
			|| hand[2].cardc == 5 && hand[4].cardc == 5 || hand[3].cardc == 5 && hand[4].cardc == 5)
		{
			value = 20;
		}
		if (hand[0].cardc == 6 && hand[1].cardc == 6 || hand[0].cardc == 6 && hand[2].cardc == 6 || hand[0].cardc == 6 && hand[3].cardc == 6 || hand[0].cardc == 6 && hand[4].cardc == 6
			|| hand[1].cardc == 6 && hand[2].cardc == 6 || hand[1].cardc == 6 && hand[3].cardc == 6 || hand[1].cardc == 6 && hand[4].cardc == 6 || hand[2].cardc == 6 && hand[3].cardc == 6
			|| hand[2].cardc == 6 && hand[4].cardc == 6 || hand[3].cardc == 6 && hand[4].cardc == 6)
		{
			value = 21;
		}
		if (hand[0].cardc == 7 && hand[1].cardc == 7 || hand[0].cardc == 7 && hand[2].cardc == 7 || hand[0].cardc == 7 && hand[3].cardc == 7 || hand[0].cardc == 7 && hand[4].cardc == 7
			|| hand[1].cardc == 7 && hand[2].cardc == 7 || hand[1].cardc == 7 && hand[3].cardc == 7 || hand[1].cardc == 7 && hand[4].cardc == 7 || hand[2].cardc == 7 && hand[3].cardc == 7
			|| hand[2].cardc == 7 && hand[4].cardc == 7 || hand[3].cardc == 7 && hand[4].cardc == 7)
		{
			value = 22;
		}
		if (hand[0].cardc == 8 && hand[1].cardc == 8 || hand[0].cardc == 8 && hand[2].cardc == 8 || hand[0].cardc == 8 && hand[3].cardc == 8 || hand[0].cardc == 8 && hand[4].cardc == 8
			|| hand[1].cardc == 8 && hand[2].cardc == 8 || hand[1].cardc == 8 && hand[3].cardc == 8 || hand[1].cardc == 8 && hand[4].cardc == 8 || hand[2].cardc == 8 && hand[3].cardc == 8
			|| hand[2].cardc == 8 && hand[4].cardc == 8 || hand[3].cardc == 8 && hand[4].cardc == 8)
		{
			value = 23;
		}
		if (hand[0].cardc == 9 && hand[1].cardc == 9 || hand[0].cardc == 9 && hand[2].cardc == 9 || hand[0].cardc == 9 && hand[3].cardc == 9 || hand[0].cardc == 9 && hand[4].cardc == 9
			|| hand[1].cardc == 9 && hand[2].cardc == 9 || hand[1].cardc == 9 && hand[3].cardc == 9 || hand[1].cardc == 9 && hand[4].cardc == 9 || hand[2].cardc == 9 && hand[3].cardc == 9
			|| hand[2].cardc == 9 && hand[4].cardc == 9 || hand[3].cardc == 9 && hand[4].cardc == 9)
		{
			value = 24;
		}
		if (hand[0].cardc == 10 && hand[1].cardc == 10 || hand[0].cardc == 10 && hand[2].cardc == 10 || hand[0].cardc == 10 && hand[3].cardc == 10 || hand[0].cardc == 10 && hand[4].cardc == 10
			|| hand[1].cardc == 10 && hand[2].cardc == 10 || hand[1].cardc == 10 && hand[3].cardc == 10 || hand[1].cardc == 10 && hand[4].cardc == 10 || hand[2].cardc == 10 && hand[3].cardc == 10
			|| hand[2].cardc == 10 && hand[4].cardc == 10 || hand[3].cardc == 10 && hand[4].cardc == 10)
		{
			value = 25;
		}
		if (hand[0].cardc == 11 && hand[1].cardc == 11 || hand[0].cardc == 11 && hand[2].cardc == 11 || hand[0].cardc == 11 && hand[3].cardc == 11 || hand[0].cardc == 11 && hand[4].cardc == 11
			|| hand[1].cardc == 11 && hand[2].cardc == 11 || hand[1].cardc == 11 && hand[3].cardc == 11 || hand[1].cardc == 11 && hand[4].cardc == 11 || hand[2].cardc == 11 && hand[3].cardc == 11
			|| hand[2].cardc == 11 && hand[4].cardc == 11 || hand[3].cardc == 11 && hand[4].cardc == 11)
		{
			value = 26;
		}
		if (hand[0].cardc == 12 && hand[1].cardc == 12 || hand[0].cardc == 12 && hand[2].cardc == 12 || hand[0].cardc == 12 && hand[3].cardc == 12 || hand[0].cardc == 12 && hand[4].cardc == 12
			|| hand[1].cardc == 12 && hand[2].cardc == 12 || hand[1].cardc == 12 && hand[3].cardc == 12 || hand[1].cardc == 12 && hand[4].cardc == 12 || hand[2].cardc == 12 && hand[3].cardc == 12
			|| hand[2].cardc == 12 && hand[4].cardc == 12 || hand[3].cardc == 12 && hand[4].cardc == 12)
		{
			value = 27;
		}
	}
	else
	{
		value = 0;
	}
	return value; 
}

/*
*Function name: int is_triple(Card hand[])
*Date: 4/6/17
*Description: determines if there is a triple in the hand and assigns a point value based on the resulting cards within the triple
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/
int is_triple(Card hand[])
{
	int value = 0;		//Combinations to check for triples
	if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[2].cardc && hand[3].cardc != hand[0].cardc && hand[4].cardc != hand[0].cardc ||
		hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[0].cardc != hand[1].cardc && hand[4].cardc != hand[1].cardc ||
		hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc && hand[0].cardc != hand[2].cardc && hand[1].cardc != hand[2].cardc ||
		hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[4].cardc && hand[3].cardc != hand[1].cardc && hand[2].cardc != hand[1].cardc ||
		hand[1].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc && hand[2].cardc != hand[1].cardc && hand[0].cardc != hand[1].cardc ||
		hand[0].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc && hand[3].cardc != hand[0].cardc && hand[1].cardc != hand[0].cardc ||
		hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[0].cardc != hand[2].cardc && hand[1].cardc != hand[4].cardc ||
		hand[0].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[0].cardc != hand[1].cardc && hand[0].cardc != hand[4].cardc ||
		hand[0].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc && hand[0].cardc != hand[2].cardc && hand[0].cardc != hand[1].cardc ||
		hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc && hand[2].cardc != hand[0].cardc && hand[2].cardc != hand[3].cardc ||
		hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[3].cardc && hand[0].cardc != hand[2].cardc && hand[0].cardc != hand[4].cardc)

	{
		if (hand[0].cardc == 0 && hand[1].cardc == 0 && hand[2].cardc == 0 ||
			hand[1].cardc == 0 && hand[2].cardc == 0 && hand[3].cardc == 0 ||
			hand[2].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0 ||
			hand[0].cardc == 0 && hand[1].cardc == 0 && hand[4].cardc == 0 ||
			hand[1].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0 ||
			hand[0].cardc == 0 && hand[2].cardc == 0 && hand[4].cardc == 0 ||
			hand[0].cardc == 0 && hand[2].cardc == 0 && hand[3].cardc == 0 ||
			hand[0].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0 ||
			hand[1].cardc == 0 && hand[2].cardc == 0 && hand[4].cardc == 0 ||
			hand[0].cardc == 0 && hand[1].cardc == 0 && hand[3].cardc == 0)
		{
			value = 31;		//Assigns value for rank of triples
		}
		if (hand[0].cardc == 1 && hand[1].cardc == 1 && hand[2].cardc == 1 ||
			hand[1].cardc == 1 && hand[2].cardc == 1 && hand[3].cardc == 1 ||
			hand[2].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1 ||
			hand[0].cardc == 1 && hand[1].cardc == 1 && hand[4].cardc == 1 ||
			hand[1].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1 ||
			hand[0].cardc == 1 && hand[2].cardc == 1 && hand[4].cardc == 1 ||
			hand[0].cardc == 1 && hand[2].cardc == 1 && hand[3].cardc == 1 ||
			hand[0].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1 ||
			hand[1].cardc == 1 && hand[2].cardc == 1 && hand[4].cardc == 1 || 
			hand[0].cardc == 1 && hand[1].cardc == 1 && hand[3].cardc == 1)
		{
			value = 32;
		}
		if (hand[0].cardc == 2 && hand[1].cardc == 2 && hand[2].cardc == 2 ||
			hand[1].cardc == 2 && hand[2].cardc == 2 && hand[3].cardc == 2 ||
			hand[2].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[1].cardc == 2 && hand[4].cardc == 2 ||
			hand[1].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[2].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[2].cardc == 2 && hand[3].cardc == 2 ||
			hand[0].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2 ||
			hand[1].cardc == 2 && hand[2].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[1].cardc == 2 && hand[3].cardc == 2)
		{
			value = 33;
		}
		if (hand[0].cardc == 3 && hand[1].cardc == 3 && hand[2].cardc == 3 ||
			hand[1].cardc == 3 && hand[2].cardc == 3 && hand[3].cardc == 3 ||
			hand[2].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[1].cardc == 3 && hand[4].cardc == 3 ||
			hand[1].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[2].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[2].cardc == 3 && hand[3].cardc == 3 ||
			hand[0].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3 ||
			hand[1].cardc == 3 && hand[2].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[1].cardc == 3 && hand[3].cardc == 3)
		{
			value = 34;
		}
		if (hand[0].cardc == 4 && hand[1].cardc == 4 && hand[2].cardc == 4 ||
			hand[1].cardc == 4 && hand[2].cardc == 4 && hand[3].cardc == 4 ||
			hand[2].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[1].cardc == 4 && hand[4].cardc == 4 ||
			hand[1].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[2].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[2].cardc == 4 && hand[3].cardc == 4 ||
			hand[0].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4 ||
			hand[1].cardc == 4 && hand[2].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[1].cardc == 4 && hand[3].cardc == 4)
		{
			value = 35;
		}
		if (hand[0].cardc == 5 && hand[1].cardc == 5 && hand[2].cardc == 5 ||
			hand[1].cardc == 5 && hand[2].cardc == 5 && hand[3].cardc == 5 ||
			hand[2].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[1].cardc == 5 && hand[4].cardc == 5 ||
			hand[1].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[2].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[2].cardc == 5 && hand[3].cardc == 5 ||
			hand[0].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5 ||
			hand[1].cardc == 5 && hand[2].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[1].cardc == 5 && hand[3].cardc == 5)
		{
			value = 36;
		}
		if (hand[0].cardc == 6 && hand[1].cardc == 6 && hand[2].cardc == 6 ||
			hand[1].cardc == 6 && hand[2].cardc == 6 && hand[3].cardc == 6 ||
			hand[2].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[1].cardc == 6 && hand[4].cardc == 6 ||
			hand[1].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[2].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[2].cardc == 6 && hand[3].cardc == 6 ||
			hand[0].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6 ||
			hand[1].cardc == 6 && hand[2].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[1].cardc == 6 && hand[3].cardc == 6)
		{
			value = 37;
		}
		if (hand[0].cardc == 7 && hand[1].cardc == 7 && hand[2].cardc == 7 ||
			hand[1].cardc == 7 && hand[2].cardc == 7 && hand[3].cardc == 7 ||
			hand[2].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[1].cardc == 7 && hand[4].cardc == 7 ||
			hand[1].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[2].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[2].cardc == 7 && hand[3].cardc == 7 ||
			hand[0].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7 ||
			hand[1].cardc == 7 && hand[2].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[1].cardc == 7 && hand[3].cardc == 7)
		{
			value = 38;
		}
		if (hand[0].cardc == 8 && hand[1].cardc == 8 && hand[2].cardc == 8 ||
			hand[1].cardc == 8 && hand[2].cardc == 8 && hand[3].cardc == 8 ||
			hand[2].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[1].cardc == 8 && hand[4].cardc == 8 ||
			hand[1].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[2].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[2].cardc == 8 && hand[3].cardc == 8 ||
			hand[0].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8 ||
			hand[1].cardc == 8 && hand[2].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[1].cardc == 8 && hand[3].cardc == 8)
		{
			value = 39;
		}
		if (hand[0].cardc == 9 && hand[1].cardc == 9 && hand[2].cardc == 9 ||
			hand[1].cardc == 9 && hand[2].cardc == 9 && hand[3].cardc == 9 ||
			hand[2].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[1].cardc == 9 && hand[4].cardc == 9 ||
			hand[1].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[2].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[2].cardc == 9 && hand[3].cardc == 9 ||
			hand[0].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9 ||
			hand[1].cardc == 9 && hand[2].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[1].cardc == 9 && hand[3].cardc == 9)
		{
			value = 40;
		}
		if (hand[0].cardc == 10 && hand[1].cardc == 10 && hand[2].cardc == 10 ||
			hand[1].cardc == 10 && hand[2].cardc == 10 && hand[3].cardc == 10 ||
			hand[2].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[1].cardc == 10 && hand[4].cardc == 10 ||
			hand[1].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[2].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[2].cardc == 10 && hand[3].cardc == 10 ||
			hand[0].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10 ||
			hand[1].cardc == 10 && hand[2].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[1].cardc == 10 && hand[3].cardc == 10)
		{
			value = 41;
		}
		if (hand[0].cardc == 11 && hand[1].cardc == 11 && hand[2].cardc == 11 ||
			hand[1].cardc == 11 && hand[2].cardc == 11 && hand[3].cardc == 11 ||
			hand[2].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[1].cardc == 11 && hand[4].cardc == 11 ||
			hand[1].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[2].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[2].cardc == 11 && hand[3].cardc == 11 ||
			hand[0].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11 ||
			hand[1].cardc == 11 && hand[2].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[1].cardc == 11 && hand[3].cardc == 11)
		{
			value = 42;
		}
		if (hand[0].cardc == 12 && hand[1].cardc == 12 && hand[2].cardc == 12 ||
			hand[1].cardc == 12 && hand[2].cardc == 12 && hand[3].cardc == 12 ||
			hand[2].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[1].cardc == 12 && hand[4].cardc == 12 ||
			hand[1].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[2].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[2].cardc == 12 && hand[3].cardc == 12 ||
			hand[0].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12 ||
			hand[1].cardc == 12 && hand[2].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[1].cardc == 12 && hand[3].cardc == 12)
		{
			value = 43;
		}
	}
	else
	{
		value = 0;
	}
	return value;
}




/*
*Function name: int is_four_of_kind(Card hand[])
*Date: 4/6/17
*Description: determines if there is a four of a kind in the hand and assigns a point value based on the resulting cards within the four
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/
int is_four_of_kind(Card hand[])
{
	int value = 0;		//Checks if four of a kind exists
	if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc || hand[1].cardc == hand[2].cardc &&
		hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc || hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc ||
		hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc ||
		hand[0].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc || hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc)
	{
		
		
		if (hand[0].cardc == 0 && hand[1].cardc == 0 && hand[2].cardc == 0 && hand[3].cardc == 0 || hand[1].cardc == 0 && hand[2].cardc == 0
			&& hand[3].cardc == 0 && hand[4].cardc == 0 || hand[0].cardc == 0 && hand[1].cardc == 0 && hand[2].cardc == 0 && hand[4].cardc == 0||
			hand[0].cardc == 0 && hand[1].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0 ||
			hand[0].cardc == 0 && hand[2].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0 || 
			hand[1].cardc == 0 && hand[2].cardc == 0 && hand[3].cardc == 0 && hand[4].cardc == 0)
		{
			value = 75;			//Gives hagher rankng values based on the rank of the card
		}
		if (hand[0].cardc == 1 && hand[1].cardc == 1 && hand[2].cardc == 1 && hand[3].cardc == 1 || hand[1].cardc == 1 && hand[2].cardc == 1
			&& hand[3].cardc == 1 && hand[4].cardc == 1 || hand[0].cardc == 1 && hand[1].cardc == 1 && hand[2].cardc == 1 && hand[4].cardc == 1 ||
			hand[0].cardc == 1 && hand[1].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1 ||
			hand[0].cardc == 1 && hand[2].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1 ||
			hand[1].cardc == 1 && hand[2].cardc == 1 && hand[3].cardc == 1 && hand[4].cardc == 1)
		{
			value = 76;
		}
		if (hand[0].cardc == 2 && hand[1].cardc == 2 && hand[2].cardc == 2 && hand[3].cardc == 2 || hand[1].cardc == 2 && hand[2].cardc == 2
			&& hand[3].cardc == 2 && hand[4].cardc == 2 || hand[0].cardc == 2 && hand[1].cardc == 2 && hand[2].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[1].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2 ||
			hand[0].cardc == 2 && hand[2].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2 ||
			hand[1].cardc == 2 && hand[2].cardc == 2 && hand[3].cardc == 2 && hand[4].cardc == 2)
		{
			value = 77;
		}
		if (hand[0].cardc == 3 && hand[1].cardc == 3 && hand[2].cardc == 3 && hand[3].cardc == 3 || hand[1].cardc == 3 && hand[2].cardc == 3
			&& hand[3].cardc == 3 && hand[4].cardc == 3 || hand[0].cardc == 3 && hand[1].cardc == 3 && hand[2].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[1].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3 ||
			hand[0].cardc == 3 && hand[2].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3 ||
			hand[1].cardc == 3 && hand[2].cardc == 3 && hand[3].cardc == 3 && hand[4].cardc == 3)
		{
			value = 78;
		}
		if (hand[0].cardc == 4 && hand[1].cardc == 4 && hand[2].cardc == 4 && hand[3].cardc == 4 || hand[1].cardc == 4 && hand[2].cardc == 4
			&& hand[3].cardc == 4 && hand[4].cardc == 4 || hand[0].cardc == 4 && hand[1].cardc == 4 && hand[2].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[1].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4 ||
			hand[0].cardc == 4 && hand[2].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4 ||
			hand[1].cardc == 4 && hand[2].cardc == 4 && hand[3].cardc == 4 && hand[4].cardc == 4)
		{
			value = 79;
		}
		if (hand[0].cardc == 5 && hand[1].cardc == 5 && hand[2].cardc == 5 && hand[3].cardc == 5 || hand[1].cardc == 5 && hand[2].cardc == 5
			&& hand[3].cardc == 5 && hand[4].cardc == 5 || hand[0].cardc == 5 && hand[1].cardc == 5 && hand[2].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[1].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5 ||
			hand[0].cardc == 5 && hand[2].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5 ||
			hand[1].cardc == 5 && hand[2].cardc == 5 && hand[3].cardc == 5 && hand[4].cardc == 5)
		{
			value = 80;
		}
		if (hand[0].cardc == 6 && hand[1].cardc == 6 && hand[2].cardc == 6 && hand[3].cardc == 6 || hand[1].cardc == 6 && hand[2].cardc == 6
			&& hand[3].cardc == 6 && hand[4].cardc == 6 || hand[0].cardc == 6 && hand[1].cardc == 6 && hand[2].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[1].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6 ||
			hand[0].cardc == 6 && hand[2].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6 ||
			hand[1].cardc == 6 && hand[2].cardc == 6 && hand[3].cardc == 6 && hand[4].cardc == 6)
		{
			value = 81;
		}
		if (hand[0].cardc == 7 && hand[1].cardc == 7 && hand[2].cardc == 7 && hand[3].cardc == 7 || hand[1].cardc == 7 && hand[2].cardc == 7
			&& hand[3].cardc == 7 && hand[4].cardc == 7 || hand[0].cardc == 7 && hand[1].cardc == 7 && hand[2].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[1].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7 ||
			hand[0].cardc == 7 && hand[2].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7 ||
			hand[1].cardc == 7 && hand[2].cardc == 7 && hand[3].cardc == 7 && hand[4].cardc == 7)
		{
			value = 82;
		}
		if (hand[0].cardc == 8 && hand[1].cardc == 8 && hand[2].cardc == 8 && hand[3].cardc == 8 || hand[1].cardc == 8 && hand[2].cardc == 8
			&& hand[3].cardc == 8 && hand[4].cardc == 8 || hand[0].cardc == 8 && hand[1].cardc == 8 && hand[2].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[1].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8 ||
			hand[0].cardc == 8 && hand[2].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8 ||
			hand[1].cardc == 8 && hand[2].cardc == 8 && hand[3].cardc == 8 && hand[4].cardc == 8)
		{
			value = 83;
		}
		if (hand[0].cardc == 9 && hand[1].cardc == 9 && hand[2].cardc == 9 && hand[3].cardc == 9 || hand[1].cardc == 9 && hand[2].cardc == 9
			&& hand[3].cardc == 9 && hand[4].cardc == 9 || hand[0].cardc == 9 && hand[1].cardc == 9 && hand[2].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[1].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9 ||
			hand[0].cardc == 9 && hand[2].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9 ||
			hand[1].cardc == 9 && hand[2].cardc == 9 && hand[3].cardc == 9 && hand[4].cardc == 9)
		{
			value = 84;
		}
		if (hand[0].cardc == 10 && hand[1].cardc == 10 && hand[2].cardc == 10 && hand[3].cardc == 10 || hand[1].cardc == 10 && hand[2].cardc == 10
			&& hand[3].cardc == 10 && hand[4].cardc == 10 || hand[0].cardc == 10 && hand[1].cardc == 10 && hand[2].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[1].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10 ||
			hand[0].cardc == 10 && hand[2].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10 ||
			hand[1].cardc == 10 && hand[2].cardc == 10 && hand[3].cardc == 10 && hand[4].cardc == 10)
		{
			value = 85;
		}
		if (hand[0].cardc == 11 && hand[1].cardc == 11 && hand[2].cardc == 11 && hand[3].cardc == 11 || hand[1].cardc == 11 && hand[2].cardc ==11
			&& hand[3].cardc == 11 && hand[4].cardc == 11 || hand[0].cardc == 11 && hand[1].cardc == 11 && hand[2].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[1].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11 ||
			hand[0].cardc == 11 && hand[2].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11 ||
			hand[1].cardc == 11 && hand[2].cardc == 11 && hand[3].cardc == 11 && hand[4].cardc == 11)
		{
			value = 86;
		}
		if (hand[0].cardc == 12 && hand[1].cardc == 12 && hand[2].cardc == 12 && hand[3].cardc == 12 || hand[1].cardc == 12 && hand[2].cardc == 12
			&& hand[3].cardc == 12 && hand[4].cardc == 12 || hand[0].cardc == 12 && hand[1].cardc == 12 && hand[2].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[1].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12 ||
			hand[0].cardc == 12 && hand[2].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12 ||
			hand[1].cardc == 12 && hand[2].cardc == 12 && hand[3].cardc == 12 && hand[4].cardc == 12)
		{
			value = 87;
		}
	}
	else
	{
		value = 0; 
	}
	return value;
}

/*
*Function name: int is_flush(Card hand[])
*Date: 4/12/17
*Description: Determines if the card hand has a flush
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/

int is_flush(Card hand[])
{
	int value = 0;		//Checks if there is a flush in the hand
	if (hand[0].cardr == hand[1].cardr && hand[1].cardr == hand[2].cardr && hand[2].cardr == hand[3].cardr && hand[3].cardr == hand[4].cardr)
	{
		value = 70; //gives flush value
	}
	else
	{
		value = 0;
	}
	return value;
}



/*
*Function name: int is_triple(Card hand[])
*Date: 4/6/17
*Description: determines if there is a triple in the hand and assigns a point value based on the resulting cards within the triple
*Input parameters: hand[]
*Returns: The point value
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/
int is_straight(Card hand[])
{
	int value = 0;	//below is all possible outcomes for a straight
	if (((hand[0].cardc == 0|| hand[1].cardc == 0 || hand[2].cardc == 0 || hand[3].cardc == 0 || hand[4].cardc == 0)  &&
		(hand[0].cardc == 1 || hand[1].cardc == 1 || hand[2].cardc == 1 || hand[3].cardc == 1 || hand[4].cardc == 1) &&
		(hand[0].cardc == 2 || hand[1].cardc == 2 || hand[2].cardc == 2 || hand[3].cardc == 2 || hand[4].cardc == 2) &&
		(hand[0].cardc == 3 || hand[1].cardc == 3 || hand[2].cardc == 3 || hand[3].cardc == 3 || hand[4].cardc == 3) &&
		(hand[0].cardc == 4 || hand[1].cardc == 4 || hand[2].cardc == 4 || hand[3].cardc == 4 || hand[4].cardc == 4)) || 
		((hand[0].cardc == 1 || hand[1].cardc == 1 || hand[2].cardc == 1 || hand[3].cardc == 1 || hand[4].cardc == 1) &&
		(hand[0].cardc == 2 || hand[1].cardc == 2 || hand[2].cardc == 2 || hand[3].cardc == 2 || hand[4].cardc == 2) &&
		(hand[0].cardc == 3 || hand[1].cardc == 3 || hand[2].cardc == 3 || hand[3].cardc == 3 || hand[4].cardc == 3) &&
		(hand[0].cardc == 4 || hand[1].cardc == 4 || hand[2].cardc == 4 || hand[3].cardc == 4 || hand[4].cardc == 4) && 
		(hand[0].cardc == 5 || hand[1].cardc == 5 || hand[2].cardc == 5 || hand[3].cardc == 5 || hand[4].cardc == 5)) || 
		((hand[0].cardc == 2 || hand[1].cardc == 2 || hand[2].cardc == 2 || hand[3].cardc == 2 || hand[4].cardc == 2) &&
		(hand[0].cardc == 3 || hand[1].cardc == 3 || hand[2].cardc == 3 || hand[3].cardc == 3 || hand[4].cardc == 3) &&
		(hand[0].cardc == 4 || hand[1].cardc == 4 || hand[2].cardc == 4 || hand[3].cardc == 4 || hand[4].cardc == 4) &&
		(hand[0].cardc == 5 || hand[1].cardc == 5 || hand[2].cardc == 5 || hand[3].cardc == 5 || hand[4].cardc == 5) && 
		(hand[0].cardc == 6 || hand[1].cardc == 6 || hand[2].cardc == 6 || hand[3].cardc == 6 || hand[4].cardc == 6)) ||
		((hand[0].cardc == 3 || hand[1].cardc == 3 || hand[2].cardc == 3 || hand[3].cardc == 3 || hand[4].cardc == 3) &&
		(hand[0].cardc == 4 || hand[1].cardc == 4 || hand[2].cardc == 4 || hand[3].cardc == 4 || hand[4].cardc == 4) &&
		(hand[0].cardc == 5 || hand[1].cardc == 5 || hand[2].cardc == 5 || hand[3].cardc == 5 || hand[4].cardc == 5) &&
		(hand[0].cardc == 6 || hand[1].cardc == 6 || hand[2].cardc == 6 || hand[3].cardc == 6 || hand[4].cardc == 6) &&
		(hand[0].cardc == 7 || hand[1].cardc == 7 || hand[2].cardc == 7 || hand[3].cardc == 7 || hand[4].cardc == 7)) ||
		((hand[0].cardc == 4 || hand[1].cardc == 4 || hand[2].cardc == 4 || hand[3].cardc == 4 || hand[4].cardc == 4) &&
		(hand[0].cardc == 5 || hand[1].cardc == 5 || hand[2].cardc == 5 || hand[3].cardc == 5 || hand[4].cardc == 5) &&
		(hand[0].cardc == 6 || hand[1].cardc == 6 || hand[2].cardc == 6 || hand[3].cardc == 6 || hand[4].cardc == 6) &&
		(hand[0].cardc == 7 || hand[1].cardc == 7 || hand[2].cardc == 7 || hand[3].cardc == 7 || hand[4].cardc == 7) && 
		(hand[0].cardc == 8 || hand[1].cardc == 8 || hand[2].cardc == 8 || hand[3].cardc == 8 || hand[4].cardc == 8)) ||
		((hand[0].cardc == 5 || hand[1].cardc == 5 || hand[2].cardc == 5 || hand[3].cardc == 5 || hand[4].cardc == 5) &&
		(hand[0].cardc == 6 || hand[1].cardc == 6 || hand[2].cardc == 6 || hand[3].cardc == 6 || hand[4].cardc == 6) &&
		(hand[0].cardc == 7 || hand[1].cardc == 7 || hand[2].cardc == 7 || hand[3].cardc == 7 || hand[4].cardc == 7) &&
		(hand[0].cardc == 8 || hand[1].cardc == 8 || hand[2].cardc == 8 || hand[3].cardc == 8 || hand[4].cardc == 8) &&
		(hand[0].cardc == 9 || hand[1].cardc == 9 || hand[2].cardc == 9 || hand[3].cardc == 9 || hand[4].cardc == 9)) || 
		((hand[0].cardc == 6 || hand[1].cardc == 6 || hand[2].cardc == 6 || hand[3].cardc == 6 || hand[4].cardc == 6) &&
		(hand[0].cardc == 7 || hand[1].cardc == 7 || hand[2].cardc == 7 || hand[3].cardc == 7 || hand[4].cardc == 7) &&
		(hand[0].cardc == 8 || hand[1].cardc == 8 || hand[2].cardc == 8 || hand[3].cardc == 8 || hand[4].cardc == 8) &&
		(hand[0].cardc == 9 || hand[1].cardc == 9 || hand[2].cardc == 9 || hand[3].cardc == 9 || hand[4].cardc == 9) && 
		(hand[0].cardc == 10 || hand[1].cardc == 10 || hand[2].cardc == 10 || hand[3].cardc == 10 || hand[4].cardc == 10)) ||
		((hand[0].cardc == 7 || hand[1].cardc == 7 || hand[2].cardc == 7 || hand[3].cardc == 7 || hand[4].cardc == 7) &&
		(hand[0].cardc == 8 || hand[1].cardc == 8 || hand[2].cardc == 8 || hand[3].cardc == 8 || hand[4].cardc == 8) &&
		(hand[0].cardc == 9 || hand[1].cardc == 9 || hand[2].cardc == 9 || hand[3].cardc == 9 || hand[4].cardc == 9) &&
		(hand[0].cardc == 10 || hand[1].cardc == 10 || hand[2].cardc == 10 || hand[3].cardc == 10 || hand[4].cardc == 10) &&
		(hand[0].cardc == 11 || hand[1].cardc == 11 || hand[2].cardc == 11 || hand[3].cardc == 11 || hand[4].cardc == 11)) || 
		((hand[0].cardc == 8 || hand[1].cardc == 8 || hand[2].cardc == 8 || hand[3].cardc == 8 || hand[4].cardc == 8) &&
		(hand[0].cardc == 9 || hand[1].cardc == 9 || hand[2].cardc == 9 || hand[3].cardc == 9 || hand[4].cardc == 9) &&
		(hand[0].cardc == 10 || hand[1].cardc == 10 || hand[2].cardc == 10 || hand[3].cardc == 10 || hand[4].cardc == 10) &&
		(hand[0].cardc == 11 || hand[1].cardc == 11 || hand[2].cardc == 11 || hand[3].cardc == 11 || hand[4].cardc == 11) &&
		(hand[0].cardc == 12 || hand[1].cardc == 12 || hand[2].cardc == 12 || hand[3].cardc == 12 || hand[4].cardc == 12)))
	{
		value = 60;		//Assigns point value for a straight
	}
	else
	{
		value = 0;
	}
	return value;

}

/*
*Function name:calculate_better_hand(Card handp[], Card handd[], int playerpoints, int  dealerpoints)
*Date: 4/12/17
*Description: determines which hand is the better hand for determining the winner of the game
*Input parameters: Card handp[], Card handd[], int playerpoints, int  dealerpoints
*Returns: A value (1 if player 1 has a higher point total, 0 for the dealer, and 100 if tie)
*Preconditions: hand must be defined with the five card values
*Post conditions: None
*/
int calculate_better_hand(Card handp[], Card handd[], int playerpoints, int  dealerpoints)
{
	int value = -1;
	if (playerpoints > dealerpoints) // if player 1's points are higher they win 
	{
		value = 1; 
		printf("\n*PLAYER ONE WINS!*\n");
	}
	else if (playerpoints < dealerpoints) // If lower, dealer wins
	{
		value = 0;
		printf("\n*DEALER WINS*\n");
	}
	else
	{		//if there is a tie highest number determines winner
		if ((handp[0].cardc == 12 || handp[1].cardc == 12 || handp[2].cardc == 12 || handp[3].cardc == 12 || handp[4].cardc == 12) &&
			(handd[0].cardc != 12 || handd[1].cardc != 12 || handd[2].cardc != 12 || handp[3].cardc != 12 || handp[4].cardc != 12))
		{
			printf("\n*PLAYER ONE WINS!*\n");
		}
		else
		{
			printf("\n*DEALER WINS*\n");
		}
	}
	return value; 
}

/*
*Function name: void redraw_cards_p1( Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[])
*Date: 4/12/17
*Description: Allows the player to choose cards to redraw and replaces the old card values 
*Input parameters: Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[]
*Returns: A value (1 if player 1 has a higher point total, 0 for the dealer, and 100 if tie)
*Preconditions: hand must be defined with the five card values, wDeck,  wFace, wSuit must also be defined
*Post conditions: None
*/
void redraw_cards_p1( Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[])
{
	int redraw_or_quit = -1, card = 0;
	if (redraw_or_quit == -1)
	{
		printf("Enter 1 to start picking cards to redraw: ");
		scanf("%d", &redraw_or_quit);
		while (redraw_or_quit != 0)
		{
			printf("\nChoose card to redraw(Enter 1 for card 1, 2 for card 2, ect. (Enter values one at a time)*Enter 0 when finished!*: ");
			scanf("%d", &redraw_or_quit);
			if (redraw_or_quit == 1)			//exchanges out card 1 for a new value
			{

				for (card = 15; card <= 16; card++)		//updating fuction to deal only five cardes
				{

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, display card */
							if (wDeck[row][column] == card)
							{

								//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
								hand[0].cardr = row;
								hand[0].cardc = column;

							}
						}
					}
				}
			}
			if (redraw_or_quit == 2)			//exchanges out card 2 for a new value
			{
				for (card = 25; card <= 26; card++)		//updating fuction to deal only five cardes
				{

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, display card */
							if (wDeck[row][column] == card)
							{

								//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
								hand[1].cardr = row;
								hand[1].cardc = column;

							}
						}
					}
				}
			}
			if (redraw_or_quit == 3)		//exchanges out card 3 for a new value
			{
				for (card = 30; card <= 31; card++)		//updating fuction to deal only five cardes
				{

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, display card */
							if (wDeck[row][column] == card)
							{

								//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
								hand[2].cardr = row;
								hand[2].cardc = column;

							}
						}
					}
				}
			}
			if (redraw_or_quit == 4)					//exchanges out card 4 for a new value
			{
				for (card = 33; card <= 34; card++)		//updating fuction to deal only five cardes
				{

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, display card */
							if (wDeck[row][column] == card)
							{

								//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
								hand[3].cardr = row;
								hand[3].cardc = column;

							}
						}
					}
				}
			}
			if (redraw_or_quit == 5)			//exchanges out card 5 for a new value
			{
				for (card = 35; card <= 36; card++)		//updating fuction to deal only five cardes
				{

					/* loop through rows of wDeck */
					for (int row = 0; row <= 3; row++)
					{
						/* loop through columns of wDeck for current row */
						for (int column = 0; column <= 12; column++)
						{
							/* if slot contains current card, display card */
							if (wDeck[row][column] == card)
							{

								//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
								hand[4].cardr = row;
								hand[4].cardc = column;

							}
						}
					}
				}
			}
		}
	}
	
}


/*
*Function name: void dealer_draw_one(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int replacethiscard, int cardnum)
*Date: 4/13/17
*Description: allows a card to be chosen one at a time and replace an old card value
*Input parameters: const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int replacethiscard, int cardnum
*Returns: none
*Preconditions: all parameters must be defined
*Post conditions: None
*/
void dealer_draw_one(const int wDeck[][13], const char *wFace[], const char *wSuit[], Card hand[], int replacethiscard, int cardnum)
{
	int card = 0, counter = 0;
	for (card = cardnum; card <= cardnum + 1; card++)		//updating fuction to deal only five cardes
	{

		/* loop through rows of wDeck */
		for (int row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (int column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{

					//printf("%d. %5s of %-8s%c", counter + 1, wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					hand[replacethiscard].cardr = row;
					hand[replacethiscard].cardc = column;

				}
			}
		}
		counter++;
	}
}


/*
*Function name: void dealer_redraw(Card hand[], int pair, int twopair, int triple, int straight, int flush, int four, const char *wSuit[], const char *wFace[], const int wDeck[][13])
*Date: 4/13/17
*Description: allows the dealer to pull new cards from the deck and replace old cards based on the values in his hand
*Input parameters: Card hand[], int pair, int twopair, int triple, int straight, int flush, int four, const char *wSuit[], const char *wFace[], const int wDeck[][13]
*Returns: none
*Preconditions: all parameters must be defined
*Post conditions: None
*/

void dealer_redraw(Card hand[], int pair, int twopair, int triple, int straight, int flush, int four, const char *wSuit[], const char *wFace[], const int wDeck[][13])
{
	int fillerspace = 0;
	if (flush != 0 || straight != 0)
	{
		fillerspace = 1;
	}
	else if (four != 0)		//If the dealer has a pair of fours then he will draw one card depending on the combo
	{
		if (hand[0].cardc == hand[1].cardr && hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc )
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
		}
		else if (hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
		}
		else if (hand[0].cardc == hand[3].cardc && hand[3].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
		}
		else if (hand[0].cardc == hand[3].cardc && hand[3].cardc == hand[1].cardc && hand[1].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
		}
	}
	else if (triple != 0)		//if the dealer has a triple then he will draw 2 cards depending on the combo
	{
		if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[2].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[0].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[0].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
		}
		else if (hand[0].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
		}
		else if (hand[0].cardc == hand[1].cardc && hand[1].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
		}
		else if (hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[1].cardc == hand[4].cardc && hand[4].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
		}
		else if (hand[1].cardc == hand[2].cardc && hand[2].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
		}
		else if (hand[2].cardc == hand[3].cardc && hand[3].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
		}
	}
	else if (twopair != 0)		//If the dealer has a tw0 pairs no action will be taken because a pair of twos will most likely beat out player 1
	{
		fillerspace = 3;
	}
	else if (pair != 0)			//If the dealer has a pair then 3 new cards will be drawn based on the combo within the pair
	{
		if (hand[0].cardc == hand[1].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 22);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 23);
		}
		else if (hand[0].cardc == hand[2].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 21);
		}
		else if (hand[0].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 22);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 23);
		}
		else if (hand[0].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
		}
		else if (hand[1].cardc == hand[2].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 22);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 26);
		}
		else if (hand[1].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 29);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 20);
		}
		else if (hand[1].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 27);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 22);
		}
		else if (hand[2].cardc == hand[3].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 26);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 4, 23);
		}
		else if (hand[2].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 21);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 31);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 3, 41);
		}
		else if (hand[3].cardc == hand[4].cardc)
		{
			dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 11);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 51);
			dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 25);
		}
	}
	else if (pair == 0)			//If the dealer has no combo then the dealer will cheat and pull two of the same cards to get a pair
	{
		dealer_draw_one(wDeck, wFace, wSuit, hand, 0, 45);
		dealer_draw_one(wDeck, wFace, wSuit, hand, 1, 43);
		dealer_draw_one(wDeck, wFace, wSuit, hand, 2, 45);
		
	}
	
}

/*
*Function name:void print_cards(Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[])
*Date: 4/13/17
*Description: prints the hand
*Input parameters:Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[]
*Returns: none
*Preconditions: all parameters must be defined
*Post conditions: None
*/
void print_cards(Card hand[], const int wDeck[][13], const char *wFace[], const char *wSuit[])
{

	for (int i = 0; i < 5; i++)
	{
		printf("%d. %s of %s%c", i + 1, wFace[hand[i].cardc], wSuit[hand[i].cardr], i % 2 == 0 ? '\n' : '\t');
	}

	//for (int card = 1; card <= 52; card++)
	//{
	//	/* loop through rows of wDeck */
	//	for (int row = 0; row <= 3; row++)
	//	{
	//		/* loop through columns of wDeck for current row */
	//		for (int column = 0; column <= 12; column++)
	//		{
	//			/* if slot contains current card, display card */
	//			if (wDeck[row][column] == card)
	//			{
	//				printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
	//			}
	//		}
	//	}
	//}
}


