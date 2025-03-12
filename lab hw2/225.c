#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int elements[100];  
    int head;           
    int tail;           
} SimpleQueue;

typedef struct {
    SimpleQueue primary;  
    SimpleQueue secondary;
} MyStack;

// resetting queue to empty state
void resetQueue(SimpleQueue* queue) {
    queue->head = 0;
    queue->tail = 0;
}

// checking if queue has no elements
bool isQueueEmpty(SimpleQueue* queue) {
    return queue->head == queue->tail;
}

// adding element to the queue
void addToQueue(SimpleQueue* queue, int value) {
    queue->elements[queue->tail++] = value;
}

// removing element from queue
int removeFromQueue(SimpleQueue* queue) {
    return queue->elements[queue->head++];
}

// viewing front element without removing
int viewFront(SimpleQueue* queue) {
    return queue->elements[queue->head];
}

// creating new stack
MyStack* myStackCreate() {
    MyStack* newStack = (MyStack*)malloc(sizeof(MyStack));
    resetQueue(&newStack->primary);
    resetQueue(&newStack->secondary);
    return newStack;
}

// adding element to stack 
void myStackPush(MyStack* stack, int value) {
    addToQueue(&stack->secondary, value);
    
    // moving everything from primary to secondary
    while (!isQueueEmpty(&stack->primary)) {
        addToQueue(&stack->secondary, removeFromQueue(&stack->primary));
    }
    
    // swapping the queues so new element is at front
    SimpleQueue tempQueue = stack->primary;
    stack->primary = stack->secondary;
    stack->secondary = tempQueue;
}

// removing and viewing top element
int myStackPop(MyStack* stack) {
    return removeFromQueue(&stack->primary);
}

// viewing top element without removing 
int myStackTop(MyStack* stack) {
    return viewFront(&stack->primary);
}

// chceking if the stack iss empty
bool myStackEmpty(MyStack* stack) {
    return isQueueEmpty(&stack->primary);
}

// cleaning up the stack memory 
void myStackFree(MyStack* stack) {
    free(stack);
}