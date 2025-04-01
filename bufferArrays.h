#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void generateBuffers(GLuint *VAO, GLuint *VBO, GLuint *EBO, GLfloat vertices[], size_t size_v, GLuint indices[], size_t size_i)
{
    glad_glGenVertexArrays(1, VAO);
    glad_glGenBuffers(1, VBO);
    glad_glGenBuffers(1, EBO);
    glad_glBindVertexArray(*VAO);

    glad_glBindBuffer(GL_ARRAY_BUFFER, *VBO);
    glad_glBufferData(GL_ARRAY_BUFFER, size_v, vertices, GL_STATIC_DRAW);

    glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *VBO);
    glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_i, indices, GL_STATIC_DRAW);

    glad_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glad_glEnableVertexAttribArray(0);

    glad_glBindBuffer(GL_ARRAY_BUFFER, 0);

    glad_glBindVertexArray(0);
}