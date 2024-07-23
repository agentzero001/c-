#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "module.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define numVAOs 1

GLuint renderingProgram;
GLuint vao[numVAOs];


void init(GLFWwindow* window) {
    renderingProgram = createShaderProgram("shaders/default.vert", "shaders/default.frag");
    //When sets of data are prepared for sending down the pipeline, they are organized into buffers.
    //Those buffers are in turn organized into Vertex Array Objects.
    glGenVertexArrays(numVAOs, vao);
    glBindVertexArray(vao[0]);
}

float x = 0.0f;
float y = 0.0f;
float inc = 0.01f;

void display(GLFWwindow* window, double currentTime) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    //need to init these each frame.
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(renderingProgram);
    
    x += inc;
    y += inc;
    if (x > 0.5f) inc = -0.00005f;
    if (x < 0.0f) inc =  0.00005f;
   
    
    GLuint offsetLoc = glGetUniformLocation(renderingProgram, "offset");
    GLuint offsetLoc2 = glGetUniformLocation(renderingProgram, "offset2");
    glProgramUniform1f(renderingProgram, offsetLoc, x);
    glProgramUniform1f(renderingProgram, offsetLoc2, y);
    
    //glLineWidth(30.0f);
    //glPointSize(30.0f);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

int main(void) {
    if (!glfwInit()) {exit(EXIT_FAILURE);}
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    GLFWwindow* window = glfwCreateWindow(600, 600, "program2", NULL, NULL);
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {exit(EXIT_FAILURE);}
    glfwSwapInterval(1);
    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);

}