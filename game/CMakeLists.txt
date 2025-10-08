set(GAME_NAME MyGame)

file(GLOB_RECURSE GAME_SOURCES
    src/*.cpp
)

add_executable(${GAME_NAME} ${GAME_SOURCES})

target_include_directories(${GAME_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${GAME_NAME}
    Abstract2DEngine
)

# Copy shaders/assets on build (optional)
#add_custom_command(TARGET ${GAME_NAME} POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#    ${CMAKE_SOURCE_DIR}/shaders $<TARGET_FILE_DIR:${GAME_NAME}>/shaders
#)
