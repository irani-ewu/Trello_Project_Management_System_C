#include<stdio.h>
#include<string.h>
#include"lists.h"
#include"cards.h"
#include"search.h"

void search_Card(CARD* head, char desired_Card[MAX_NAME_LENGTH])
{
    CARD* ptr;
    ptr = head;

        while(ptr!=NULL)
        {
            if(strcmp(ptr->name,desired_Card)==0)
            {
                printf("Found the Card.\n");
                printf("%s\n",ptr->name);
                printf("%s",ptr->description);
            }

            ptr=ptr->next_card;
        }
}
void search_List(LIST* head,char desired_List[MAX_NAME_LENGTH])
{
    LIST* ptr;
    ptr = head;

        while(ptr!=NULL)
        {
            if(strcmp(ptr->name,desired_List)==0)
            {
                printf("Found the List.");
                printf("%s",ptr->name);
            }
            ptr=ptr->next_List;
        }
}
