#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct Stack{
    int top;
    int capacity;
    int* array;
};


int isFull(struct Stack* stack){
    return (stack->top==stack->capacity-1);
}


struct Stack* createStack(int capacity){
struct Stack* stack=malloc(sizeof(struct Stack));

stack->capacity=capacity;
stack->top=-1;
stack->array=malloc(sizeof(capacity * sizeof(int)));
return stack;
}


void push(struct Stack* stack,int value){
if(isFull(stack)){
    printf("Stack overflow! Can't perform push operation");
    return;
}
stack->array[++stack->top]=value;
printf("%d pushed into the stack",value);
}


void peek(struct Stack* stack){
//if(stack->top==-1)
   // printf(stack->array);

}


int main(){
    struct Stack* stack=createStack(5);
    bool a=1;
    printf("%d",a);
   // push(stack,5);
    //printf("Hello World!");
    return 0;
}