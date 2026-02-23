#include "engine.hpp"

Engine::Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs} {};

void Engine::run() const
{
    if (m_fs)
    {
        sf::RenderWindow window(sf::VideoMode(), m_title, sf::Style::Fullscreen);
    }
    else
    {
        sf::RenderWindow window(sf::VideoMode(m_width, m_height), m_title);
    }
    window.s while (window.isOpen())
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