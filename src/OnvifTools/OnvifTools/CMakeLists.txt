# CMakeList.txt : CMake project for OnvifTools, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(project_name "OnvifTools")
project(${project_name})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/vendor/libonvif/source
	${CMAKE_SOURCE_DIR}/vendor/libxml2-2.9.10/include
	${CMAKE_BINARY_DIR}/vendor/libxml2-2.9.10
	${CMAKE_SOURCE_DIR}/vendor/libiconv-1.16/include
	${CMAKE_BINARY_DIR}/vendor/libiconv-1.16
)

link_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_BINARY_DIR}/vendor/libxml2-2.9.10
	${CMAKE_BINARY_DIR}/vendor/libonvif/
)

file(GLOB SRCS "*.cpp")

# Add source to this project's executable.
add_executable (${project_name} ${SRCS})

if (MSVC)
	list(APPEND project_name_cflags /W4)
	list(APPEND project_name_defines WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0501)
	MESSAGE(STATUS "CMAKE_BUILD_TYPE=" ${CMAKE_BUILD_TYPE})

	set(CompilerFlags
		CMAKE_CXX_FLAGS
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_RELEASE
		CMAKE_C_FLAGS
		CMAKE_C_FLAGS_DEBUG
		CMAKE_C_FLAGS_RELEASE
		)
	foreach(CompilerFlag ${CompilerFlags})
		string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
endif(MSVC)

target_link_libraries(${project_name} PRIVATE libonvif_static)
# TODO: Add tests and install targets if needed.
