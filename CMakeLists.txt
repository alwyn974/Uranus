cmake_minimum_required(VERSION 3.17)
project(
        Uranus
        VERSION 0.0.1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
# Make project-provided Find modules available
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

option(URANUS_BUILD_TESTS "Build tests" OFF)
option(URANUS_INSTALL "Install Uranus" ON)
option(USE_CLANG_TIDY "Use clang-tidy" OFF)
option(USE_CLANG_FORMAT "Use clang-format" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(${PROJECT_NAME} main.cpp
        src/ecs/Components.cpp
        src/engine/Systems.cpp
        src/Player.cpp
        src/Enemy.cpp
        src/Bullet.cpp
        src/engine/Texture.cpp
        src/engine/Sprite.cpp
        include/engine/Event.hpp
        include/engine/Keyboard.hpp
        include/engine/Manager.hpp
        src/engine/Manager.cpp
        src/engine/SceneManager.cpp
        include/engine/SceneManager.hpp
        include/engine/Scene.hpp
        src/engine/Scene.cpp
        src/SceneMain.cpp
        include/SceneMain.hpp
        include/engine/Transform.hpp
        include/engine/Transform.cpp
        include/engine/Color.hpp
        include/engine/Color.hpp
        include/engine/Color.cpp
        include/engine/Vector2.hpp
        include/engine/Vector2.cpp
        include/engine/Rect.hpp
        include/engine/Rect.cpp
        include/engine/Image.hpp include/engine/Circle.hpp include/engine/Clock.hpp include/engine/Time.hpp include/engine/Convex.hpp include/engine/Cursor.hpp include/engine/Font.hpp include/engine/Glyph.hpp include/engine/Glyph.hpp include/engine/InputSoundFile.hpp include/engine/InputStream.hpp include/engine/Vector3.hpp include/engine/Listener.hpp include/engine/MemoryInputStream.hpp include/engine/FileInputStream.hpp include/engine/Mouse.hpp include/engine/Music.hpp include/engine/Rectangle.hpp include/engine/RenderStates.hpp include/engine/BlendMode.hpp include/engine/Shader.hpp include/engine/RenderTarget.hpp include/engine/GraphicView.hpp include/engine/RenderTexture.hpp include/engine/Sound.hpp include/engine/Vertex.hpp include/engine/VertexArray.hpp include/engine/PrimitiveType.hpp include/engine/VertexBuffer.hpp include/engine/ContextSettings.hpp include/engine/Transformable.hpp include/engine/Text.hpp include/engine/BlendMode.cpp include/engine/Cursor.cpp include/engine/Convex.cpp include/engine/Clock.cpp include/engine/Circle.cpp include/engine/FileInputStream.cpp include/engine/Font.cpp include/engine/GraphicView.cpp include/engine/Image.cpp include/engine/Listener.cpp include/engine/MemoryInputStream.cpp include/engine/Mouse.cpp include/engine/Music.cpp include/engine/Rectangle.cpp include/engine/RenderTexture.cpp include/engine/RenderWindow.cpp include/engine/Sound.cpp include/engine/SoundBuffer.cpp include/engine/Transformable.cpp include/engine/VertexArray.cpp)
# Include all headers directories
target_include_directories(${PROJECT_NAME}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
        )

find_package(SFML 2.6 REQUIRED COMPONENTS graphics window)

# Link all libraries
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        sfml-graphics sfml-audio sfml-system sfml-window
        )

# Enable warnings, will not work on header only libraries
target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Wall -Wextra>
        $<$<CXX_COMPILER_ID:MSVC>: /W4>
        )

# Set some properties
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "-debug")

# Set the startup project in Visual Studio
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    message(STATUS "Setting startup project to ${PROJECT_NAME}")
endif (MSVC)

if (URANUS_BUILD_TESTS)
    message(STATUS "Generating tests")
    include(GoogleTest)
    enable_testing()
    add_subdirectory(tests)
endif ()

if (USE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
    if (NOT CLANG_TIDY_EXE)
        message(WARNING "clang-tidy not found.")
    else ()
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        set_target_properties(${PROJECT_NAME} PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif ()
endif ()

if (USE_CLANG_FORMAT)
    # TODO: add clang-{format,tidy}
endif ()

if (URANUS_INSTALL)
    # Specify the files to be installed
    message(STATUS "Installing ${PROJECT_NAME}")
    get_target_property(${PROJECT_NAME}_deps ${PROJECT_NAME} INTERFACE_LINK_LIBRARIES)

    install(TARGETS ${PROJECT_NAME} ${${PROJECT_NAME}_deps}
            EXPORT ${PROJECT_NAME}Targets
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
            )

    install(EXPORT ${PROJECT_NAME}Targets
            FILE ${PROJECT_NAME}Targets.cmake
            NAMESPACE ${PROJECT_NAME}::
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
            )

    # Setup the version file
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            ${PROJECT_NAME}ConfigVersion.cmake
            VERSION ${PROJECT_VERSION}
            COMPATIBILITY AnyNewerVersion
    )

    # generate the config file that is includes the exports
    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
            INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
            NO_SET_AND_CHECK_MACRO
            NO_CHECK_REQUIRED_COMPONENTS_MACRO
            )

    install(FILES
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
            )

    export(EXPORT ${PROJECT_NAME}Targets FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

endif ()
