#ifndef WINDOW
#define WINDOW

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* init_window();
// void render(GLFWwindow* window);

void set_render_callback(void *func);
float getAspectRatio();

void terminate();

#endif /* WINDOW */
