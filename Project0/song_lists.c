/*
Jackie Xu and William Hong
Systems Period 4
Project 0 My Tunez
10/20/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "song_lists.h"

// takes: a pointer to a node struct, prints out all of the data in the list
void print_list(struct song_node * list) {
	//printf("\nTesting print_list: \n");
	printf("\n");
	while (list) {
		printf("(%s: %s) ", list->artist, list->name);
		list = list->next;
	}
	//printf("NULL\n"); //only for testing purposes
}

void print_node(struct song_node *list){
	//printf("\nTesting print_node: \n");
	printf("\n(%s: %s) ",  list->artist, list->name); }

// inputs information into a song_node
// returns: a pointer to the song_node
struct song_node * initialize_song(char * person, char * song){
	struct song_node *insert = (struct song_node *)malloc(sizeof(struct song_node));
	strncpy(insert->artist, person, sizeof(insert->artist));
	strncpy(insert->name, song, sizeof(insert->name));
	insert->next = NULL;
	return insert;
}

//takes in pointers to two different song nodes, compares the artist strings then song title strings;
// returns: -1 if a comes before b, 0 if they are the same, 1 if b comes before a
int compare_nodes(struct song_node * a, struct song_node * b) {
	char * artist_A = a->artist;
	char * artist_B = b->artist;

	if (strcmp(artist_A, artist_B) < 0){
		return -1; } //this means artist a is before artist b

	else{
			if (strcmp(artist_A, artist_B) > 0){
				return 1; } //this means artist a comes after artist b

			else{
				char * song_A = a->name;
				char * song_B = b->name;
				if (strcmp(song_A, song_B) < 0){
					return -1; } //this means song a comes before song b
				if (strcmp(song_A, song_B) > 0){
					return 1; } //this means song a comes after song b
				}
		}

		return 0; //if all else fails
}

int compare_nodes_testing(char * personA, char * songA, char * personB, char *songB){
	printf("\nComparing (%s: %s)", personA, songA);
	printf(" to (%s: %s) \n", personB, songB);
	if (strcmp(personA, personB) < 0){
		printf("Result is -1\n");
		return -1; } //this means artist a is before artist b

	else{
			if (strcmp(personA, personB) > 0){
				printf("Result is 1\n");
				return 1; } //this means artist a comes after artist b

			else{
				if (strcmp(songA, songB) < 0){
					printf("Result is -1\n");
					return -1; } //this means song a comes before song b
				if (strcmp(songA, songB) > 0){
					printf("Result is 1\n");
					return 1; } //this means song a comes after song b
				}
		}

		printf("Result is 0\n");
		return 0; //if all else fails
}


// takes a pointer to the existing list and the data to be added, creates a new node and puts it at the beginning of the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_front(struct song_node * list, char * person, char * name) {
	struct song_node *insert = initialize_song(person, name);
	insert->next = list;
	return insert;
}

struct song_node * insert_end(struct song_node * list, char * person, char *name){
	struct song_node *insert = initialize_song(person, name);
	while(list && list->next != NULL){
		list = list->next; }

	list->next = insert;
	return insert;
}

// takes a pointer to the existing list and the data to be added, creates a new node and alphabetizes it in the list;
// returns: a pointer to the beginning of the list.
struct song_node * insert_song(struct song_node * list, char * person, char * name) {
	struct song_node *copy = list; //so we can return beginning of the list later

	struct song_node *insert = initialize_song(person, name);

	//while the current song's artist and name is not "less" than the song we want to insert
	while (list && list->next != NULL && compare_nodes(list->next, insert) != 0 && compare_nodes(list, insert) != 0){
		//case 1: if insert should be first song in list
		if (compare_nodes(insert,list) < 0){
			insert_front(list, person, name);
		 	return copy; }

		//case 2: add in middle
		else if (compare_nodes(insert,list) > 0 && compare_nodes(insert, list->next) < 0){
			insert->next = list->next;
			list->next = insert;
			return copy; }

		list = list->next; }

		//case 3: if insert should be the last song in list
		//if while loop lasted till end, we know insert end must be the case
		insert_end(list,person,name);
		return copy;
}


// takes a pointer to the existing list, goes through the entire list freeing each node;
// returns: a pointer to the beginning of the list (which should be NULL by then).
struct song_node * free_list(struct song_node * list) {
	struct song_node * temp = (struct song_node *)malloc(sizeof(struct song_node));
	while (list) {
		printf("\nFreeing node: (%s: %s)", list->artist, list->name);
		temp = list;
		list = list->next;
		free(temp);
	}
	//once released you have no access to piece of memory anymore
	//then in main you would do n = free_list(n) to reallocate memory
	printf("\nHere's the updated library after we freed the list:\n");
	print_list(list);
	return NULL;
}

// takes a pointer to the existing list and a song title, goes through entire list until song title matches;
// returns: a pointer to the node whose song title matches parameter
struct song_node * find_node(struct song_node * list, char * person, char *song) {
	printf("\nLooking for node (%s: %s) -> ", person, song);
	while (list){
		if (strcmp(list->name, song) == 0 && strcmp(list->artist, person) == 0){
			printf("Node found! ");
			//print_list(list); //for testing purposes
			return list; }
		else{
			list = list->next; }
	}

	printf("Node not found :(");
	return NULL;
}

struct song_node * find_node_testing(struct song_node * list, char * person, char *song) {
	while (list){
		if (strcmp(list->name, song) == 0 && strcmp(list->artist, person) == 0){
			return list; }
		else{
			list = list->next; }
	}

	return NULL;
}

// takes a pointer to the existing list and an artist name, goes through entire list until artist name matches;
// returns: a pointer to the first node whose artist name matches parameter
struct song_node * find_artist(struct song_node * list, char * person) {
	printf("\nLooking for artist %s -> ", person);
	while (list){
		if (strcmp(list->artist, person) == 0){
			printf("Artist found!");
			print_list(list);
			printf("\n");
			return list; }
		else{
			list = list->next; }
	}

	printf("Artist not found :( \n");
	return NULL;
}

// takes a pointer to the existing list, goes through the entire list;
// returns: how many nodes in the entire linked list
int length_of(struct song_node * list) {
	int ans = 0;
	while (list) {
		list = list->next;
		ans++;
	}
	return ans;
}

// takes a pointer to the existing list;
// returns: how a pointer to a random node in the list
struct song_node * find_random(struct song_node * list) {

	int l = length_of(list);
	struct song_node * copy = list;
	//printf("\nlength of list: %d \n", l); //for testing purposes

	int r = ( rand() % l);
	//printf("\nrandom index: %d", r); //for testing purposes

	int i = 0;
	while(i < r){
		copy = copy->next;
		i++; }

	print_node(copy); //for testing purposes
	return copy;
}

// takes a pointer to the existing list and a node to be removed, goes through entire list until node matches and removes it;
// returns: pointer to the beginning of the edited list
struct song_node * remove_song(struct song_node * list, char * person, char *name) {
	struct song_node *copy = list; //so we can return beginning of the list later

	struct song_node *one = initialize_song(person, name);

	printf("\nRemoving (%s: %s)", one->artist, one->name);

	if (find_node_testing(list, person, name) != NULL){
		//case 1: if remove first node of list
		if (compare_nodes(list,one) == 0){
			copy = list->next;
	 		list = NULL;
		}

		else {
			while (list && list->next != NULL){
				//case 2: remove from the middle
				if (compare_nodes(one,list->next) == 0){
					struct song_node *temp = list->next;
					list->next = temp->next;
					temp->next = NULL;
				}

				list = list->next;
			}
		}

		//case 3: remove from the end
		//if while loop lasted till end, we know list is the last node
		list = NULL;
		printf(" -> removal successful");
		return copy; }

	else{
		printf(" -> You can't remove a song that's not in the library");
		return NULL; }
}
