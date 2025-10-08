set(ENGINE_NAME Abstract2DEngine)

file(GLOB_RECURSE ENGINE_SOURCES
    core/*.cpp
    core/config/*.cpp
)

file(GLOB_RECURSE ENGINE_HEADERS
    core/*.h
    core/config/*.h
)

add_library(${ENGINE_NAME}
    ${ENGINE_SOURCES}
    ${ENGINE_HEADERS}
)

target_include_directories(${ENGINE_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
)

add_subdirectory(thirdparty)

target_link_libraries(${ENGINE_NAME}
    spdlog
)

if(WIN32)
    target_compile_definitions(${ENGINE_NAME} PRIVATE PLATFORM_WINDOWS)
elseif(ANDROID)
    target_compile_definitions(${ENGINE_NAME} PRIVATE PLATFORM_ANDROID)
endif()


option(ENABLE_LOGGING "Enable logging with spdlog" ON)

# usage : when building, cmake -B build -DENABLE_LOGGING=OFF
if(ENABLE_LOGGING)
    add_definitions(-DENABLE_LOGGING)
endif()
