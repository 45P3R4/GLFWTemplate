TARGET = glfw
SRCS = main.c thirdparty/glad/src/glad.c
# HEADERS = input.h camera.h deMath.h draw.h player.h global.h
# SOURCES = thirdparty/glad/src/glad.c
INCLUDES = -Ithirdparty\glfw\include -Ithirdparty\glad\include
LIBRARIES = -lmingw32 -lopengl32 -lglu32 -lglfw3
CFLAGS = -Wall $(INCLUDES) $(LIBRARIES) -mwindows  -g -mconsole
LIBS = -Lthirdparty\glad\lib -Lthirdparty\glfw\lib
$(TARGET): $(SRCS) $(HEADERS)
	gcc $(SRCS) -o $(TARGET) $(CFLAGS) $(LIBS) $(SOURCES)
clean: 
	rm -f $(TARGET) 