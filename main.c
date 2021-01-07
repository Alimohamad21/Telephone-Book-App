#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct birthDate
{
    char day[3];
    char month[3];
    char year[5];
} birthDate;

typedef struct
{
    char firstName[20];
    char lastName[20];
    birthDate birthdate;
    char streetAddress[100];
    char email[50];
    char phoneNumber[20];
    int modify;
} record;
record records[100];
int i=0;
int loaded=0;

void load();
void add();
void save();
void quit();
void search();
void delete();
void modify();
void sortedprint();
int substring(char s1[],char s2[]);
char* fetch(char *str,int n);
int endsubstring(char s1[],char s2[]);
int containnum(char s1[]);
int main()
{
    int option,optiontest=0;
    printf("***************************Welcome to our Telephone Book Application***************************\n");
    while(1)
    {
        printf("\n\n\n\n**********MAIN MENU**********\n\n");
        printf("1- LOAD\n");
        printf("2- SEARCH\n");
        printf("3- ADD\n");
        printf("4- DELETE\n");
        printf("5- MODIFY\n");
        printf("6- SORT & PRINT\n");
        printf("7- SAVE\n");
        printf("8- QUIT\n");
        printf("\nEnter number associated with the option you want to select:");
        do
        {
            if(optiontest)
                printf("WARNING!Invalid input,Please enter a valid option(1 to 8)\a:");
            scanf("%d",&option);
            optiontest=1;
        }

        while(option<1 || option>8);
        optiontest=0;
        switch(option)
        {
        case 1:
            load();
            break;
        case 2:
            search();
            break;
        case 3:
            add();
            break;
        case 4:
            delete();
            break;
        case 5:
            modify();
            break;
        case 6:
            sortedprint();
            break;
        case 7:
            save();
            break;
        case 8:
            quit();
        }
    }
    return 0;

}


