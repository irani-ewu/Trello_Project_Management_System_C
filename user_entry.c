#include<stdio.h>
#include<string.h>
#include"user_entry.h"

void registration()
{
    FILE *fp;
    fp=fopen("USERNAME.txt","a");

    USER user;

    printf("Enter your Name:\n");
    scanf("%s",user.name);

    printf("Enter your Email ID:\n");
    scanf("%s",user.email_id);

    fprintf(fp,"%s\n%s\n",user.name,user.email_id);
    fclose(fp);
}

int log_In()
{
    FILE *fp;
    fp=fopen("USERNAME.txt","r");
    char name[MAX_LENGTH];
    char email_id[MAX_LENGTH];

    USER user;

    printf("Enter your Name:\n");
    scanf("%s",name);

    printf("Enter your Email id:\n");
    scanf("%s",email_id);


    int found=0;

    while(fscanf(fp,"%s\n%s\n",user.name,user.email_id)!=EOF)
    {
        if(strcmp(name,user.name)==0 && strcmp(email_id,user.email_id)==0)
        {
            found=1;
        }
    }
    fclose(fp);
    if(found==1)
    {
        printf("Log In Successful.\n");
        return 1;
    }
    else
    {
        printf("Log In Unsuccessful.\n");
        return 0;
    }


}
