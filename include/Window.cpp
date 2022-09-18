#include "Window.h"

Window::Window()
{
    this->width = 800;
    this->height = 600;
    this->isResized = false;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), "SFML-app");
    this->window->setView(sf::View(sf::Vector2f(0, 0), sf::Vector2f(25.f, 25.f)));
}

Window::Window(int width, int height)
{
    this->width = width;
    this->height = height;
    this->isResized = false;
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), "SFML-app");
    this->window->setView(sf::View(sf::Vector2f(0, 0), sf::Vector2f(25.f, 25.f)));
}

Window::~Window()
{
}

bool Window::isRunning()
{
    return this->window->isOpen();
}

void Window::pollEvents()
{
    sf::Event ev;
    while (this->window->pollEvent(ev))
    {
        switch (ev.type)
        {
        case (sf::Event::Closed):
            this->window->close();
            break;
        case (sf::Event::KeyPressed):
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->window->close();
                break;
            }
        case (sf::Event::Resized):
            this->width = this->window->getSize().x;
            this->height = this->window->getSize().y;
            this->isResized = true;
        }
    }
}

void Window::clear()
{
    this->window->clear(sf::Color::Black);
}

void Window::display()
{
    this->window->display();
}

void Window::draw(sf::VertexBuffer buffer)
{
    this->window->draw(buffer);
}