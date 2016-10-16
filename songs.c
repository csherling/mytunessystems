#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node {
    char name[256];
    char artist[256];
    struct song_node *next;
} song_node;

void print_list(song_node* node) {
    while (node != 0) {
        printf("%s - %s\n", node->name, node->artist);
        node = node->next;
    }
}

song_node* insert_front(song_node* node, char* name, char* artist) {
    song_node* new = (song_node*) malloc(sizeof(song_node));
    strncpy(new->name, name, 256);
    strncpy(new->artist, artist, 256);
    new->next = node;
    return new;
}

void free_list(song_node* cur_node) {
    song_node* next;
    while (cur_node != 0) {
        next = cur_node->next;
        free(cur_node);
        cur_node = next;
    }
}

//and later:

song_node *table[26];
