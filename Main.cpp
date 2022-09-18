#include <iostream>

#include "./include/Window.h"
#include "./include/Renderer.h"

int main()
{
    int frame(0);
    int width(1920);
    int height(1080);

    // Initialize window and renderer
    Window window(width, height);
    Renderer renderer;

    // Render Obj file
    renderer.loadObj("FinalBaseMesh.obj");

    // Main loop
    while (window.isRunning())
    {
        switch (window.isResized)
        {
        case (true):
            window.isResized = false;
            renderer.width = window.width;
            renderer.height = window.height;
        }
        window.pollEvents();
        window.clear();
        renderer.renderObj();
        window.draw(renderer.vertexArray);
        window.display();
        renderer.frame = renderer.frame + 1.f;
    }
}