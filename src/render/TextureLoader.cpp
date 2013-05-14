/*
 * TextureLoader.cpp
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#include "TextureLoader.h"
#include <string>
#include "SDL_image.h"
#include "SDL_opengl.h"
using std::string;

SDL_Surface* loadImage(string fname)
{
	return IMG_Load(fname.c_str());
}

GLuint loadTexture(string fname)
{
	GLuint tex;
	SDL_Surface *surf = loadImage(fname);
	GLenum texFormat;
	GLint numCols;

	if (surf)
	{
		if ((surf->w & (surf->w - 1)) != 0)
		{
			return 0;
		}

		if ((surf->h & (surf->h - 1)) != 0)
		{
			return 0;
		}

		numCols = surf->format->BytesPerPixel;
		if (numCols == 4)
		{
			if (surf->format->Rmask == 0x000000ff)
				texFormat = GL_RGBA;
			else
				texFormat = GL_BGRA;
		}
		else if (numCols == 3)
		{
			if (surf->format->Rmask == 0x000000ff)
				texFormat = GL_RGB;
			else
				texFormat = GL_BGR;
		}
		else
		{
			return 0;
		}

		glGenTextures(1, &tex);
		glBindTexture(GL_TEXTURE_2D, tex);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, numCols, surf->w, surf->h, 0, texFormat, GL_UNSIGNED_BYTE, surf->pixels);

		return tex;
	}

	return 0;
}
