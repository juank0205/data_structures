add_library(linked_list src/linked_list.cpp)
target_include_directories(linked_list PRIVATE include)

add_executable(linked_list_test src/main.cpp)
target_include_directories(linked_list_test PRIVATE include)
target_link_libraries(linked_list_test linked_list)
