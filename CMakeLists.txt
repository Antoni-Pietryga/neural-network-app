cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(NeuralNetworkAPP VERSION 1.0.0 LANGUAGES CXX)
find_package(Torch ${PYTORCH_VERSION} EXACT QUIET PATHS "${CMAKE_SOURCE_DIR}/libtorch")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 14)

if(NOT Torch_FOUND)
    unset(Torch_FOUND)
    include(fetch_libtorch)
endif()
set(EXECUTABLE_NAME NeuralNetworkAPP)

add_executable(${EXECUTABLE_NAME})
target_sources(${EXECUTABLE_NAME} PRIVATE
					  src/main.cpp
					  src/train_params.cpp
                                          src/neural_net.cpp
					  src/dataset.cpp
                                          include/neural_net.h
                                          include/dataset.h
					  include/train.h
					  include/train_params.h
					  src/train.cpp
					  src/test.cpp
            src/main_window.cpp
            include/main_window.h
            src/train_window.cpp
            include/train_window.h
            include/ui_train_window.h
            src/stats_window.cpp
            include/stats_window.h
            include/ui_stats_window.h
            src/predict_window.cpp
            include/predict_window.h
            include/ui_predict_window.h
					  include/test.h
)

target_include_directories(${EXECUTABLE_NAME} PRIVATE include)

target_link_libraries(${EXECUTABLE_NAME} ${TORCH_LIBRARIES})
target_link_libraries (${EXECUTABLE_NAME} Qt5::Widgets)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
)


if(MSVC)
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR})
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR})
    include(copy_torch_dlls)
    copy_torch_dlls(${EXECUTABLE_NAME})
endif(MSVC)

