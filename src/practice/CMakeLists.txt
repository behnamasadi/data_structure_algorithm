set(CMAKE_BUILD_TYPE DEBUG)

add_executable(main src/main.cpp)
target_link_libraries(main)

IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/geeksforgeeks")
        ADD_SUBDIRECTORY(src/geeksforgeeks)
ENDIF()

IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/hackerrank")
        ADD_SUBDIRECTORY(src/hackerrank)
ENDIF()

#IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/interviews")
#        ADD_SUBDIRECTORY(src/interviews)
#ENDIF()
