/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include "song_lists.h"
#include "music_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void initialize_playlist(){
	int i = 0;
	while (i < 26){
		playlist[i] = NULL;
		i ++; }
}

// Converts ASCII character into an integer value to use to get index for the playlist array
int letter_index(char letter) {
	int ans = letter - 65;
	return ans;
	// letter 'A' = 0, 'B' = 1, etc
}

char first_letter(char * string) {
	return string[0];
}

// Adds song nodes
void add_song(char *person, char *song) {
	int i = letter_index(first_letter(person));
	if (playlist[i] == NULL){
		playlist[i] = initialize_song(person,song); }
	else{
		playlist[i] = insert_song(playlist[i], person, song); }
}

// Print out the entire library
void print_all() {
	int i;
	for (i = 0; i < 26; i++) {
		if (playlist[i]){
			printf("%c songs: ", 'A' + i);
			print_list(playlist[i]);
		  printf("\n\n"); }
		}
}

// Searches for a song given song and artist name
// Returns: a pointer to the song
struct song_node * search_song(char * song, char * person) {
	int i = letter_index(first_letter(person));
	return find_node(playlist[i], song, person);
}

// Search for an artist
// Returns: a pointer to the first song of the artist
struct song_node * search_artist(char * person) {
	int i = letter_index(first_letter(person));
	return find_artist(playlist[i], person);
}

// Print out all the entries under a certain letter
void print_letter(char letter) {

	int i = letter_index(letter);
	printf("\n%c songs: ", 'A' + i);
	print_list(playlist[i]);
	printf("\n");
}

// Print out all the songs of a certain artist
void print_artist(char * person) {
	int i = letter_index(first_letter(person));
	struct song_node * charlist = playlist[i];

	find_artist(charlist,person);
}

// Print out a series of randomly chosen songs
void shuffle() {
	int i;
	int random_int = rand() % 26;
	while(playlist[random_int] == NULL){
		random_int = rand() % 26; }
	find_random(playlist[random_int]);
}

// Delete a song
void delete_song(char * person, char * song) {
	int i = letter_index(first_letter(person));
	struct song_node * new = initialize_song(person, song);
	remove_song(playlist[i], person, song);
}

// Delete all the nodes
void delete_all() {
	int i;
	for (i = 0; i < 26; i++) {
		while(playlist[i]){
			free_list(playlist[i]);
		 	playlist[i] = 0; }
	}
}
