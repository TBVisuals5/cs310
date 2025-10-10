#ifndef SORTED_ARRAY_PLAYLIST_H
#define SORTED_ARRAY_PLAYLIST_H

#include "Song.h"
#include <vector>
#include <algorithm>

class SortedArrayPlaylist {
private:
    std::vector<Song> songs;
    int currentIndex;

public:
    SortedArrayPlaylist() : currentIndex(0) {}

    void addSong(const Song& song) {
        auto it = std::lower_bound(songs.begin(), songs.end(), song);
        songs.insert(it, song);
    }

    void mergeSortedPlaylists(SortedArrayPlaylist& other) {
        std::vector<Song> merged;
        std::merge(songs.begin(), songs.end(),
                   other.songs.begin(), other.songs.end(),
                   std::back_inserter(merged));
        songs = std::move(merged);
    }

    void mergeWithUnsorted(const std::vector<Song>& unsorted) {
        songs.insert(songs.end(), unsorted.begin(), unsorted.end());
        std::sort(songs.begin(), songs.end());
    }

    Song* getCurrentSong() {
        if (songs.empty()) return nullptr;
        return &songs[currentIndex];
    }

    void nextSong() {
        if (currentIndex + 1 < songs.size()) currentIndex++;
    }

    void previousSong() {
        if (currentIndex > 0) currentIndex--;
    }

    size_t getLength() const {
        return songs.size();
    }
};

#endif
