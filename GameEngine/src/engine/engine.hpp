#include <SFML/Graphics.hpp>

class Engine
{
public:
    Engine(int width, int height, std::string title, int fps, int fs) : m_width{width}, m_height{height}, m_title{title}, m_fps{fps}, m_fs{fs}, m_working{1} {};
    ~Engine()
    {
        m_working = 0;
    }

private:
    int m_width{};
    int m_height{};
    std::string m_title{};
    int m_fps{};
    int m_fs{};
    int m_working{};
};