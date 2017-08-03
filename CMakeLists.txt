cmake_minimum_required (VERSION 2.6)

MACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)
     STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
     "${CMAKE_BINARY_DIR}" insource)
     GET_FILENAME_COMPONENT(PARENTDIR ${CMAKE_SOURCE_DIR} PATH)
     STRING(COMPARE EQUAL "${CMAKE_SOURCE_DIR}"
     "${PARENTDIR}" insourcesubdir)
     MESSAGE("CMakeLists.txt is in: ${CMAKE_SOURCE_DIR}")
     MESSAGE("The command is run from: ${CMAKE_BINARY_DIR}")
    IF(insource OR insourcesubdir)
	    MESSAGE(FATAL_ERROR "Please build in the 'build' subdirectory!")
    ENDIF(insource OR insourcesubdir)
     

ENDMACRO(MACRO_ENSURE_OUT_OF_SOURCE_BUILD)

MACRO_ENSURE_OUT_OF_SOURCE_BUILD()

project (probability-tester)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
FIND_PACKAGE(Boost 1.38 REQUIRED COMPONENTS graph)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES( ${Boost_LIBRARY_DIRS})

add_executable(Main main.cpp)
target_link_libraries(Main ${Boost_LIBRARIES})
