#ifndef SHADER
#define SHADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

char* getSourceString(const char* filename);

GLuint createShaderProgram();

#endif /* SHADER */