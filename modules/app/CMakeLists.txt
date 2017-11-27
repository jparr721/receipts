cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
project(zeus VERSION 0.1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
	src/app.cpp
)

target_link_libraries(${PROJECT_NAME}
	Odin
)

install(TARGETS ${PROJECT_NAME}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)