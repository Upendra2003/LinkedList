#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

void printList(struct node *head);
int countList(struct node *head);
void searchInList(struct node *head);
struct node *insertAtBegin(struct node *head);
struct node  *insertAtEnd(struct node *head);
struct node *insertAtLoc(struct node *head);
struct node *deleteLastNode(struct node *head);
struct node *deleteFirstNode(struct node *head);
struct node *createNode(struct node *head);


int main(){
    struct node *head,*p;
    int choice;
    while(1){
        printf("\n1.Create Linked List\n");
        printf("2.Print Linked List\n");
        printf("3.Insert at the begining\n");
        printf("4.Insert at the ending\n");
        printf("5.Insert at a location\n");
        printf("6.Delete first node\n");
        printf("7.Delete last node\n");
        printf("8.Delete at particular locatiion\n");
        printf("9.Search a node in Linked List");
        printf("-1.To break");
        printf("Enter an operation(1-9)");
        scanf("%d",&choice);
        printf("\n--------------------------------------------\n");
        struct node *p;
        switch(choice){
            case 1: p=createNode(head);
                    break;
            case 2: printList(p);
                    break;
            case 3: insertAtBegin(p);
                    break;
            case 4: insertAtEnd(head);
                    break;
            case 5: insertAtLoc(head);
                    break;
            case 6: deleteFirstNode(head);
                    break;
            case 7: deleteLastNode(head);
                    break;
            // case 8: printList(deleteAtPos(head));
            //         break;
            case -1: break;
        }
    }
    
    return 0;
}

void printList(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
}
struct node *createNode(struct node *head){
    int n;
    printf("Enter the no of nodes : ");
    scanf("%d",&n);
    struct node *p,*temp;
    int ele;
    p=malloc(sizeof(struct node));
    printf("Enter the element : ");
    scanf("%d",&ele);
    p->data=ele;
    p->next=NULL;
    temp=p;
    head=temp;
    for(int i=1;i<n;i++){
        p=malloc(sizeof(struct node));
        printf("Enter the element : ");
        scanf("%d",&ele);
        p->data=ele;
        p->next=NULL;
        temp->next=p;
        temp=temp->next;
    }
    return head;
}
    
    

// int countList(struct node *head){
//     struct node *move=head;
//     int count=0;
//     while(move!=NULL){
//         count++;
//         move=move->next;
//     }
//     return count;
// }
// void searchInList(struct node *head){
//     int find;
//     printf("\nEnter an element to find in the linked list : ");
//     scanf("%d",&find);
//     struct node *temp=head;
//     while(temp!=NULL){
//         if(find==temp->data)
//             return find;
//         temp=temp->next;
//     }
//     if(find)
//         printf("\nThe element is present in the Linked List");
//     else
//         printf("\nElement not found.");
//     printf("Search Completed.");
// }

struct node *insertAtBegin(struct node *head){
    int addEle;
    printf("Enter an element to add at the Begining : ");
    scanf("%d",&addEle);
    struct node *first;
    struct node *newNode,*p,*temp;
    newNode=malloc(sizeof(struct node));
    p=head;
    temp=p;
    newNode->data=addEle;
    newNode->next=p;
    temp=newNode;
    head=temp;
    return head;
}

struct node  *insertAtEnd(struct node *head){
    int addEle;
    printf("Enter an element to add at the End : ");
    scanf("%d",&addEle);
    struct node *newNode,*p;
    newNode=malloc(sizeof(struct node));
    newNode->data=addEle;
    newNode->next=NULL;
    p=head;
    while(p->next!=NULL){
        p=p->next;
    } 
    p->next=newNode;
    return head;
}

struct node *insertAtLoc(struct node *head){
    int pos,addEle;
    printf("Enter an element : ");
    scanf("%d",&addEle);
    printf("Enter the position you want to insert : ");
    scanf("%d",&pos);
    struct node *newNode,*temp;
    newNode=malloc(sizeof(struct node));
    newNode->data=addEle;
    newNode->next=NULL;
    temp=head;
    for(int i=0;i<pos;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
}

struct node *deleteFirstNode(struct node *head){
    struct node *p=head;
    head=p->next;
    return head;
}

struct node *deleteLastNode(struct node *head){
    struct node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

struct node *deleteAtPos(struct node *head){
    int pos;
    printf("Enter a position : ");
    scanf("%d",&pos);
    struct node *temp1;
    temp1=head;
    int i=0;
    while(i<pos-1){
        temp1=temp1->next;
        i++;
    }
    temp1->next=temp1->next->next;
    return head;
}