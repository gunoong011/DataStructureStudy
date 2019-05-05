#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_Queue.h"

ArrayQueue* createArrayQueue(int maxElementCount) {
    ArrayQueue *pReturn = NULL;

    if(maxElementCount > 0) {
        pReturn = (ArrayQueue *)malloc(sizeof(ArrayQueueNode));
        if(pReturn == NULL) {
            printf("memory Allocation Failed\n");
            return NULL;
        } else {
            memset(pReturn, 0, sizeof(ArrayQueue));
            pReturn->currentElementCount = 0;
            pReturn->front = -1;
            pReturn->maxElementCount = maxElementCount;
            pReturn->rear = -1;
        }
    } else {
        printf("maxElement must be more than 0\n");
        return NULL;
    }
    pReturn->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
    if(pReturn->pElement != NULL) {
        memset(pReturn->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);
    } else {
        printf("Memory Allocation Failed\n");
        free(pReturn);
        return NULL;
    }
    return pReturn;
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
    ArrayQueueNode *pNode;
    if(pQueue != NULL) {
        if(!isArrayQueueFull(pQueue)) {
            pQueue->pElement[pQueue->currentElementCount] = element;
            if(isArrayQueueEmpty(pQueue)) pQueue->front = 0;
            //if(pQueue->rear = pQueue->maxElementCount - 1) pQueue->rear = 0;
            else pQueue->rear++;
            pQueue->currentElementCount++;
        } else {
            printf("Queue is full\n");
            return FALSE;
        }
    } else {
        printf("Queue is NULL\n");
        return FALSE;
    }
    return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) {
    ArrayQueueNode *pNode;
    if(pQueue != NULL) {
        if(!isArrayQueueEmpty(pQueue)) {
            pNode = &pQueue->pElement[pQueue->front];
            if(pQueue->front = pQueue->maxElementCount - 1) pQueue->front = 0;
            else pQueue->front++;
            pQueue->currentElementCount--;
        } else {
            printf("Underflow!\n");
            return NULL;
        }
    } else {
        printf("Queue is NULL\n");
        return NULL;
    }
    return pNode;
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue) {
    ArrayQueueNode *pNode;
    if(pQueue != NULL) {
        if(!isArrayQueueEmpty(pQueue)) {
            pNode = &pQueue->pElement[pQueue->front];
            return pNode;
        } else {
            printf("Queue is Empty\n");
        }
    } else {
        printf("Queue is NULL\n");
    }
    return NULL;
}

void deleteArrayQueue(ArrayQueue* pQueue) {
    if(pQueue != NULL) {
        free(pQueue->pElement);
        free(pQueue);
    }
}

int isArrayQueueFull(ArrayQueue* pQueue) {
    int ret = TRUE;
    if(pQueue != NULL) {
        if(pQueue->currentElementCount == pQueue->maxElementCount) return ret;
        ret = FALSE;
    } else {
        printf("Queue is NULL");
    }
    return ret;
}
int isArrayQueueEmpty(ArrayQueue* pQueue) {
    int ret = TRUE;
    if(pQueue != NULL) {
        if(pQueue->currentElementCount == 0) return ret;
        ret = FALSE;
    } else {
        printf("Queue is NULL");
    }
    return ret;
}