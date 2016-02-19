/*
Programmer: Courtney Snyder
Last Update: 2/18/2016
Description: A game of Yahtzee.
Credits: We wrote roll_dice, show_dice, reroll, select_combo, and populate_num_values in class.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "PA5_functions.h"

int main (void)
{
int option = 0, index = 0, player1[5] = {0}, player2[5] = {0}, player1_score[13] = {0}, player2_score[13] = {0}, player1_combo_used[13] = {0}, player2_combo_used[13] = {0}, num_values[6] = {0};
srand((unsigned int)time(NULL));

intro(option); //Runs the instructions/play game/exit menu
system("pause"); //Doesn't immediately clear the screen so the player can read the text
system("cls"); //Clears the screen

	for (; index < 13; index++) //Loops 13 times so less space is used in main.c
	{
	printf("ROUND %d\n", index+1); //Shows players what round they are on out of 13
	printf("Player 1\n"); //Shows that it is Player 1's turn
	display_score(player1_score); //Player can see their score card and see which combos they have already used
	turn(player1_score, player1, 5, num_values); //Lets player reroll 0-5 dice up to 2 two times after first roll
	select_combo(player1, player1_score, player1_combo_used, num_values); //After third roll, player selects combo
	printf("It is Player 2's turn.\n");
	system("pause");
	system("cls"); //Clears screen for Player 2
	printf("ROUND %d\n", index+1);
	printf("Player 2\n");
	display_score(player2_score);
	turn(player2_score, player2, 5, num_values);
	select_combo(player2, player2_score, player2_combo_used, num_values);
	printf("It is Player 1's turn.\n");
	system("pause");
	system("cls"); //Clears screen for Player 1
	}

	printf("Player 1: ");
	get_bonus(player1_score); //If Player 1's top half = 63 or more, then 35 points is added to their score
	printf("Player 2: ");
	get_bonus(player2_score); //If Player 2's top half = 63 or more, then 35 points is added to their score
	who_wins(player1_score, player2_score); //Compares Player 1's score to Player 2's and determines who wins
	printf("Thanks for playing!\n");

return 0; 
} 