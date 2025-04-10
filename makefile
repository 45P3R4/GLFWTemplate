TARGET = glfw

SRCS = \
src/main.c \
src/shader.c \
src/cube.c \
src/render.c \
src/window.c \
thirdparty/glad.c \
thirdparty/stb_image.h \

HEADERS = \
src/shader.h \
src/cube.h \
src/texture.h \
src/render.h \
src/window.h \
src/bufferArrays.h \

SHADERS = shaders/vertex.glsl shaders/fragment.glsl
CFLAGS = -Wall -lglfw3 -lm

$(TARGET): $(SRCS) $(SHADERS) $(HEADERS)
	gcc $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS) $(SOURCES)
clean: 
	rm -f $(TARGET) 
