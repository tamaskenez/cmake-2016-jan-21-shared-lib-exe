CMAKE_MINIMUM_REQUIRED (VERSION 3.2)

##  Set variable names for this module
SET (TARGET_NAME_EXEC "X-main")

##  Set the source files
SET (SRC_FILES
)

##  Set the files with main ()
SET (TEST_FILES
  main.cpp
)

##  Set the main source path to the very top directory
IF (NOT DEFINED MAIN_SRC_PATH)
  SET (MAIN_SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/..")
ENDIF (NOT DEFINED MAIN_SRC_PATH)

##  Project name
PROJECT (${TARGET_NAME_EXEC} VERSION 1.0 LANGUAGES CXX)

##  Set the output directory of the libraries to the top-level binary directory
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

##  Create the test executable
IF (NOT TARGET ${TARGET_NAME_EXEC})
  ADD_EXECUTABLE (${TARGET_NAME_EXEC} ${TEST_FILES} ${SRC_FILES})
  TARGET_LINK_LIBRARIES (${TARGET_NAME_EXEC} A B)
ENDIF (NOT TARGET ${TARGET_NAME_EXEC})

##  Location of additional header files
INCLUDE_DIRECTORIES (${MAIN_SRC_PATH}/A)
INCLUDE_DIRECTORIES (${MAIN_SRC_PATH}/B)

##  Add subdirectories to the build
ADD_SUBDIRECTORY (${MAIN_SRC_PATH}/A ${CMAKE_CURRENT_BINARY_DIR}/A)
ADD_SUBDIRECTORY (${MAIN_SRC_PATH}/B ${CMAKE_CURRENT_BINARY_DIR}/B)

##  CTest
ENABLE_TESTING ()
ADD_TEST (NAME X-test COMMAND ${TARGET_NAME_EXEC})
