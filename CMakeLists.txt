cmake_minimum_required(VERSION 3.29.0)
project(CvGst LANGUAGES C CXX)

find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_BASE REQUIRED gstreamer-base-1.0)
pkg_check_modules(GSTREAMER_VIDEO REQUIRED gstreamer-video-1.0)
pkg_check_modules(GSTREAMER_APP REQUIRED gstreamer-app-1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(SRC_LIB_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(SRC_INCLUDE_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    main.c
    ${SRC_LIB_DIRECTORY}/opencv/opencv.cpp
    ${SRC_LIB_DIRECTORY}/gst/gstreamer.c
)

# Include directories
include_directories(${GSTREAMER_INCLUDE_DIRS})
include_directories(${GSTREAMER_BASE_INCLUDE_DIRS})
include_directories(${GSTREAMER_VIDEO_INCLUDE_DIRS})
include_directories(${GSTREAMER_APP_INCLUDE_DIRS})

include_directories(${OpenCV_INCLUDE-DIRECTORIES})
include_directories(${SRC_INCLUDE_DIRECTORY})

# Link directories
link_directories(${GSTREAMER_LIBRARY_DIRS})
link_directories(${GSTREAMER_BASE_LIBRARY_DIRS})
link_directories(${GSTREAMER_VIDEO_LIBRARY_DIRS})
link_directories(${GSTREAMER_APP_LIBRARY_DIRS})

# add_executable(display_image Opencv_hello_world.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_executable(cvgst ${SOURCES})


target_link_libraries(cvgst ${OpenCV_LIBS})
# Link the GStreamer libraries to your executable
target_link_libraries(cvgst ${GSTREAMER_LIBRARIES})
target_link_libraries(cvgst ${GSTREAMER_BASE_LIBRARIES})
target_link_libraries(cvgst ${GSTREAMER_VIDEO_LIBRARIES})
target_link_libraries(cvgst ${GSTREAMER_APP_LIBRARIES})
target_link_libraries(cvgst Qt6::Core Qt6::Gui Qt6::Widgets)
