#version 330 core
out vec4 fragColor;

in vec3 ourColor;
uniform vec3 baseColor;
in vec2 uvCoord;

uniform sampler2D texture1;

void main(void)
{    
    fragColor = vec4(mix(ourColor, baseColor, 0.5), 1.0);
    fragColor *= texture2D(texture1, uvCoord);
}
