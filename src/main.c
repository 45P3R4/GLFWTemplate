#include <stdio.h>

#include "shader.h"
#include "render.h"
#include "window.h"

int main()
{
    GLFWwindow* window = init_window();

    GLuint shaderProgram = createShaderProgram();
    glUseProgram(shaderProgram);

    render(window, shaderProgram);

    glfwTerminate();
    return 0;
}

