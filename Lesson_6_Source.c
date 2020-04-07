/*
Author: Parker Guillen
3/28/18
Description: Lesson 6, function files, functions are included
*/

#include "Lesson_6_header.h"

/*
*Function name: void start_screen()
*Description: prints the game rules for battleship
*Input parameters:  none
*Returns: none
*Preconditions: none
*Post conditions: none
*/

void start_screen()
{
	printf("\t\t\t\t\t***Welcome to Battle***\nGAME RULES:\n");
	printf("Battleship is a two player Navy game. The objective of the game is to sink all ships in your enemy's fleet.\n");
	printf("The Player to sink his/her enemy's fleet first wins. Both players' fleets consist of 5 ships that are hidden from the\n");
	printf("enemy. Each ship may be differentiated by its 'size' (besides the Cruiser and Submarine) or number of cells it expands\non the game board.\n");
	printf("The Carrier has 5 cells, Battleship has 4 cells, Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer \n");
	printf("has 2 cells. Turns will change after one player select a shot at the other players board.\n");
}

/*
*Function name: void fill_board(char board[][MAX_C], int num_rows, int num_cols)
*Description: fills a board with the water symbol
*Input parameters: char board[][MAX_C], int num_rows, int num_cols)
*Returns: none
*Preconditions: board must be defined
*Post conditions: none
*/

void fill_board(char board[][MAX_C], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index] = '~';
		}
	}
}


/*
*Function name: void print_board(char board[][MAX_C], int num_rows, int num_cols)
*Description: prints out the game board to the scrren
*Input parameters: char board[][MAX_C], int num_rows, int num_cols
*Returns: none
*Preconditions: board must be defined
*Post conditions: none
*/

void print_board(char board[][MAX_C], int num_rows, int num_cols, int player)
{
	int row_index = 0, col_index = 0;
	if (player == 1)
	{
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (row_index = 0; row_index < num_rows; ++row_index)
		{
			printf("%d ", row_index);
			for (col_index = 0; col_index < num_cols; ++col_index)
			{
				printf("%c ", board[row_index][col_index]);
			}
			putchar('\n');
		}
	}
	else
	{
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (row_index = 0; row_index < num_rows; ++row_index)
		{
			printf("%d ", row_index);
			for (col_index = 0; col_index < num_cols; ++col_index)
			{
				if (board[row_index][col_index] == 'c' || board[row_index][col_index] == 'b' || board[row_index][col_index] == 'r' ||
					board[row_index][col_index] == 's' || board[row_index][col_index] == 'd')
				{
					printf("~ ");
				}
				else
				{
					printf("%c ", board[row_index][col_index]);
				}

			}
			putchar('\n');
		}
	}
}

/*
*Function name: char manually_place_ships(char board[][MAX_C])
*Description: Allows the user to enter in values for printing the ships
*Input parameters: char board[][MAX_C]
*Returns: the board
*Preconditions: board must be defined
*Post conditions: none
*/

