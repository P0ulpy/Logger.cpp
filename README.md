# Logger.cpp

Simple logging lib for c++20 and higher (i could make it work with under and maybe i will do it someday, for now i don't have the usage for it)

This is not a full featured logging lib, it is just a simple wrapper around the standard output stream.
This is **NOT** a header only library, you need to compile the source code and link it to your project.

This repo contain a CMakelists.txt file, so you can use add_subdirectory.

## Usage

```c++
#include <Logger.hpp>

int main()
{
    // You can define a label for the current thread (if not defined it take the thread id)
    Logger::SetThreadLabel("main");

    // Regular log for information porposes
    Logger::Log("Yep i think this is working as intended");

    // Warning log for warning porposes
    Logger::Warn("Warning! this should not happen too often");

    // Error log for error porposes
    Logger::Error("Error! this should not happen at all");

    return 0;
}
```