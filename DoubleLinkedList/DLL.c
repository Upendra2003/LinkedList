#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

void createList(node **head,node **tail);
void printList1(node *head);
void printList2(node *tail);
void insertAtBeg(node **head,node **tail,int n);
void insertAtEnd(node **head,node **tail,int n);
void insertAtLoc(node **head,node **tail,int n,int loc);
void deleteFirstNode(node **head,node **tail);
void deleteLastNode(node **head,node **tail);
void deleteAtLoc(node **head,node **tail,int loc);
void deleteList(node **head);

int main(){
    node *head,*tail;
    createList(&head,&tail);
    int choose,ele,loc;
    printf("1.Print List using head.\n");
    printf("2.Print List using tail(In reverse order).\n");
    printf("3.Insert at the begining.\n");
    printf("4.Insert at the End.\n");
    printf("5.Insert an element at a location.\n");
    printf("6.Delete first node.\n");
    printf("7.Delete last element.\n");

    while(1){
        printf("\nChoose an operation :");
        scanf("%d",&choose);
        switch(choose){
            case 1: printList1(head);
                    break;
            case 2: printList2(tail);
                    break;
            case 3: printf("\nEnter an element to add : ");
                    scanf("%d",&ele);
                    insertAtBeg(&head,&tail,ele);
                    break;
            case 4: printf("\nEnter an element to add : ");
                    scanf("%d",&ele);
                    insertAtEnd(&head,&tail,ele);
                    break;
            case 5: printf("Enter the position : ");
                    fflush(stdin);
                    scanf("&d",&loc);
                    fflush(stdin);
                    printf("Enter element : ");
                    scanf("%d",&ele);
                    insertAtLoc(&head,&tail,ele,loc);
                    break;
            case 6: deleteFirstNode(&head,&tail);
                    break;
            case 7: deleteLastNode(&head,&tail);
                    break;
            case 8: printf("Enter position : ");
                    scanf("%d",&loc);
                    deleteAtLoc(&head,&tail,loc);
                    break;
            case 9: deleteList(&head);
                    break;
        }
    }
    return 0;
}

void createList(node **head,node **tail){
    *head=*tail=NULL;
}

void printList1(node *head){
    if(head==NULL){
        printf("\nList is empty.");
    }else{
        while(head!=NULL){
            printf("%d ",head->data);
            head=head->next;
        }
    }
}

void printList2(node *tail){
    if(tail==NULL){
        printf("\nList is empty.");
    }else{
        while(tail!=NULL){
            printf("%d ",tail->data);
            tail=tail->prev;
        }
    }
}

void insertAtBeg(node **head,node **tail,int n){
    node *newNode=malloc(sizeof(node));
    newNode->data=n;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(*head==NULL && *tail==NULL){
        *head=*tail=newNode;
    }else{
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}

void insertAtEnd(node **head,node **tail,int n){
    node *newNode=malloc(sizeof(node));
    newNode->data=n;
    newNode->prev=NULL;
    newNode->next=NULL;
    if(*head==NULL && *tail==NULL){
        *head=*tail=newNode;
    }else{
        (*tail)->next=newNode;
        newNode->prev=*tail;
        *tail=newNode;
    }  
}

void insertAtLoc(node **head,node **tail,int n,int loc){
    node *newNode=malloc(sizeof(node)),*ptr;
    ptr=*head;
    newNode->data=n;
    newNode->prev=NULL;
    newNode->next=NULL; 
    if(*head==NULL && *tail==NULL){
        *head=*tail=newNode;
    }else{
        printf("v");
        for(int i=0;i<loc-1;i++){
            ptr=ptr->next;
            printf("l");
        }
        printf("e");
        ptr->next->prev=newNode;
        newNode->next=ptr->next;
        ptr->next=newNode;
        newNode->prev=ptr;
    }  
}

void deleteFirstNode(node **head,node **tail){
    if(*head==NULL){
        printf("Link is empty.\n");
    }else{
        *head=(*head)->next;
    }
}

void deleteLastNode(node **head,node **tail){
    node *ptr;
    if(*head==NULL){
        printf("Link is empty.\n");
    }else{
        ptr=*head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=NULL;
        *tail=ptr;
    }
}

void deleteAtLoc(node **head,node **tail,int loc){
    node *ptr;
    if(*head==NULL){
        printf("Link is empty.\n");
    }else{
        ptr=*head;
        for(int i=0;i<loc-1;i++){
            ptr=ptr->next;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
    }
}

void deleteList(node **head){
    node *ptr;
    while(*head!=NULL){
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
    printf("\nThe list is Free.");
}

