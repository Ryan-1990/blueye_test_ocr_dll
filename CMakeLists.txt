cmake_minimum_required(VERSION 3.8)

project(test_ocr_dll)

set(TARGET_NAME ${CMAKE_PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(ASSETS digit_ocr.dll opencv_world430.dll)

set(FILES_TO_COPY ${ASSETS})
list(TRANSFORM FILES_TO_COPY PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/resource/)

set(COPIED_FILES ${ASSETS})
list(TRANSFORM COPIED_FILES PREPEND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)/)


add_custom_command(
    COMMAND ${CMAKE_COMMAND} -E copy ${FILES_TO_COPY} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
    OUTPUT ${COPIED_FILES}
    COMMENT "Copying resource files to build directory"
)

add_custom_target(${TARGET_NAME}_copy_assets
	ALL
	DEPENDS ${COPIED_FILES}
)

add_executable(${TARGET_NAME} source/main.cpp)

add_dependencies(${TARGET_NAME} ${TARGET_NAME}_copy_assets)

install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)