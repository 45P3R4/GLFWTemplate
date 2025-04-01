TARGET = glfw
SRCS = main.c glad.c shader.c
HEADERS = bufferArrays.h shader.h shaders/vertex.glsl shaders/fragment.glsl
CFLAGS = -Wall -lglfw3 -lm

$(TARGET): $(SRCS) $(HEADERS)
	gcc $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS) $(SOURCES)
clean: 
	rm -f $(TARGET) 
