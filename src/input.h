#ifndef INPUT
#define INPUT

#include <GLFW/glfw3.h>

enum {
	ACTION_UP,
	ACTION_DOWN,
	ACTION_LEFT,
	ACTION_RIGHT,
	ACTION_JUMP,
	ACTION_CROUCH,
	ACTION_FIRE
};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

#endif /* INPUT */
