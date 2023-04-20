# Logger.cpp

Simple logging lib for c++20 and higher (i could make it work with under and maybe i will do it someday, for now i don't have the usage for it)

This is not a full featured logging lib, it is just a simple wrapper around the standard output stream.
This is **NOT** a header only library, you need to compile the source code and link it to your project.

This repo contain a CMakelists.txt file, so you can use add_subdirectory.

## Import in your project

As you noticed this repo is not mature at all so use it at your own risk.

Anyway if you are brave enough to use it you can use it in your project by adding this repo as a submodule and then add it to your project.

```bash
git submodule add https://github.com/P0ulpy/cpp-logger.git vendors/cpp-logger
```

Then in your CMakeLists.txt file you can add this line

```cmake

include_directories(${CMAKE_SOURCE_DIR}/vendors/cpp-logger/includes)
add_subdirectory(vendors/cpp-logger)

```

## Usage

```cpp
#include <Logger.hpp>

int main()
{
    // You can define a label for the current thread (if not defined it take the thread id)
    Logger::SetThreadLabel("main");

    // Regular log for information purposes
    Logger::Log("Yep i think this is working as intended");

    // Warning log for warning purposes
    Logger::Warn("Warning! this should not happen too often");

    // Error log for error purposes
    Logger::Error("Error! this should not happen at all");

    return 0;
}
```