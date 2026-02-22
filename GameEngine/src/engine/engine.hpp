#include <SFML/Graphics.hpp>

class Engine
{
public:
    Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs} {};
    void run() const
    {
        sf::RenderWindow window(sf::VideoMode(m_width, m_height), m_title);
        window.setFramerateLimit(m_fps);
        if (m_fs == 1)
        {
            sf::Style::Fullscreen;
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

private:
    int m_width{};
    int m_height{};
    std::string m_title{};
    int m_fps{};
    int m_fs{};
};