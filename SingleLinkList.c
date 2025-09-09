#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


void insertFront(struct Node** head, int data){
    
}


void printList(struct Node* head){

    while(head!=NULL){
        printf("%d",head->data);
        head=head->next;
    }
    printf("NULL");
}

int main(){
struct Node* head=NULL;


    return 0;
}

