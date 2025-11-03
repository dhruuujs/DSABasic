#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};


void insertFront(struct Node** head, int data){
struct Node* newNode=malloc(sizeof(struct Node));
newNode->data=data;
if(*head==NULL){
    newNode->next=NULL;
    newNode->prev=NULL;
    *head=newNode;
    return;
}
newNode->next=*head;
newNode->prev=NULL;
(*head)->prev=newNode;
*head=newNode;
}


void insertBack(struct Node** head,int data){
struct Node* newNode = malloc(sizeof(struct Node));
newNode->data=data; 
newNode->next=NULL;
newNode->prev=NULL;
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}


void removeFront(struct Node** head){
if(*head==NULL){
    printf("List is empty!\n");
    return;
}
struct Node* temp = *head;
*head=temp->next;
if(*head!=NULL){
(*head)->prev=NULL;
}
free(temp);
}


void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;  
        }
        free(temp);
        return;
    }
    struct Node* temp = *head;
    while (temp!= NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    // temp is the node to delete
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
 free(temp);
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
insertFront(&head,15);
insertFront(&head,10);//head
insertBack(&head,20);
insertBack(&head,25);
insertBack(&head,30);
removeFront(&head);

printList(head);

return 0;
}