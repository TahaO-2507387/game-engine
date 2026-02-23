#include "engine/engine.hpp"

int main()
{
    Engine test{2560, 1440, "testing", 60, 0};

    test.run();

    return 0;
}