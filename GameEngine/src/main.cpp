#include "engine/engine.hpp"

int main()
{
    Engine test{800, 600, "testing", 60, 1};

    test.run();

    return 0;
}