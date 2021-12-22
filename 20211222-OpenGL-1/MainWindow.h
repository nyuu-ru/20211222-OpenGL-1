/*
 * MainWindow.h
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>

class MainWindow final: public Window
{
protected:
	double _angle { 0.0 };

	virtual void update() override;
	virtual void setup() override;
	virtual void render() override;

public:
	static constexpr int DEFAULT_WIDTH  = 3200;
	static constexpr int DEFAULT_HEIGHT = 1800;
public:
	MainWindow();
	virtual ~MainWindow() = default;
};

#endif /* MAINWINDOW_H_ */
