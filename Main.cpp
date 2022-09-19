#include <iostream>

#include "./include/Window.h"
#include "./include/Renderer.h"

int main()
{
    int frame(0);
    int width(1920);
    int height(1080);

    // Initialize window and renderer
    Renderer renderer;
    Window window(width, height);

    // Render Obj file
    renderer.loadObj("FinalBaseMesh.obj");

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
