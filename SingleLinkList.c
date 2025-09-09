#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};



void insertFront(struct Node** head, int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
}



void insertBack(struct Node** head, int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}



void printList(struct Node* head){

    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}



int main(){
struct Node* head=NULL;

insertFront(&head,10);
insertFront(&head,15);
insertBack(&head,20);


printList(head);
    return 0;
}

