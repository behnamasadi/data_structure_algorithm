# Set the output directories for different configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)

add_executable(array_string src/array_string.cpp)

set_target_properties(array_string PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY $<CONFIG>/  # ${CMAKE_BINARY_DIR}/Debug or Release or other configs
    LIBRARY_OUTPUT_DIRECTORY $<CONFIG>/ 
    ARCHIVE_OUTPUT_DIRECTORY $<CONFIG>/ 
)

# add_executable(bfs  src/bfs.cpp)

# add_executable(dfs  src/dfs.cpp)

# add_executable(dynamic_programming  src/dynamic_programming.cpp)

# add_executable(graphs  src/graphs.cpp)

# add_executable(hash  src/hash.cpp)

# add_executable(heap  src/heap.cpp)

# add_executable(linked_list src/linked_list.cpp)

# add_executable(stack src/stack.cpp)

# add_executable(recursion src/recursion.cpp)

# add_executable(queue src/queue.cpp)

# add_executable(matrices src/matrices.cpp)

