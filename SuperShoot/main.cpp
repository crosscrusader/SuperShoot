#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "shader.h"
#include "window.h"
#include "mesh.h"
#include "camera.h"

#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/matrix_transform.hpp>
#include <glm/glm/gtc/type_ptr.hpp>
#include <vector>
#include <fstream>

int main() {
	// Create Window
	GameWindow win;
	glEnable(GL_DEPTH_TEST);

	// Create Shaders
	Shader shader("shaders/vshader.txt", "shaders/fshader.txt");
	shader.use();

	// Enable Wireframe mode
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	bool quit = false;
	glfwSwapInterval(1);

	std::ofstream output_file;
	output_file.open("log.txt");
	while (!quit) {
		
		// Take input
		if (glfwGetKey(win.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			quit = true;
		}

		if (glfwWindowShouldClose(win.getWindow())) {
			quit = true;
		}
;
		// Clear Screen
		glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.use();

		glfwSwapBuffers(win.getWindow()); // Swap Buffers
		glfwPollEvents(); // Get events

	}

	glfwTerminate();
	output_file.close();
}
