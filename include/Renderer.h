#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include "Window.h"
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include <string>
#include <vector>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void renderObj();
    void loadObj(std::string objFile);

    std::vector<sf::Vector3f> mesh;
    int vertCount;
    sf::VertexArray vertexArray;

    int width;
    int height;

    float frame;

private:
};

#endif