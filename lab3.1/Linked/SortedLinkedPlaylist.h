#ifndef SORTED_LINKED_PLAYLIST_H
#define SORTED_LINKED_PLAYLIST_H

#include "Song.h"

class SortedLinkedPlaylist {
private:
    struct Node {
        Song data;
        Node* next;
        Node(const Song& s) : data(s), next(nullptr) {}
    };

    Node* head;
    Node* current;

public:
    SortedLinkedPlaylist() : head(nullptr), current(nullptr) {}

    ~SortedLinkedPlaylist() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addSong(const Song& song) {
        Node* newNode = new Node(song);
        if (!head || song < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data < song) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void mergeSortedPlaylists(SortedLinkedPlaylist& other) {
        Node dummy(Song("", "", 0, ""));
        Node* tail = &dummy;
        Node* a = head;
        Node* b = other.head;

        while (a && b) {
            if (a->data < b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        head = dummy.next;
        other.head = nullptr;
    }

    void mergeWithUnsorted(const std::vector<Song>& unsorted) {
        for (const auto& song : unsorted) {
            addSong(song);
        }
    }

    Song* getCurrentSong() {
        return current ? &current->data : nullptr;
    }

    void nextSong() {
        if (!current) current = head;
        else if (current->next) current = current->next;
    }

    void previousSong() {
        if (!current || current == head) return;
        Node* temp = head;
        while (temp->next != current) {
            temp = temp->next;
        }
        current = temp;
    }

    size_t getLength() const {
        size_t count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

#endif
