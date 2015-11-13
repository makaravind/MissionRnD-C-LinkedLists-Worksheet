/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void Insert(struct node **head, int data){

	struct node *p, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	p = *head;

	// insert at the begining
	newnode->num = data;
	newnode->next = p;
	*head = newnode;
}
struct node * numberToLinkedList(int N) {

	//init checking
	if (N < 0) N = -N;

	struct node *head = NULL;
	if (N == 0){
		struct node *newnode = (struct node*)malloc(sizeof(struct node));
		newnode->num = 0;
		newnode->next = NULL;
		head = newnode;
		return head;
	}
	while (N != 0){
		int digit = N % 10;
		Insert(&head, digit);
		N /= 10;
	}

	return head;
}