char manually_place_ships(char board[][MAX_C])
{
	int c1x = 0, c1y = 0, c2x = 0, c2y = 0, c3x = 0, c3y = 0, c4x = 0, c4y = 0, c5x = 0, c5y = 0;	// x and y coordinates for the carrier locations
	int cvalid = 0; 


	//FOR CARRIER
	printf("Enter the 5 cells to place the carrier(ex. 0 1 0 2 0 3 0 4 0 5): ");
	scanf("%d%d%d%d%d%d%d%d%d%d", &c1x, &c1y, &c2x, &c2y, &c3x, &c3y, &c4x, &c4y, &c5x, &c5y);
	//Need to check for over lapping ships / Check if user tries to place outside of bounds / Set bounds carrier can't be placed on
	if (c1x >= 10 || c1y >= 10 || c2x >= 10 || c2y >= 10 || c3x >= 10 || c3y >= 10 || c4x >= 10 || c4y >= 10 || c5x >= 10 || c5y >= 10 ||
		c1x < 0 || c1y < 0 || c2x < 0 || c2y < 0 || c3x < 0 || c3y < 0 || c4x < 0 || c4y < 0 || c5x < 0 || c5y < 0 ) //For user trying to place outside bounds
	{
		cvalid = 1;
	}
	else
	{
		cvalid = 0;
	}
	while (cvalid == 1)
	{
		printf("Sorry you've entered invalid coordinates, please enter new coordinates: ");
		scanf("%d%d%d%d%d%d%d%d%d%d", &c1x, &c1y, &c2x, &c2y, &c3x, &c3y, &c4x, &c4y, &c5x, &c5y);
		if (c1x >= 10 || c1y >= 10 || c2x >= 10 || c2y >= 10 || c3x >= 10 || c3y >= 10 || c4x >= 10 || c4y >= 10 || c5x >= 10 || c5y >= 10 ||
			c1x < 0 || c1y < 0 || c2x < 0 || c2y < 0 || c3x < 0 || c3y < 0 || c4x < 0 || c4y < 0 || c5x < 0 || c5y < 0)
		{
			cvalid = 1;
		}
		else
		{
			cvalid = 0;
		}
	}
	board[c1x][c1y] = 'c';
	board[c2x][c2y] = 'c';
	board[c3x][c3y] = 'c';
	board[c4x][c4y] = 'c';
	board[c5x][c5y] = 'c';



	//FOR BATTLESHIP
	int b1x = 0, b1y = 0, b2x = 0, b2y = 0, b3x = 0, b3y = 0, b4x = 0, b4y = 0; // x and y coordinates for battleship locations
	int bvalid = 0;


	printf("Enter the 4 cells to place the battleship(ex. 0 1 0 2 0 3 0 4 ): ");
	scanf("%d%d%d%d%d%d%d%d", &b1x, &b1y, &b2x, &b2y, &b3x, &b3y, &b4x, &b4y);

	if (b1x >= 10 || b1y >= 10 || b2x >= 10 || b2y >= 10 || b3x >= 10 || b3y >= 10 || b4x >= 10 || b4y >= 10 ||
		b1x < 0 || b1y < 0 || b2x < 0 || b2y < 0 || b3x < 0 || b3y < 0 || b4x < 0 || b4y < 0 || board[b1x][b1y] != '~' ||
		board[b2x][b2y] != '~' || board[b3x][b3y] != '~' || board[b4x][b4y] != '~')
	{
		bvalid = 1;
	}
	else
	{
		bvalid = 0; 
	}
	while (bvalid == 1)
	{
		printf("Sorry you've entered invalid coordinates for the battleship, please enter new coordinates: ");
		scanf("%d%d%d%d%d%d%d%d", &b1x, &b1y, &b2x, &b2y, &b3x, &b3y, &b4x, &b4y);
		if (b1x >= 10 || b1y >= 10 || b2x >= 10 || b2y >= 10 || b3x >= 10 || b3y >= 10 || b4x >= 10 || b4y >= 10 ||
			b1x < 0 || b1y < 0 || b2x < 0 || b2y < 0 || b3x < 0 || b3y < 0 || b4x < 0 || b4y < 0 || board[b1x][b1y] != '~' ||
			board[b2x][b2y] != '~' || board[b3x][b3y] != '~' || board[b4x][b4y] != '~')
		{
			bvalid = 1;
		}
		else
		{
			bvalid = 0;
		}
	}
	board[b1x][b1y] = 'b';
	board[b2x][b2y] = 'b';
	board[b3x][b3y] = 'b';
	board[b4x][b4y] = 'b';


	//FOR CRUSIER
	int r1x = 0, r1y = 0, r2x = 0, r2y = 0, r3x = 0, r3y = 0; // x and y coordinates for Crusier locations
	int rvalid = 0;

	printf("Enter the 3 cells to place the Crusier(ex. 0 1 0 2 0 3 ): ");
	scanf("%d%d%d%d%d%d", &r1x, &r1y, &r2x, &r2y, &r3x, &r3y);

	if (r1x >= 10 || r1y >= 10 || r2x >= 10 || r2y >= 10 || r3x >= 10 || r3y >= 10 ||
		r1x < 0 || r1y < 0 || r2x < 0 || r2y < 0 || r3x < 0 || r3y < 0 || board[r1x][r1y] != '~' ||
		board[r2x][r2y] != '~' || board[r3x][r3y] != '~' || board[r1x][r1y] != board[r2x][r2y + 1] ||
		board[r1x][r1y] != board[r2x][r2y - 1] || board[r1x][r1y] != board[r2x + 1][r2y] || board[r1x][r1y] != board[r2x - 1][r2y] ||
		board[r2x][r2y] != board[r3x][r3y + 1] || board[r2x][r2y] != board[r3x][r3y - 1] || board[r2x][r2y] != board[r3x + 1][r3y] ||
		board[r2x][r2y] != board[r3x - 1][r3y])
	{
		rvalid = 1;
	}
	else
	{
		rvalid = 0;
	}
	while (rvalid == 1)
	{
		printf("Sorry you've entered invalid coordinates for the Crusier, please enter new coordinates: ");
		scanf("%d%d%d%d%d%d", &r1x, &r1y, &r2x, &r2y, &r3x, &r3y);
		if (r1x >= 10 || r1y >= 10 || r2x >= 10 || r2y >= 10 || r3x >= 10 || r3y >= 10 ||
			r1x < 0 || r1y < 0 || r2x < 0 || r2y < 0 || r3x < 0 || r3y < 0 || board[r1x][r1y] != '~' ||
			board[r2x][r2y] != '~' || board[r3x][r3y] != '~' || board[r1x][r1y] != board[r2x][r2y + 1] ||
			board[r1x][r1y] != board[r2x][r2y - 1] || board[r1x][r1y] != board[r2x + 1][r2y] || board[r1x][r1y] != board[r2x - 1][r2y] ||
			board[r2x][r2y] != board[r3x][r3y + 1] || board[r2x][r2y] != board[r3x][r3y - 1] || board[r2x][r2y] != board[r3x + 1][r3y] ||
			board[r2x][r2y] != board[r3x - 1][r3y])
		{
			rvalid = 1;
		}
		else
		{
			rvalid = 0;
		}
	}
	board[r1x][r1y] = 'r';
	board[r2x][r2y] = 'r';
	board[r3x][r3y] = 'r';



	//FOR SUBMARINE
	int s1x = 0, s1y = 0, s2x = 0, s2y = 0, s3x = 0, s3y = 0; // x and y coordinates for Submarine locations
	int svalid = 0;

	printf("Enter the 3 cells to place the Submarine(ex. 0 1 0 2 0 3 ): ");
	scanf("%d%d%d%d%d%d", &s1x, &s1y, &s2x, &s2y, &s3x, &s3y);

	if (s1x >= 10 || s1y >= 10 || s2x >= 10 || s2y >= 10 || s3x >= 10 || s3y >= 10 ||
		s1x < 0 || s1y < 0 || s2x < 0 || s2y < 0 || s3x < 0 || s3y < 0 || board[s1x][s1y] != '~' ||
		board[s2x][s2y] != '~' || board[s3x][s3y] != '~' || board[s1x][s1y] != board[s2x][s2y + 1] ||
		board[s1x][s1y] != board[s2x][s2y - 1] || board[s1x][s1y] != board[s2x+1][s2y] || board[s1x][s1y] != board[s2x - 1][s2y] ||
		board[s2x][s2y] != board[s3x][s3y + 1] || board[s2x][s2y] != board[s3x][s3y - 1]|| board[s2x][s2y] != board[s3x + 1][s3y] ||
		board[s2x][s2y] != board[s3x - 1][s3y])
	{
		svalid = 1;
	}
	else
	{
		svalid = 0;
	}
	while (svalid == 1)
	{
		printf("Sorry you've entered invalid coordinates for the Submarine, please enter new coordinates: ");
		scanf("%d%d%d%d%d%d", &s1x, &s1y, &s2x, &s2y, &s3x, &s3y);
		if (s1x >= 10 || s1y >= 10 || s2x >= 10 || s2y >= 10 || s3x >= 10 || s3y >= 10 ||
			s1x < 0 || s1y < 0 || s2x < 0 || s2y < 0 || s3x < 0 || s3y < 0 || board[s1x][s1y] != '~' ||
			board[s2x][s2y] != '~' || board[s3x][s3y] != '~' || board[s1x][s1y] != board[s2x][s2y + 1] ||
			board[s1x][s1y] != board[s2x][s2y - 1] || board[s1x][s1y] != board[s2x + 1][s2y] || board[s1x][s1y] != board[s2x - 1][s2y] ||
			board[s2x][s2y] != board[s3x][s3y + 1] || board[s2x][s2y] != board[s3x][s3y - 1] || board[s2x][s2y] != board[s3x + 1][s3y] ||
			board[s2x][s2y] != board[s3x - 1][s3y]) 
		{
			svalid = 1;
		}
		else
		{
			svalid = 0;
		}
	}
	board[s1x][s1y] = 's';
	board[s2x][s2y] = 's';
	board[s3x][s3y] = 's';


	//FOR DESTROYER
	int d1x = 0, d1y = 0, d2x = 0, d2y = 0; // x and y coordinates for Destroyer locations
	int dvalid = 0;

	printf("Enter the 2 cells to place the destroyer(ex. 0 1 0 2 ): ");
	scanf("%d%d%d%d", &d1x, &d1y, &d2x, &d2y);

	if (d1x >= 10 || d1y >= 10 || d2x >= 10 || d2y >= 10 ||
		d1x < 0 || d1y < 0 || d2x < 0 || d2y < 0 || board[d1x][d1y] != '~' ||
		board[d2x][d2y] != '~' || board[d1x][d1y] != board[d2x][d2y + 1] || board[d1x][d1y] != board[d2x][d2y - 1] ||
		board[d1x][d1y] != board[d2x+1][d2y] || board[d1x][d1y] != board[d2x - 1][d2y])
	{
		dvalid = 1;
	}
	else
	{
		dvalid = 0;
	}
	while (dvalid == 1)
	{
		printf("Sorry you've entered invalid coordinates for the destroyer, please enter new coordinates: ");
		scanf("%d%d%d%d", &d1x, &d1y, &d2x, &d2y);
		if (d1x >= 10 || d1y >= 10 || d2x >= 10 || d2y >= 10 ||
			d1x < 0 || d1y < 0 || d2x < 0 || d2y < 0 || board[d1x][d1y] != '~' ||			//Look over
			board[d2x][d2y] != '~' || board[d1x][d1y] != board[d2x][d2y + 1] || board[d1x][d1y] != board[d2x][d2y - 1] ||
			board[d1x][d1y] != board[d2x + 1][d2y] || board[d1x][d1y] != board[d2x - 1][d2y])
		{
			dvalid = 1;
		}
		else
		{
			dvalid = 0;
			
		}
	}
	board[d1x][d1y] = 'd';
	board[d2x][d2y] = 'd';

	return board; 
}


