typedef struct song_node {
    char name[256];
    char artist[256];
    struct song_node *next;
} song_node;
void print_list(song_node* node);
song_node* insert_front(song_node* node, char* name, char* artist);
song_node* insert_ordered(song_node* node, char* name, char* artist);
song_node* find_by_name(song_node* node, char* name);
song_node* find_by_artist(song_node* node, char* artist);
void free_list(song_node* cur_node);
