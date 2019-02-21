cmake_minimum_required(VERSION 3.5)
project(server)
set(APP_SRC "calcServer.cpp")
add_subdirectory(CalcServer)
add_executable(server ${APP_SRC})
target_link_libraries(server libCalcServer)

 