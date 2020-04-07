/*
Author: Parker Guillen
3/28/18
Description: PA 6, main
Help: Andrew's code for printing and filling functions
CPTS 121
*/

#include "Header.h"

int main(void)
{
	
	FILE*outfile = NULL;	//sets out file equal to NULL	
	outfile = fopen("battleship.log", "w");	//opens the outfile

	srand(time(NULL));		// Allows for random selection
	srand((unsigned int)(time(NULL)));
	
	// Player 1 variables
	int shipplace = -1, starting_player = 0, p1_shotx = 0, p1_shoty=0; 
	int p1_misses = 0, carrier_hits = 0, battleship_hits = 0, crusier_hits = 0, submarine_hits = 0, destroyer_hits = 0, total_hits_p1 = 0;//Pointer variables

	// Computer variables
	int comp_shoty = 0, comp_shotx = 0;
	int  comp_misses = 0, total_hits_comp = 0, comp_carrier_hits = 0, comp_battleship_hits = 0, comp_crusier_hits = 0, comp_submarine_hits = 0, comp_destroyer_hits = 0;

	int winner = 0; 

	char player1board[MAX_R][MAX_C] = { '\0' },	//Sets values in the 2D arrays to 0 
		playercompboard[MAX_R][MAX_C] = { '\0' };

	start_screen();		//Presents the start screen and game rules
	system("Pause");
	system("cls");

	fill_board(player1board, MAX_R, MAX_C);		//Fills player 1's and computers boards with '~'
	fill_board(playercompboard, MAX_C, MAX_C);
	print_board(player1board, MAX_R, MAX_C, 1); //Prints empty board might need to remove but gives user reference point to choose ships


	printf("Enter 1 to manually place ships and 0 to randomly place ships: ");
	scanf("%d", &shipplace); 
	if (shipplace == 1)	//If user enters 1 then function for manually placing ships is selected
	{
		manually_place_ships(player1board);
		printf("\nPlayer 1's board\n");
		print_board(player1board, MAX_R, MAX_C, 1);	//prints board with their placed ships
	}
	else				//if the user doesn't enter 1 then function for randomly placing ships is selected
	{
		randomly_place_ships(player1board);
		printf("\nPlayer 1's board\n");
		print_board(player1board, MAX_R, MAX_C, 1);	//Prints board with randomly generated ships
	}

	randomly_place_ships(playercompboard);		//randomly places the ships for the computers board
	printf("Computers board\n");
	print_board(playercompboard, MAX_R, MAX_C, 2);

	system("pause");
	system("cls");

	//Game start

	starting_player = starter();			// If 1 is returned player 1 starts, if 2 is returned computer goes first
	

	if (starting_player == 1) // Write a fucntion for the shot a computer takes
	{
		printf("Player 1 has been randomly selected to go first!\n");
		while (total_hits_p1 < 17 || total_hits_comp < 17)	//|| total_hits_comp < 17
		{
			// Adjust functions for the computer
			p1_shoty = player1_turn(&p1_shotx, playercompboard);	//fires shots on the computers board, asks for a new shot if out of range or used before
			check_shot(playercompboard, p1_shotx, p1_shoty, &p1_misses, &total_hits_p1, &carrier_hits, &battleship_hits, &crusier_hits, &submarine_hits, &destroyer_hits, outfile, 1);		//checks if shot was a hit or miss 
			printf("Computer's board: \n");
			print_board(playercompboard, MAX_R, MAX_C, 2);	    // prints the players board
			printf("Player 1:\nNumber of misses:%d\nNumber of hits:%d\n", p1_misses, total_hits_p1);
			//printf("player 1:\nCarrier hits:%d\tBattle hits:%d\tCrusier hit:%d\tSub hits:%d\tDestroyer hits:%d\n\n", carrier_hits, battleship_hits, crusier_hits, submarine_hits, destroyer_hits);
			check_ship_sunk(p1_shotx, p1_shoty, &carrier_hits, &battleship_hits, &crusier_hits, &submarine_hits, &destroyer_hits, outfile, 1);
			if (total_hits_p1 == 17)
			{
				break;
			}
	

			system("pause");

			printf("\n");
			comp_shoty = player_comp_turn(&comp_shotx, player1board);
			check_shot(player1board, comp_shotx, comp_shoty, &comp_misses, &total_hits_comp, &comp_carrier_hits, &comp_battleship_hits, &comp_crusier_hits, &comp_submarine_hits, &comp_destroyer_hits, outfile, 2);
			printf("Player 1's board: \n");
			print_board(player1board, MAX_R, MAX_C, 1);
			printf("Computer:\nNumber of misses:%d\nNumber of hits:%d\n", comp_misses, total_hits_comp);
			//printf("Computer:\nCarrier hits:%d\tBattle hits:%d\tCrusier hit:%d\tSub hits:%d\tDestroyer hits:%d\n", comp_carrier_hits, comp_battleship_hits, comp_crusier_hits, comp_submarine_hits, comp_destroyer_hits);
			check_ship_sunk(comp_shotx, comp_shoty, &comp_carrier_hits, &comp_battleship_hits, &comp_crusier_hits, &comp_submarine_hits, &comp_destroyer_hits, outfile, 2);

			system("pause");
			system("cls");
		}
		winner = check_for_winner(total_hits_p1, total_hits_comp);

	}
	else
	{
		printf("The computer has been randomly selected to go first!!\n");
		while (total_hits_p1 < 17 || total_hits_comp < 17)
		{
			printf("\n");
			comp_shoty = player_comp_turn(&comp_shotx, player1board);
			check_shot(player1board, comp_shotx, comp_shoty, &comp_misses, &total_hits_comp, &comp_carrier_hits, &comp_battleship_hits, &comp_crusier_hits, &comp_submarine_hits, &comp_destroyer_hits, outfile, 2);
			printf("Player 1's board: \n");
			print_board(player1board, MAX_R, MAX_C, 1);
			printf("Computer:\nNumber of misses:%d\nNumber of hits:%d\n", comp_misses, total_hits_comp);
			//printf("Computer:\nCarrier hits:%d\tBattle hits:%d\tCrusier hit:%d\tSub hits:%d\tDestroyer hits:%d\n", comp_carrier_hits, comp_battleship_hits, comp_crusier_hits, comp_submarine_hits, comp_destroyer_hits);
			check_ship_sunk(comp_shotx, comp_shoty, &comp_carrier_hits, &comp_battleship_hits, &comp_crusier_hits, &comp_submarine_hits, &comp_destroyer_hits, outfile, 2);
			if (total_hits_comp == 17)
			{
				break;
			}


			system("pause");

			p1_shoty = player1_turn(&p1_shotx, playercompboard);	//fires shots on the computers board, asks for a new shot if out of range or used before
			check_shot(playercompboard, p1_shotx, p1_shoty, &p1_misses, &total_hits_p1, &carrier_hits, &battleship_hits, &crusier_hits, &submarine_hits, &destroyer_hits, outfile, 1);		//checks if shot was a hit or miss 
			printf("Computer's board: \n");
			print_board(playercompboard, MAX_R, MAX_C, 2);	    // prints the players board
			printf("Player 1:\nNumber of misses:%d\nNumber of hits:%d\n", p1_misses, total_hits_p1);
			//printf("player 1:\nCarrier hits:%d\tBattle hits:%d\tCrusier hit:%d\tSub hits:%d\tDestroyer hits:%d\n\n", carrier_hits, battleship_hits, crusier_hits, submarine_hits, destroyer_hits);
			check_ship_sunk(p1_shotx, p1_shoty, &carrier_hits, &battleship_hits, &crusier_hits, &submarine_hits, &destroyer_hits, outfile, 1);
			if (total_hits_p1 == 17)
			{
				break;
			}
			system("pause");
			system("cls");
			

		}
		winner = check_for_winner(total_hits_p1, total_hits_comp);
	}

	double ratiop1 = 0, ratiocomp = 0;
	ratiop1 = (double)total_hits_p1 / p1_misses;
	ratiocomp = (double)total_hits_comp / comp_misses;

	Stats player1 = { 0,0,0,0.0,"" };		// declares and fills player ones struct with values
	player1.total_shots = p1_misses + total_hits_p1;
	player1.total_hits = total_hits_p1;
	player1.total_misses = p1_misses;
	player1.hits_misses_ratio = ratiop1;
	
	Stats computer = { 0,0,0,0.0,"" };		// declares and fills computer's struct with values
	computer.total_shots = comp_misses + total_hits_comp;
	computer.total_hits = total_hits_comp;
	computer.total_misses = comp_misses;
	computer.hits_misses_ratio = ratiocomp;

	if (winner == 1)
	{

	strcpy(player1.win_lose, "PLAYER 1 WINS");
	strcpy(computer.win_lose, "COMPUTER LOSES");
	}
	else {
		strcpy(player1.win_lose, "PLAYER 1 LOSES");
		strcpy(computer.win_lose, "COMPUTER WINS");
	}

	fprintf(outfile, "Player 1:\n");
	output_stats(player1, outfile);
	fprintf(outfile, "Computer: \n");
	output_stats(computer, outfile);


	fclose(outfile); 

	system("Pause");
	return 0; 
}