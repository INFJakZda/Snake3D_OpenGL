#include "main.h"

WINDOWMODE aspectWindow = FULL_WINDOW;	//Aspekt obrazu
GStatus gameStatus;					//Status gry
int playerScore;					//Ile punkt�w uzyska� gracz

SDirection snakeMoveDirection;		//Kierunek, w kt�r� si� w�� porusza
float snakePositionX;				//Pozycj� w�a, odpowiednio X,Y,Z
float snakePositionY;
float snakePositionZ;
int snakeTailLenght;				//Rozmiar 'ogona' w�a; pocz�tkowa warto�� 0
float snakeTailPositionX[50];		//Pozycja 'ogona', odpowiednio X,Y. Z b�dzie ten sam co dla g�owy.
float snakeTailPositionY[50];

float fruitPositionX;				//Pozycj� jedzenia, odpowiednio X,Y,Z
float fruitPositionY;
float fruitPositionZ;


int main(int argc, char *argv[]) {
	
	initializeGLUT(&argc, argv);
	initializeGLEW();
	glutCreateMenu(menu);				//Utworzenie menu podr�cznego
	menuInit();
	glutAttachMenu(GLUT_RIGHT_BUTTON);	//Okre�lenie przycisku myszki obs�uguj�cej menu podr�czne
	gameStatus = GNOREADY;

	glutMainLoop();					//Wprowadzenie programu do obs�ugi p�tli komunikat�w
	
	return 0;
}