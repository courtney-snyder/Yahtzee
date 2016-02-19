#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "PA5_functions.h"

void print_rules() //Shows the rules. I wrote it because it saves space in main.
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section. A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds. If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
}

void intro(int x)
{
	do
	{
	printf("Welcome to Yahtzee!\n1. Read rules\n2. Play Yahtzee\n3. Exit\n");
	scanf("%d", &x);
	switch (x)
	{
		case 1: print_rules();
				break;
		case 2: break;
		case 3: printf("See you later!\n");
				return 0;
		default: printf("Command not recognized. Please enter an integer between 1 and 3.\n");
			break;
	}
	}
	while (x != 2 && x != 3); //Runs while x = 1 so the player can reselect 1 or 3
}

void roll_dice (int dice_values[], int size)
{
	int index = 0;
	for (; index < size; index++)
	{
		dice_values[index] = rand() % 6 + 1;
	}
}

void show_dice (int dice_values[], int size)
{
	int index = 0;
	while (index < size)
	{
		printf("Die %d: %d\n", index+1, dice_values[index]);
		index++;
	}
}

void reroll(int dice_values[], int num_items)
{
	int num_reroll = 0, dice_position = 0, count = 0;
	do
	{
	printf("How many dice would you like to reroll? Enter an integer between 0 and 5.\n");
	scanf("%d", &num_reroll);
	}
	while(num_reroll >= 6); //Do while loop stops user from entering a number over 5 because there are only 5 dice to roll in Yahtzee
	for (;count < num_reroll; count++)
	{
		printf("Which die will you reroll? Enter an integer between 1 and 5.\n");
		scanf("%d", &dice_position);
		dice_values[dice_position - 1] = rand() % 6 + 1;
	}
}

void turn (int score[], int dice_values[], int size, int num_values[])
{
//Saw redundancy in the code, so instead of copy and pasting this 26 times, I made it into a function
printf("Roll 1\n");
roll_dice(dice_values, size);
show_dice(dice_values, size);
reroll(dice_values, size);
printf("Roll 2\n");
show_dice(dice_values, size);
reroll(dice_values, size);
printf("Roll 3\n");
show_dice(dice_values, size);
}

void print_combos() 
//Wrote because this will definitely save space in main. Shows the user all of the possible combos of dice in Yahtzee and their corresponding menu choice
{
	printf("1. Sum of 1's 7. Three-of-a-kind\n2. Sum of 2's 8. Four-of-a-kind \n3. Sum of 3's 9. Full house\n4. Sum of 4's 10. Small straight\n5. Sum of 5's 11. Large straight\n6. Sum of 6's 12. Yahtzee\n13. Chance\n");
}

void populate_num_dice (int dice_values[], int num_values[])
{
	int index = 0;
	for (; index < 5; index++)
	{
		num_values[dice_values[index] - 1]++;
	}
}

