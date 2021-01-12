#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    Node *next; 
} *head, *tail; 

int max=0;
int min=1000;

Node *createNode(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    if(max<value){
        max=value;
    }
    if(min>value){
        min=value;
    }
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
    pushHead(3);
    pushTail(5);
    pushTail(8);
    printf("min: %d\n", min);
    printf("max: %d\n", max); //ka max nya masih ngaco
    printf("range: %d\n", max-min);
    return 0;
}