#ifndef MESH_H
#define MESH_H

#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "shader.h"

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <vector>

class Cube {
private:
	unsigned int VBO, VAO;
	unsigned int EBO;

	float vertices[24] = {
	0.5f, 0.5f, 0.5f, // 0
	-0.5f, 0.5f, 0.5f, // 1
	-0.5f, -0.5f, 0.5f, // 2
	0.5f, -0.5f, 0.5f, // 3

	0.5f, 0.5f, -0.5f, // 4
	-0.5f, 0.5f, -0.5f, // 5
	-0.5f, -0.5f, -0.5f, // 6
	0.5f, -0.5f, -0.5f, // 7
	};

	int indices[36]{
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		3, 2, 6,
		6, 7, 3,

		0, 1, 5,
		5, 4, 0,

		0, 3, 4,
		4, 7, 3,

		2, 1, 5,
		5, 6, 2,

	};

public:

	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	
	Cube(Shader& s);

	void bindBuffers();

	void assignAttrib();

	void draw();

	void transModel(Shader& s, glm::vec3 translate);

	void translate(Shader& s, glm::vec3 translate);

	void rotate(Shader& s, float degree, glm::vec3 vector);

};

#endif