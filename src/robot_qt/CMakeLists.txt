##############################################################################
# CMake
##############################################################################

cmake_minimum_required(VERSION 2.8.0)
project(robot_qt)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_compile_options(-std=c++11)
##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
find_package(catkin REQUIRED COMPONENTS rviz roscpp rospy sensor_msgs
    cv_bridge
    std_msgs
    image_transport
    )
find_package(Qt5 REQUIRED Core Widgets Multimedia WebEngineWidgets Charts)
set(QT_LIBRARIES Qt5::Widgets Qt5::Multimedia Qt5::WebEngineCore Qt5::WebEngineWidgets Qt5::Charts)
include_directories(
  ${catkin_INCLUDE_DIRS}
  ./ThirdParty/GeographicLib/include/
)
add_subdirectory(./ThirdParty/GeographicLib/)
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package()

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in package.xml
#rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/*.hpp *.h)#修改这里，可以加上.hpp和.h文件

QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})
##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

##############################################################################
# Binaries
##############################################################################

add_executable(robot_qt ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(robot_qt ${QT_LIBRARIES} ${catkin_LIBRARIES} libGeographiccc)
install(TARGETS robot_qt RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

