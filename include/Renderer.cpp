#include "Renderer.h"
#include "OBJ_Loader.h"
#include "Matrix.h"
#include <string>

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
        glm::vec4 result = matrix.matrixTranslate(this->mesh[i].x, this->mesh[i].y, this->mesh[i].z);
        vertexArray.append(sf::Vertex(sf::Vector2f(result.x, result.y), sf::Color(sf::Color::White)));
    }
}

void Renderer::loadObj(std::string objFile, sf::PrimitiveType primType)
{
    objl::Loader loader;
    loader.LoadFile(objFile);
    this->vertCount = loader.LoadedVertices.size();
    this->vertexArray = sf::VertexArray(primType, this->vertCount);
    for (auto i = 0; i < this->vertCount && i % 1 == 0; i++)
    {
        this->mesh.emplace_back(loader.LoadedVertices[i].Position.X, loader.LoadedVertices[i].Position.Y, loader.LoadedVertices[i].Position.Z);
        this->meshNormals.emplace_back(loader.LoadedVertices[i].Normal.Y, loader.LoadedVertices[i].Normal.X, loader.LoadedVertices[i].Normal.Z);
    }
}

void Renderer::setSize(sf::Vector2i size)
{
    this->width = size.x;
    this->height = size.y;
}