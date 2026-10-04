#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song *next;
    Song *prev;
};

Song *head = NULL, *tail = NULL, *current = NULL;

void addSong(string t, string a) {
    Song *p = new Song;
    p->title = t;
    p->artist = a;
    p->next = NULL;
    p->prev = NULL;
    
    if (head == NULL) {
        head = tail = current = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void nextSong() {
    if (current == NULL) { cout << "Playlist empty\n"; return; }
    if (current->next == NULL) current = head;
    else current = current->next;
    cout << "Now playing: " << current->title << " by " << current->artist << endl;
}

void prevSong() {
    if (current == NULL) { cout << "Playlist empty\n"; return; }
    if (current->prev == NULL) current = tail;
    else current = current->prev;
    cout << "Now playing: " << current->title << " by " << current->artist << endl;
}

void displayForward() {
    cout << "Playlist (forward): ";
    Song *p = head;
    while (p != NULL) {
        cout << p->title;
        if (p->next != NULL) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

void displayBackward() {
    cout << "Playlist (backward): ";
    Song *p = tail;
    while (p != NULL) {
        cout << p->title;
        if (p->prev != NULL) cout << " <- ";
        p = p->prev;
    }
    cout << endl;
}

void removeSong(string title) {
    Song *p = head;
    while (p != NULL) {
        if (p->title == title) {
            if (current == p)
                current = (p->next != NULL) ? p->next : p->prev;
            
            if (p->prev != NULL) p->prev->next = p->next;
            else head = p->next;
            
            if (p->next != NULL) p->next->prev = p->prev;
            else tail = p->prev;
            
            delete p;
            cout << "Removed: " << title << endl;
            return;
        }
        p = p->next;
    }
    cout << "Song not found: " << title << endl;
}

int main() {
    addSong("Song A", "Artist 1");
    addSong("Song B", "Artist 2");
    addSong("Song C", "Artist 3");
    addSong("Song D", "Artist 4");
    
    displayForward();
    displayBackward();
    
    cout << "\n--- Playback ---" << endl;
    nextSong();
    nextSong();
    prevSong();
    
    cout << "\n--- Remove ---" << endl;
    removeSong("Song B");
    displayForward();
    
    return 0;
}