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

	glBegin(GL_TRIANGLES);
	glVertex2f(  0.0f,  0.8f);
	glVertex2f(  0.8f, -0.8f);
	glVertex2f( -0.8f, -0.8f);
	glEnd();
}
