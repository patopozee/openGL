        
//
// File:        cube.c
// Author:      Matt Daisley
// Created:     4/25/2012
// Project:     Source code for Make a Cube in OpenGL
// Description: Creates an OpenGL window and draws a 3D cube
//              That the user can rotate using the arrow keys
// 
// Controls:    Left Arrow  - Rotate Left
//              Right Arrow - Rotate Right
//              Up Arrow    - Rotate Up
//              Down Arrow  - Rotate Down     

// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
       #include <stdio.h>
       #include <stdarg.h>
       #include <math.h>
       #define GL_GLEXT_PROTOTYPES
       #ifdef __APPLE__
       #include <GLUT/glut.h>
       #else
       #include <GL/glut.h>
       #endif
	
	using namespace std;
	const int screenWidth = 640;
	const int screenHeight = 480;
	GLdouble A, B, C, D;
	void myInit(void)
	{
	glClearColor(1.0, 1.0, 1.0, 0.0); //background color
	glColor3f(0.0f, 0.0f, 0.0f); //drawing color black
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	A = screenWidth / 4.0;
	B = 0.0;
	C = D = screenHeight / 2.0;
	}
      	//viewing utility function
	void pilotView(float xtran, float ytran, float ztran, float xrot, float yrot, float zrot,float scale)
	{
	    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
            glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	    glRotatef(zrot, 0.0f, 0.0f, 1.0f);
            glTranslatef(xtran, ytran, ztran);
            glScalef(scale, scale, scale);
	    void polygonTop(void)
	{
	    glBegin(GL_POLYGON);
	    {
	         
	        glVertex3f(-1.0, 1.0, -1.0);
	        glVertex3f(-1.0, 1.0, 1.0);
	        glVertex3f(0.0, 1.0, 1.0);
	        glVertex3f(1.0, 1.0, 0.0);
	        glVertex3f(1.0, 1.0, -1.0);
	        glEnd();

	    }
	}

	 
	void polygonBottom(void)

	{
	    glBegin(GL_POLYGON);
	    {
	    glVertex3f(-1.0, -1.0, 1.0);
	    glVertex3f(-1.0, -1.0, -1.0);
	    glVertex3f(1.0, -1.0, -1.0);
	    glVertex3f(1.0, -1.0, 1.0);
	    glEnd();
	    }
	} 
	void polygonRight(void)
	{
        glBegin(GL_POLYGON);
        {
	 
	    glVertex3f(1.0, -1.0, -1.0);
	    glVertex3f(1.0, 1.0, -1.0);
	    glVertex3f(1.0, 1.0, 0.0);
	    glVertex3f(1.0, 0.0, 1.0);
	    glVertex3f(1.0, -1.0, 1.0);
	    glEnd();
	    }
	}
	 
	void polygonLeft(void)

	{
         glBegin(GL_POLYGON);
	    {

	    glVertex3f(-1.0, -1.0, 1.0);
	    glVertex3f(-1.0, 1.0, 1.0);
	    glVertex3f(-1.0, 1.0, -1.0);
	    glVertex3f(-1.0, -1.0, -1.0);
	    glEnd();
	    }
	}
	 
	 
	void polygonFront(void)
	{
	    glBegin(GL_POLYGON);
	    {
	    glVertex3f(1.0, -1.0, 1.0);
	    glVertex3f(1.0, 0.0, 1.0);
	    glVertex3f(0.0, 1.0, 1.0);
	    glVertex3f(-1.0, 1.0, 1.0);
	    glVertex3f(-1.0, -1.0, 1.0);
	 
	    glEnd();
	    }
	}
	 
	 
	void polygonBack(void)
	{
	    glBegin(GL_POLYGON);
	    {
	    glVertex3f(-1.0, -1.0, -1.0);
	    glVertex3f(-1.0, 1.0, -1.0);
	    glVertex3f(1.0, 1.0, -1.0);
	    glVertex3f(1.0, -1.0, -1.0);
	 
	    glEnd();
	    }
	}
	 
	void polygonCorner(void)
	{
	    glBegin(GL_POLYGON);
	    {
	    glVertex3f(1.0, 0.0, 1.0);
	    glVertex3f(1.0, 1.0, 0.0);
	    glVertex3f(0.0, 1.0, 1.0);
	 
	    glEnd();
	    }
	}
	 
	void myDisplay(void)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //CLEAR SCREEN
	glLoadIdentity();
	 
	polygonTop();
	polygonBottom();
	polygonRight();
	polygonLeft();
	polygonFront();
	polygonBack();
	polygonCorner();
	 
	//SingleView
	//pilotView(100.0f, 100.0f, 100.0f, -45.0f, 45.0f, 0.0f, 200.0f);
	 
	glFlush();
	}
	 
	int main(int argc, char* argv[])
	{
	glutInit(&argc, argv); //initialize toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("AnthonyR opengl project3");
	myInit();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(myDisplay);
	//glutSpecialFunc(specialKeys);
	glutMainLoop();
	}
