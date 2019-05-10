cmake_minimum_required (VERSION 3.8)
project(ConsoleGame)

include_directories(src)

set(ALL_FILES
	sprite.h
	sprite.cpp
	engine.h
	engine.cpp
	pch.h
	pch.cpp
	main.cpp
)


source_group("src" FILES ${ALL_FILES})

add_executable(game ${ALL_FILES})

set_property(TARGET game PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/resources")