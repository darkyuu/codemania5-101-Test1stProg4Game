set(APP_NAME SlidingPuzzleTest)
project (${APP_NAME})
cmake_minimum_required(VERSION 3.1)

IF (WIN32)
	include_directories($ENV{GMOCK_HOME}/include $ENV{GTEST_HOME}/include)
	link_directories($ENV{GMOCK_HOME}/lib/vs2015/Debug $ENV{GTEST_HOME}/lib/vs2015/Debug)
ELSE ()
	include_directories($ENV{GMOCK_HOME}/include $ENV{GTEST_HOME}/include)
	link_directories($ENV{GMOCK_HOME}/lib/apple $ENV{GTEST_HOME}/lib/apple)
ENDIF ()
add_definitions(-std=c++0x)
IF(APPLE)
	set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wno-c++11-narrowing")
ELSE ()
	set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")
ENDIF ()

IF (MSVC)
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /W3 /MTd")
ELSE ()
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
ENDIF ()
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(Sources
	../Classes/SliderPuzzleGameplay.cpp
	../Classes/SliderPuzzleGameplay.h
	../Classes/SliderPuzzleGameManager.cpp
	../Classes/SliderPuzzleGameManager.h
	RunAllTests.cpp
	SliderPuzzleGameplayMode3x3Test.cpp
)
add_executable(RunAllTests ${Sources})
target_link_libraries(RunAllTests gmock)
target_link_libraries(RunAllTests gtest)
IF (NOT WIN32)
target_link_libraries(RunAllTests pthread)
ENDIF ()
