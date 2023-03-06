//B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // in order to use the "rand" and "srand" functions
#include <time.h>	// in order to use "time" function
#include <conio.h>  // in order to handle keyboard input in a non-blocking manner
#define DOWN_ARROW 80
#define UP_ARROW 72
#define ENTER_KEY 13
#define INDEX_MOVE_FORWARD true
#define INDEX_MOVE_BACKWARD false
#define MAX_NAME_LEN 20
#define INSTANT_GAME_SPEED_NO_DELAY 0
#define FAST_GAME_SPEED_DELAY 20
#define DEFAULT_GAME_SPEED_DELAY 100
//Databases
struct card
{
	int cardId;
	char cardColor;
}; typedef struct card Card;
struct player
{
	char name[MAX_NAME_LEN];
	int currCardNum;
	int handMemorySize;
	Card* playerHand;
}; typedef struct player PLAYER;
struct cpu
{
	char name[MAX_NAME_LEN];
	int currCardNum, handMemorySize, difficulty;
	Card* playerHand;
}; typedef struct cpu CPU;

//menu functions
void startMenuLogic(int* difficulty , int* gamespeed);
int startMenu();
void optionsMenuLogic(int* difficulty, int* gamespeed);
int optionsMenu();
void gameSpeedMenuLogic(int* gamespeed);
void choiseArrow(int optionNum , int arrowPosition);


//verstile functions
void moveIndex(int* indexPosition,bool direction, int minIndex, int maxIndex);


void main() {
	int difficulty = 1, gamespeed = DEFAULT_GAME_SPEED_DELAY;
	startMenuLogic(&difficulty,&gamespeed);
}

//responsible for all the menus before the player enters the game
//1 - start game
//2 - options menu
//3 - exit the game
void startMenuLogic(int* difficulty, int* gamespeed) {
#define START_GAME 1
#define OPTIONS 2
#define EXIT 3
	int playerChoise = startMenu();
	while (playerChoise != START_GAME) {
		switch (playerChoise) {
		case OPTIONS:
			optionsMenuLogic(difficulty, gamespeed);
			break;
		case EXIT:
			exit(0);
		}
		playerChoise = startMenu();
	}
	return;
}

//Prints the Start menu for the user returns the option the user choose after hitting enter
int startMenu() {
#define MAX_START_MENU_OPTION 3
#define MIN_START_MENU_OPTION 1
	int arrowPosition = MIN_START_MENU_OPTION;
	int keyPress = 0;
	while (keyPress != ENTER_KEY) {
		printf("\t----Welcome to Uno!----\n\n");
		choiseArrow(1, arrowPosition); printf("Play\n");
		choiseArrow(2, arrowPosition); printf("Options\n");
		choiseArrow(3, arrowPosition); printf("Exit\n");
		keyPress = _getch();
		switch (keyPress) {
		case DOWN_ARROW:
			moveIndex(&arrowPosition, INDEX_MOVE_FORWARD, MIN_START_MENU_OPTION, MAX_START_MENU_OPTION);
			break;
		case UP_ARROW:
			moveIndex(&arrowPosition, INDEX_MOVE_BACKWARD, MIN_START_MENU_OPTION, MAX_START_MENU_OPTION);
			break;
		}
		system("cls");
	}
	return arrowPosition;
}

//prints the manu and changes settings according to the user's choise
// 1 - NO OPTION
// 3 - BACK
void optionsMenuLogic(int* difficulty, int* gamespeed) {
#define DIFFICULTY 1
#define GAME_SPEED 2
#define BACK 3
	int playerChoise = optionsMenu();
	while (playerChoise != BACK) {
		switch (playerChoise) {
		case DIFFICULTY:
			break;
		case GAME_SPEED:
			break;
		case BACK:
			break;
		}
		playerChoise = optionsMenu();
	}
	return;
}

//Prints the Options menu for the user returns the option the user choose after hitting enter
int optionsMenu() {
	#define MIN_OPTION_MENU_OPTION 1
	#define MAX_OPTION_MENU_OPTION 3
	int arrowPosition = MIN_OPTION_MENU_OPTION;
	int keyPress = NULL;
	while (keyPress != ENTER_KEY) {
		printf("\t----    OPTIONS    ----\n\n");
		choiseArrow(1, arrowPosition); printf("Difficulty\n");
		choiseArrow(2, arrowPosition); printf("Game speed\n\n");
		choiseArrow(3, arrowPosition); printf("Back\n");
		keyPress = _getch();
		switch (keyPress) {
		case DOWN_ARROW:
			moveIndex(&arrowPosition, INDEX_MOVE_FORWARD, MIN_OPTION_MENU_OPTION, MAX_OPTION_MENU_OPTION);
			break;
		case UP_ARROW:
			moveIndex(&arrowPosition, INDEX_MOVE_BACKWARD, MIN_OPTION_MENU_OPTION, MAX_OPTION_MENU_OPTION);
			break;
		}
		system("cls");
	}
	return arrowPosition;
}

void gameSpeedMenuLogic(int* gamespeed) {
#define INSTANT 1
#define FAST 2
#define NORMAL 3
	int playerChoise = optionsMenu();
	while (playerChoise != BACK) {
		switch (playerChoise) {
		case INSTANT:
			*gamespeed = INSTANT_GAME_SPEED_NO_DELAY;
			break;
		case FAST:
			*gamespeed = FAST_GAME_SPEED_DELAY;
			break;
		case NORMAL:
			*gamespeed = DEFAULT_GAME_SPEED_DELAY;
			break;
		}
		playerChoise = optionsMenu();
	}
	return;
}


//prints an arrow in front of the option currently selected
void choiseArrow(int optionNum, int arrowPosition) {
	if (optionNum == arrowPosition)
		printf("\t======> ");
	else
		printf("\t\t");
}
//moves the index between the given numbers(farward/backwards), if the index passes a given number , it resets to the other end
void moveIndex(int* indexPosition, bool direction, int minIndex, int maxIndex) {
	switch (direction) {
	case INDEX_MOVE_FORWARD:
		if (*indexPosition < maxIndex)
			*indexPosition+=1;
		else
			*indexPosition = minIndex;
		break;
	case INDEX_MOVE_BACKWARD:
		if (*indexPosition > minIndex)
			*indexPosition-=1;
		else
			*indexPosition = maxIndex;
		break;
	}
	
}