cmake_minimum_required(VERSION 3.5)

# Set the project name
project (glog_crash)
# coverage option
# OPTION (ENABLE_COVERAGE "Use gcov" OFF)
# MESSAGE(STATUS ENABLE_COVERAGE=${ENABLE_COVERAGE})
# IF(ENABLE_COVERAGE)
#     SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
#     SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
#     # 其中 -fprofile-arcs 用来生成 gcno 文件； -ftest-coverage 用来在统计时生成 gcda 文件
#     SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage") 
# ENDIF()
find_package(Boost REQUIRED COMPONENTS filesystem system)

# check if boost was found
if(Boost_FOUND)
    message ("boost found")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/include)
add_executable(glog_crash main.cpp)

target_link_libraries(glog_crash
${Boost_LIBRARIES}
yaml-cpp
pthread
${CMAKE_CURRENT_SOURCE_DIR}/lib/x64/lib/libglog.so
)
