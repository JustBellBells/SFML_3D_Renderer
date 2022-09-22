#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int width, int height, float frame)
{
    this->frame = frame;
    this->translationMatrix = glm::translate(glm::mat4(), glm::vec3(0.f, 0.f, 0.f));
    // glm::mat4 scalingMatrix  = glm::scale(2.0f, 2.0f ,2.0f);
    this->rotationX = {1.f, 0.f, 0.f};
    this->rotationY = {0.f, 1.f, 0.f};
    this->rotationZ = {0.f, 0.f, 1.f};
    this->perspectiveMatrix = glm::perspective(glm::radians(90.0f), (float)width / (float)height, 0.1f, 100.0f);
}

Matrix::~Matrix()
{
}

glm::vec4 Matrix::matrixTranslate(float &x, float &y, float &z)
{
    glm::vec4 vec(x, y, z, 1.f);
    glm::mat4 translation = glm::mat4(1.f);
    translation = glm::rotate(translation, glm::radians(this->frame), glm::vec3(1.f, 1.f, 1.f));
    vec = translation * vec;
    return this->perspectiveMatrix * vec;
}