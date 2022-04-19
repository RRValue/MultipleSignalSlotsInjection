CMAKE_MINIMUM_REQUIRED(VERSION 3.16)

IF(NOT DEFINED ENV{Qt6_DIR})
    MESSAGE(FATAL, "Qt6_DIR not found")
ELSE()
    SET(CMAKE_PREFIX_PATH $ENV{Qt6_DIR})
ENDIF()

SET(PROJECT_BIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

PROJECT(MultipleSignalSlotsInjection)

# Set C++ Standard
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

FIND_PACKAGE(Qt6 REQUIRED COMPONENTS Core Widgets)

QT_STANDARD_PROJECT_SETUP()
QT_ADD_EXECUTABLE(
    MultipleSignalSlotsInjection
    source/main.cpp
)

TARGET_LINK_LIBRARIES(MultipleSignalSlotsInjection PRIVATE Qt6::Core)
TARGET_LINK_LIBRARIES(MultipleSignalSlotsInjection PRIVATE Qt6::Widgets)

IF(MSVC)
    SET_TARGET_PROPERTIES(MultipleSignalSlotsInjection PROPERTIES PDB_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
    SET_TARGET_PROPERTIES(MultipleSignalSlotsInjection PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_PATH})
ENDIF(MSVC)

ADD_CUSTOM_COMMAND(
    TARGET MultipleSignalSlotsInjection
    POST_BUILD
    COMMAND CD $<$<CONFIG:Debug>:${PROJECT_BIN_PATH}/Debug>$<$<CONFIG:Release>:${PROJECT_BIN_PATH}/Release> && ${WINDEPLOYQT_EXECUTABLE} MultipleSignalSlotsInjection.exe --verbose 1 --dir . --plugindir plugins --no-translations --compiler-runtime
    )