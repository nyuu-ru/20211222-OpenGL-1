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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.5f, 0.7f, 1.f, 1.f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.0, double(width()) / double(height()),
	               0.1, 30.0);
	glMatrixMode(GL_MODELVIEW);
}

void MainWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(4.0, 3.0, 1.5,
	          0.0, 0.0, 0.0,
	          0.0, 0.0, 1.0);

	glRotated(_angle, 0.0, 0.0, 1.0);

	_house_texture.bind();
	_house.draw();

}

void MainWindow::update()
{
	_angle += 0.5;
	if (_angle >= 360.0)
		_angle -= 360.0;
}
