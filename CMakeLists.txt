cmake_minimum_required(VERSION 3.0)
project(addersubbers C)
add_executable(addersubbers  pthread_race.c)
find_package (Threads REQUIRED)
target_link_libraries(addersubbers pthread)
set(CMAKE_C_STANDARD 99)
