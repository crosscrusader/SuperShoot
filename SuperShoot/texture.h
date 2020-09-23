#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <iostream>
#include "stb_image.h"

class Texture {
private:
	unsigned int texture;
	unsigned char* data = nullptr;

	int width;
	int height;
	int nrChannels;

public:
	inline Texture(const char * path);
	inline void LoadTexture();
	inline void BindTexture();
};


#endif // !TEXTURE_H
