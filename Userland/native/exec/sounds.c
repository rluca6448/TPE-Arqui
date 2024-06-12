#include "../include/sounds.h"
#include "../include/syscalls.h"
#define MAX_SIZE 128

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} BoundedQueue;

typedef enum {
    SILENCE, E2, F2, Fs2, G2, Gs2, A2, As2, B2, C3, Cs3, D3, Ds3, E3, F3, Fs3,
    G3, Gs3, A3, As3, B3, C4, Cs4, D4, Ds4, E4, F4, Fs4, G4, Gs4, A4, As4, B4,
    C5, Cs5, D5, Ds5, E5
} MusicalNote;

BoundedQueue not_played_yet;

int last_note = 0;

int retro_song[];            // song id 1      

int os_initiating[];        // song id 2

int you_lost[];             // song id 3  


void play_song(int song_id){
    switch(song_id){
        case 1: initializeQueueWithArray(retro_song, 64); break;
        case 2: initializeQueueWithArray(os_initiating, 10); break;
        case 3: initializeQueueWithArray(you_lost, 10); break;
        default: initializeQueue(); break;
        last_note = sys_ticks_elapsed;
    }
}

// char next_part(){ // devuelve 1 si la cancion termina
//     las
// }               
















BoundedQueue not_played_yet; // Declaration of global BoundedQueue variable

// Function to initialize the queue
void initializeQueue() {
    not_played_yet.front = 0;
    not_played_yet.rear = -1;
    not_played_yet.size = 0;
}

void initializeQueueWithArray(int arr[], int n) {
    if (n >= MAX_SIZE) return;
    not_played_yet.front = 0;
    not_played_yet.rear = n - 1; // Rear points to the last element
    not_played_yet.size = n;

    // Copy elements from the array to the queue
    for (int i = 0; i < n; i++) {
        not_played_yet.data[i] = arr[i];
    }
}

// Function to check if the queue is empty
char isEmpty() {
    return not_played_yet.size == 0 ? 1 : 0;
}

// Function to check if the queue is full
char isFull() {
    return not_played_yet.size == MAX_SIZE ? 1 : 0;
}

// Function to get the current size of the queue
int getSize() {
    return not_played_yet.size;
}

// Function to add an element to the queue
char enqueue(int value) {
    if (isFull()) {
        return 0; // Queue is full
    }
    not_played_yet.rear = (not_played_yet.rear + 1) % MAX_SIZE;
    not_played_yet.data[not_played_yet.rear] = value;
    not_played_yet.size++;
    return 1;
}

// Function to remove an element from the queue
char dequeue(int* value) {
    if (isEmpty()) {
        return 0; // Queue is empty
    }
    *value = not_played_yet.data[not_played_yet.front];
    not_played_yet.front = (not_played_yet.front + 1) % MAX_SIZE;
    not_played_yet.size--;
    return 1;
}