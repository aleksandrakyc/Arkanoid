# CMakeList.txt: plik projektu CMake najwyższego poziomu, wykonaj konfigurację globalną
# i uwzględnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.16)

project ("Arkanoid")

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/src
)
file(GLOB DIR_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
		"${PROJECT_SOURCE_DIR}/include/*.hpp"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
		"${PROJECT_SOURCE_DIR}/src/*.c"
        )

# Specify build target
add_executable(
	Arkanoid
	${DIR_SRCS}
)
target_link_libraries(
	Arkanoid
	sfml-graphics
)
#resources - font
add_custom_command(
	TARGET Arkanoid POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:Arkanoid>/resources
)
