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
    void loadObj(std::string objFile, sf::PrimitiveType primType);
    void setSize(sf::Vector2i size);

    std::vector<sf::Vector3f> mesh;
    std::vector<sf::Vector3f> meshNormals;
    int vertCount;
    sf::VertexArray vertexArray;

    int width;
    int height;

    float frame;
};

#endif