#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "Song.h"
#include "SortedArrayPlaylist.h" // or SortedLinkedPlaylist.h

TEST_CASE("Playlist Operations") {
    SortedArrayPlaylist pl;
    pl.addSong(Song("Song1", "Artist1", 200, "path1.mp3"));
    pl.addSong(Song("Song2", "Artist2", 150, "path2.mp3"));

    REQUIRE(pl.getLength() == 2);
    REQUIRE(pl.getCurrentSong()->title == "Song1");

    SECTION("Merge two sorted playlists") {
        SortedArrayPlaylist other;
        other.addSong(Song("Song3", "Artist3", 180, "path3.mp3"));
        other.addSong(Song("Song0", "Artist0", 210, "path0.mp3"));

        pl.mergeSortedPlaylists(other);
        REQUIRE(pl.getLength() == 4);
        REQUIRE(pl.getCurrentSong()->title == "Song0"); // Sorted order
    }

    SECTION("Merge with unsorted playlist") {
        std::vector<Song> unsorted = {
            Song("Song5", "Artist5", 190, "path5.mp3"),
            Song("Song4", "Artist4", 170, "path4.mp3")
        };
        pl.mergeWithUnsorted(unsorted);
        REQUIRE(pl.getLength() == 4); // After merge
        REQUIRE(pl.getCurrentSong()->title == "Song1"); // Still sorted
    }
}
