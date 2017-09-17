#include "stdafx.h"

#include <stdio.h>
#include <GL/glut.h>

// Based on: https://www.youtube.com/watch?v=_OAYRV5fjuE


float counter = 0.0;	// For spinning triangles


void tut_display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Begining of frame (overwrites last frame)
	{
		counter += 1;	// Rotates based on frame counts
		if (counter > 420)
		{
			counter = -420.0;
		}

		// 1st triangle
		glLoadIdentity();	// Resets rotation, so it won't spin, just be rotated, but still.
		// Translate before rotate, if you want it to rotate around its own axis, and not around the creation point.
		glTranslatef(-counter / 300, 0.0, 0.0);		// Move by x, y, z
		glRotatef(counter, 0.0, 1.0, 0.0);	// Rotates the object. Degrees, around vectX, vectY, vectZ
		glBegin(GL_TRIANGLES);
			glColor3f(0.0, 1.0, 0.0);		// Color, 3D in floats
			glVertex3f(-0.5, -0.5, 0.0);	// Create a geometrix point
			glColor3f(0.0, 0.0, 1.0);		// Color, 3D in floats
			glVertex3f(0.0, 0.5, 0.0);		// Create a geometrix point
			glColor3f(1.0, 1.0, 0.0);		// Color, 3D in floats
			glVertex3f(0.5, -0.5, 0.0);		// Create a geometrix point
		glEnd();

		// 2nd triangle
		glLoadIdentity();	// Resets rotation, so it won't spin, just be rotated, but still.
		glTranslatef(counter/200, 0.0, 0.0);		// Move by x, y, z
		glRotatef(25, 0.0, 1.0, 0.0);	// Rotates the object. Degrees, around vectX, vectY, vectZ
		glBegin(GL_TRIANGLES);
			glColor3f(1.0, 0.0, 0.0);		// Color, 3D in floats
			glVertex3f(-0.25, 0.0, 0.0);	// Create a geometrix point

			glColor3f(0.0, 1.0, 0.0);		// Color, 3D in floats
			glVertex3f(0.0, 0.5, -0.9);		// Create a geometrix point

			glColor3f(0.0, 0.0, 1.0);		// Color, 3D in floats
			glVertex3f(0.25, 0.0, 0.0);		// Create a geometrix point
		glEnd();
	}
	glutSwapBuffers();	// End of frame (writes new frame)
}

void tut_reshape(int w, int h)
{
	// Makes it such that it scales with screen size as well.
	glViewport(0, 0, w, h);	// lower left coords, width, height (where OpenGL should draw)
}

void initOpenGL()
{
	glClearColor(1.0, 0.0, 0.0, 1.0);	// Background color: RGBA
	glEnable(GL_DEPTH_TEST);	// Enable depth information (for proper 3D)
	glDepthFunc(GL_LEQUAL);		// How to compare depths (Less or equals to)
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
