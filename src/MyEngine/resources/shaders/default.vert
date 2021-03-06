#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vColor;
layout (location = 2) in vec2 vUv;

uniform mat4 MVP;

out vec3 ourColor;
out vec2 uvCoord;

void main(void)
{
    gl_Position = MVP * vec4(vPos, 1.0);
    ourColor = vColor;
    uvCoord = vec2(vUv.x, -vUv.y);
};
