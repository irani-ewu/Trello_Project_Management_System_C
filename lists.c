#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"lists.h"
#include"cards.h"

LIST* create_List(char name[MAX_NAME_LENGTH])
{
    LIST* newList;
    newList = (LIST*) malloc(sizeof(LIST));
    strcpy(newList->name,name);

    printf("You have created a List. Now add your tasks in a card!\n");

    char Name[MAX_NAME_LENGTH];

    printf("Card's name:\n");
    fgets(Name,sizeof(Name),stdin);

    while(getchar()!='\n');

    char Description[MAX_DESCRIPTION_LENGTH];
    printf("Card's description:\n");
    fgets(Description,sizeof(Description),stdin);

    newList->CARD = create_Card(Name,Description);

while(1)
{
    printf("You have created a card successfully. Want to add a card?\n1. Add a new Card\n2. No\n");

    int choice;

    CARD* head = newList->CARD;
    scanf("%d",&choice);

    while(getchar() != '\n');

    if(choice==1)
    {
        add_a_Card(head);
    }
    else
    {
        return;
    }

}

    newList->prev_List = NULL;
    newList->next_List = NULL;

return newList;
}

void add_a_List(LIST* head)
{
    LIST* ptr;
    LIST* newList;
    char name[MAX_NAME_LENGTH];

    printf("Write your list's name here:\n");
    scanf("%s",name);

    while(getchar() != '\n');

    newList = create_List(name);
    ptr=head;

    while(ptr->next_List!=NULL)
    {
        ptr=ptr->next_List;
    }
    ptr->next_List = newList;
    newList->prev_List = ptr;
}

LIST* delete_a_List(LIST* head)
{

    int choice;

    printf("Want to remove a List from this Board?\n1.YES\n2.NO\n");
    scanf("%d",&choice);

    while(getchar() != '\n');

    switch (choice)
    {
    case 1:
        printf("Which one?\n1.First\n2.Any other position?\n");
        scanf("%d",&choice);

        while(getchar() != '\n');

        switch (choice)
        {
        case 1:
            head = delete_First_List(head);
            break;

        case 2:
            head = delete_Intermediate_or_Last_List(head);

        default:
            break;
        }
        break;

    default:
        break;
    }
return head;
}

LIST* delete_First_List(LIST* head)
{
    LIST* ptr;
    ptr=head;

    head = ptr->next_List;
    ptr->next_List=NULL;
    printf("%s deleted successfully",ptr->name);
    free(ptr->CARD);
    free(ptr);

return head;
}

LIST* delete_Intermediate_or_Last_List(LIST* head)
{
    LIST* ptr;
    ptr=head;

    typedef struct choice
    {
        int position;
        int count;

    }choice;

    choice c;

    printf("Which LIST you want to delete?\n");
    scanf("%d",&c.position);

    while(getchar() != '\n');

    c.count = 1;

    while(c.count!=c.position)
    {
        ptr=ptr->next_List;
        c.count++;
    }

    if(ptr==NULL)
    {
        printf("Invalid Position\n");
        return head;
    }

    if(ptr->prev_List!=NULL)
    {
        ptr->prev_List->next_List = ptr->next_List;
    }
    if(ptr->next_List!=NULL)
    {
        ptr->next_List->prev_List = ptr->prev_List;
    }

    ptr->next_List = NULL;
    ptr->prev_List = NULL;
    printf("%s deleted successfully",ptr->name);
    free(ptr->CARD);
    free(ptr);

return head;
}
