/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
void Init(struct node *b, struct node *c){
	//a = NULL;
	*b = *c;
	*c = *c->next->next;
}
struct node * removeEveryKthNode(struct node *head, int K) {
	//init checking
	if (head == NULL) return NULL;
	if (K <= 1) return NULL;

	//pointers
	struct node *before = (struct node*)malloc(sizeof(struct node));
	struct node *at = (struct node*)malloc(sizeof(struct node));
	struct node *after = (struct node*)malloc(sizeof(struct node));

	// initalize
	int t = 1;
	at = head;
	before = at;
	after = before->next->next;

	while (/*after != NULL || */before != NULL)
	{
		if (t == (K - 1))
		{
			t = 1;
			before->next = after;
			before = after;
			if (after == NULL) continue;
			after = after->next->next;
			//Init(before, after);
		}
		else {
			t++;
			before = before->next;
			if (after == NULL) continue;
			after = after->next;
		}
	}
	*head = *at;
}

/*int t = 1;
before = NULL;
at = head;
after = at->next;*/
//Init(before, at, after);
/*	while (at!=NULL)
{
if (t != K){
t++;
if (before == NULL) before = at;
else before = before->next;
at = at->next;
after = after->next;
}
else if (t == K){
t = 1;
before->next = after->next;
before = NULL;
Init( at, after);
}
}*/
