#include "../Includes/Logger.hpp"

int main()
{
    Logger::SetThreadLabel("Main");

    Logger::Log("Hello World!");

    Logger::Warn("Hello World!", "Hello World!", "Hello World!");
    Logger::Err("Hello World!");

    return 0;
}