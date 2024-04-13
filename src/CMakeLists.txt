add_subdirectory("linked_list")

add_executable(out main.cpp)
target_link_libraries(out linked_list)
