#include "stdafx.h"

#include "OpenGL_file_1.h"

#include <GL/freeglut.h>
#include <iostream>	// For exit(0);

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// First method. Clears the screen of all previous drawings.
	glBegin(GL_TRIANGLES);
	// 2 - 2D
	// 3 - 3D
	// 4 - 4D
	// f - float
	// i - integer
	// d - double
	// glVertex234fid
	glColor3f(1, 0, 0);	// r, g, b
	glVertex2f(-0.5, 0);
	glColor3f(0, 1, 0);
	glVertex2f(0.5, -0.5);
	glColor3f(0, 0, 1);
	glVertex2f(0.0, 0.5);
	glEnd();
	glutSwapBuffers();	// Last method. Sends what has been made to rendering or something.
}



void keyboard(unsigned char c, int x, int y)
{
	if (c == 27)	// Esc
	{
		exit(0);	// Close application
	}
}


void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON)	// Right click
	{
		exit(0);	// Close application
	}
}


int OpenGL_main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Simple GLUT Application");

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}
