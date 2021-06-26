
cmake_minimum_required(VERSION 3.10.2)

project("parcel")

file(GLOB SOURCE *.c *.cpp)

add_library(
             native-lib
             SHARED

             ${SOURCE})

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )