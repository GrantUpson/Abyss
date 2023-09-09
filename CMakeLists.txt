cmake_minimum_required(VERSION 3.26)
project(Abyss)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libraries)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libraries)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(libraries/)
include_directories(libraries/glad/include/)
include_directories(libraries/glfw-3.3.7/include/GLFW)
include_directories(${CMAKE_SOURCE_DIR}/source/)
add_subdirectory(libraries/glfw-3.3.7)


set(SOURCE_FILES source/Main.cpp
        source/Game.cpp
        source/Game.h
        libraries/glad/src/glad.c
        source/utility/Utility.h
        source/utility/Logger.cpp
        source/utility/Logger.h
        source/networking/Socket.h
        source/networking/Address.cpp
        source/networking/Address.h
        testing/Receiver.cpp
        testing/Receiver.h
        testing/Sender.cpp
        testing/Sender.h
        source/networking/Packet.h
        source/networking/Opcodes.h
        libraries/crc/CRC.h
        source/networking/BinaryDecoder.cpp
        source/networking/BinaryDecoder.h
        source/networking/BinaryEncoder.cpp
        source/networking/BinaryEncoder.h
        source/networking/Packet.cpp
        source/networking/NetworkingUtilities.h)


if(WIN32)
    include_directories(${CMAKE_SOURCE_DIR}/source/platform/windows)
    include_directories(${CMAKE_SOURCE_DIR}/source/rendering/opengl)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/windows/WindowsWindow.cpp source/platform/windows/Window.h
            #source/rendering/directx/Texture.cpp
            #source/rendering/directx/Texture.h
            source/rendering/opengl/Texture.cpp
            source/rendering/opengl/Texture.h
            source/platform/windows/WindowsSocket.cpp
            source/platform/windows/WindowsNetworkingUtilities.cpp)

elseif(APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/source/platform/macos)
    #include_directories(${CMAKE_SOURCE_DIR}/source/rendering/metal)
    include_directories(${CMAKE_SOURCE_DIR}/source/rendering/opengl)
    SET(SOURCE_FILES ${SOURCE_FILES}
            source/platform/macos/MacOSWindow.cpp source/platform/macos/Window.h
            #source/rendering/metal/Texture.cpp
            #source/rendering/metal/Texture.h
            source/rendering/opengl/Texture.cpp
            source/rendering/opengl/Texture.h
            source/platform/macos/MacOSSocket.cpp
            source/platform/macos/MacOSNetworkingUtilities.cpp
    )

elseif(UNIX AND NOT APPLE)
    include_directories(${CMAKE_SOURCE_DIR}/source/platform/linux)
    include_directories(${CMAKE_SOURCE_DIR}/source/rendering/vulkan)
    SET(SOURCE_FILES ${SOURCE_FILES} source/platform/linux/LinuxWindow.cpp source/platform/linux/Window.h
            source/rendering/vulkan/Texture.cpp
            source/rendering/vulkan/Texture.h
            source/platform/linux/LinuxSocket.cpp
            source/platform/linux/LinuxNetworkingUtilities.cpp)

endif()

add_executable(Abyss ${SOURCE_FILES})

#Stops the command prompt from appearing in windows
if(WIN32)
    #set_target_properties(Abyss PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
endif()

target_link_libraries(Abyss LINK_PUBLIC glfw)
install(TARGETS Abyss RUNTIME)
