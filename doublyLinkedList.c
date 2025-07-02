#include <stdio.h>
#include <stdlib.h>

struct node {

    int data;
    struct node* prev;
    struct node* next;

};

//function prototypes..

void addBeg(struct node **head, int data);

void print(struct node *head);

void addEnd(struct node** head, int data);

int count(struct node *head);

void addPos(struct node **head, int data);

int main(void)
{

    struct node* head = NULL;

    addEnd(&head, 45);

    addBeg(&head, 7);

    addBeg(&head, 9);

    print(head);

    addEnd(&head, 77);

    print(head);

    addPos(&head, 108);

    int res = count(head);

    print(head);

    printf("Total number of nodes in a list are: %d\n", res);



    return 0;
}

//function for alocating memory to a node...

struct node* createNode(int data)
{
    struct node* newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

//function to add node at the begining of the list..

void addBeg(struct node **head, int data)
{

    struct node* ptr = createNode(data);
    if (*head == NULL)
    {
        *head = ptr;
    }

    else
    {
        ptr->prev = NULL;
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}

//function to print list

void print(struct node *head)
{
    struct node* temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//function to add a node at the end of list

void addEnd(struct node** head, int data)
{
    struct node* ptr = createNode(data);

    struct node* temp = *head;

    //if no element in a listt

    if(*head == NULL)
    {

        //item added at the begining of the list
        *head = ptr;

    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = ptr;
        ptr->prev = temp;


    }


}

//function to count number of nodes in a list

int count(struct node *head)
{
    struct node *temp = head;

    int num = 0;

    while(temp != NULL)
    {
        num++;
        temp = temp->next;
    }

    return num;

}

//function to add node at any position

void addPos(struct node **head, int data)
{
    int loc;
    printf("At what location you want to insert a node: ");
    scanf("%d", &loc);

    int nodes = count(*head);

    if (loc > nodes)
    {
        printf("Number should be smaller then total number of nodes\n");
        exit(1);
    }
    struct node *temp = createNode(data);
    struct node *ptr = *head;

    int count = 1;

    while(count < loc)
    {
        ptr = ptr->next;
        count++;
    }

    temp->next = ptr->next;
    ptr->next->prev = temp;
    ptr->next = temp;
    temp->prev = ptr;

}