/*
*Function name: char randomly_place_ships(char board[][MAX_C])
*Description: Allows the user and computer to randomly place ships
*Input parameters: char board[][MAX_C]
*Returns: the board
*Preconditions: board must be defined
*Post conditions: none
*/

char randomly_place_ships(char board[][MAX_C])
{
	//For randomly placing carrier
	int carh_or_v = -1, carrandvertr = 0, carrandvertc = 0, carrandhorr = 0, carrandhorc = 0;
	carh_or_v = rand() % 2 + 1;
	

	if (carh_or_v == 1)		// 1 is for vertical values
	{
		carrandvertr = rand() % 6 + 1;		//Limits the rows to 0-5/prevents carrier going off board in vertical dir
		carrandvertr = carrandvertr - 1;
		carrandvertc = rand() % 10 + 1;		//Allows colunms to be 0-9
		carrandvertc = carrandvertc - 1;
		board[carrandvertr][carrandvertc] = 'c';		//Places 'c's downwards from the board
		board[carrandvertr+1][carrandvertc] = 'c';
		board[carrandvertr+2][carrandvertc] = 'c';
		board[carrandvertr+3][carrandvertc] = 'c';
		board[carrandvertr+4][carrandvertc] = 'c';

	}
	else                  // 2 is for horziental 
	{
		carrandhorr = rand() % 10 + 1;
		carrandhorr = carrandhorr - 1;
		carrandhorc = rand() % 6 + 1;
		carrandhorc = carrandhorc - 1;
		board[carrandhorr][carrandhorc ] = 'c';
		board[carrandhorr][carrandhorc + 1] = 'c';
		board[carrandhorr][carrandhorc + 2] = 'c';
		board[carrandhorr][carrandhorc + 3] = 'c';
		board[carrandhorr][carrandhorc + 4] = 'c';
	}


	//For randomly placing battleship
	int battle_h_or_v = 0, battle_rand_vert_r = 0, battle_rand_vert_c = 0, battle_rand_hor_r = 0, battle_rand_hor_c = 0;
	int battle_test_v = -1, battle_test_h = -1;
	battle_h_or_v = rand() % 2 + 1;

	

	if (battle_h_or_v == 1)	 //1 is for vertical values
	{
		battle_rand_vert_r = rand() % 7 + 1;
		battle_rand_vert_r = battle_rand_vert_r - 1;
		battle_rand_vert_c = rand() % 10 + 1;
		battle_rand_vert_c = battle_rand_vert_c - 1;
		while (battle_test_v != 0)
		{
			if (board[battle_rand_vert_r][battle_rand_vert_c] != '~' || board[battle_rand_vert_r + 1][battle_rand_vert_c] != '~' ||
				board[battle_rand_vert_r + 2][battle_rand_vert_c] != '~' || board[battle_rand_vert_r + 3][battle_rand_vert_c] != '~' )
			{
				battle_test_v = 1;
				battle_rand_vert_r = rand() % 7 + 1;
				battle_rand_vert_r = battle_rand_vert_r - 1;
				battle_rand_vert_c = rand() % 10 + 1;
				battle_rand_vert_c = battle_rand_vert_c - 1;


			}
			else					
			{
				battle_test_v = 0;
			}
		}
		board[battle_rand_vert_r][battle_rand_vert_c] = 'b';
		board[battle_rand_vert_r + 1][battle_rand_vert_c] = 'b';
		board[battle_rand_vert_r + 2][battle_rand_vert_c] = 'b';
		board[battle_rand_vert_r + 3][battle_rand_vert_c] = 'b';
	}


	if (battle_h_or_v == 2)					// 2 for horizental values
	{
		battle_rand_hor_r = rand() % 10 + 1;
		battle_rand_hor_r = battle_rand_hor_r - 1;
		battle_rand_hor_c = rand() % 7 + 1;
		battle_rand_hor_c = battle_rand_hor_c - 1;
		while (battle_test_h != 0)
		{
			if (board[battle_rand_hor_r][battle_rand_hor_c] != '~' || board[battle_rand_hor_r][battle_rand_hor_c + 1] != '~' ||
				board[battle_rand_hor_r][battle_rand_hor_c + 2] != '~' || board[battle_rand_hor_r][battle_rand_hor_c + 3] != '~')
			{
				battle_test_h = 1;
				battle_rand_hor_r = rand() % 10 + 1;
				battle_rand_hor_r = battle_rand_hor_r - 1;
				battle_rand_hor_c = rand() % 7 + 1;
				battle_rand_hor_c = battle_rand_hor_c - 1;

			}
			else
			{
				battle_test_h = 0; 
			}
		}
		board[battle_rand_hor_r][battle_rand_hor_c] = 'b';
		board[battle_rand_hor_r][battle_rand_hor_c + 1] = 'b';
		board[battle_rand_hor_r][battle_rand_hor_c + 2] = 'b';
		board[battle_rand_hor_r][battle_rand_hor_c + 3] = 'b';
	}

	//Randomly placing crusier
	int crusier_h_or_v = 0, cr_vert_r = 0, cr_vert_c = 0, cr_hor_r = 0, cr_hor_c = 0; 
	int crusier_test_v = -1, crusier_test_h = -1; 
	crusier_h_or_v = rand() % 2 + 1;
	
	

	if (crusier_h_or_v == 1)	//1 for vertical values
	{
		cr_vert_r = rand() % 8 + 1;
		cr_vert_r = cr_vert_r - 1;
		cr_vert_c = rand() % 10 + 1;
		cr_vert_c = cr_vert_c - 1;
		while (crusier_test_v != 0)
		{
			if (board[cr_vert_r][cr_vert_c] != '~' || board[cr_vert_r + 1][cr_vert_c] != '~' || board[cr_vert_r + 2][cr_vert_c] != '~' )
			{
				cr_vert_r = rand() % 8 + 1;
				cr_vert_r = cr_vert_r - 1;
				cr_vert_c = rand() % 10 + 1;
				cr_vert_c = cr_vert_c - 1;
			}
			else
			{
				crusier_test_v = 0;
			}
		}
		board[cr_vert_r][cr_vert_c] = 'r';
		board[cr_vert_r + 1][cr_vert_c] = 'r';
		board[cr_vert_r + 2][cr_vert_c] = 'r';
	}
	if (crusier_h_or_v == 2)
	{
		cr_hor_r = rand() % 10 + 1;
		cr_hor_r = cr_hor_r - 1;
		cr_hor_c = rand() % 8 + 1;
		cr_hor_c = cr_hor_c - 1;
		while (crusier_test_h != 0)
		{
			if (board[cr_hor_r][cr_hor_c] != '~' || board[cr_hor_r][cr_hor_c + 1] != '~' || board[cr_hor_r][cr_hor_c + 2] != '~')
			{
				cr_hor_r = rand() % 10 + 1;
				cr_hor_r = cr_hor_r - 1;
				cr_hor_c = rand() % 8 + 1;
				cr_hor_c = cr_hor_c - 1;
			}
			else
			{
				crusier_test_h = 0;
			}
		}
		board[cr_hor_r][cr_hor_c] = 'r';
		board[cr_hor_r][cr_hor_c + 1] = 'r';
		board[cr_hor_r][cr_hor_c + 2] = 'r';
	}


	//Randomly placing submarine
	int sub_h_or_v = 0, s_vert_r = 0, s_vert_c = 0, s_hor_r = 0, s_hor_c = 0;
	int sub_test_v = -1, sub_test_h = -1;
	sub_h_or_v = rand() % 2 + 1;
	
	if (sub_h_or_v == 1)	//1 for vertical values
	{
		s_vert_r = rand() % 8 + 1;
		s_vert_r = s_vert_r - 1;
		s_vert_c = rand() % 10 + 1;
		s_vert_c = s_vert_c - 1;
		while (sub_test_v != 0)
		{
			if (board[s_vert_r][s_vert_c] != '~' || board[s_vert_r + 1][s_vert_c] != '~' || board[s_vert_r + 2][s_vert_c] != '~')
			{
				s_vert_r = rand() % 8 + 1;
				s_vert_r = s_vert_r - 1;
				s_vert_c = rand() % 10 + 1;
				s_vert_c = s_vert_c - 1;
			}
			else
			{
				sub_test_v = 0;
			}
		}
		board[s_vert_r][s_vert_c] = 's';
		board[s_vert_r + 1][s_vert_c] = 's';
		board[s_vert_r + 2][s_vert_c] = 's';
	}

	if (sub_h_or_v == 2)
	{
		s_hor_r = rand() % 10 + 1;
		s_hor_r = s_hor_r - 1;
		s_hor_c = rand() % 8 + 1;
		s_hor_c = s_hor_c - 1;
		while (sub_test_h != 0)
		{
			if (board[s_hor_r][s_hor_c] != '~' || board[s_hor_r][s_hor_c + 1] != '~' || board[s_hor_r][s_hor_c + 2] != '~')
			{
				s_hor_r = rand() % 10 + 1;
				s_hor_r = s_hor_r - 1;
				s_hor_c = rand() % 8 + 1;
				s_hor_c = s_hor_c - 1;
			}
			else
			{
				sub_test_h = 0;
			}
		}
		board[s_hor_r][s_hor_c] = 's';
		board[s_hor_r][s_hor_c + 1] = 's';
		board[s_hor_r][s_hor_c + 2] = 's';
	}

	//Randomly placing submarine
	int des_h_or_v = 0, d_vert_r = 0, d_vert_c = 0, d_hor_r = 0, d_hor_c = 0;
	int des_test_v = -1, des_test_h = -1;
	des_h_or_v = rand() % 2 + 1;
	

	if (des_h_or_v == 1)	//1 for vertical values
	{
		d_vert_r = rand() % 9 + 1;
		d_vert_r = d_vert_r - 1;
		d_vert_c = rand() % 10 + 1;
		d_vert_c = d_vert_c - 1;
		while (des_test_v != 0)
		{
			if (board[d_vert_r][d_vert_c] != '~' || board[d_vert_r + 1][d_vert_c] != '~' )
			{
				d_vert_r = rand() % 9 + 1;
				d_vert_r = d_vert_r - 1;
				d_vert_c = rand() % 10 + 1;
				d_vert_c = d_vert_c - 1;
			}
			else
			{
				des_test_v = 0;
			}
		}
		board[d_vert_r][d_vert_c] = 'd';
		board[d_vert_r + 1][d_vert_c] = 'd';
	}

	if (des_h_or_v == 2)
	{
		d_hor_r = rand() % 10 + 1;
		d_hor_r = d_hor_r - 1;
		d_hor_c = rand() % 9 + 1;
		d_hor_c = d_hor_c - 1;
		while (des_test_h != 0)
		{
			if (board[d_hor_r][d_hor_c] != '~' || board[d_hor_r][d_hor_c + 1] != '~')
			{
				d_hor_r = rand() % 10 + 1;
				d_hor_r = d_hor_r - 1;
				d_hor_c = rand() % 9 + 1;
				d_hor_c = d_hor_c - 1;
			}
			else
			{
				des_test_h = 0;
			}
		}
		board[d_hor_r][d_hor_c] = 'd';
		board[d_hor_r][d_hor_c + 1] = 'd';
	}

	return board;
}


