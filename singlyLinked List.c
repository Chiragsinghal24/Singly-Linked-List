// making singly linked list intially
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
    printf("elements of linked list are: \n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    create();
    display();
    return 0;
}
