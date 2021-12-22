/*
 * MainWindow.cc
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#include "MainWindow.h"

MainWindow::MainWindow()
: Window(DEFAULT_WIDTH, DEFAULT_HEIGHT)
{
}

void MainWindow::setup()
{
	glClearColor(0.5f, 0.7f, 1.f, 1.f);
}

void MainWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, 0.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.7f, 0.2f);
	glVertex2f(  0.0f,  0.8f);
	glColor3f(0.0f, 0.0f, 0.5f);
	glVertex2f(  0.8f, -0.8f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f( -0.8f, -0.8f);
	glEnd();

}
