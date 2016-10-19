#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "songs.h"

void add_song(song_node** playlist, char * name, char * artist){
  char first = artist[0];
  song_node * slot = playlist[first - 'a'];
  if(slot->artist[0] == 0){
    printf("memes\n");
    insert_ordered(slot, name, artist);
    /* playlist[first - 'a'] = playlist[first - 'a']->next; */
    /* free(slot); */


    
    /* playlist[first - 'a'] = (song_node *)malloc(sizeof(song_node)); */
    /* memcpy(slot->name, name, sizeof(slot->name)); */
    /* memcpy(slot->artist, artist, sizeof(slot->artist)); */
  }
  else{
    printf("rainbow\n");
    insert_ordered(slot, name, artist);
  }
  /* while(temp->next){ */
  /*   if(strcmp(temp->artist, song->artist) > 0){ */
  /*     temp = temp->next; */
  /*   } */
  /*   else if(strcmp(temp->artist, song->artist) <= 0){ */
  /*     insert_front(temp, song->name, song->artist); */
  /*     return; */
  /*   } */
  /* } */
}

song_node* search_song(char *song, song_node** playlist){
  int i = 0;
  for(; i < 26; i++){
    if(find_by_name(playlist[i], song)){
      return find_by_name(playlist[i], song);
    }
  }
  return 0;
  /* int i = 0; */
  /* song_node * temp = playlist[0]; */
  /* for(; i < 26; i++){ */
  /*   while(temp->next){ */
  /*     if(strcmp(temp->name, song) == 0){ */
  /* 	return &temp; */
  /*     } */
  /*     temp = temp->next; */
  /*   } */
  /*   temp = playlist[i + 1]; */
  /* } */
  /* return 0; */
}

song_node* search_artist(char *artist, song_node **playlist){
  char first = artist[0];
  return find_by_artist(playlist[first-97], artist);

  /* song_node * temp = playlist[first - 97]; */
  /* while(temp->next){ */
  /*   if(strcmp(temp->artist, song->artist) == 0){ */
  /*     return &temp; */
  /*   } */
  /*   else if(strcmp(temp->artist, song->artist) != 0){ */
  /*     temp = temp->next; */
  /*   } */
  /* } */
  /* return 0; */
}

void print_letter(char letter, song_node **playlist){
  print_list(playlist[letter - 97]);
}

void artist_songs(char *artist, song_node **playlist){
  song_node * slot = search_artist(artist, playlist);
  printf("yes");
  while(strcmp(slot->artist, artist) == 0){
    printf("yes1");
    printf("%s\n", slot->name);
    printf("yes2");
    slot = slot->next;
    printf("yes3");
  }
}

void print_library(song_node *playlist[26]){
  int i = 0;
  for(; i < 26; i++){
    printf("%d\n", i + 97);
    print_list(playlist[i]);
  }
}

/* void shuffle(song_node *playlist){ */

/* } */

void delete_song(char *song, song_node **playlist){
  remove_node(*playlist, search_song(song, playlist));
}

void delete_nodes(song_node *playlist){
  free_list(playlist);
}
