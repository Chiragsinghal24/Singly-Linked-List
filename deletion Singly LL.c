// first create singly linked list intially
//than go for deletion in linked list

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


void delete_from_beg(){
    if(head==0){
        printf("list is empty");
    }                               //here maintain 1 pointer to delete 
    else{
        temp=head;
        head=head->next;
        free(temp);           // to free garbage value
    }
}


void delete_from_end(){
    struct node *prev;
    temp=head;                 //here 2 pointer to delete
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
    }
    prev->next=0;
    free(temp);
}


void delete_at_pos(){
    struct node* nextnode;
    int pos;
    int i=1;
    printf("\nenter the position to delete element \n");
    scanf("%d",&pos);
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    nextnode=temp->next;
    temp->next=nextnode->next;       //for deletion code 
    free(nextnode);
}


void display(){
    temp=head;
    printf("\nelements of linked list are: \n");
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}


int main()
{
    create();
    display();             //intial display
    delete_from_beg();    
    display();             //after delete at beg
    delete_from_end();
    display();            //after delete at end
    delete_at_pos();
    display();             //after delete at pos
    
    return 0;
}
