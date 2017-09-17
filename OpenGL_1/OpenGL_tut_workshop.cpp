#include "stdafx.h"

#include <stdio.h>
#include <GL/glut.h>


void tut_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutSwapBuffers();
}

void tut_reshape(int w, int h)
{
	glViewport(0, 0, w, h);	// lower left coords, width, height (where OpenGL should draw)
}

void initOpenGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);	// Background color: RGBA
}

int OpenGL_tut_workshop_main(int argc, char** argv)
{
	//  start up freeglut
	glutInit(&argc, argv);
	// Double buffering | RGBA colour space | Depth (3D rather than 2D)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hello OpenGL");

	initOpenGL();

	glutDisplayFunc(tut_display);
	glutIdleFunc(tut_display);
	glutReshapeFunc(tut_reshape);

	glutMainLoop();

	return 0;
}
