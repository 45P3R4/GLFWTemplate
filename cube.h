#ifndef CUBE
#define CUBE

#define STB_IMAGE_IMPLEMENTATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cglm/mat4.h>

#include "texture.h"

const GLfloat vertices[] = {

//  position     color       texcoord
//front
/*0*/ 1, 1, 0,    1, 1, 1,    1, 1,
/*1*/ 1, 0, 0,    1, 1, 1,    1, 0,
/*2*/ 0, 0, 0,    1, 1, 1,    0, 0,
/*3*/ 0, 1, 0,    1, 1, 1,    0, 1,
//left
/*4*/ 0, 1, 0,    1, 1, 1,    1, 1,
/*5*/ 0, 0, 0,    1, 1, 1,    1, 0,
/*6*/ 0, 0, 1,    1, 1, 1,    0, 0,
/*7*/ 0, 1, 1,    1, 1, 1,    0, 1,
//back
/*8*/ 0, 1, 1,    1, 1, 1,    1, 1,
/*9*/ 0, 0, 1,    1, 1, 1,    1, 0,
/*10*/1, 0, 1,    1, 1, 1,    0, 0,
/*11*/1, 1, 1,    1, 1, 1,    0, 1,
//right
/*12*/1, 1, 1,    1, 1, 1,    1, 1,
/*13*/1, 0, 1,    1, 1, 1,    1, 0,
/*14*/1, 0, 0,    1, 1, 1,    0, 0,
/*15*/1, 1, 0,    1, 1, 1,    0, 1,
//top
/*16*/1, 1, 1,    1, 1, 1,    1, 1,
/*17*/1, 1, 0,    1, 1, 1,    1, 0,
/*18*/0, 1, 0,    1, 1, 1,    0, 0,
/*19*/0, 1, 1,    1, 1, 1,    0, 1,
//bottom
/*20*/1, 0, 0,    1, 1, 1,    1, 1,
/*21*/1, 0, 1,    1, 1, 1,    1, 0,
/*22*/0, 0, 1,    1, 1, 1,    0, 0,
/*23*/0, 0, 0,    1, 1, 1,    0, 1,
};

const GLuint indices[] = {
   0, 1, 3, //front
   1, 2, 3,

   4, 5, 7, //left
   5, 6, 7,

   8, 9, 11, //back
   9, 10, 11,

   12, 13, 15, // right
   13, 14, 15,

   16, 17, 19, //up
   17, 18, 19,

   20, 21, 23, //down
   21, 22, 23
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

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    texture = loadTexture("textures/test.png");

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

}

void drawCube()
{
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

#endif /* CUBE */
