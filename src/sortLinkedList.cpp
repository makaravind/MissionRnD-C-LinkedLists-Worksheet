/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}
int Length(struct node *ptr){
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp = ptr;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
struct node * sortLinkedList(struct node *head) {
	//init checking 
	if (head == NULL) return NULL;

	int swapped, i;
	struct node *ptr1;
	struct node *lptr = NULL;

	do
	{
		swapped = 0;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (ptr1->num > ptr1->next->num)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);

	return head;
}