/*
*Function name: starter(void)
*Description: Choices either 1 or 2 for player 1 or the computer for a randomly starter
*Input parameters: none
*Returns: the random value
*Preconditions: random library has been ncluded
*Post conditions: none
*/

int starter(void)
{
	int p1_or_comp = 0;
	p1_or_comp = rand() % 2 + 1;
	return p1_or_comp;
}


/*
*Function name: int player1_turn(int *shotx, char board[][MAX_C])
*Description: Allows player one to choose locations for shots
*Input parameters: *shotx, char board[][MAX_C]
*Returns: The y shot and x shot as a pointer
*Preconditions: board must be defined, shotx must be defined
*Post conditions: none
*/

int player1_turn(int *shotx, char board[][MAX_C])
{
	int shotx1 = 0, shoty1 = 0, valid_shot = -1;
	printf("Player 1 enter your target(ex. 0 1 ): ");
	scanf("%d%d", &shotx1, &shoty1);
	while (valid_shot != 0)
	{
		if (shotx1 >= 10 || shoty1 >= 10 || board[shotx1][shoty1] == 'm' || board[shotx1][shoty1] == '*')
		{
			valid_shot = 1;
			printf("Player 1 please enter a valid target(ex. 0 1 ): ");
			scanf("%d%d", &shotx1, &shoty1);
		}
		else
		{
			valid_shot = 0;
		}
	}
	*shotx = shotx1;
	return shoty1;
}

