IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/geeksforgeeks")
        ADD_SUBDIRECTORY(src/geeksforgeeks)
ENDIF()

IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/hackerrank")
        ADD_SUBDIRECTORY(src/hackerrank)
ENDIF()

#IF(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/interviews")
#        ADD_SUBDIRECTORY(src/interviews)
#ENDIF()
