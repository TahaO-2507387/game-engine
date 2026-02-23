#include "engine.hpp"

Engine::Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs} {};

void Engine::run()
{
    sf::Clock timer;
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
        sf::Time currentTime = timer.getElapsedTime();
        sf::Event event;
        process_input(window);
        update(currentTime);
        render(window);

        timer.restart();
    }
}

void Engine::process_input(sf::RenderWindow &window)
{
    using namespace sf;
    Event event;

    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            window.close();
        }
        else if (event.type == Event::Resized)
        {
            return;
        }
        else if (event.type == Event::KeyPressed)
        {
            return;
        }
        else if (event.type == Event::KeyReleased)
        {
            return;
        }
    }
}

void Engine::update(sf::Time dt)
{
    return;
}

void Engine::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);

    window.display();
}