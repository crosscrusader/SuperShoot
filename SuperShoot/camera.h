#ifndef CAMERA_H
#define CAMERA_H

#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "shader.h"
#include "window.h"

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <vector>

class Camera {
public:

	glm::mat4 view;
	glm::mat4 proj;

	Camera(GameWindow win, Shader shader);
};

#endif // !CAMERA_H



