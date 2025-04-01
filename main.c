#include <stdio.h>
#include <glad/glad.h>
// GLFW
#include <GLFW/glfw3.h>

#include "shader.h"

#include <cglm/mat4.h>

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

GLfloat vertices[] = {
    0.5f,  0.5f, 0.0f,  // Top Right
    0.5f,  0.0f, 0.0f,  // Bottom Right
    0.0f,  0.0f, 0.0f,  // Bottom Left
    0.0f,  0.5f, 0.0f   // Top Left 
};
GLuint indices[] = {  // Note that we start from 0!
   0, 1, 3,  // First Triangle
   1, 2, 3   // Second Triangle
};

GLuint VBO, VAO, EBO;

void init()
{
    //VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //VBO
    glGenBuffers(1, &VBO); //generate 1 buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copy data to buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0); // set vertices attrib
    glEnableVertexAttribArray(0);

}

void display()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}


int main()
{
    printf("Starting GLFW context, OpenGL 3.3\n");

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize OpenGL context");
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    // Define the viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);  
    glViewport(0, 0, width, height);
    
    init();

    GLuint shaderProgram = createShaderProgram();
    glUseProgram(shaderProgram);


    mat4 matrix;
    glm_mat4_identity(matrix);
    GLint transformLocation = glGetUniformLocation(shaderProgram, "transform");

    // Uncommenting this call will result in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Game loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        matrix[0][3] += 0.1;
        glUniformMatrix4fv(transformLocation, 1, GL_FALSE, matrix[0]);
        
        // Draw
        display();

        glfwSwapBuffers(window);
    }

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

