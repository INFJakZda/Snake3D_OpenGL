#include "main.h"

/* Funckja inicjalizuj¹ca bibliotekê FreeGLUT */
void initializeGLUT(int *pargc, char **argv) {
	glutInit(pargc, argv);							//Inicjalizacja biblioteki GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//Inicjalizacja bufora ramki
	glutInitWindowSize(500, 500);					//Rozmiary g³ównego okna programu
	glutCreateWindow("Snake3dOpenGl");				//Utworzenie g³ównego okna programu
	glutDisplayFunc(&displayFrame);						//Do³¹czenie funkcji generuj¹cej scenê 3D
	glutReshapeFunc(&reshapeFrame);						//Do³¹czenie funkcji wywo³ywanej przy zmianie rozmiaru okna
}

/* Funkcja inicjalizuj¹ca bibliotekê GLEW */
void initializeGLEW() {
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		/* Problem: Nie uda³o siê zainicjowaæ biblioteki GLEW */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
	}
#define TEST_GLEW_VERSION
#ifdef TEST_GLEW_VERSION
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
#endif // TEST_GLEW_VERSION
}

/* Funckja rysuj¹ca okno */
void displayFrame() {	
	glClearColor(0.0, 0.4, 0.8, 1.0);							//Kolor t³a - zawartoœæ bufora koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//Czyszczenie bufora koloru
	glutSwapBuffers();											//Zamiana buforów koloru
}

/* Zmiana wielkoœci okna */
void reshapeFrame(int width, int height) {
#define RESHARPE_PRINT_SIZE
#ifdef RESHARPE_PRINT_SIZE
	std::cout << "width: " << width << " height: " << height << std::endl;
#endif // RESHARPE_PRINT_SIZE
	if (aspectWindow == ASPECT_1_1) {
		//Szerokoœæ okna wiêksza od wysokoœci okna
		if (width > height) {
			glViewport((width - height) / 2, 0, (GLsizei)height, (GLsizei)height);
		}
		else {
		//Wysokoœæ okna wiêksza od wysokoœci okna
			if (width < height) {
				glViewport(0, (height - width) / 2, (GLsizei)width, (GLsizei)width);
			}
		}
	}
	//Obszar renderingu - ca³e okno (tak¿e, gdy aspekt wynosi 1:1)
	else {
		glViewport(0, 0, width, height);
	}
	displayFrame();
}

//Obsu³ga menu podrêcznego
void menu(int value) {
	switch (value) {
	//Obszar renderingu - ca³e okno
	case FULL_WINDOW:
		aspectWindow = FULL_WINDOW;
		reshapeFrame(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
		break;
	//Obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspectWindow = ASPECT_1_1;
		reshapeFrame(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	//Wyjœcie z programu
	case EXIT:
		exit(0);
	}
}

/* Funkcja inicjalizuj¹ca pozycje menu */
void menuInit() {
	glutAddMenuEntry("Obszar renderingu - cale okno", FULL_WINDOW);
	glutAddMenuEntry("Obszar renderingu - aspekt 1:1", ASPECT_1_1);
	glutAddMenuEntry("Wyjscie", EXIT);
}