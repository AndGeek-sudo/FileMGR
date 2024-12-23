project(BaseFileMGR VERSION 1.0)

add_executable(filemgr 
           ${CMAKE_CURRENT_SOURCE_DIR}/model.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/view/cli/linux.cpp
)

set_target_properties(filemgr PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)

target_include_directories(filemgr PUBLIC ${CMAKE_SOURCE_DIR}/include)