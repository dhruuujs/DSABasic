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



void deleteFront(struct Node** head){
    struct Node* temp = (*head)->next;
    *head=temp;
    free(*head);
}



void deleteBack(struct Node** head){
    if(*head==NULL){
        printf("List is empty!\n");
    }

    if((*head)->next==NULL){
        free(*head);
        *head=NULL;
        return;
    }

    struct Node* temp=*head;
    while(temp->next->next!=NULL){
    temp=temp->next;
    }
temp->next=NULL;
free(temp->next);
}



void insertAt(struct Node** head, int data, int pos){
struct Node* newNode=malloc(sizeof(struct Node));
newNode->data=data;
newNode->next=NULL;
    if(*head==NULL && pos!=1){
    printf("List is empty!");
    free(newNode);
    return;
    }
    struct Node* temp=*head;
    int flag=1;
        while(temp!=NULL && flag<pos-1){
            temp=temp->next;
            flag++;
        }
    if(temp==NULL){
        printf("Position");
        free(newNode);
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteByValue(struct Node** head,int value){
    if(*head==NULL){
        printf("List is empty!\n");
        return;
    }

    if((*head)->data==value){
        struct Node* temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }

    struct Node* temp=*head;
    while(temp->next!=NULL && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Element not found\n");
        return;
    }
    struct Node* delEle=temp->next;
    temp->next=temp->next->next;
    free(delEle);
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

insertAt(&head,18,3);

printList(head);

deleteFront(&head);
deleteByValue(&head,25);

printList(head);
    

return 0;
}

