#version 330 core

out vec4 fragColor;
in vec3 ourColor;
uniform vec3 baseColor;

void main(void)
{    
    fragColor = vec4((ourColor + baseColor)*0.5, 1.0);
}
