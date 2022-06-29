#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int power;
    int coefficient;
    struct node *next;
}node;

void add(node **head);
void addNode(node **head,int pow,int coe);
void printPoly(node *head);
void addPoly(node **poly1,node **poly2,node **poly3);

int main()
{
    node *poly1=NULL,*poly2=NULL,*poly3=NULL;
    printf("Enter in Ascending order.\n");
    printf("\nEnter polynomial 1");
    add(&poly1);
    printf("\nEnter polynomial 2");
    add(&poly2);
    printf("\nThe polynomials are : \n");
    printPoly(poly1);
    printPoly(poly2);
    printf("The sum of the two polynomials is : ");
    addPoly(&poly1,&poly2,&poly3);
    printPoly(poly3);
    return 0;
}

void add(node **head){
    int pow,coe;
    char choice;
    while(1){
        printf("\nEnter power : ");
        scanf("%d",&pow);
        printf("Enter coefficient : ");
        scanf("%d",&coe);
        fflush(stdin);
        addNode(head,pow,coe);
        fflush(stdin);
        printf("Want to continue : (y/n)");
        scanf("%c",&choice);
        if(choice=='n'){
            break;
        }
    }
    
}
void addNode(node **head,int pow,int coe){
    fflush(stdin);
    node *p1;
    p1=malloc(sizeof(node));
    p1->power=pow;
    p1->coefficient=coe;
    if(*head==NULL){
        p1->next=NULL;
        *head=p1;
    }else{
        p1->next=*head;
        *head=p1;
    }
}

void printPoly(node *head){
    //printf("The polynomial is : ");
    node *p;
    p=head;
    while(p!=NULL){
        if(p->power==0){
            printf("%d",p->coefficient);
        }else if(p->power==1){
            printf("%dx",p->coefficient);
        }else{
            printf("%dx^%d",p->coefficient,p->power);
        }
        if(p->coefficient>0 && p->next!=NULL){
            printf("+");
        }
        p=p->next;
    }
    printf("\n");
}

void addPoly(node **poly1,node **poly2,node **poly3){
    int pow,coe;
    fflush(stdin);
    while((*poly1!=NULL) && (*poly2!=NULL)){
        if((*poly1)->power < (*poly2)->power){
            pow=(*poly2)->power;
            coe=(*poly2)->coefficient;
            *poly2=(*poly2)->next;
        }else if((*poly1)->power > (*poly2)->power){
            pow=(*poly1)->power;
            coe=(*poly1)->coefficient;
            *poly1=(*poly1)->next;
        }else{
            pow=(*poly1)->power+(*poly2)->power;
            coe=(*poly1)->coefficient+(*poly2)->coefficient;
            *poly1=(*poly1)->next;
            *poly2=(*poly2)->next;
        }
        if(coe!=0){
            addNode(poly3,pow,coe);
        }
        if(*poly1==NULL){
            for(;*poly2!=NULL;*poly2=(*poly2)->next){
                addNode(poly3,(*poly2)->power,(*poly2)->coefficient);
            }
        }else if(*poly2==NULL){
            for(;*poly1!=NULL;*poly1=(*poly1)->next){
                addNode(poly3,(*poly1)->power,(*poly1)->coefficient);
            }
        }
        
    }
}

