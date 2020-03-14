SET(SOURCES normal_chicken_controller.cpp chicken/normal_chicken.cpp)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

ADD_LIBRARY(normal_chicken_controller ${SOURCES})
