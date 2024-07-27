#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "module.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>


using namespace std;


#define numVAOs 1
#define numVBOs 2

float cameraX, cameraY, cameraZ;
float cubeLocX, cubeLocY, cubeLocz;
GLuint renderingProgram;
GLuint vao[numVAOs];
GLuint vbo[numVBOs];

//allocate variables used in display() function, so that they won't need to be allocated during rendering

GLuint mvLoc, projLoc;
int width, height;
float aspect;
glm::mat4 pMat, vMat, mMat, mvMat;

void setupVertices(void){
    float vertexPositions[108] = {
        -1.0f, -1.0f,  1.0f, // Triangle 1
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, // Triangle 2
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        // Back face
        -1.0f, -1.0f, -1.0f, // Triangle 1
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f, // Triangle 2
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,

        // Left face
        -1.0f, -1.0f, -1.0f, // Triangle 1
        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f, // Triangle 2
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,

        // Right face
         1.0f, -1.0f, -1.0f, // Triangle 1
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, // Triangle 2
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        // Top face
        -1.0f,  1.0f, -1.0f, // Triangle 1
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f, // Triangle 2
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        // Bottom face
        -1.0f, -1.0f, -1.0f, // Triangle 1
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f, // Triangle 2
        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f
    };

    glGenVertexArrays(1, vao);
    glBindVertexArray(vao[0]);
    glGenBuffers(numVBOs, vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
}


void init(GLFWwindow* window) {
    renderingProgram = createShaderProgram("shaders/default.vert", "shaders/default.frag");
    cameraX = 0.0f; cameraY = 0.0f; cameraZ = 8.0f;
    cubeLocX = 0.0f; cubeLocY = -2.0f; cubeLocZ = 0.0f;
    setupVertices();
}


void display(GLFWwindow* window, double currentTime) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    //need to init these each frame.
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(renderingProgram);


    //get the uniform variables for the MV and projection matrices
    mvLoc = glGetUniformLocation(renderingProgram, "mv_matrix")
    projLoc = glGetUniformLocation(renderingProgram, "proj_matrix")

    //build perspective matrix      
    glfwGetFramebufferSize(window, &width, &height);


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