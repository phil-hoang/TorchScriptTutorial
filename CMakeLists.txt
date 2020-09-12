# CMakeLists.txt

# Older versions of CMake are likely to work just fine but, since
# I don't know where to cut off I just use the version I'm using
cmake_minimum_required(VERSION "3.17")

# name of this example project
project(torch-demo)

# set OpenCV_DIR variable equal to the path to the cmake
# files within the previously installed opencv program
set(OpenCV_DIR /Users/Philip/opencv/install/lib/cmake/opencv4)

# Tell compiler to use C++ 14 features which is needed because
# Clang version is often behind in the XCode installation
set(CMAKE_CXX_STANDARD 14)

# configure the necessary common CMake environment variables
# needed to include and link the OpenCV program into this
# demo project, namely OpenCV_INCLUDE_DIRS and OpenCV_LIBS
find_package( OpenCV REQUIRED )

# tell the build to include the headers from OpenCV
include_directories( ${OpenCV_INCLUDE_DIRS} )

# specify the executable target to be built
add_executable(torch-demo main.cpp)

# tell it to link the executable target against OpenCV
target_link_libraries(torch-demo ${OpenCV_LIBS} )

# Add pytorch libraries

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
list(APPEND CMAKE_PREFIX_PATH "/Users/Philip/opencv/libtorch")

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

target_link_libraries(torch-demo "${TORCH_LIBRARIES}")
set_property(TARGET torch-demo PROPERTY CXX_STANDARD 14)

# The following code block is suggested to be used on Windows.
# According to https://github.com/pytorch/pytorch/issues/25457,
# the DLLs need to be copied to avoid memory errors.
if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET example-app
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:example-app>)
endif (MSVC)



# Add torchvision libraries

cmake_minimum_required(VERSION 3.10)
list(APPEND CMAKE_PREFIX_PATH "/Users/Philip/opencv/vision/build/CMakeFiles")

# The first thing do is to tell cmake to find the TorchVision library.
# The package pulls in all the necessary torch libraries,
# so there is no need to also add `find_package(Torch)` here.
find_package(TorchVision REQUIRED)

target_link_libraries(torch-demo TorchVision::TorchVision)
