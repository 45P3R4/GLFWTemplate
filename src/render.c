#include "render.h"
#include "cube.h"
#include "window.h"

#include <stdio.h>
#include <cglm/mat4.h>
#include <cglm/cam.h>
#include <cglm/affine-mat.h>
#include <cglm/affine.h>

int i = 0;

mat4 perspective;
mat4 ortho;
mat4 view;
mat4 model;

GLint projectionLocation;
GLint viewLocation;
GLint modelLocation;

float angle = 0;

void render_init(GLuint shaderProgram)
{
	
    projectionLocation = glGetUniformLocation(shaderProgram, "projection");
    viewLocation = glGetUniformLocation(shaderProgram, "view");
    modelLocation = glGetUniformLocation(shaderProgram, "model");

	glm_mat4_identity(view);
    glm_mat4_identity(model);

	glm_translate(view, (vec3){0, 0, -3});
    glm_translate(model, (vec3){-0.5, -0.5, -0.5});

    glm_perspective(glm_rad(45.0f), getAspectRatio(), 0.1f, 100.0f, perspective);
    glm_ortho(-2, 2, -2, 2, 0.1, 100, ortho);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);

	initCube(shaderProgram);
	
}

void render_loop(GLFWwindow* window)
{
	while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

        angle = 0.01;
        glm_rotate(view, angle, (vec3){1, 0.3, 0.1});
        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, perspective[0]);
        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, view[0]);
        glUniformMatrix4fv(modelLocation, 1, GL_FALSE, model[0]);
        
        // Draw
        drawCube();

        glfwSwapBuffers(window);
    }
}


void render(GLFWwindow* window, GLuint shaderProgram)
{
	render_init(shaderProgram);
	render_loop(window);
}