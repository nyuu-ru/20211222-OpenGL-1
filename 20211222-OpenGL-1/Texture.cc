/*
 * Texture.cc
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <stdexcept>
#include <string>

Texture::Texture(const char *filename)
{
	auto pic1 = std::shared_ptr<SDL_Surface>(
			IMG_Load(filename),
			SDL_FreeSurface);
	if (pic1 == nullptr)
		throw std::runtime_error(
				std::string("Не могу загрузить текстуру: ") +
				std::string(SDL_GetError()));

	auto pic2 = std::shared_ptr<SDL_Surface>(
			SDL_CreateRGBSurfaceWithFormat(0, pic1->w, pic1->h, 32,
			                               SDL_PIXELFORMAT_ABGR8888),
			SDL_FreeSurface);
	SDL_UpperBlit(pic1.get(), nullptr, pic2.get(), nullptr);

	glGenTextures(1, &_name);
	bind();
	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA,
	                  pic2->w, pic2->h,
	                  GL_RGBA, GL_UNSIGNED_BYTE,
	                  pic2->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
	                GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
	                GL_LINEAR_MIPMAP_LINEAR);
}
