#include "main.h"

/* Funckja inicjalizuj�ca bibliotek� FreeGLUT */
void initializeGLUT(int *pargc, char **argv) {
	glutInit(pargc, argv);							//Inicjalizacja biblioteki GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//Inicjalizacja bufora ramki
	glutInitWindowSize(500, 500);					//Rozmiary g��wnego okna programu
	glutCreateWindow("Snake3dOpenGl");				//Utworzenie g��wnego okna programu
	glutDisplayFunc(&displayFrame);						//Do��czenie funkcji generuj�cej scen� 3D
	glutReshapeFunc(&reshapeFrame);						//Do��czenie funkcji wywo�ywanej przy zmianie rozmiaru okna
}

/* Funkcja inicjalizuj�ca bibliotek� GLEW */
void initializeGLEW() {
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		/* Problem: Nie uda�o si� zainicjowa� biblioteki GLEW */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(1);
	}
#define TEST_GLEW_VERSION
#ifdef TEST_GLEW_VERSION
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
#endif // TEST_GLEW_VERSION
}

/* Funckja rysuj�ca okno */
void displayFrame() {	
	glClearColor(0.0, 0.4, 0.8, 1.0);							//Kolor t�a - zawarto�� bufora koloru
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//Czyszczenie bufora koloru
	glutSwapBuffers();											//Zamiana bufor�w koloru
}

/* Zmiana wielko�ci okna */
void reshapeFrame(int width, int height) {
#define RESHARPE_PRINT_SIZE
#ifdef RESHARPE_PRINT_SIZE
	std::cout << "width: " << width << " height: " << height << std::endl;
#endif // RESHARPE_PRINT_SIZE
	if (aspectWindow == ASPECT_1_1) {
		//Szeroko�� okna wi�ksza od wysoko�ci okna
		if (width > height) {
			glViewport((width - height) / 2, 0, (GLsizei)height, (GLsizei)height);
		}
		else {
		//Wysoko�� okna wi�ksza od wysoko�ci okna
			if (width < height) {
				glViewport(0, (height - width) / 2, (GLsizei)width, (GLsizei)width);
			}
		}
	}
	//Obszar renderingu - ca�e okno (tak�e, gdy aspekt wynosi 1:1)
	else {
		glViewport(0, 0, width, height);
	}
	displayFrame();
}

//Obsu�ga menu podr�cznego
void menu(int value) {
	switch (value) {
	//Obszar renderingu - ca�e okno
	case FULL_WINDOW:
		aspectWindow = FULL_WINDOW;
		reshapeFrame(glutGet(GLUT_WINDOW_WIDTH),glutGet(GLUT_WINDOW_HEIGHT));
		break;
	//Obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspectWindow = ASPECT_1_1;
		reshapeFrame(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	//Wyj�cie z programu
	case EXIT:
		exit(0);
	}
}

/* Funkcja inicjalizuj�ca pozycje menu */
void menuInit() {
	glutAddMenuEntry("Obszar renderingu - cale okno", FULL_WINDOW);
	glutAddMenuEntry("Obszar renderingu - aspekt 1:1", ASPECT_1_1);
	glutAddMenuEntry("Wyjscie", EXIT);
}