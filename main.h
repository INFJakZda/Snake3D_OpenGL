#pragma once
#ifndef _MAIN_H
#define _MAIN_H

/* INCLUDE FILES */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "GL\glew.h"
#include "GL\glut.h"
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

/* DEFINE */
#define FRUITVALUE 5

/* ENUMS */
enum SDirection { LEFT = 0, UP, RIGHT, DOWN };		//Do sterowania wê¿em
enum GStatus { GNOREADY, GREADY, GEND};				//Stan gry; 0 - jeszcze nie rozpoczêta, 1 - rozgrywka, 2 - koniec
enum GameObjectTypes { NONE = 0, SNAKE, FOOD, BARRIER };
enum WINDOWMODE {FULL_WINDOW = 0, ASPECT_1_1, EXIT};	//Obszar renderingu: ca³e okno lub aspekt 1:1, wyjœcie z programu.

/* GLOBAL VARIABLES */
extern WINDOWMODE aspectWindow;				//Aspekt obrazu
extern GStatus gameStatus;					//Status gry
extern int playerScore;						//Ile punktów uzyska³ gracz
extern SDirection snakeMoveDirection;		//Kierunek, w któr¹ siê w¹¿ porusza
extern float snakePositionX;				//Pozycjê wê¿a, odpowiednio X,Y,Z
extern float snakePositionY;
extern float snakePositionZ;
extern int snakeTailLenght;					//Rozmiar 'ogona' wê¿a; pocz¹tkowa wartoœæ 0
extern float snakeTailPositionX[50];		//Pozycja 'ogona', odpowiednio X,Y. Z bêdzie ten sam co dla g³owy.
extern float snakeTailPositionY[50];

extern float fruitPositionX;				//Pozycjê jedzenia, odpowiednio X,Y,Z
extern float fruitPositionY;
extern float fruitPositionZ;


/* FUNCTIONS */
void displayFrame();							/* Funckja rysuj¹ca okno */
void reshapeFrame(int width, int height);		/* Zmiana wielkoœci okna */
void initializeGLUT(int *pargc, char **argv);	/* Funckja inicjalizuj¹ca bibliotekê FreeGLUT */
void initializeGLEW();							/* Funkcja inicjalizuj¹ca bibliotekê GLEW */
void menu(int value);							/* Funckja odpowiedzialna za menu podrêczne */
void menuInit();								/* Funkcja inicjalizuj¹ca pozycje menu */

#endif