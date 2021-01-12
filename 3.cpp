#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next; 
} *head, *tail; 

int count=0;

Node *createNode(int value){
    count++;
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
}

void pushHead(int value){
    Node *temp=createNode(value);

    if(!head){ 
        head=tail=temp;
    }
    else{ 
        temp->next=head; 
        head=temp; 
    }
}

void pushTail(int value){
    Node *temp=createNode(value); 

    if(!head){ 
        head=tail=temp; 
    } 
    else{ 
        tail->next=temp; 
        tail=temp; 
    }
}

void popHead(){
    if(!head){ 
        return; 
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{ 
        Node *temp=head->next; 
        head->next=NULL; 
        free(head);
        head=temp; 
    }
}

void popTail(){
    if(!head){ 
        return;
    }
    else if(head==tail){
        free(head);
        head=tail=NULL;
    }
    else{ 
        Node *temp=head; 
        
        while(temp->next!=tail){
            temp=temp->next;
        }

        temp->next=NULL;
        free(tail);
        tail=temp;
    }
}

int main(){
    pushHead(2);
    pushTail(4);
    pushTail(5);
    pushTail(8);
    pushTail(10);

    Node *curr=head;

    int count1=count/2;

    for(int i=0; i<count; i++){
        if(i==count1){
            printf("%d\n", curr->value);
            break;
        }
        curr=curr->next;
    }

    return 0;
}