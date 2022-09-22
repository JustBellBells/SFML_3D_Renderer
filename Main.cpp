#include <iostream>

#include "./include/Window.h"
#include "./include/Renderer.h"

int main()
{
    int frame(0);
    const int width(1920);
    const int height(1080);

    // Initialize window and renderer
    Renderer renderer;
    Window window(width, height);

    // Render Obj file
    //  You can choose the model to render as well as the primitive type to render with.
    renderer.loadObj("Teapot.obj", sf::Triangles);

    // Main loop
    while (window.isRunning())
    {
        window.pollEvents();
        renderer.setSize(window.size());
        window.clear();
        renderer.renderObj();
        window.draw(renderer.vertexArray);
        window.display();
        renderer.frame++;
    }
}
