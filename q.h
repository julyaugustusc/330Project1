#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#include "tcb.h"

#ifndef _Q_H_
#define _Q_H_


//struct TCB_t* NewItem();
//void InitiQueue(struct queue *head);
//void AddQueue(struct queue *head, struct TCB_t *item);
//struct TCB_t* DelQueue(struct queue *head);
//void RotateQ(struct queue *head);


typedef struct queue {
	struct TCB_t* header;
} queue;

struct TCB_t* NewItem() {
	struct TCB_t* item;

	item = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	return item;
}

void InitQueue(struct queue *head) {
	head->header = NULL;

	return;

}

void AddQueue(struct queue *head, struct TCB_t *item) {
	//empty
	if (head->header == NULL) {
		item->prev = item; //should loop back to themselves, not be empty if circular
		item->next = item;
		head->header = item;
		
	}
	else {
		//not empty

		//Added to end
		item->prev = head->header->prev;
		item->next = head->header;
		head->header->prev->next = item;
		head->header->prev = item; //prev of header is at the end
		
		//old
		//Added to beginning
		//item->next = *head;
		//item->next->prev = *item;
		//end->next = *item;
		//item->prev = *end;
		//*head = *item;
	}

	return;
}

struct TCB_t* DelQueue(struct queue *head) {
	struct TCB_t* toDelete = head->header;

	if (toDelete->next == toDelete || head->header == NULL) { //if it loops back on itself (has only 1 item), or is empty
		head->header = NULL;
		
	}
	else {
		head->header->prev->next = head->header->next;
		head->header->next->prev = head->header->prev;
		head->header = head->header->next;
	}

	toDelete->next = NULL; // I feel like these should be nulled
	toDelete->prev = NULL;

	return toDelete;

}

void RotateQ(struct queue *head) {

	head->header = head->header->next;

	return;

}

#endif // _Q_H_