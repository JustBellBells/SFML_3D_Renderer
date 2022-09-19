#include "Renderer.h"
#include "OBJ_Loader.h"
#include "Matrix.h"
#include <string>
#include "SFML-2.5.1/include/SFML/Graphics.hpp"

Renderer::Renderer()
{
    this->width = 1920;
    this->height = 1080;
    this->frame = 0;
}

Renderer::~Renderer()
{
}

void Renderer::renderObj()
{
    this->vertexArray.clear();
    Matrix matrix(width, height, frame);
    for (auto i = 0; i < this->vertCount; i++)
    {
        glm::vec4 vec4 = matrix.matrixTranslate(mesh[i].x, mesh[i].y, mesh[i].z);
        this->vertexArray.append(sf::Vertex(sf::Vector2f(vec4.x, vec4.y)));
    }
}

void Renderer::loadObj(std::string objFile)
{
    objl::Loader loader;
    loader.LoadFile(objFile);
    this->vertCount = loader.LoadedVertices.size();
    for (auto i = 0; i < this->vertCount; i++)
    {
        this->mesh.emplace_back(loader.LoadedVertices[i].Position.X, loader.LoadedVertices[i].Position.Y, loader.LoadedVertices[i].Position.Z);
    }
    this->vertexArray = sf::VertexArray(sf::Points, this->vertCount);
}