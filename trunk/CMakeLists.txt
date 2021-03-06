
#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.6)

if(POLICY CMP0020)
  # Accept new policy related to automatically linking Qt apps to qtmain.lib on Windows
  cmake_policy(SET CMP0020 NEW)
endif()

project(ENigMA CXX)

#Configure options
set(ENigMA_DIR $ENV{ENIGMA_DIR} CACHE FILEPATH "")
set(GTest_DIR $ENV{GTEST_DIR} CACHE FILEPATH "")
set(Exprtk_DIR $ENV{EXPRTK_DIR} CACHE FILEPATH "")
set(Eigen3_DIR $ENV{EIGEN_DIR} CACHE FILEPATH "")
set(ViennaCL_DIR $ENV{VIENNACL_DIR} CACHE FILEPATH "")

set(RTree_DIR $ENV{RTREE_DIR} CACHE FILEPATH "")
set(QT_MOC_EXECUTABLE "$ENV{QTDIR}/bin/moc.exe" CACHE FILEPATH "")
set(QT_UIC_EXECUTABLE "$ENV{QTDIR}/bin/uic.exe" CACHE FILEPATH "")
set(QT_QMAKE_EXECUTABLE "$ENV{QTDIR}/bin/qmake.exe" CACHE FILEPATH "")
set(VTK_DIR $ENV{VTK_DIR} CACHE FILEPATH "")

set(USE_VIENNACL OFF CACHE BOOL "Use ViennaCL")

set(ENIGMA_BUILD_CONSOLE_EXAMPLES OFF CACHE BOOL "Build console examples")
set(ENIGMA_BUILD_OPENGL_EXAMPLES OFF CACHE BOOL "Build OpenGL examples")
set(ENIGMA_BUILD_QT_EXAMPLES OFF CACHE BOOL "Build QT examples")
set(ENIGMA_BUILD_VTK_EXAMPLES OFF CACHE BOOL "Build VTK examples")

set(ENIGMA_BUILD_UNIT_TESTS ON CACHE BOOL "Build unit tests")

set(ENIGMA_BUILD_WRAPPERS_SWIG OFF CACHE BOOL "Build SWIG wrapper")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY AUTOGEN_TARGETS_FOLDER automoc)

add_subdirectory(lib)

IF (ENIGMA_BUILD_UNIT_TESTS)
add_subdirectory(tests)
endif(ENIGMA_BUILD_UNIT_TESTS)

add_subdirectory(wrappers)

add_subdirectory(examples)

