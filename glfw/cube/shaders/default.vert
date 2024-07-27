#version 430 core


void main(void) {
    if (gl_VertexID == 0) gl_Position = vec4(vertex_pos + offset, -vertex_pos - offset, 0.0, 1.0);
    else if (gl_VertexID == 1) gl_Position = vec4(-vertex_pos - offset, -vertex_pos - offset, 0.0, 1.0);
    else gl_Position = vec4(0.0, vertex_pos + offset, 0.0, 1.0);
}