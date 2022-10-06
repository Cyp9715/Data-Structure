#include "Queue.h"

Queue* CreateQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

Node* NewNode(void* data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void EnQueue(Queue* queue, void* data)
{    
    // Create a new LL node
    Node* temp = NewNode(data);

    // If queue is empty, then new node is front and rear both
    if (queue->rear == NULL) 
    {
        queue->front = queue->rear = temp;
    }
    else
    {
        // Add the new node at the end of queue and change rear
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

// Function to remove a key from given queue q
void DeQueue(Queue* queue)
{
    // If queue is empty, return NULL.
    if (queue->front == NULL)
    {
        return;
    }
  
    // Store previous front and move front one node ahead
    Node* temp = queue->front;
  
    queue->front = queue->front->next;
  
    // If front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
        queue->rear = NULL;
  
    free(temp);
}



void EnQueue_Lock(Queue* queue, void* data)
{    
    pthread_mutex_lock(&lock_EnQueue);

    // Create a new LL node
    Node* temp = NewNode(data);

    // If queue is empty, then new node is front and rear both
    if (queue->rear == NULL) 
    {
        queue->front = queue->rear = temp;
    }
    else
    {
        // Add the new node at the end of queue and change rear
        queue->rear->next = temp;
        queue->rear = temp;
    }

    pthread_mutex_unlock(&lock_EnQueue);
}

// Function to remove a key from given queue q
void DeQueue_Lock(Queue* queue)
{
    pthread_mutex_lock(&lock_DeQueue);

    // If queue is empty, return NULL.
    if (queue->front == NULL)
    {
        return;
    }
  
    // Store previous front and move front one node ahead
    Node* temp = queue->front;
  
    queue->front = queue->front->next;
  
    // If front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
        queue->rear = NULL;
  
    free(temp);

    pthread_mutex_unlock(&lock_DeQueue);
}