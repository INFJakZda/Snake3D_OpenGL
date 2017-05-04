#include "main.h"

WINDOWMODE aspectWindow = FULL_WINDOW;	//Aspekt obrazu
GStatus gameStatus;					//Status gry
int playerScore;					//Ile punktów uzyska³ gracz

SDirection snakeMoveDirection;		//Kierunek, w któr¹ siê w¹¿ porusza
float snakePositionX;				//Pozycjê wê¿a, odpowiednio X,Y,Z
float snakePositionY;
float snakePositionZ;
int snakeTailLenght;				//Rozmiar 'ogona' wê¿a; pocz¹tkowa wartoœæ 0
float snakeTailPositionX[50];		//Pozycja 'ogona', odpowiednio X,Y. Z bêdzie ten sam co dla g³owy.
float snakeTailPositionY[50];

float fruitPositionX;				//Pozycjê jedzenia, odpowiednio X,Y,Z
float fruitPositionY;
float fruitPositionZ;


int main(int argc, char *argv[]) {
	
	initializeGLUT(&argc, argv);
	initializeGLEW();
	glutCreateMenu(menu);				//Utworzenie menu podrêcznego
	menuInit();
	glutAttachMenu(GLUT_RIGHT_BUTTON);	//Okreœlenie przycisku myszki obs³uguj¹cej menu podrêczne
	gameStatus = GNOREADY;

	glutMainLoop();					//Wprowadzenie programu do obs³ugi pêtli komunikatów
	
	return 0;
}