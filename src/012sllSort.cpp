/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
void Insert1(struct node **head, int data){

	struct node *p, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	p = *head;

	// Insert1 at the begining
	newnode->data = data;
	newnode->next = p;
	*head = newnode;
}
void sll_012_sort(struct node *head){

	// corresponding heads
	struct node *zerohead = (struct node*)malloc(sizeof(struct node));
	struct node	*onehead = (struct node*)malloc(sizeof(struct node));
	struct node *twohead = (struct node*)malloc(sizeof(struct node));

	//pointers
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	struct node *ptr1 = (struct node*)malloc(sizeof(struct node));

	//initalize
	zerohead = NULL;
	onehead = NULL;
	twohead = NULL;
	ptr1 = NULL;
	ptr = head;

	while (ptr != NULL)
	{
		if (ptr->data == 0) Insert1(&zerohead, 0);
		else if (ptr->data == 1)Insert1(&onehead, 1);
		else Insert1(&twohead, 2);

		ptr = ptr->next;
	}

	if (zerohead != NULL && onehead != NULL && twohead != NULL){
		// forming complete LL
		ptr1 = zerohead;
		ptr = zerohead;

		while (ptr->next != NULL){
			ptr = ptr->next;
		};

		ptr->next = onehead;

		// get to tail of onehead and append two
		ptr = onehead;
		while (ptr->next != NULL){
			ptr = ptr->next;
		};

		ptr->next = twohead;

		*head = *ptr1;
	}

}