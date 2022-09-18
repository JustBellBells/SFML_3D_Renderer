#ifndef RENDERER_H
#define RENDERER_H

#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Renderer
{
public:
    Renderer();
    ~Renderer();
    void renderObj();
    void loadObj(std::string objFile);

    std::vector<sf::Vector3f> vec3fArr;
    int vertCount;
    std::vector<sf::Vertex> vertexArray;
    sf::VertexBuffer vertexBuffer;

    int width;
    int height;

    float frame;

private:
};

#endif