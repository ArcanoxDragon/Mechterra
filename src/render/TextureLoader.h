/*
 * TextureLoader.h
 *
 *  Created on: May 14, 2013
 *      Author: Brian
 */

#ifndef TEXTURELOADER_H_
#define TEXTURELOADER_H_

#include <string>
#include "SDL_image.h"
#include "SDL_opengl.h"
using std::string;

SDL_Surface* loadImage(string fname);
GLuint loadTexture(string fname);

#endif /* TEXTURELOADER_H_ */
