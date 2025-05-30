#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "user_entry.h"
#include "lists.h"
#include "cards.h"

int main()
{
    int choose; char name[MAX_NAME_LENGTH]; LIST* head;

    printf("\t\t\t\t\tWelcome to Trello\n\t\t\t\tA project management system\n");
    printf("Want to sign up or log in?\n1.sign up\n2.log in\n");
    scanf("%d",&choose);

    while(getchar() != '\n');

    if(choose==1)
    {
        registration();
    }
    else if(choose==2)
    {
        choose = log_In();
        if(choose==1)
        {
        while(1)
        {
            printf("\nHere is your board.Create your List and manage tasks\n1.Create new list\n2.Add a list\n3.Delete a list\n");
            scanf("%d",&choose);

            while(getchar() != '\n');

            switch(choose)
            {
            case 1:

                printf("Enter the list name:\n");
                scanf("%s",name);

                while(getchar() != '\n');

                head = create_List(name);
                break;
            case 2:

                add_a_List(head);
                break;

            case 3:

                head = delete_a_List(head);
                break;
            }

        }


        }
    }

}

   /* NUBAH'S Implementation of create card--------
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];

    printf("Do you want to create a new card? (yes/no): ");
    char choice[4];
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        printf("Enter the card name:\n");
        scanf("%s", name);

        while (getchar() != '\n');

        printf("Enter the card description:\n");
        fgets(description,sizeof(description),stdin);

        CARD* myCard = create_Card(name, description);

        printf("\nCard created successfully!\n");
        printf("Card Name: %s\n", myCard->name);
        printf("Card Description: %s\n", myCard->description);


        free(myCard);
    } else {
        printf("No card created.\n");
    }

    return 0;*/
