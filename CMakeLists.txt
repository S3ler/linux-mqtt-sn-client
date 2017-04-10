cmake_minimum_required(VERSION 3.6)
project(core-mqtt-sn-client)

set(CMAKE_CXX_STANDARD 11)

include_directories(src/main)
include_directories(src/Implementation)
include_directories(src/core-mqtt-sn-client/src)


set(IMPLEMENTATION_FILES
        src/main/main.cpp
        src/Implementation/LinuxUdpSocket.cpp
        src/Implementation/LinuxUdpSocket.h
        src/Implementation/LinuxSystem.h
        src/Implementation/LinuxSystem.cpp
        src/Implementation/Arduino.h
        src/Implementation/Arduino.cpp
        src/Implementation/LinuxUdpClient.cpp
        src/Implementation/LinuxUdpClient.h)

add_executable(linux-mqtt-sn-client ${IMPLEMENTATION_FILES})

add_subdirectory(src/core-mqtt-sn-client)
target_link_libraries(linux-mqtt-sn-client core-mqtt-sn-client)
