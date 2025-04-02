#ifndef CUBE
#define CUBE

#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/mat4.h>

#include "texture.h"

const GLfloat vertices[] = {
//  position     color       texcoord
/*0*/1, 1, 0,    0, 0, 0,    1, 1,   //    5_________7       //
/*1*/1, 0, 0,    1, 1, 0,    1, 0,   //   I\        I\       //
/*2*/0, 0, 0,    1, 1, 0,    0, 0,   //   I  \ 3____I__\ 0   //
/*3*/0, 1, 0,    0, 0, 0,    0, 1,   //   I___I_____I  I     //
/*4*/0, 0, 1,    0, 1, 0,    1, 1,   //   4\  I      6 I     //
/*5*/0, 1, 1,    0, 0, 0,    1, 0,   //      \I________I     //
/*6*/1, 0, 1,    1, 1, 0,    0, 0,   //       2         1    //
/*7*/1, 1, 1,    1, 0, 0,    0, 1    //                      //
};

const GLuint indices[] = {
   0, 1, 3,
   1, 2, 3,
   3, 2, 5,
   2, 4, 5,
   5, 4, 7,
   4, 6, 7,
   7, 6, 0,
   6, 1, 0,
   7, 0, 5,
   0, 3, 5,
   6, 1, 4,
   1, 2, 4
};

GLuint VBO, VAO, EBO;

unsigned int texture;



void initCube(GLuint shaderProgram )
{
    //VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //copy data to buffer
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0); // set vertices attrib
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    texture = loadTexture("textures/test.png");

}

void drawCube()
{
    glActiveTexture(GL_TEXTURE0);  // Активируем слот 0
    glBindTexture(GL_TEXTURE_2D, texture); // Привязываем текстуру
    glDrawElements(GL_TRIANGLES, 32, GL_UNSIGNED_INT, 0);
    
}

#endif /* CUBE */
