TARGET = glfw
SRCS = main.c thirdparty/glad.c shader.c cube.h stb_image.h texture.h
HEADERS = bufferArrays.h shader.h shaders/vertex.glsl shaders/fragment.glsl
CFLAGS = -Wall -lglfw3 -lm

$(TARGET): $(SRCS) $(HEADERS)
	gcc $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS) $(SOURCES)
clean: 
	rm -f $(TARGET) 
