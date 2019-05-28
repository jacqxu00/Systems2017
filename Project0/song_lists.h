struct song_node{
	char name[256];
	char artist[256];
	struct song_node *next;
};

/* declare all functions */
void print_list(struct song_node * list);
void print_node(struct song_node *list);
int compare_nodes(struct song_node * a, struct song_node * b);
int compare_nodes_testing(char * personA, char * songA, char * personB, char *songB);
struct song_node * insert_front(struct song_node * list, char *person, char *song);
struct song_node * insert_end(struct song_node * list, char *person, char *song);
struct song_node * insert_song(struct song_node * list, char *person, char *song);
struct song_node * initialize_song(char * person, char * song);
struct song_node * free_list(struct song_node * list);
struct song_node * find_node(struct song_node * list, char * person, char * song);
struct song_node * find_node_testing(struct song_node * list, char * person, char *song);
struct song_node * find_artist(struct song_node * list, char * person);
int length_of(struct song_node * list);
struct song_node * find_random(struct song_node * list);
struct song_node * remove_song(struct song_node * list, char *person, char *song);
