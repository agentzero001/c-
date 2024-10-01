#version 430 core

in vec4 varyingColor;

out vec4 color;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

void main(void) {
    color = varyingColor;
}