#include "texture.h"

Texture::Texture(const char * path) {
	data = stbi_load(path, &width, &height, &nrChannels, 0);
	LoadTexture();
}


void Texture::LoadTexture() {
	glGenTextures(1, &texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	if (data) {
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	}
	else {
		std::cout << "Failed to load texture. " << std::endl;
	}
	
	glGenerateMipmap(GL_TEXTURE_2D);

}

void Texture::BindTexture() {
	 
}