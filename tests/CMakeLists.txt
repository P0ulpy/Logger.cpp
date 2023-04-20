add_executable(cpp-logger-test
    tests.cpp
)

target_link_libraries(cpp-logger-test PRIVATE cpp-logger)