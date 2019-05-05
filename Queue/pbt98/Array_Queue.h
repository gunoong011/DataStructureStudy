#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

typedef struct ArrayQueueNodeType {
    char element;
} ArrayQueueNode;

typedef struct ArrayQueueType {
    int maxElementCount;
    int currentElementCount;
    int front;
    int rear;
    ArrayQueueNode *pElement;
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF
#define _COMMON_QUEUE_DEF

#define TRUE 1
#define FALSE 0

#endif
