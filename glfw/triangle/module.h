#ifndef SHADER_UTILS_H
#define SHADER_UTILS_H
#include <GL/glew.h>  
#include <GLFW/glfw3.h>
#include <SOIL2/SOIL2.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>



void printShaderLog(GLuint shader);
void printProgramLog(int prog);
bool CheckOpenGLError();
std::string readShaderSource(const char* filePath);
GLuint createShaderProgram();
GLuint loadTexture(const char* texImagePath);

#endif 