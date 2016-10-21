#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct song_node {
    char name[256];
    char artist[256];
    struct song_node *next;
} song_node;
void print_list(song_node* node);
void print_song(song_node* node);
song_node* insert_front(song_node* node, char* name, char* artist);
song_node* insert_ordered(song_node* node, char* name, char* artist);
song_node* find_by_name(song_node* node, char* name);
song_node* find_by_artist(song_node* node, char* artist);
song_node* find_song(song_node* node, char* name, char* artist);
song_node* remove_node(song_node* node, song_node* to_remove);
int count_songs(song_node* songs);
song_node* find_by_index(song_node* node, int index);
song_node* select_random(song_node* node);
void free_list(song_node* cur_node);

#endif
