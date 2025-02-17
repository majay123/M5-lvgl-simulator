cmake_minimum_required(VERSION 3.19)
project(LVGL)

#  SET(CMAKE_C_COMPILER "D:/ProgramFiles/LLVM/x86/bin/clang.exe")
#  SET(CMAKE_CXX_COMPILER "D:/ProgramFiles/LLVM/x86/bin/clang++.exe")

message("-- " ${PROJECT_NAME} " " ${CMAKE_CXX_COMPILER})

set(CMAKE_CXX_STANDARD 20) #1

file(GLOB_RECURSE HEADERS demos/*.h examples/*.h lv_drivers/*.h lvgl/*.h lv_conf.h main/src/x86_smart_panel/*.h main/src/x86_smart_panel/common/*.h lv_demo_conf.h lv_drv_conf.h lvgl.hi= ko)
file(GLOB_RECURSE SOURCES demos/*.c examples/*.c lv_drivers/*.c lvgl/*.c main/*.c main/testapp/*.c main/testapp/src/*.c)
include_directories(.  ./lvgl)
link_directories(/opt/homebrew/lib/)

find_package(SDL2 REQUIRED SDL2)
include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})
#message(${HEADERS})
#message(${SOURCES})
add_executable(LVGL  ${HEADERS} ${SOURCES})

# target_link_libraries(LVGL libSDL2.a)
target_link_libraries(LVGL SDL2)

