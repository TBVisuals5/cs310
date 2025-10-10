cmake_minimum_required(VERSION 3.10)
project(MediaPlayer)

set(CMAKE_CXX_STANDARD 17)

# SFML
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

# Catch2
find_package(Catch2 REQUIRED)

# Tests
add_executable(tests
    test_playlist.cpp
    Song.cpp
    SortedArrayPlaylist.cpp # or SortedLinkedPlaylist.cpp
)

target_link_libraries(tests
    SFML::Graphics
    SFML::Audio
    Catch2::Catch2
)

# Media Player
add_executable(player
    MediaPlayer.cpp
    Song.cpp
    SortedArrayPlaylist.cpp # or SortedLinkedPlaylist.cpp
)

target_link_libraries(player
    SFML::Graphics
    SFML::Audio
)
