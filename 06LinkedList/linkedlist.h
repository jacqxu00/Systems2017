struct node {
	int i;
	struct node * next;
};

/* declare all functions */
void print_list(struct node * list);
struct node * insert_front(struct node * list, int x);
struct node * free_list(struct node * list);
