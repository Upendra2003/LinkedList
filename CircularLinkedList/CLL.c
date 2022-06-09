#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void createEmptyList(node **tail,node **head);
void printList_1(node *head);
void printList_2(node *tail);
void addAtBeg(node **head,node **tail,int n);
void addAtEnd(node **head,node **tail,int n);
void addAtPos(node **head,node **tail,int n,int pos);
void deleteBeg(node **head,node **tail);
void deleteAtEnd(node **head,node **tail);
void deleteAtPos(node **head,node **tail,int pos);
void deleteList(node **head);

int main(){
    node *tail,*head;
    int choice,ele,pos;
    createEmptyList(&tail,&head);
    printf("1.Print List using head.\n");
    printf("2.Print List using tail.\n");
    printf("3.Add element at the begining.\n");
    printf("4.Add element at the end.\n");
    printf("5.Add element at a position.\n");
    printf("6.Delete first element.\n");
    printf("7.Delete last element.\n");
    printf("8.Delete element at a position.\n");
    while(1){
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printList_1(head);
                    break;
            case 2: printList_2(tail);
                    break;
            case 3: printf("Enter an element :");
                    scanf("%d",&ele);
                    addAtBeg(&head,&tail,ele);
                    break;
            case 4: printf("Add an element :");
                    scanf("%d",&ele);
                    addAtEnd(&head,&tail,ele);
                    break;
            case 5: printf("Add an element :");
                    scanf("%d",&ele);
                    printf("Enter position :");
                    scanf("%d",&pos);
                    addAtPos(&head,&tail,ele,pos);
                    break;
            case 6: deleteBeg(&head,&tail);
                    break;
            case 7: deleteAtEnd(&head,&tail);
                    break;
            case 8: printf("Enter position :");
                    scanf("%d",&pos);
                    deleteAtPos(&head,&tail,pos);
                    break;
            case 9: deleteList(&head);
                    exit(1);
        }
    }
    return 0;
}

void createEmptyList(node **tail,node **head){
    *head=*tail=NULL;
}

void printList_1(node *head){
    node *ptr;
    if(head==NULL)
        printf("\nList is empty");
    else{
        ptr=head;
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
}

void printList_2(node *tail){
    node *ptr;
    if(tail==NULL){
        printf("List is empty.");
    }else{
        ptr=tail->next;
        do{
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }while(ptr!=tail->next);
    }
}

void addAtBeg(node **head,node **tail,int n){
    node *newNode=malloc(sizeof(node));
    newNode->data=n;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        newNode->next=*head;
    }else{
        newNode->next=(*tail)->next;
        *head=newNode;
        (*tail)->next=*head;
    }
}

void addAtEnd(node **head,node **tail,int n){
    node *newNode=malloc(sizeof(node));
    newNode->data=n;
    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
        newNode->next=*head;
    }else{
        (*tail)->next=newNode;
        *tail=newNode;
        newNode->next=*head;
    }
}

void addAtPos(node **head,node **tail,int n,int pos){
    node *ptr,*newNode=malloc(sizeof(node));
    newNode->data=n;
    ptr=*head;
    for(int i=0;i<pos;i++)
        ptr=ptr->next;
    newNode->next=ptr->next;
    ptr->next=newNode;
}

void deleteBeg(node **head,node **tail){
    if(*head==NULL)
        printf("\nList is empty.");
    else{
        *head=(*head)->next;
        (*tail)->next=*head;
    }
}

void deleteAtEnd(node **head,node **tail){
    node *ptr;
    if(*head==NULL)
        printf("\nList is empty.");
    else{
        ptr=*head;
        do{
            ptr=ptr->next;
        }while(ptr->next->next!=*head);
        ptr->next=*head;
        *tail=ptr;
    }
}

void deleteAtPos(node **head,node **tail,int pos){
    node *ptr;
    if(*head==NULL)
        printf("\nList is empty.");
    else{
        ptr=*head;
        for(int i=0;i<pos-1;i++)
            ptr=ptr->next;
        ptr->next=ptr->next->next;
    }
}

void deleteList(node **head){
    node *ptr,*del;
    ptr=*head;
    while(ptr!=*head){
        del=ptr;
        ptr=ptr->next;
        free(del);
    }
    printf("The linked list is free now.");
}