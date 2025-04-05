#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D modelTexture;

out vec4 color;

void main()
{
    color = texture(modelTexture, TexCoord) * vec4(vertexColor, 1.0f);
    // color = vec4(vertexColor, 1.0);
}
