#ifndef MATRIX_H
#define MATRIX_H

#pragma once
#include "glm-master/glm/gtx/transform.hpp"
#include "glm-master/glm/matrix.hpp"

class Matrix
{
public:
    Matrix(int width, int height, float frame);
    ~Matrix();
    glm::vec4 matrixTranslate(float &x, float &y, float &z);
    float frame;

private:
    glm::vec3 rotationX;
    glm::vec3 rotationY;
    glm::vec3 rotationZ;
    glm::mat4 translationMatrix;
    glm::mat4 perspectiveMatrix;
};

#endif