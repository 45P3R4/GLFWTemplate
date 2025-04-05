#include <stdio.h>
// glad
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>
// cglm
#include <cglm/mat4.h>
#include <cglm/cam.h>
#include <cglm/affine-mat.h>
#include <cglm/affine.h>

#include "shader.h"
#include "cube.h"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

void windowResizeCallback(GLFWwindow* window, int width, int height);

GLuint windowWidth = 800, windowHeight = 600;

mat4 perspective;
mat4 ortho;
mat4 view;
mat4 model;

int main()
{
    printf("Starting GLFW context, OpenGL 3.3\n");

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize OpenGL context");
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetWindowSizeCallback(window, windowResizeCallback);

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);  
    glViewport(0, 0, width, height);

    GLuint shaderProgram = createShaderProgram();
    glUseProgram(shaderProgram);

    
    GLint projectionLocation = glGetUniformLocation(shaderProgram, "projection");
    GLint viewLocation = glGetUniformLocation(shaderProgram, "view");
    GLint modelLocation = glGetUniformLocation(shaderProgram, "model");


    // matrix = prjection * view * model * local
    glm_mat4_identity(view);
    glm_mat4_identity(model);

    glm_translate(view, (vec3){0, 0, -3});
    glm_translate(model, (vec3){-0.5, -0.5, -0.5});

    glm_perspective(glm_rad(45.0f), (float)windowWidth/(float)windowHeight, 0.1f, 100.0f, perspective);
    glm_ortho(-2, 2, -2, 2, 0.1, 100, ortho);


    // Uncommenting this call will result in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    float angle = 0;
    initCube(shaderProgram);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_ALWAYS);

    // Game loop
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

    glDeleteBuffers(1, &EBO);
    glDeleteBuffers(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
 
void windowResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    glm_perspective(glm_rad(45.0f), (float)width/(float)height, 0.1f, 100.0f, perspective);
}

