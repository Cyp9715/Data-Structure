#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include "pthread.h"

// A linked list (LL) node to store a queue entry
typedef struct Node 
{
    void* data;
    struct Node* next;
} Node;

// The queue, front stores the front node of LL and rear stores the
// last node of LL
typedef struct Queue 
{
    Node *front;
    Node *rear;
} Queue;
  
// A utility function to create an empty queue
Queue* CreateQueue();

// A utility function to create a new linked list node.
Node* NewNode(void* data);
  
// The function to add a key k to q
void EnQueue(Queue* queue, void* data);
  
// Function to remove a key from given queue q
void DeQueue(Queue* queue);


// MutexQueue
pthread_mutex_t lock_EnQueue;
pthread_mutex_t lock_DeQueue;

void EnQueue_Lock(Queue* queue, void* data);

void DeQueue_Lock(Queue* queue);

#endif
