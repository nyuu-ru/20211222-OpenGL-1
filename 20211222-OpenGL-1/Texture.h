/*
 * Texture.h
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture
{
protected:
	GLuint _name {};
public:
	Texture(const char *filename);
	virtual ~Texture() = default;

	void bind() { glBindTexture(GL_TEXTURE_2D, _name); }
};

#endif /* TEXTURE_H_ */