/*
*Function name: int player_comp_turn(int *shotx, char board[][MAX_C])
*Description: Allows the computer to randomly choose locations for shots
*Input parameters: *shotx, char board[][MAX_C]
*Returns: The y shot and x shot as a pointer
*Preconditions: board must be defined, shotx must be defined
*Post conditions: none
*/

int player_comp_turn(int *shotx, char board[][MAX_C])
{
	int shotx2 = 0, shoty2 = 0, valid_shot1 = -1;
	shotx2 = rand() % 10 + 1;
	shotx2 = shotx2 - 1;
	shoty2 = rand() % 10 + 1;
	shoty2 = shoty2 - 1;
	while (valid_shot1 != 0)
	{
		if (shotx2 >= 10 || shoty2 >= 10 || board[shotx2][shoty2] == 'm' || board[shotx2][shoty2] == '*')
		{
			valid_shot1 = 1;
			shotx2 = rand() % 10 + 1;
			shotx2 = shotx2 - 1;
			shoty2 = rand() % 10 + 1;
			shoty2 = shoty2 - 1;
		}
		else
		{
			valid_shot1 = 0;
			printf("Computer's target is (%d,%d)\n", shotx2, shoty2);
		}
	}
	*shotx = shotx2;
	return shoty2;
}




/*
*Function name: char check_shot(char playerboard[][MAX_C], int targetx, int targety, int *misses,int *tot_hits, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num)
*Description: Checks for shots on all the different ships also collects how many hits and misses
*Input parameters:char playerboard[][MAX_C], int targetx, int targety, int *misses,int *tot_hits, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num
*Returns: the board
*Preconditions: all pointer input parameters must be defined
*Post conditions: none
*/

