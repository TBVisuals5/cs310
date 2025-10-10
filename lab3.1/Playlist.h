#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "UnsortedLinkedList.h" // Assume this exists from previous labs

class Playlist : public UnsortedLinkedList<Song> {
public:
    void addSong(const Song& song);
    void removeSong(const std::string& title);
    Song* getCurrentSong();       // Returns current playing song
    void nextSong();              // Move to next in list
    void previousSong();          // Move to previous in list
    void sortByTitle();           // Add sorting method if extending to sorted list
};

#endif
