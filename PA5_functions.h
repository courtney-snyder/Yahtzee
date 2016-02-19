#ifndef PA5_FUNCTIONS_H
#define PA5_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

void print_rules();
void intro(int x);
void roll_dice (int dice_values[], int size);
void show_dice (int dice_values[], int size);
void reroll(int dice_values[], int num_items);
void turn (int score[], int dice_values[], int size, int num_values[]);
void print_combos();
void select_combo(int dice_values[], int score[], int combo_used[], int num_values[]);
void populate_num_dice (int dice_values[], int num_values[]);
void display_score(int score[]);
void get_bonus(int score[]);
void who_wins (int player1[], int player2[]);

#endif