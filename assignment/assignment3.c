// Doubly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head = NULL;
node* create_node (int data);
void add_first(int data);
void backward_display();
void forward_display();
void add_last(int data);
void delete_first();
void delete_last();

int main()
{
    add_first(30);
    add_first(20);
    add_first(50);
    add_first(80);
    add_last(40);
    add_last(85);
    add_last(32);
    add_first(28);
    add_first(65);
    forward_display();
    backward_display();
    delete_first();
    forward_display();
    delete_last();
    forward_display();
    
   // head->65->28->80->50->20->30->40->85->32
   // tail->32->85->40->30->20->50->80->28->65
    return 0;
}

node* create_node (int data)
{
    struct node *new_node = (node *)malloc(sizeof(node));

    if(new_node != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;

}


void add_first(int data)
{
    node *new_node = create_node(data);

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        head = new_node;
    }
}


void forward_display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        struct node *trav = head;

        printf("Head");
        do{
            printf("->%d",trav->data);
            trav = trav->next;
        }while (trav != head);
    }
    printf("\n");
}

void backward_display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        struct node *trav = head->prev;
        printf("Tail");
        do{
            printf("->%d",trav->data);
            trav = trav->prev;
        }while(trav != head->prev);
    }
    printf("\n");
}

void add_last(int data)
{
    node *new_node = create_node(data);

    if(head == NULL)
    {
        head = new_node;
        head->next = new_node;
        head->prev = new_node;
    }
    else
    {
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        head = temp->next;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;

        free(temp);
        temp = NULL;
    }
}