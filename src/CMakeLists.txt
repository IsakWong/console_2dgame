cmake_minimum_required (VERSION 3.8)
project(ConsoleGame)

include_directories(src)

set(SOURCE_FILES
	sprite.h
	sprite.cpp
	engine.h
	engine.cpp
	resource.h
	resource.cpp
	pch.h
	pch.cpp
	main.cpp
)
set(
	MATH_FILES
	math/2d_math.h
	math/2d_math.cpp
)
set(ALL_FILES
	${SOURCE_FILES}
	${MATH_FILES}
)

source_group("src" FILES ${SOURCE_FILES})
source_group("src\\math" FILES ${MATH_FILES})

add_executable(game ${ALL_FILES})

set_property(TARGET game PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/resources")