void load()
{
    FILE *fp;
    int n=i,j=0,c,recordcount=1;
    char str[2000];
    char *token=malloc(30);
    fp=fopen("Directory.txt","r");
    if(loaded==1)
    {
        printf("\n\nFile contents have been already loaded,Returning to main menu to avoid duplication...\n\n\a");
        return;
    }
    if(!fp)
    {
        printf("Error,failed to open file\nReturning to main menu...\n\a");
        return ;
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%[^\n]\n",str);
            token=strtok(str,",");
            j=0;
            while(token!=NULL)
            {
                switch(j)
                {
                case 0:
                    strcpy(records[n].firstName,token);
                    token=strtok(NULL,",");
                    j++;
                    break;

                case 1:

                    strcpy(records[n].lastName,token);
                    token=strtok(NULL,"-");
                    j++;
                    break;
                case 2:
                    strcpy(records[n].birthdate.day,token);
                    token=strtok(NULL,"-");

                    j++;
                    break;
                case 3:
                    strcpy(records[n].birthdate.month,token);
                    token=strtok(NULL,",");

                    j++;
                    break;
                case 4:
                    strcpy(records[n].birthdate.year,token);
                    token=strtok(NULL,",");
                    j++;
                    break;

                case 5:
                    strcpy(records[n].streetAddress,token);
                    token=strtok(NULL,",");
                    j++;
                    break;
                case 6:
                    strcpy(records[n].email,token);
                    token=strtok(NULL,",");
                    j++;
                    break;
                case 7:
                    strcpy(records[n].phoneNumber,token);
                    token=strtok(NULL,",");
                    j++;
                    break;
                }

            }

            n++;
        }
        printf("\n\nFile loaded successfully.\n\nFile contents:\n");
        for(c=i; c<n; c++)
        {
            if(!strcmp(records[c].firstName,"")&&!strcmp(records[c].lastName,""))
                continue;
            printf("\n\nRecord %d-First Name:%s\n",recordcount++,records[c].firstName);
            printf("Last Name:%s\n",records[c].lastName);
            printf("Birth Date:%s/%s/%s\n",records[c].birthdate.day,records[c].birthdate.month,records[c].birthdate.year);
            printf("Address:%s\n",records[c].streetAddress);
            printf("Email:%s\n",records[c].email);
            printf("Phone number:%s\n",records[c].phoneNumber);
            i++;
        }
    }
    printf("\n\nFile data loaded successfully\n\nReturning to main menu... ");
    loaded++;
    fclose(fp);
}
void add()
{
    int validate=0,test=3000,test1=3000,test2=-100,no=0,test3=100,test4=1000;
    printf("\n\nPlease enter the details of the record as following:\n");

    while(test3)
    {
        if(!validate)
            printf("Enter first name:");
        else
            printf("Invalid input.Please enter a correct name:\a");


        scanf("%s",records[i].firstName);
        test3=containnum(records[i].firstName);
        validate=1;
    }
    validate=0;
    while(test4)
    {
        if(!validate)
            printf("Enter last name:");
        else
            printf("Invalid input.Please enter a correct name:\a");


        scanf("%s",records[i].lastName);
        test4=containnum(records[i].lastName);
        validate=1;
    }
    validate=0;
    while(test<1 || test>31)
    {
        if(!validate)
            printf("Enter day of birth:");
        else
            printf("Invalid input.Please enter a correct day of birth:\a");
        scanf("%s",records[i].birthdate.day);
        test=atoi(records[i].birthdate.day);
        validate=1;
    }
    validate=0;
    while(test1<1|| test1>12)
    {

        if(!validate)
            printf("Enter month of birth:");
        else
            printf("Invalid input.Please enter a correct month of birth:\a");
        scanf("%s",records[i].birthdate.month);
        test1=atoi(records[i].birthdate.month);
        validate=1;
    }
    validate=0;
    while(test2<1900|| test2>2019)
    {
        if(!validate)
            printf("Enter year of birth:");
        else
            printf("Invalid input.Please enter a correct year of birth:\a");

        scanf("%s",records[i].birthdate.year);
        test2=atoi(records[i].birthdate.year);
        validate=1;
    }
    validate=0;
    printf("Enter street Address:");
    gets(records[i].streetAddress);
    gets(records[i].streetAddress);//it skips the first one for some reason//
    while(!endsubstring(records[i].email,".com") ||!substring(records[i].email,"@") || substring(records[i].email,"@.com") )
    {
        if(!validate)
            printf("Enter email(example@domain.com):");
        else
            printf("Invalid input.Please enter a correct email:\a");

        scanf("%s",records[i].email);
        validate=1;
    }
    validate=0;
    while(!no||!substring(records[i].phoneNumber,"03-")|| strlen(records[i].phoneNumber)!=10)
    {
        if(!validate)
            printf("Enter phone number(03-followed by 7 numbers) e.g:03-1234567:");
        else
            printf("Invalid input.Please enter a correct year of birth:\a");
        scanf("%s",records[i].phoneNumber);
        no=atoi(records[i].phoneNumber);
        validate=1;
    }

    printf("\n\nRecord added successfully\n\n------------Please Save changes to add the record to the main directory------------\n\n");
    printf("Returning to main menu...\n");
    i++;
}
void quit()
{
    int quittest;
    printf("\n\nWARNING!All unsaved changes will be discarded,Are you sure you want to quit?\n\n");
    printf("Press 1 to quit or any button to return to the main menu\n");
    scanf("%d",&quittest);
    if(quittest==1)
    {
        printf("\n\nExiting program...");
        exit(1);
    }
}
void save()
{
    int c,savetest;
    FILE *file;
    if(!i)
    {
        printf("\n\nWARNING!No data has been found,Please load/add data to be able to save\a\n\nReturning to main menu...");
        return ;
    }
    int error=0;
    if(!loaded)
        printf("\n\n1-Save and overwrite existing file(WARNING!Will cause loss of previous data in file)\n2-Save and add to the existing file(Recommended)\n\n");
    else if(loaded)
        printf("\n\n1-Save and overwrite existing file(Recommended)\n2-Save and add to the existing file(NOT RECOMMENDED)(Will result in duplicating original file contents)\n\n");
    while(savetest!=1 && savetest!=2)
    {
        if(!error)
        {
            printf("\n\nPlease select an option from the above(1 or 2):");
            scanf("%d",&savetest);
        }
        else if(error)
        {
            printf("\n\nPlease select an option from the above(1 or 2):\a");
            scanf("%d",&savetest);
        }
        error=1;
    }
    error=0;
    if(savetest==1)
    {
        file=fopen("Directory.txt","w");
    }
    else if(savetest==2)
    {
        file=fopen("Directory.txt","a");
    }

    for(c=0; c<i; c++)
    {
        if(!strcmp(records[c].firstName,"")&&!strcmp(records[c].lastName,""))
            continue;
        else
        {

            fprintf(file,"%s,",records[c].firstName);
            fprintf(file,"%s,",records[c].lastName);
            fprintf(file,"%s-",records[c].birthdate.day);
            fprintf(file,"%s-",records[c].birthdate.month);
            fprintf(file,"%s,",records[c].birthdate.year);
            fprintf(file,"%s,",records[c].streetAddress);
            fprintf(file,"%s,",records[c].email);
            fprintf(file,"%s\n",records[c].phoneNumber);
        }
    }
    printf("\n\nDate saved successfully\n\nReturning to main menu...\n");
    fclose(file);


}
void search()
{
    int c,s=0,option,multi=1,multiflag=0;
    char lastnamekey[20];
    char firstnamekey[20];
    char birthdaykey[20];
    char birthmonthkey[20];
    char birthyearkey[20];
    char addresskey[40];
    char emailkey[20];
    char numberkey[20];

    if(!i)
    {
        printf("\n\nWARNING!No data has been found,Please load/add data to be able to search\a\n\nReturning to main menu...");
        return ;
    }
    int flag=0;
    printf("1-Search by Last Name\n2-Multi-Search\n\n");
    while(option!=1&&option!=2)
    {
        printf("Select an option from the above(1 or 2):");
        scanf("%d",&option);
    }
    switch(option)
    {
    case 1:
        printf("\n\n\nPlease enter the last name of the record(s) you want to find:");
        scanf("%s",lastnamekey);
        for(c=0; c<i; c++)
        {
            if(!strcasecmp(lastnamekey,records[c].lastName))
            {
                flag=1;
                s++;
                printf("\n\n%d-First Name:%s\n",s,records[c].firstName);
                printf("Last Name:%s\n",records[c].lastName);
                printf("Birth Date:%s/%s/%s\n",records[c].birthdate.day,records[c].birthdate.month,records[c].birthdate.year);
                printf("Address:%s\n",records[c].streetAddress);
                printf("Email:%s\n",records[c].email);
                printf("Phone number:%s\n",records[c].phoneNumber);
            }
        }
        if(!flag)
            printf("\n\nFailed to find any records associated with the last name %s\n\nReturning to main menu...\n",lastnamekey);
        else
            printf("\n\nAll records associated with the last name %s have been loaded successfully\n\nReturning to main menu...",lastnamekey);
        break;
    case 2:
        printf("\n\nFor the record you want to search for...\nEnter the following and skip (using Enter) fields you don't want to include in the search:");
        printf("\n\nEnter first name:");
        gets(firstnamekey);
        gets(firstnamekey);//it skips the first one for some reason//
        printf("Enter last name:");
        gets(lastnamekey);
        printf("Enter day of birth:");
        gets(birthdaykey);
        printf("Enter month of birth:");
        gets(birthmonthkey);
        printf("Enter year of birth:");
        gets(birthyearkey);
        printf("Enter street Address:");
        gets(addresskey);
        printf("Enter email(example@domain.com):");
        gets(emailkey);
        printf("Enter phone number:");
        gets(numberkey);
        for(c=0; c<i; c++)
        {
            multi=0;
            if(!strcasecmp(firstnamekey,records[c].firstName)||!strcmp(firstnamekey,""))
                multi++;
            if(!strcasecmp(lastnamekey,records[c].lastName)||!strcmp(lastnamekey,""))
                multi++;
            if(!strcasecmp(birthdaykey,records[c].birthdate.day)||!strcmp(birthdaykey,""))
                multi++;
            if(!strcasecmp(birthmonthkey,records[c].birthdate.month)||!strcmp(birthmonthkey,""))
                multi++;
            if(!strcasecmp(birthyearkey,records[c].birthdate.year)||!strcmp(birthyearkey,""))
                multi++;
            if(!strcasecmp(addresskey,records[c].streetAddress)||!strcmp(addresskey,""))
                multi++;
            if(!strcasecmp(emailkey,records[c].email)||!strcmp(emailkey,""))
                multi++;
            if(!strcasecmp(numberkey,records[c].phoneNumber)||!strcmp(numberkey,""))
                multi++;



            if(multi==8)
            {
                s++;
                multiflag=1;
                printf("\n\n%d-First Name:%s\n",s,records[c].firstName);
                printf("Last Name:%s\n",records[c].lastName);
                printf("Birth Date:%s/%s/%s\n",records[c].birthdate.day,records[c].birthdate.month,records[c].birthdate.year);
                printf("Address:%s\n",records[c].streetAddress);
                printf("Email:%s\n",records[c].email);
                printf("Phone number:%s\n",records[c].phoneNumber);
            }

        }
        if(multiflag)
            printf("\n\nMulti-Search completed successfully\n\n");
        else
            printf("\n\nNo records matching your entries were found\n\n");
        printf("\n\nReturning to main menu...");


        break;
    }

}
void delete()
{
    char firstnamekey[20];
    char lastnamekey[20];
    int c=0,flag=0;
    if(!i)
    {
        printf("\n\nWARNING!No data has been found,Please load/add data to be able to delete\a\n\nReturning to main menu...");
        return ;
    }
    printf("\n\nEnter first name of the record you want delete:");
    scanf("%s",firstnamekey);
    printf("\nEnter last name of the record you want delete:");
    scanf("%s",lastnamekey);

    for(c=0; c<i; c++)
    {
        if(!strcasecmp(lastnamekey,records[c].lastName)&&!strcasecmp(firstnamekey,records[c].firstName))
        {
            strcpy(records[c].firstName,"");
            strcpy(records[c].lastName,"");
            strcpy(records[c].birthdate.day,"");
            strcpy(records[c].birthdate.month,"");
            strcpy(records[c].birthdate.year,"");
            strcpy(records[c].streetAddress,"");
            strcpy(records[c].email,"");
            strcpy(records[c].phoneNumber,"");
            flag=1;
        }
    }
    if(!flag)
        printf("\n\nFailed to delete,Record not found");
    else
        printf("\n\nRecord deleted successfully\n\n----------Please save to erase from main directory----------\n\n");
    printf("\n\nReturning to main menu...");


}
void modify()
{
    char lastnamekey[20];
    int optionkey;
    int flag=0,c,s=0,validate=0,test=3000,test1=3000,test2=-1000,no=0,test3=1000,test4=1000;

    if(!i)
    {
        printf("\n\nWARNING!No data has been found,Please load/add data to be able to modify\a\n\nReturning to main menu...");
        return ;
    }
    printf("\n\n\nPlease enter the last name of the record(s) you want to modify:");
    scanf("%s",lastnamekey);
    for(c=0; c<i; c++)
    {

        if(!strcasecmp(lastnamekey,records[c].lastName))
        {
            flag=1;
            s++;
            records[c].modify=s;
            printf("\n\n%d-First Name:%s\n",s,records[c].firstName);
            printf("Last Name:%s\n",records[c].lastName);
            printf("Birth Date:%s/%s/%s\n",records[c].birthdate.day,records[c].birthdate.month,records[c].birthdate.year);
            printf("Address:%s\n",records[c].streetAddress);
            printf("Email:%s\n",records[c].email);
            printf("Phone number:%s\n",records[c].phoneNumber);
        }
    }
    if(flag==1)
    {
        printf("\n\nNow from the above options,Enter number associated with the record you want to modify:");
        scanf("%d",&optionkey);
        for(c=0; c<i; c++)
        {
            if(!strcasecmp(lastnamekey,records[c].lastName)&&optionkey==records[c].modify)
            {
                flag=2;
                printf("\n\nPlease enter the new details of the record as following:\n\n");
                while(test3)
                {
                    if(!validate)
                        printf("Enter first name:");
                    else
                        printf("Invalid input.Please enter a correct name:\a");


                    scanf("%s",records[c].firstName);
                    test3=containnum(records[c].firstName);
                    validate=1;
                }
                validate=0;
                while(test4)
                {
                    if(!validate)
                        printf("Enter last name:");
                    else
                        printf("Invalid input.Please enter a correct name:\a");


                    scanf("%s",records[c].lastName);
                    test4=containnum(records[c].lastName);
                    validate=1;
                }
                validate=0;
                while(test<1 || test>31)
                {
                    if(!validate)
                        printf("Enter day of birth:");
                    else
                        printf("Invalid input.Please enter a correct day of birth:\a");
                    scanf("%s",records[c].birthdate.day);
                    test=atoi(records[c].birthdate.day);
                    validate=1;
                }
                validate=0;
                while(test1<1|| test1>12)
                {

                    if(!validate)
                        printf("Enter month of birth:");
                    else
                        printf("Invalid input.Please enter a correct month of birth:\a");
                    scanf("%s",records[c].birthdate.month);
                    test1=atoi(records[c].birthdate.month);
                    validate=1;
                }
                validate=0;
                while(test2<1900|| test2>2019)
                {
                    if(!validate)
                        printf("Enter year of birth:");
                    else
                        printf("Invalid input.Please enter a correct year of birth:\a");

                    scanf("%s",records[c].birthdate.year);
                    test2=atoi(records[c].birthdate.year);
                    validate=1;
                }
                validate=0;
                printf("Enter street Address:");
                gets(records[c].streetAddress);
                gets(records[c].streetAddress);//it skips the first one for some reason//
                do
                {
                    if(!validate)
                        printf("Enter email(example@domain.com):");
                    else
                        printf("Invalid input.Please enter a correct email:\a");

                    scanf("%s",records[c].email);
                    validate=1;
                }
                while(!endsubstring(records[c].email,".com") ||!substring(records[c].email,"@") || substring(records[c].email,"@.com") );

                validate=0;

                while(!no||!substring(records[c].phoneNumber,"03-")|| strlen(records[c].phoneNumber)!=10)
                {
                    if(!validate)
                        printf("Enter phone number(03-followed by 7 numbers) e.g:03-1234567:");
                    else
                        printf("Invalid input.Please enter a correct phone number:\a");
                    scanf("%s",records[c].phoneNumber);
                    no=atoi(records[c].phoneNumber);
                    validate=1;
                }



            }
        }
    }
    if(flag==2)
    {
        printf("\n\nRecord modified successfully\n\n");
        printf("\n\n-------------Please save to modify the record in the main directory-------------\n\n");
    }
    else if(flag==1)
        printf("\n\nFailed to modify record\n\n");
    else
        printf("\n\nNo records where found associated with the last name %s\n\n",lastnamekey);
    printf("Returning to main menu...\n\n");
}
void sortedprint()
{
    int c,sortOption=0,recordcount=1,flag;
    if(!i)
    {
        printf("\n\nWARNING!No data has been found,Please load/add data to be able to sort&print\a\n\nReturning to main menu...");
        return ;
    }
    printf("\n\n1-Sort by Date of Birth\n2-Sort by last Name\n3-Sort by first Name");
    while(sortOption!=1 && sortOption!=2 && sortOption!=3)
    {
        printf("\n\nPlease select the sorting type you want(1,2 or 3):");
        scanf("%d",&sortOption);
    }


    switch(sortOption)
    {
        record temp;
        int c,d;
    case 1:
        for (c=0 ; c<i-1; c++)
        {
            for (d=0 ; d<i-c-1 ; d++)
            {
                flag=0;
                if (strcmp(records[d].birthdate.year,records[d+1].birthdate.year)<0)
                    flag=1;
                if(!strcmp(records[d].birthdate.year,records[d+1].birthdate.year)&&strcmp(records[d].birthdate.month,records[d+1].birthdate.month)<0)
                    flag=1;
                if(!strcmp(records[d].birthdate.year,records[d+1].birthdate.year)&&!strcmp(records[d].birthdate.month,records[d+1].birthdate.month)&&strcmp(records[d].birthdate.day,records[d+1].birthdate.day)<0)
                    flag=1;
                if(flag==1)
                {
                    temp=records[d];
                    records[d]=records[d+1];
                    records[d+1]=temp;
                }
            }
        }
        break;
    case 2:
        for (c=0 ; c<i-1; c++)
        {
            for (d=0 ; d<i-c-1 ; d++)
            {
                if (strcasecmp(records[d].lastName,records[d+1].lastName)>0)
                {
                    temp=records[d];
                    records[d]=records[d+1];
                    records[d+1]=temp;
                }
            }
        }
        break;
    case 3:
        for (c=0 ; c<i-1; c++)
        {
            for (d=0 ; d<i-c-1 ; d++)
            {
                if (strcasecmp(records[d].firstName,records[d+1].firstName)>0)
                {
                    temp=records[d];
                    records[d]=records[d+1];
                    records[d+1]=temp;
                }
            }
        }
        break;


    }

    printf("\n\nSorted Directory:\n\n");
    for(c=0; c<i; c++)
    {
        if(!strcmp(records[c].firstName,"")&&!strcmp(records[c].lastName,""))
            continue;
        printf("\n\n%d-First Name:%s\n",recordcount++,records[c].firstName);
        printf("Last Name:%s\n",records[c].lastName);
        printf("Birth Date:%s/%s/%s\n",records[c].birthdate.day,records[c].birthdate.month,records[c].birthdate.year);
        printf("Address:%s\n",records[c].streetAddress);
        printf("Email:%s\n",records[c].email);
        printf("Phone number:%s\n",records[c].phoneNumber);

    }
    printf("\n\nSorted Directory printed successfully\n\nReturning to main menu...");
}
char* fetch(char *str,int n)
{
    char* str1=(char*)malloc(100);
    int c;
    for(c=0; c<n; c++)
        str1[c]=str[c];
    str1[c]='\0';
    return str1;
}
int substring(char s1[],char s2[])
{
    int flag=0,c,j;
    for(c=strlen(s1); c>=0; c--)
    {
        for(j=0; j<strlen(fetch(s1,c)); j++)
        {
            if(!strcmp(fetch(s1,c)+j,s2))
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        return 1;
    else
        return 0;
}
int endsubstring(char s1[],char s2[])
{
    int flag=0,c;
    for(c=0; c<=strlen(s1); c++)
    {
        if(!strcmp(s1+c,s2))
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return 1;
    else
        return 0;
}
int containnum(char s1[])
{
    int c;
    for(c=0; c<strlen(s1); c++)
    {
        if(s1[c]=='0'||s1[c]=='1'||s1[c]=='2'||s1[c]=='3'||s1[c]=='4'||s1[c]=='5'||s1[c]=='6'||s1[c]=='7'||s1[c]=='8'||s1[c]=='9')
            return 1;
    }
    return 0;

}


