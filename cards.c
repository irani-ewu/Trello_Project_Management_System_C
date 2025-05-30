#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"cards.h"

CARD* create_Card(char name[MAX_NAME_LENGTH],char description[MAX_DESCRIPTION_LENGTH])
{
    CARD* newCard;
    newCard = (CARD*) malloc(sizeof(CARD));

    strcpy(newCard->name, name);
    strcpy(newCard->description, description);
    newCard->prev_card = NULL;
    newCard->next_card = NULL;

return newCard;
}

void add_a_Card(CARD* head)
{
    CARD* ptr;
    CARD* newCard;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    printf("Write your card's name here:\n");
    fgets(name,sizeof(name),stdin);

    while(getchar()!='\n');

    printf("Write your description here:\n");
    fgets(description,sizeof(description),stdin);

    newCard = create_Card(name,description);
    ptr=head;

    while(ptr->next_card!=NULL)
    {
        ptr=ptr->next_card;
    }
    ptr->next_card = newCard;
    newCard->prev_card = ptr;
}

CARD* delete_a_Card(CARD* head)
{
    int choice,choice1;

    printf("Want to remove a card from this list?\1.YES\n2.NO\n");
    scanf("%d",&choice);

    while(getchar() != '\n');

    switch (choice)
    {
    case 1:
        printf("Which one?1.First\n2.Any other position?\n");
        scanf("%d",&choice1);

        while(getchar() != '\n');

        switch (choice1)
        {
        case 1:
            head = delete_First_Card(head);
            break;

        case 2:
             head = delete_Intermediate_or_Last_Card(head);

        default:
            break;
        }
        break;

    default:
        break;
    }
return head;
}

CARD* delete_First_Card(CARD* head)
{
    CARD* ptr;
    ptr=head;

    head = ptr->next_card;
    ptr->next_card=NULL;
    free(ptr);

return head;
}

CARD* delete_Intermediate_or_Last_Card(CARD* head)
{
    CARD* ptr;
    ptr=head;

    typedef struct choice
    {
        int position;
        int count;

    }choice;

    choice c;

    printf("Which card you want to delete?\n");
    scanf("%d",&c.position);

    while(getchar() != '\n');

    c.count = 1;

    while(c.count!=c.position)
    {
        ptr=ptr->next_card;
        c.count++;
    }

    if(ptr==NULL)
    {
        printf("Invalid Position\n");
    }
    if(ptr->prev_card!=NULL)
    {
        ptr->prev_card->next_card = ptr->next_card;
    }
    if(ptr->next_card!=NULL)
    {
        ptr->next_card->prev_card = ptr->prev_card;
    }

    ptr->next_card = NULL;
    ptr->prev_card = NULL;
    free(ptr);
return head;
}

bool checkList()
{
    typedef struct choice
    {
        int tick;

    }choice;

    choice c;

    printf("If you have done this task,then give a tick.\n1.Tick\n");
    scanf("%d",&c.tick);

    while(getchar() != '\n');

    if(c.tick==1)
    {
        return DONE;
    }
    else
    {
        return NOT_DONE;
    }

}
