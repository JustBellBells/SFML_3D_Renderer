#ifndef WINDOW_H
#define WINDOW_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class Window
{

public:
    Window(int width, int height);
    ~Window();
    bool isRunning();
    void pollEvents();
    void draw(sf::VertexArray vertexArray);
    void clear();
    void display();

    sf::Vector2i size();

    int width;
    int height;

    bool isResized;

private:
    sf::RenderWindow *window;
};

#endif