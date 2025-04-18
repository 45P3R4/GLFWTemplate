#version 330 core

out vec4 color;

float zNear = 0.1; 
float zFar  = 1.0; 

float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; 
    return (2.0 * zNear * zFar) / (zFar + zNear - z * (zFar - zNear));	
}

void main()
{
    float depth = LinearizeDepth(gl_FragCoord.z) / zFar;
    color = vec4(vec3(depth), 1.0);
}
