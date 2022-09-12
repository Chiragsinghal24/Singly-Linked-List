// first we have to create singly linked list 
// than we have to go for insertion

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


void insert_at_beginning(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data u want to insert at beg:\n ");
    scanf("%d",&newnode->data);
    newnode->next=head;          //in insertion always we update right
    head=newnode;
}


void insert_at_end(){
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter data u want to insert at end:\n ");
    scanf("%d",&newnode->data);
    newnode->next=0; 
    while(temp->next!=0){
        temp=temp->next;          //transverse till last
    }
    temp->next=newnode;        // assigning node at last;
    temp=temp->next;
}


void insert_at_pos(){                //at any position insertion
    int pos;
    int length=0;
    temp=head;
    printf("\nenter the position after which u want to insert:\n ");
    scanf("%d",&pos);
    while(temp!=0){
        length++;           //finding length of linked list
        temp=temp->next;
    }
    if(pos>length){
        printf("wrong position \n");
    }
    else{
        int i=1;
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter data:\n");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
}


void display(){
    temp=head;
    printf("elements of linked list are: \n");
    while(temp!=0){
        printf("%d ",temp->data);     
        temp=temp->next;
    }
}


int main()
{
    create();
    display();            //before insertion at beg
    insert_at_beginning();
    display();            //after insertion at beg
    insert_at_end();
    display();            //after insetion at end
    insert_at_pos();
    display();            //after insertion at pos
    return 0;
}
