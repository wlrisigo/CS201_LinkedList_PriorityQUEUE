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
	if(pqueue->tail!=NULL){
	return(pqueue->tail);
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
		printf(" %d", theList->priority);
		theList = theList->next;
	}
	printf(" \n");
	return(0);
}

//////////////////////////////// TESTING ////////////////////////////////
void pqueue_test_2() {
	 PQueue pqueue;
	 DataNode *data;
	 int priority;
	 printf("start of test_2()\n");
	 // initialize a priority queue
	 pqueue.head = NULL;
	 pqueue.tail = NULL;
	 // enqueue data with priority = 8
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data four-a");
	 priority = 4;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 // enqueue data with priority = 3
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data three");
	 priority = 3;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 // enqueue data with priority = 10
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data ten");
	 priority = 10;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 priority = getMinPriority(&pqueue);
	 data = (DataNode *) dequeue(&pqueue);
	 if (data == NULL) {
	 printf("ERROR: expect data to be non-null\n");
	 } else {
	 printf("dequeue: %s, priority = %d\n", data->name, priority);
	 }
	 // enqueue data with priority = 4
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data four-b");
	 priority = 4;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 // enqueue data with priority = 6
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data six");
	 priority = 6;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 priority = getMinPriority(&pqueue);
	 data = (DataNode *) dequeue(&pqueue);
	 if (data == NULL) {
	 printf("ERROR: expect data to be non-null\n");
	 } else {
	 printf("dequeue: %s, priority = %d\n", data->name, priority);
	 }
	// enqueue data with priority = 1
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data one");
	 priority = 1;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 priority = getMinPriority(&pqueue);
	 data = (DataNode *) dequeue(&pqueue);
	 if (data == NULL) {
	 printf("ERROR: expect data to be non-null\n");
	 } else {
	 printf("dequeue: %s, priority = %d\n", data->name, priority);
	 }
	 // enqueue data with priority = 9
	 data = (DataNode *) malloc(sizeof(DataNode));
	 strcpy(data->name, "data nine");
	 priority = 9;
	 printf("enqueue %s %d\n", data->name, priority);
	 enqueue(&pqueue, priority, data);
	 priority = getMinPriority(&pqueue);
	 data = (DataNode *) peek(&pqueue);
	 if (data == NULL) {
	 printf("ERROR: expect data to be non-null\n");
	 } else {
	 printf("peek: %s, priority = %d\n", data->name, priority);
	 }
	 priority = getMinPriority(&pqueue);
	 printQueue(&pqueue);
	 data = (DataNode *) dequeue(&pqueue);
	 while (data != NULL) {
	 printf("dequeue: %s, priority = %d\n", data->name, priority);
	 priority = getMinPriority(&pqueue);
	 data = (DataNode *) dequeue(&pqueue);
	 }
	 printf("end of test_2()\n");
	 printf("\n");
	}


//////////////////////////////// MAIN //////////////////////

int main(int argc, char *argv[])
{
	pqueue_test_2();
	return(0);
}





