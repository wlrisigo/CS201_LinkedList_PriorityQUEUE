/*
 * Linked.c
 *
 *  Created on: Sep 13, 2018
 *      Author: wlrisigo
 */

#include "p_queue.wrisigo.h"
#include <stdio.h>
#include <stdlib.h>




////////////////////////////////InsertSorted////////////////////////////////


int enqueue(PQueue *pqueue, int priority, void *data){


	PQueueNode *current;
	PQueueNode *newNode = (PQueueNode *) malloc(sizeof(PQueueNode));
	PQueue *pq = pqueue;
	PQueueNode *Head = pq->head;



	if( Head == NULL || Head->priority >= priority){

			newNode->next = Head;
			newNode->priority= priority;
			newNode->data = data;
			pq->head = newNode;
			}
	else{

				current= pq->head;
		while(current->next!=NULL && current->next->priority < priority){
			current = current->next;
		}
		//current node now bigger that priority
		//space for new node
		//new node points to what current was pointing to
		newNode->next = current->next;
		//store newNode priority
		newNode->priority = priority;
		newNode->data = data;

		//current pointer now pointing to newNode
		current->next = newNode;
		//newNode pointing to current
	}
	if(newNode->next == NULL){
		pq->tail = newNode;
	}
	return(0);
}

int getMinPriority(PQueue *pqueue){
	if(pqueue->head!=NULL){
	return(pqueue->head->priority);
	}
	return(-1);
}

void *peek(PQueue *pqueue){
	if(pqueue->head!=NULL){
	return(pqueue->head->data);
	}
	return(NULL);
}


/////////////////////////// dequeue /////////////////////////////////////


void *dequeue(PQueue *pqueue){
	PQueue *pq = pqueue;
	PQueueNode *Current = pq->head;
	PQueueNode *temp = pq->head;


		if(Current == NULL){
			return(NULL);
		}

		Current = temp->next;
		pq->head = Current;
		void *data = temp->data;
		free(temp);


	return(data);
}


//////////////////////////////// PRINT ////////////////////////////////


int printQueue(PQueue *pqueue){
	PQueue *pq = pqueue;
	PQueueNode *theList = pq->head;


	while(theList != NULL){
		char s[32];
		printf(" %d", theList->priority);
		strcpy(s, theList->data);
		printf(" %s", s);

		theList = theList->next;
	}
	printf(" \n");
	return(0);
}

//////////////////////////////// MAIN //////////////////////

int main(int argc, char *argv[])
{
	pqueue_test_1();
	pqueue_test_2();
	pqueue_test_3();
	pqueue_test_4();
	return(0);
}





