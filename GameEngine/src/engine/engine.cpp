#include "engine.hpp"

Engine::Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs} {};

void Engine::run()
{
    sf::RenderWindow window;
    if (m_fs)
    {
        window.create(sf::VideoMode(), m_title, sf::Style::Fullscreen);
    }
    else
    {
        window.create(sf::VideoMode(m_width, m_height), m_title);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}