#include "song_lists.h"
#include "music_library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

  //testing song lists
  printf("\nTESTING SONG LISTS \n================================================\n");
  struct song_node *list = initialize_song("Jay Z", "Dirt Off Your Shoulder");
	insert_song(list, "Jay Z", "Ninety Nine Problems");
	insert_song(list, "Nirvana", "Lithium");
	insert_song(list, "Nas", "NY State of Mind");
	insert_song(list, "Radiohead", "No Surprises");
	insert_song(list, "Nas", "The World Is Yours");

  //testing print_list
  printf("Testing print_list: \n");
  print_list(list);
  printf("\n================================================\n");

	//testing print node
  printf("Testing print_node :\n");
	print_node(list);
  printf("\n================================================\n");

	//testing find node
  printf("Testing find_node: \n");
	find_node(list, "Nirvana", "Lithium");
  find_node(list, "Nas", "NY State of Mind");
	find_node(list, "Tupac", "Hit Em Up");
  printf("\n================================================\n");

	//testing find_artist
  printf("Testing find_artist: \n");
	find_artist(list, "Radiohead");
	find_artist(list, "Nas");
	find_artist(list, "Biggie");
  printf("\n================================================\n");

	//testing compare_nodes
  printf("Testing compare_nodes: \n");
  compare_nodes_testing("Nas", "NY State of Mind", "Nas", "NY State of Mind");
  compare_nodes_testing("Nas", "NY State of Mind", "Nas", "The World Is Yours");
  compare_nodes_testing("Nas", "NY State of Mind", "Jay Z", "Ninety Nine Problems");
  printf("\n================================================\n");

  //testing find_random
  printf("Testing find_random: \n");
	srand(time(NULL));
	find_random(list);
	find_random(list);
	find_random(list);
  find_random(list);
  printf("\n================================================\n");

  //testing remove_song
  printf("Testing remove_song: \n");
  remove_song(list, "Radiohead", "No Surprises");
  remove_song(list, "Radiohead", "Karma Police");
  printf("\n\nHere's the updated library after the remove: ");
  print_list(list);
  printf("\n================================================\n");

  //testing free_list
  printf("Testing free_list: \n");
	free_list(list);
  printf("================================================\n");

  //TESTING MUSIC LIBRARY
  printf("TESTING MUSIC LIBRARY \n================================================\n");

  initialize_playlist();
	//some old school hip hop
	add_song("Tupac", "Changes");
	add_song("Tupac", "California Love");
	add_song("Biggie", "Juicy");
	add_song("Wu-Tang Clan", "CREAM");
	add_song("Dr Dre", "Forgot About Dre");
	add_song("Mobb Deep", "Shook Ones");
	add_song("MC Hammer", "U Can't Touch This");
	add_song("Nas", "Hate Me Now");
	add_song("NWA", "Straight Outta Compton");

	//testing print_all
  printf("Testing print_all: \n\n");
	print_all();
  printf("================================================\n");

  //testing print_letter
  printf("Testing print_letter: \n");
	print_letter('N');
	print_letter('F');
	print_letter('D');
  printf("\n================================================\n");

  //testing print_artist
  printf("Testing print_artist: \n");
	print_artist("Tupac");
	print_artist("Kendrick Lamar");
  printf("\n================================================\n");

	//testing delete_song
  printf("Testing delete_song: \n");
	delete_song("MC Hammer", "U Can't Touch This");
	print_artist("MC Hammer");
  delete_song("A Tribe Called Quest", "Scenario");
  printf("\n================================================\n");

  //testing shuffle
  printf("Testing shuffle: \n");
  srand(time(NULL));
	shuffle();
	shuffle();
	shuffle();
  printf("\n================================================\n");

	//testing delete_all
  printf("Testing delete_all: \n");
	delete_all();
	print_all();
  printf("\nThat's all folks! \n");


}
