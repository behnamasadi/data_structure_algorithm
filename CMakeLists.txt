cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
set(CMAKE_BUILD_TYPE DEBUG)

project(data_structure_algorithm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)




if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-variable")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-private-field")
endif()



set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################ Data Structure ################################

add_executable(hashing_main src/hashing/hashing_main.cpp)
target_link_libraries(hashing_main)

add_executable(sort_algorithms  src/sort_algorithms/sort_algorithms.cpp)
target_link_libraries(sort_algorithms)

add_executable(heap src/heap/heap.cpp)
target_link_libraries(heap)

add_executable(matrices src/matrices/matrices.cpp)
target_link_libraries(matrices)

add_executable(tree_representation src/trees/tree_representation.cpp)
target_link_libraries(tree_representation)

add_executable(avl_tree src/trees/avl_tree.cpp)
target_link_libraries(avl_tree)

add_executable(queue_main src/queue/main.cpp)
target_link_libraries(queue_main)

add_executable(binary_search_tree src/trees/binary_search_tree.cpp)
target_link_libraries(binary_search_tree)

add_executable(graph_main src/graphs/main.cpp)
target_link_libraries(graph_main)

add_executable(graph_representation src/graphs/graph_representation.cpp)
target_link_libraries(graph_representation)

add_executable(graph_bfs_dfs_search src/graphs/graph_bfs_dfs_search.cpp)
target_link_libraries(graph_bfs_dfs_search)

add_executable(graph_spanning_tree src/graphs/spanning_tree.cpp)
target_link_libraries(graph_spanning_tree)

add_executable(hash_chaining src/hashing/hash_chaining.cpp)
target_link_libraries(hash_chaining)

add_executable(linked_list_main src/linked_list/main.cpp)
target_link_libraries(linked_list_main)

add_executable(hash_linear_probing src/hashing/hash_linear_probing.cpp)
target_link_libraries(hash_linear_probing)

add_executable(recursion src/recursion/main.cpp)
target_link_libraries(recursion)

add_executable(array_main src/array/main.cpp)
target_link_libraries(array_main)

add_executable(B_B+_tree src/trees/B_B+_tree.cpp)
target_link_libraries(B_B+_tree)

add_executable(red_black_tree src/trees/red_black_tree.cpp)
target_link_libraries(red_black_tree)

add_executable(2_3_trees src/trees/2_3_trees.cpp)
target_link_libraries(2_3_trees)

################################ Algorithms ################################
add_executable(greedy_methods src/algorithms/Greedy_method/greedy_methods.cpp)
target_link_libraries(greedy_methods)

add_executable(dynamic_programming src/algorithms/Dynamic_programming/dynamic_programming.cpp)
target_link_libraries(dynamic_programming)

add_executable(backtracking src/algorithms/Backtracking/backtracking.cpp)
target_link_libraries(backtracking)

add_executable(branch_and_bound src/algorithms/Branch_and_bound/branch_and_bound.cpp)
target_link_libraries(branch_and_bound)

add_executable(strassen_matrix_multiplication src/algorithms/Divide_and_conquer/strassen_matrix_multiplication.cpp)
target_link_libraries(strassen_matrix_multiplication)
