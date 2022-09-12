// first create the singly linked list intially
// than reverse the linked list by reversing the address and head
// making head at last

#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head,*temp,*newnode;

void create(){
    head=0;
    int ch;
    printf("enter choice: ");
    scanf("%d",&ch);
    while(ch!=0){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=0;
        printf("enter data: ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=temp->next;
        }
        printf("if u want to continue enter choice (1/0): ");
        scanf("%d",&ch);
    }
}

void display(){
    temp=head;
    printf("\nelements of linked list are: \n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


void reverse(){
    struct node *currentnode,*prevnode,*nextnode;
    prevnode=0;
    currentnode=nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}


int main()
{
    create();
    display();
    reverse();        
    display();            //after reversing
    return 0;
}