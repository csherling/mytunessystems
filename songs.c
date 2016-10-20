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

int songnodecmp(song_node* a, char* name, char* artist) {
    if (a == 0) {
        return 1;
    }
    int by_artist = strcmp(a->artist, artist);
    if (by_artist == 0) {
        return strcmp(a->name, name);
    }
    return by_artist;
}

song_node* insert_ordered(song_node* node, char* name, char* artist) {
    if (songnodecmp(node, name, artist) > 0) {
        return insert_front(node, name, artist);
    } else {
        song_node* leftnode = node;
        song_node* rightnode = node->next;
        while (1) {
            if (rightnode == 0) {
                // Allocate and create new song_node
                song_node* last = 0;
                last = (song_node*) malloc(sizeof(song_node));
                strncpy(last->name, name, 256);
                strncpy(last->artist, artist, 256);

                // Append new song_node to the list
                last->next = 0;
                leftnode->next = last;
                break;
            }
            if (songnodecmp(rightnode, name, artist) > 0) {
                leftnode->next = insert_front(rightnode, name, artist);
                break;
            }
            // Step forward:
            leftnode = rightnode;
            rightnode = rightnode->next;
        }
        return node;
    }
}

song_node* find_by_name(song_node* node, char* name) {
    while (node != 0) {
        if (strcmp(node->name, name) == 0) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

song_node* find_by_artist(song_node* node, char* artist) {
    while (node != 0) {
        if (strcmp(node->artist, artist) == 0) {
            return node;
        }
        node = node->next;
    }
    return 0;
}

song_node* remove_node(song_node* head, song_node* to_remove) {
    if (songnodecmp(head, to_remove->name, to_remove->artist) == 0) {
        return to_remove->next;
    }
    song_node* node = head;
    while (node != 0) {
        if (songnodecmp(node->next, to_remove->name, to_remove->artist) == 0) {
            // The condition guarantees that node->next is not NULL
            node->next = (node->next)->next;
            break;
        }
        // Otherwise, advance node
        node = node->next;
    }
    return head;
}

int count_songs(song_node* songs) {
    int n = 0;
    while (songs != 0) {
        n++;
        songs = songs->next;
    }
    return n;
}

song_node* find_by_index(song_node* node, int index) {
    int i;
    for (i = 0; i < index; i++) {
        if (node == 0) {
            return 0;
        }
        node = node->next;
    }
    return node;
}

song_node* select_random(song_node* node) {
    return find_by_index(node, rand() % count_songs(node));
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
