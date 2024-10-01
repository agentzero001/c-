#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H
#include <GL/glew.h>  
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <tuple>
#include <stack>



void printShaderLog(GLuint shader);
void printProgramLog(int prog);
bool CheckOpenGLError();
std::string readShaderSource(const char *filePath);
GLuint createShaderProgram(const char *vp, const char *fp);
std::stack<glm::mat4> mvStack;

// Function prototype for display_model
void display_model(int scalefactor,
                   std::tuple<glm::vec3, int> rotate,
                   std::tuple<glm::vec3, int> translate);

#endif 