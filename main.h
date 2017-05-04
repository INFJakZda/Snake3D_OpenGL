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
enum SDirection { LEFT = 0, UP, RIGHT, DOWN };		//Do sterowania w�em
enum GStatus { GNOREADY, GREADY, GEND};				//Stan gry; 0 - jeszcze nie rozpocz�ta, 1 - rozgrywka, 2 - koniec
enum GameObjectTypes { NONE = 0, SNAKE, FOOD, BARRIER };
enum WINDOWMODE {FULL_WINDOW = 0, ASPECT_1_1, EXIT};	//Obszar renderingu: ca�e okno lub aspekt 1:1, wyj�cie z programu.

/* GLOBAL VARIABLES */
extern WINDOWMODE aspectWindow;				//Aspekt obrazu
extern GStatus gameStatus;					//Status gry
extern int playerScore;						//Ile punkt�w uzyska� gracz
extern SDirection snakeMoveDirection;		//Kierunek, w kt�r� si� w�� porusza
extern float snakePositionX;				//Pozycj� w�a, odpowiednio X,Y,Z
extern float snakePositionY;
extern float snakePositionZ;
extern int snakeTailLenght;					//Rozmiar 'ogona' w�a; pocz�tkowa warto�� 0
extern float snakeTailPositionX[50];		//Pozycja 'ogona', odpowiednio X,Y. Z b�dzie ten sam co dla g�owy.
extern float snakeTailPositionY[50];

extern float fruitPositionX;				//Pozycj� jedzenia, odpowiednio X,Y,Z
extern float fruitPositionY;
extern float fruitPositionZ;


/* FUNCTIONS */
void displayFrame();							/* Funckja rysuj�ca okno */
void reshapeFrame(int width, int height);		/* Zmiana wielko�ci okna */
void initializeGLUT(int *pargc, char **argv);	/* Funckja inicjalizuj�ca bibliotek� FreeGLUT */
void initializeGLEW();							/* Funkcja inicjalizuj�ca bibliotek� GLEW */
void menu(int value);							/* Funckja odpowiedzialna za menu podr�czne */
void menuInit();								/* Funkcja inicjalizuj�ca pozycje menu */

#endif