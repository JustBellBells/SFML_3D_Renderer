#ifndef WINDOW_H
#define WINDOW_H

#pragma once
#include <SFML/Graphics.hpp>

class Window
{

public:
    Window();
    Window(int width, int height);
    ~Window();
    bool isRunning();
    void pollEvents();
    void draw(sf::VertexArray vertexArray);
    void clear();
    void display();

    int width;
    int height;

    bool isResized;

private:
    sf::RenderWindow *window;
};

#endif