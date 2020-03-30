cmake_minimum_required(VERSION 3.5)

project(rlmidi LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rlmidi
  main.cpp
  ExampleReceiver.cpp
  rlmidi/MidiIn.cpp
  rlmidi/MidiDevice.cpp
)

target_link_libraries(rlmidi rtmidi pthread)
