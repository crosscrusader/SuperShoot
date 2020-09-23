#include "mesh.h"

Cube::Cube(Shader& s) {
	s.setMat4fv("model", model);
	s.setMat4fv("trans", model);
	bindBuffers();
	assignAttrib();
}


void Cube::bindBuffers() {
	// Generate vertex arrays and VBOs
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Bind VAOs and VBOs
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Generate and bind EBO
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

}

void Cube::assignAttrib() {
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Cube::draw() {
	glBindVertexArray(VAO);

	// Draw Triangles
	glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
	// glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Cube::transModel(Shader& s, glm::vec3 translate) {
	model = glm::translate(model, translate);
	s.setMat4fv("model", model);
}

void Cube::translate(Shader& s, glm::vec3 translate) {
	trans = glm::translate(trans, translate);
	s.setMat4fv("trans", trans);
}

void Cube::rotate(Shader& s, float degree, glm::vec3 vector) {
	trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, degree, vector);
	s.setMat4fv("trans", trans);
}