void select_combo(int dice_values[5], int score[13], int combo_used[13], int num_values[])
{
	int option = 0, check = 0, i = 0, j = 0;

	do //Written in class. If the combo has been used, it will enter the if statement and tell the user to choose a different option
	{
		printf("Enter the combination you would like to use:\n");
		print_combos(); //Shows the user what number corresponds to what option
		scanf("%d", &option);
		if (combo_used[option - 1] == 1)
		{
		check = 1;
		printf("Sorry, you have already used this combination. Please choose another.\n");
		scanf("%d", &option);
		}
	} 
	while (check);
	
	combo_used[option - 1] = 1; // Sets the combo as used so if the user already used that combo, it will enter the above if statement
	populate_num_dice (dice_values, num_values); //Populates num_dice, which tells how many 1's, 2's, etc. there are in a roll

	switch(option)
	{
	//If option = 1, the player chose to use their roll for their sum of ones
	case 1:
			score[0] = num_values[0]; //Sets the player's sum of ones section to however many ones they rolled
			printf("Player used %d for the sum of ones section.\n", score[0]);
			break;
	//If option = 2, the player chose to use their roll for their sum of twos
	case 2: 
			score[1] = (num_values[1] * 2); //Sets the players sum of twos section to (twos rolled * 2)
			printf("Player used %d for the sum of twos section.\n", score[1]);
			break;
	//If option = 3, the player chose to use their roll for their sum of threes
	case 3: 
			score[2] = (num_values[2] * 3); //Sets the players sum of threes section to (threes rolled * 3)
			printf("Player used %d for the sum of threes section.\n", score[2]);
			break;
	//If option = 4, the player chose to use their roll for their sum of fours
	case 4: 
			score[3] = (num_values[3] * 4); //Sets the players sum of fours section to (fours rolled * 4)
			printf("Player used %d for the sum of fours section.\n", score[3]);
			break;
	//If option = 5, the player chose to use their roll for their sum of fives
	case 5:
			score[4] = (num_values[4] * 5); //Sets the players sum of fives section to (fives rolled * 5)
			printf("Player used %d for the sum of fives section.\n", score[4]);
			break;
	//If option = 6, the player chose to use their roll for their sum of sixes
	case 6: 
			score[5] = (num_values[5] * 6); //Sets the players sum of sixes section to (sixes rolled * 6)
			printf("Player used %d for the sum of sixes section.\n", score[5]);
			break;
	//If option = 7, the player chose to use their 3 of a kind
	case 7: 
		if (num_values[0] >= 3 || num_values[1] >= 3 || num_values[2] >= 3 || num_values[3] >= 3 || num_values[4] >= 3 || num_values[5] >= 3)
		//if the dice don't meet any of these conditions, the player gets to make a different choice
		{
			score[6] = num_values[0] + (num_values[1] * 2) + (num_values[2] * 3) + (num_values[3] * 4) + (num_values[4] * 5) + (num_values[5] * 6);
			printf("Player used %d for the three of a kind section.\n", score[6]);
		}
		break;
	//If option = 8, the player chose to use their 4 of a kind
	case 8: 
		if (num_values[0] >= 4 || num_values[1] >= 4 || num_values[2] >= 4 || num_values[3] >= 4 || num_values[4] >= 4 || num_values[5] >= 4)
		{
			score[7] = num_values[0] + (num_values[1] * 2) + (num_values[2] * 3) + (num_values[3] * 4) + (num_values[4] * 5) + (num_values[5] * 6);
			printf("Player used %d for the four of a kind section.\n", score[7]);
		}
		break;
	//If option = 9, the player chose to use their full house
	case 9:
		for (i = 0; i < 6; i++) //Checks all of num_values ( [0]-[5] )
		{
			if (num_values[i] == 3) //If num_values[i] has 3, then the player has three of a kind and needs a pair for a full house
			{
				for (j = 0; j < 6; j++) //Checks all of num_values again
				{
					if (num_values[j] == 2) //If num_values[j] has 2, then the player gets a full house
					{
						printf("Player used the full house section.\n");
						score[8] = 25;
					}
				}
			}
		}
	//If option = 10, the player chose to use their small straight
	case 10:
		if ((num_values[0] >= 1 && num_values[1] >= 1 && num_values[2] >= 1 && num_values[3] >= 1) /* If the player gets 1 & 2 & 3 & 4 */ ||(num_values[1] >= 1 && num_values[2] >= 1 && num_values[3] >= 1 && num_values[4] >= 1 /*If the player gets 2, 3, 4, 5*/) || (num_values[2] >= 1 && num_values[3] >= 1 && num_values[4] >= 1 && num_values[5] >= 1) /*If the player gets 3, 4, 5, 6*/)
		{
			printf("Player used the small straight section.\n");
			score[9] = 30;
		}
	//If option = 11, the player chose to use their large straight
	case 11:
		if ((num_values[0] == 1 && num_values[1] == 1 && num_values[2] == 1 && num_values[3] == 1 && num_values[4] == 1) || (num_values[1] == 1 && num_values[2] == 1 && num_values[3] == 1 && num_values[4] == 1 && num_values[5] == 1))
		{
			printf("Player used the large straight section.\n");
			score[10] = 40;
		}
		break;
	//If option = 12, the player chose to use their Yahtzee
	case 12:
		if (num_values[0] == 5 || num_values[1] == 5 || num_values[2] == 5 || num_values[3] == 5 || num_values[4] == 5 || num_values[5] == 5)
		{
			printf("Congratulations, you got a Yahtzee!\n");
			score[11] = 50;
		}
		break;
	//If option = 13, the player chose to use their chance
	case 13:
		{
		score[12] = num_values[0] + (num_values[1] * 2) + (num_values[2] * 3) + (num_values[3] * 4) + (num_values[4] * 5) + (num_values[5] * 6);
		printf("Player used %d for the chance section.\n", score[12]);
		break;
		}
	default:
		do
		{
		printf("Command not recognized. Please enter an integer between 1 and 13.\n");
		scanf("%d", &option);
		}
		while (option <= 0 || option >= 14);
		break;
	}
}

void get_bonus(int score[])
//If player's top half >= 63, 35 is added to the score. I added it to score[0] because it doesn't really matter where the extra 35 points is added, as long as it is in the final (top half + bottom half) sum
{
	int top_sum = score[0]+score[1]+score[2]+score[3]+score[4]+score[5];
	if ( top_sum >= 63)
	{
		printf("Congrats, your top score is %d and you get the bonus!\n", top_sum);
		score[0] + 35;
	}
	else
	{
		printf("Sorry, no bonus for you.\n");
	}
}

void display_score(int score[13])
//Shows players their scores
{
	printf("Top Score:\n Ones: %d\n Twos: %d\n Threes: %d\n Fours: %d\n Fives: %d\n Sixes: %d\nBottom Score:\n 3 of a Kind: %d\n 4 of a Kind: %d\n Full House: %d\n Small Straight: %d\n Large Straight: %d\n Yahtzee: %d\n Chance: %d\n", score[0], score[1], score[2], score[3], score[4], score[5], score[6], score[7], score[8], score[9], score[10], score[11], score[12]);
}

void who_wins (int player1[], int player2[])
//Determines which player wins by comparing their scores
{
int x = 0, player1_score = 0, player2_score = 0;
for (; x < 13; x++) //Runs through the array 13 times ( [0] to [12] ) and adds up the scores, including the bonus, which will be added before, using get_bonus
{
	player1_score = player1_score + player1[x];
	player2_score = player2_score + player2[x];
}
	if (player1_score == player2_score)
{
	printf("It's a tie, both players had %d!\n", player1_score);
}
else if (player1_score > player2_score)
{
	printf("Player 1 wins with a score of %d!\n", player1_score);
}
else if (player2_score > player1_score)
{
	printf("Player 2 wins with a score of %d!\n", player2_score);
}
}