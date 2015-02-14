add_library(number_thing numbers.cpp)

add_executable(numbers main.cpp)
target_link_libraries (numbers number_thing)
