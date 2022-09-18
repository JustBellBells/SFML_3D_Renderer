#include "Renderer.h"
#include "OBJ_Loader.h"
#include "Matrix.h"
#include <string>
#include <SFML/Graphics.hpp>

Renderer::Renderer()
{
    this->width = 1920;
    this->height = 1080;
    vertexBuffer = sf::VertexBuffer(sf::Triangles, sf::VertexBuffer::Usage::Stream);
    this->frame = 0;
}

Renderer::~Renderer()
{
}

void Renderer::renderObj()
{
    Matrix matrix(width, height, frame);
    this->vertexArray.clear();
    for (auto i = 0; i < this->vertCount; i++)
    {
        glm::vec4 vec4 = matrix.matrixTranslate(vec3fArr[i].x, vec3fArr[i].y, vec3fArr[i].z);
        this->vertexArray.emplace_back(sf::Vertex(sf::Vector2f(vec4.x, 0 - vec4.y), sf::Color(255, 255, 255, 255)));
    }
    vertexBuffer.update(vertexArray.data());
}

void Renderer::loadObj(std::string objFile)
{
    objl::Loader loader;
    loader.LoadFile(objFile);
    this->vertCount = loader.LoadedVertices.size();
    vertexBuffer.create(loader.LoadedVertices.size());
    for (auto i = 0; i < this->vertCount; i++)
    {
        this->vec3fArr.emplace_back(loader.LoadedVertices[i].Position.X, loader.LoadedVertices[i].Position.Y, loader.LoadedVertices[i].Position.Z);
    }
}