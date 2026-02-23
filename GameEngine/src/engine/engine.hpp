#include <SFML/Graphics.hpp>

// to-do make it more modular, take the functions from .hpp to .cpp file and improve the run() function with updaters and renderers.

class Engine
{
public:
    Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs} {};
    void run() const;

private:
    int m_width{};
    int m_height{};
    std::string m_title{};
    int m_fps{};
    int m_fs{};
};