#include "shader.h"


GLuint createShaderProgram()
{
    const GLchar *vertexShaderSource = getSourceString("shaders/vertex.glsl");
    const GLchar *fragmentShaderSource = getSourceString("shaders/fragment.glsl");

    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
    }
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
    }
    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glad_glAttachShader(shaderProgram, vertexShader);
    glad_glAttachShader(shaderProgram, fragmentShader);
    glad_glLinkProgram(shaderProgram);
    // Check for linking errors
    glad_glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
    }
    glad_glDeleteShader(vertexShader);
    glad_glDeleteShader(fragmentShader);

    return shaderProgram;
}


char* getSourceString(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char* buffer = NULL;
    size_t buffer_size = 0;
    char line[1024]; 

    while (fgets(line, sizeof(line), file)) {
        size_t line_len = strlen(line);
        char* temp = realloc(buffer, buffer_size + line_len + 1);
        if (!temp) {
            perror("Memory reallocation failed");
            free(buffer);
            fclose(file);
            return NULL;
        }
        buffer = temp;
        strcpy(buffer + buffer_size, line);
        buffer_size += line_len;
    }

    fclose(file);
    return buffer;
}