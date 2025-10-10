#include "MediaPlayer.h"
#include <filesystem> // For directory iteration (C++17)

MediaPlayer::MediaPlayer()
    : window(sf::VideoMode(800, 600), "SFML Media Player"),
      currentIndex(0), isPlaying(false) {
    
    if (!font.loadFromFile("arial.ttf")) {
        // Handle error: fallback or exit
    }

    // Initialize GUI elements
    currentSongText.setFont(font);
    currentSongText.setString("No song loaded");
    currentSongText.setPosition(10, 10);

    playButton.setSize(sf::Vector2f(100, 50));
    playButton.setPosition(10, 50);
    playButton.setFillColor(sf::Color::Green);
}

void MediaPlayer::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void MediaPlayer::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            if (playButton.getGlobalBounds().contains(mousePos)) {
                if (isPlaying) {
                    music.pause();
                } else {
                    music.play();
                }
                isPlaying = !isPlaying;
            }
        }
    }
}

void MediaPlayer::update() {
    Song* current = playlist.getCurrentSong();
    if (current) {
        if (!music.getStatus() == sf::Music::Playing) {
            if (!music.openFromFile(current->filePath)) {
                // Handle error
            }
            music.play();
            isPlaying = true;
        }
        currentSongText.setString(current->title + " - " + current->artist);
        // You could also update a progress bar here using music.getPlayingOffset()
    }
}

void MediaPlayer::render() {
    window.clear();
    window.draw(currentSongText);
    window.draw(playButton);
    window.display();
}

void MediaPlayer::loadPlaylist(const std::string& directory) {
    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".mp3") {
            // You could extract metadata here if needed
            Song song("Sample Title", "Sample Artist", 180, entry.path().string());
            playlist.addSong(song);
        }
    }
}