char check_shot(char playerboard[][MAX_C], int targetx, int targety, int *misses,int *tot_hits, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num)
{
	
	if (num == 1) //Pass in 1 for player 1's board
	{
		if (playerboard[targetx][targety] == '~')
		{
			printf("(%d,%d) is a miss!\n", targetx, targety);
			playerboard[targetx][targety] = 'm';
			*misses = *misses + 1;
			fprintf(outfile, "Player 1: (%d,%d) is a miss!\n", targetx, targety);
			// save if miss and coordinates to file
		}
		else if (playerboard[targetx][targety] != '~')
		{

			printf("(%d,%d) is a hit!\n", targetx, targety);
			*tot_hits = *tot_hits + 1;

			if (playerboard[targetx][targety] == 'c')
			{
				*c_hits = *c_hits + 1;
				fprintf(outfile, "Player 1: (%d,%d) is a hit on the Carrier!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'b')
			{
				*b_hits = *b_hits + 1;
				fprintf(outfile, "Player 1: (%d,%d) is a hit on the Battleship!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'r')
			{
				*r_hits = *r_hits + 1;
				fprintf(outfile, "Player 1: (%d,%d) is a hit on the Crusier!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 's')
			{
				*s_hits = *s_hits + 1;
				fprintf(outfile, "Player 1: (%d,%d) is a hit on the Submarine!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'd')
			{
				*d_hits = *d_hits + 1;
				fprintf(outfile, "Player 1: (%d,%d) is a hit on the Destroyer!\n", targetx, targety);
			}
			playerboard[targetx][targety] = '*';
			// Save miss and hits
		}
	}
	
	else
	{
		if (playerboard[targetx][targety] == '~')
		{
			printf("(%d,%d) is a miss!\n", targetx, targety);
			playerboard[targetx][targety] = 'm';
			*misses = *misses + 1;
			fprintf(outfile, "Computer: (%d,%d) is a miss!\n", targetx, targety);
			// save if miss and coordinates to file
		}
		else if (playerboard[targetx][targety] != '~')
		{

			printf("(%d,%d) is a hit!\n", targetx, targety);
			*tot_hits = *tot_hits + 1;

			if (playerboard[targetx][targety] == 'c')
			{
				*c_hits = *c_hits + 1;
				fprintf(outfile, "Computer: (%d,%d) is a hit on the Carrier!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'b')
			{
				*b_hits = *b_hits + 1;
				fprintf(outfile, "Computer: (%d,%d) is a hit on the Battleship!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'r')
			{
				*r_hits = *r_hits + 1;
				fprintf(outfile, "Computer: (%d,%d) is a hit on the Crusier!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 's')
			{
				*s_hits = *s_hits + 1;
				fprintf(outfile, "Computer: (%d,%d) is a hit on the Submarine!\n", targetx, targety);
			}
			else if (playerboard[targetx][targety] == 'd')
			{
				*d_hits = *d_hits + 1;
				fprintf(outfile, "Computer: (%d,%d) is a hit on the Destroyer!\n", targetx, targety);
			}
			playerboard[targetx][targety] = '*';
			// Save miss and hits
		}
	}
	return playerboard;
}

/*
*Function name:void check_ship_sunk(int shotx, int shoty, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num)
*Description: Checks to see if any ships were sunk during the last turn
*Input parameters: int shotx, int shoty, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num
*Returns: none
*Preconditions: all pointer input parameters must be defined
*Post conditions: none
*/

void check_ship_sunk(int shotx, int shoty, int *c_hits, int *b_hits, int *r_hits, int *s_hits, int *d_hits, FILE *outfile, int num)
{
	if (num == 1)
	{
		if (*c_hits == 5)
		{
			printf("Carrier has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Player 1: Carrier has been sunk at (%d,%d)!\n", shotx, shoty);
			*c_hits -= 1;
		}
		else if (*b_hits == 4)
		{
			printf("Battleship has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Player 1: Battleship has been sunk at (%d,%d)!\n", shotx, shoty);
			*b_hits -= 1;
		}
		else if (*r_hits == 3)
		{
			printf("Crusier has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Player 1: Crusier has been sunk at (%d,%d)!\n", shotx, shoty);
			*r_hits -= 1;
		}
		else if (*s_hits == 3)
		{
			printf("Submarine has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Player 1: Submarine has been sunk at (%d,%d)!\n", shotx, shoty);
			*s_hits -= 1;
		}
		else if (*d_hits == 2)
		{
			printf("Destroyer has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Player 1: Destroyer has been sunk at (%d,%d)!\n", shotx, shoty);
			*d_hits -= 1;
		}
	}
	else
	{
		if (*c_hits == 5)
		{
			printf("Carrier has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Computer: Carrier has been sunk at (%d,%d)!\n", shotx, shoty);
			*c_hits -= 1;
		}
		else if (*b_hits == 4)
		{
			printf("Battleship has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Computer: Battleship has been sunk at (%d,%d)!\n", shotx, shoty);
			*b_hits -= 1;
		}
		else if (*r_hits == 3)
		{
			printf("Crusier has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Computer: Crusier has been sunk at (%d,%d)!\n", shotx, shoty);
			*r_hits -= 1;
		}
		else if (*s_hits == 3)
		{
			printf("Submarine has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Computer: Submarine has been sunk at (%d,%d)!\n", shotx, shoty);
			*s_hits -= 1;
		}
		else if (*d_hits == 2)
		{
			printf("Destroyer has been sunk at (%d,%d)!\n", shotx, shoty);
			fprintf(outfile, "Computer: Destroyer has been sunk at (%d,%d)!\n", shotx, shoty);
			*d_hits -= 1;
		}
	}
}


/*
*Function name: int check_for_winner(int p1_hits, int comp_hits)
*Description: prints the game rules for battleship
*Input parameters:  int p1_hits, int comp_hits
*Returns: int for who won
*Preconditions: none
*Post conditions: none
*/

int check_for_winner(int p1_hits, int comp_hits)
{
	int winner = 0;
	if (p1_hits > comp_hits)
	{
		printf("\nPLAYER 1 WINS!!!!\n\n");
		winner = 1;
	}
	else
	{
		printf("\nCOMPUTER WINS!!\nAre you really that bad?\n\n");
		winner = 2;
	}
	return winner; 

}

void output_stats(Stats player, FILE*outfile)
{
	fprintf(outfile, "Total Shots: %d\n", player.total_shots);
	fprintf(outfile, "Total Hits: %d\n", player.total_hits);
	fprintf(outfile, "Total Misses: %d\n", player.total_misses);
	fprintf(outfile, "Hits to Misses Ratio: %.4lf\n", player.hits_misses_ratio);
	fprintf(outfile, "%s\n\n", player.win_lose);

}
