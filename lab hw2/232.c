#include <stdlib.h>
#include <stdbool.h>

//initializing pointers
typedef struct {
    int* stackPush; 
    int* stackPop;  
    int pushTop;    
    int popTop;     
    int capacity;   
} MyQueue;

// creating a new queue
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100;
    queue->stackPush = (int*)malloc(queue->capacity * sizeof(int));
    queue->stackPop = (int*)malloc(queue->capacity * sizeof(int));
    queue->pushTop = -1;
    queue->popTop = -1;
    return queue;
}

// function to transfer elements from push to pop stack
void transferElements(MyQueue* obj) {
    // only transferring if the pop stack is empty
    if (obj->popTop == -1) {
        // transfers all elements from push stack to pop stack and reverses the order
        while (obj->pushTop >= 0) {
            obj->stackPop[++(obj->popTop)] = obj->stackPush[(obj->pushTop)--];
        }
    }
}

// push operations
void myQueuePush(MyQueue* obj, int x) {
    obj->stackPush[++(obj->pushTop)] = x;
}

// pop operations
int myQueuePop(MyQueue* obj) {
    transferElements(obj); // checking if pop stack has elements    
    return obj->stackPop[(obj->popTop)--]; 
}

// peek opeations
int myQueuePeek(MyQueue* obj) {
    transferElements(obj); // checking if pop stack has elements    
    return obj->stackPop[obj->popTop];
}

// checking if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return (obj->pushTop == -1 && obj->popTop == -1);
}

// freeing all the allocated memory
void myQueueFree(MyQueue* obj) {
    free(obj->stackPush);
    free(obj->stackPop);
    free(obj);
}