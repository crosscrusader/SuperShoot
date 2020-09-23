#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}



class GameWindow {
	
private:
	GLFWwindow* window;
	const int HEIGHT = 600;
	const int WIDTH = 800;

public:
	


	GameWindow(){
		glfwInit();
		
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "Super Shoot", NULL, NULL);

		if (window == NULL) {
			std::cout << "Failed to create window!" << std::endl;
			glfwTerminate();
		}

		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}

		// Set viewport
		glViewport(0, 0, 800, 600);

		// Enable depth testing
		glEnable(GL_DEPTH_TEST);
	}

	GLFWwindow * getWindow() {
		// Returns pointer to window
		return window;
	}

	int getHeight() {
		return HEIGHT;
	}

	int getWidth() {
		return WIDTH;
	}
};

#endif