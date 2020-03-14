SET(SOURCES chicken_test.cpp chicken_controller_test.cpp)

INCLUDE(qt_module)
INCLUDE(3rdparty)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/chicken_controller/chicken)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src/chicken_controller)

ADD_EXECUTABLE(normal_tests ${SOURCES})

TARGET_LINK_LIBRARIES(normal_tests normal_chicken_controller Qt5::Core pthread)
