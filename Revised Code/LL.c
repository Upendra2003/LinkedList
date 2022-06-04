#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void createList(struct node **head);
void printList(struct node *head);
void addAtBegin(struct node **head,int n);
void addAtEnd(struct node **head,int n);
void addAtPos(struct node **head,int n,int pos);
void deleteAtBegin(struct node **head);
void deleteAtEnd(struct node **head);
void deleteAtLoc(struct node **head,int pos);
void searchInList(struct node **head,int n);
void deleteList(struct node **head);

int main(){
    struct node *head;
    createList(&head);
    int choice,add,pos,n;
    printf("1.Print Linked List\n");
    printf("2.Insert at the begining\n");
    printf("3.Insert at the End\n");
    printf("4.Insert at a position\n");
    printf("5.Delete first node\n");
    printf("6.Delete last node\n");
    printf("7.Delete at a particular position\n");
    printf("8.Search an element in linked list\n");
    printf("9.Delete Linked List\n");
    while(1){
        printf("Enter an operation(1-9)");
        scanf("%d",&choice);
        printf("\n--------------------------------------------\n");
        switch(choice){
            case 1: if(head==NULL)
                        printf("List is empty");
                    else
                        printList(head);
                        printf("\n");
                    break;
            case 2: printf("Enter an element to insert at begining : ");
                    scanf("%d",&add);
                    addAtBegin(&head,add);
                    break;
            case 3: printf("Enter an element to insert at the end : ");
                    scanf("%d",&add);
                    addAtEnd(&head,add);
                    break;
            case 4: printf("Enter a positon: ");
                    scanf("%d",&pos);
                    printf("Enter element to add : ");
                    scanf("%d",&add);
                    addAtPos(&head,add,pos);
                    break;
            case 5: deleteAtBegin(&head);
                    break;
            case 6: deleteAtEnd(&head);
                    break;
            case 7: printf("Enter a position : ");
                    scanf("%d",&pos);
                    deleteAtLoc(&head,pos);
                    break;
            case 8: printf("Enter an element to search : ");
                    scanf("%d",&n);
                    searchInList(&head,n);
                    break;
            case 9: deleteList(&head);
                    exit(1);
        }
        printf("--------------------------------------------\n");
    }
    return 0;
}

void createList(struct node **head){
    *head=NULL;
}

void printList(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}

void addAtBegin(struct node **head,int n){
    struct node *ptr;
    ptr=malloc(sizeof(struct node));
    ptr->data=n;
    if(*head==NULL){
        ptr->next=NULL;
    }else{
        ptr->next=*head;
    }
    *head=ptr;
}

void addAtEnd(struct node **head,int n){
    struct node *newNode,*ptr;
    newNode=malloc(sizeof(struct node));
    newNode->data=n;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        ptr=*head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
}

void addAtPos(struct node **head,int n,int pos){
    struct node *ptr,*newNode;
    newNode=malloc(sizeof(struct node));
    newNode->data=n;
    newNode->next=NULL;
    if(*head==NULL){
        *head=newNode;
    }else{
        ptr=*head;
        for(int i=0;i<pos-1;i++)
            ptr=ptr->next;
        newNode->next=ptr->next;
        ptr->next=newNode;    
    }
}

void deleteAtBegin(struct node **head){
    struct node *ptr;
    if(*head==NULL){
        printf("No element to delete.\n");
    }else{
        ptr=*head;
        *head=ptr->next;
    }
    
}

void deleteAtEnd(struct node **head){
    struct node *ptr;
    if(*head==NULL){
        printf("No element to delete.\n");
    }else{
        ptr=*head;
        while(ptr->next->next!=NULL)
            ptr=ptr->next;
        ptr->next=NULL;
    }
}

void deleteAtLoc(struct node **head,int pos){
    struct node *ptr;
    if(*head==NULL){
        printf("No element to delete.\n");
    }else{
        ptr=*head;
        for(int i=0;i<pos-1;i++){
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
    }
}

void searchInList(struct node **head,int n){
    struct node *ptr;
    int found=0;
    if(*head==NULL){
        printf("Empty to search.");
    }else{
        ptr=*head;
        while(ptr->next!=NULL){
            if(ptr->data==n)
                found=1;
            ptr=ptr->next;
        }
    }
    if(found)
        printf("Element found in Linked List.\n");
    else
        printf("Element not found in Linked List.\n");
}

void deleteList(struct node **head){
    struct node *ptr;
    while(*head!=NULL){
        ptr=*head;
        *head=(*head)->next;
        free(ptr);
    }
    printf("List is Empty.");
}
