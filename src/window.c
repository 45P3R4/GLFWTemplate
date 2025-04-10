#include "window.h"

#include <stdio.h>

#include <cglm/mat4.h>
#include <cglm/cam.h>
#include <cglm/affine-mat.h>
#include <cglm/affine.h>

#include "utils.h"
#include "input.h"
#include "render.h"
#include "shader.h"

GLFWwindow* mainWindow;

int window_width = 800;
int window_height = 600;


void error_callback(int error, const char* description)
{
	printerr(description);
}

 
void windowResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

float getAspectRatio()
{
	return (float)window_width/(float)window_height;
}

GLFWwindow* init_window()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	printf("Starting GLFW context, OpenGL 3.3\n");

	GLFWwindow* mainWindow = glfwCreateWindow(window_width, window_height, "OpenGL", NULL, NULL);

    glfwMakeContextCurrent(mainWindow);

	glfwSetErrorCallback(error_callback);
	glfwSetKeyCallback(mainWindow, key_callback);
    glfwSetWindowSizeCallback(mainWindow, windowResizeCallback);
	// glfwSetWindowRefreshCallback(mainWindow, render_loop);
	
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
		printerr("Failed to initialize OpenGL context\n");
        return NULL;
    }
	
    glfwGetFramebufferSize(mainWindow, &window_width, &window_height);
    glViewport(0, 0, window_width, window_height);

	// GLuint shaderProgram = createShaderProgram();
    // glUseProgram(shaderProgram);
    
    // render_init(shaderProgram);
	// render_loop(mainWindow);

	return mainWindow;
}

void terminate()
{
	glfwTerminate();
}