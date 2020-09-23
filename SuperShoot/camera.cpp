#include "camera.h"

Camera::Camera(GameWindow win, Shader shader) {

	view = glm::mat4(1.0f);
	proj = glm::perspective(glm::radians(80.0f), (float)win.getWidth() / win.getHeight(), 0.1f, 100.0f);

	shader.setMat4fv("view", view);
	shader.setMat4fv("proj", proj);

}

	