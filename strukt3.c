#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct _Person{
    char name[20];
    char surname[30];
    int birthYear;
    struct _Person* next;
}person;


int PrependList(person* head);
int AppendList(person* head);
person* CreatePerson();
int insertAfter(person* position, person* newPerson);
person* FindLast(person* head);
int freeList(person* head);
int PrintList(person* head);
int PrintMember(person* head, int num);
person* FindViaSurname(person* head);
int FindViaSurnameAndPrint(person* head);
int DeleteMember(person* head);
void clearScreen();
person* FindViaSurname(person* head);
person* FindMemberBefore(person* inputMember, person* head);
///////////////
int AddNewPersonAfter(person* head);
int AddNewPersonBefore(person* head);
int AddMember_SortOnEntery(person* head);
int WriteListInFile(person* head);
int ReadListFromFile(person* head);

int main(int argc, char** argv)
{
    int check=0;
    char znak1[10]={0};
    char znak[10]={0};
    person head={.name={0}, .surname={0}, .birthYear=0, .next=NULL};

    while(1){

        printf("\n-----------------------------------------------------------------"
               "\nTo have members alphabetically sorted:\t\t\tAUTO\n"
               "To choose in which order your members are sorted:\tMANUAL\n"
               "To exit:\t\t\t\t\t\tSTOP\n"
               "-----------------------------------------------------------------\n");
        printf("User input:\t");
        scanf(" %s", znak1);

        clearScreen();

        if(strcmp(znak1, "auto")==0){
            while(1){
                printf("\n-------------------------------------------------"
                     "\nTo add a member:\t\t+\n"
                     "To print the whole list:\tPRINT\n"
                     "To find a member by surname:\tFIND\n"
                     "To save a list to file:\t\tWRITE\n"
                     "To read a list from file:\tREAD\t(read only alphabetically sorted lists)\n"
                     "To delete by surname:\t\tDELETE\n"
                     "To exit:\t\t\tSTOP\n");
                printf("-------------------------------------------------\n");
                printf("User input:\t");
                scanf(" %s", znak);

                if(strcmp(znak, "+")==0){
                    check=AddMember_SortOnEntery(&head);
                    if(check!=0)
                        return -1;
                }
                else if(strcmp(znak, "print")==0 || strcmp(znak, "PRINT")==0) {
                    check=PrintList(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "find")==0 || strcmp(znak, "FIND")==0) {
                    check=FindViaSurnameAndPrint(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "delete")==0 || strcmp(znak, "DELETE")==0) {
                    check=DeleteMember(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "write")==0 || strcmp(znak, "WRITE")==0) {
                    check=WriteListInFile(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "read")==0 || strcmp(znak, "READ")==0) {
                    check=ReadListFromFile(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "stop")==0 || strcmp(znak, "STOP")==0){
                        clearScreen();
                        return freeList(&head);
                }
                else{
                    clearScreen();
                    puts("\nWRONG INPUT! TRY AGAIN...");
                }
            }
        }

        else if(strcmp(znak1, "manual")==0){
            while(1){
                printf("\n-------------------------------------------------"
                     "\nTo prepend:\t\t\t-\n"
                     "To append:\t\t\t+\n"
                     "To print the whole list:\tPRINT\n"
                     "To find a member by surname:\tFIND\n"
                     "To delete by surname:\t\tDELETE\n"
                     "To add before a member:\t\t-ADD\n"
                     "To add after a member:\t\tADD+\n"
                     "To save a list to file:\t\tWRITE\n"
                     "To read a list from file:\tREAD\n"
                     "To exit:\t\t\tSTOP\n");
                printf("-------------------------------------------------\n");
                printf("User input:\t");
                scanf(" %s", znak);

                if(strcmp(znak, "-")==0){
                    check=PrependList(&head);
                    if(check==-1){
                        freeList(&head);
                        return -1;
                    }
                }
                else if (strcmp(znak, "+")==0){
                    check=AppendList(&head);
                    if(check==-1){
                        freeList(&head);
                        return -1;
                    }
                }
                else if(strcmp(znak, "print")==0 || strcmp(znak, "PRINT")==0) {
                    check=PrintList(&head);
                    if(check!=0){
                        continue;
                    }

                }
                else if(strcmp(znak, "find")==0 || strcmp(znak, "FIND")==0) {
                    check=FindViaSurnameAndPrint(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "delete")==0 || strcmp(znak, "DELETE")==0) {
                    check=DeleteMember(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "-add")==0 || strcmp(znak, "-ADD")==0) {
                    check=AddNewPersonBefore(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "add+")==0 || strcmp(znak, "ADD+")==0) {
                    check=AddNewPersonAfter(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "write")==0 || strcmp(znak, "WRITE")==0) {
                    check=WriteListInFile(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "read")==0 || strcmp(znak, "READ")==0) {
                    check=ReadListFromFile(&head);
                    if(check!=0){
                        continue;
                    }
                }
                else if(strcmp(znak, "stop")==0 || strcmp(znak, "STOP")==0){
                        clearScreen();
                        return freeList(&head);

                }
                else{
                    clearScreen();
                    puts("\nWRONG INPUT! TRY AGAIN...");
                }

            }

            return 0;
        }

        else if(strcmp(znak1, "stop")==0){
            clearScreen();
            return 0;
        }

        else{
            clearScreen();
            puts("\nWRONG INPUT! TRY AGAIN...");
        }
    }
}

int ReadListFromFile(person* head)
{
    FILE* fp=NULL;
    person* last=NULL;
    person* temp=NULL;
    char fileName[40]={0};
    char scan[1024]={0};
    int count=0;
    int num=0;

    if(head->next!=NULL){
        freeList(head);
    }

    printf("Input file name:\t");
    scanf(" %s", fileName);

    fp=fopen(fileName, "r");
    if(fp==NULL){
        clearScreen();
        printf("Cannot access given file!\n");
        return -1;
    }

    while(fgets(scan, 1024, fp)!=NULL){
            count++;
        }
    rewind(fp);

    while(num!=count){
            temp=(person*)malloc(sizeof(person));
            if(temp==NULL){
                return -1;
            }
            fscanf(fp, " %s %s %d", temp->name, temp->surname, &temp->birthYear);

            if(head->next==NULL){
                if(insertAfter(head, temp)!=0)
                    return -1;
            }
            else{
                last=FindLast(head);
                if(insertAfter(last, temp)!=0)
                    return -1;
            }
            num++;
        }



    PrintList(head);

    fclose(fp);
    return 0;
}
int WriteListInFile(person* head)
{
    FILE* fp=NULL;
    char fileName[40]={0};
    person* temp=head->next;
    int check=0;

    if(temp==NULL){
        clearScreen();
        printf("\nNothing to store!\n");
        return -1;
    }
    printf("Input file name:\t");
    scanf(" %s", fileName);

    fp=fopen(fileName, "w");
    if(fp==NULL){
        clearScreen();
        printf("Cannot access given file!\n");
        return -1;
    }

    fseek(fp, 0, SEEK_SET);

    while(temp!=NULL){
        fprintf(fp,"%s %s %d\n", temp->name, temp->surname, temp->birthYear);

        temp=temp->next;
    }

    fclose(fp);
    return 0;

}
int AddMember_SortOnEntery(person* head)
{
    person* newPerson=NULL;
    person* before=NULL;
    person* temp=head;

    newPerson=CreatePerson();
    if(newPerson==NULL){
        return -1;
    }

    while(1){
            if(temp->next==NULL){ //checks if list is empty, if true inserts new person after head
                insertAfter(temp, newPerson);
                return 0;
            }
            else if(strcmp(newPerson->surname, temp->next->surname)<0){
                insertAfter(temp, newPerson);
                return 0;
            }
            else {
                temp=temp->next;
                if((temp->next==NULL)&&(strcmp(newPerson->surname, temp->surname)<0)){
                            before=FindMemberBefore(temp, head);
                            insertAfter(before, newPerson);
                            return 0;
                        }
                else if((temp->next==NULL)&&(strcmp(newPerson->surname, temp->surname)>0)){
                            insertAfter(temp, newPerson);
                            return 0;
                        }
                else if(((strcmp(newPerson->surname, temp->surname)>0)) && ((strcmp(newPerson->surname, temp->next->surname)<0))){
                            insertAfter(temp, newPerson);
                            return 0;
                        }
            }
        }

}
int DeleteMember(person* head) //deletes a member by surname, returns -1 if FindViaSurname returns -1, if all is good returns 0
{
    person* before=NULL;
    person* temp=NULL;

    temp=FindViaSurname(head);
    if(temp==NULL){
        return -1;
    }

    before=FindMemberBefore(temp, head);

    before->next=temp->next;
    free(temp);

    return 0;
}
person* FindMemberBefore(person* inputMember, person* head) //Finding the one before(before starts from the head and looks for a member before the inputMember)
{
    person* before=head;

    while(before->next!=inputMember){
        before=before->next;
    }
    return before;
}
int AddNewPersonAfter(person* head)
{
    person* temp=NULL;
    person* newPerson=NULL;

    temp=FindViaSurname(head);
    if(temp==NULL){
        return -1;
    }

    newPerson=CreatePerson();
    if(newPerson==NULL){
        return -1;
    }

    if(insertAfter(temp, newPerson)!=0)
        return -1;

    return 0;
}
int AddNewPersonBefore(person* head)
{
    person* before=NULL;
    person* input=NULL;
    person* newPerson=NULL;

    input=FindViaSurname(head);
    if(input==NULL)
        return -1;

    before=FindMemberBefore(input, head);

    newPerson=CreatePerson();
    if(newPerson==NULL)
        return -1;

    insertAfter(before, newPerson);

    return 0;

}
person* FindViaSurname(person* head) //returns NULL if the list is empty, or if there is no such surname
{
    person* temp=head;
    person* last=FindLast(head);
    char sur[30]={0};

    if(last==head){
        clearScreen();
        printf("\nList is empty!\n");
        return NULL;
    }

    printf("\nEnter a surname:\t");
    scanf(" %s", sur);


    while((strcmp(temp->surname, sur)!=0)){
        temp=temp->next;
        if((temp==last) && (strcmp(temp->surname, sur)!=0)){
                clearScreen();
                printf("\nNo such surname in this list\n");
                return NULL;
        }
    }
    return temp;
}
int FindViaSurnameAndPrint(person* head) //returns -1 if the list is empty, or if there is no such surname
{
    int check=0;
    int num=0;
    person* temp=head;
    person* last=FindLast(head);
    char sur[30]={0};

    if(last==head){
        clearScreen();
        printf("\nList is empty!\n");
        return -1;
    }

    printf("\nEnter a surname:\t");
    scanf(" %s", sur);


    while((strcmp(temp->surname, sur)!=0)){
        temp=temp->next;
        num++;
        if((temp==last) && (strcmp(temp->surname, sur)!=0)){
            clearScreen();
            printf("\nNo such surname stored in this list\n");
            return -1;
        }
    }

    check=PrintMember(temp, num);
    if(check!=0){
            printf("ERROR");
            return -1;
    }
    return 0;
}
int PrintList(person* head) //prints the whole list, returns -1 if the list is empty
{
    clearScreen();
    int br=0;
    person* temp=head;
    person* last=FindLast(head);

    if(last==head){
        clearScreen();
        printf("\nList is empty!\n");
        return -1;
    }
    printf("\n-------------------------------------------------");
    while(temp->next){
            temp=temp->next;
            printf("\nNum.%d\n"
                   "Name:\t\t%s\n"
                   "Surname:\t%s\n"
                   "Birth year:\t%d\n", br+1, temp->name, temp->surname, temp->birthYear);
            br++;
    }
    printf("-------------------------------------------------\n");
    return 0;
}
int PrintMember(person* member, int num) //prints out a member
{
    clearScreen();
    printf("\n-------------------------------------------------");
    printf("\nNum.%d\n"
            "Name:\t\t%s\n"
            "Surname:\t%s\n"
            "Birth year:\t%d\n", num, member->name, member->surname, member->birthYear);
    printf("-------------------------------------------------\n");
    return 0;
}
int PrependList(person* head)//adds a new member to the end of a list
{
    person* newPerson;

    newPerson=CreatePerson();
    if(newPerson==NULL){
        return -1;
    }
    if(insertAfter(head, newPerson)!=0)
        return -1;

    return 0;
}

int AppendList(person* head) //adds a new member to the beginning of a list
{
    person* newPerson=NULL;
    person* last=NULL;

    newPerson=CreatePerson();
    if(newPerson==NULL){
        return -1;
    }

    last=FindLast(head);
    if(last==NULL){
        return -1;
    }

    if(insertAfter(last, newPerson)!=0){
        return -1;
    }
    return 0;
}
person* FindLast(person* head) // finds returns last node of a linked list
{
    person* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return temp;
}
person* CreatePerson() //returns (person*) NewPerson, writes an error message and returns NULL if it was unable to access memory
{
    person* NewPerson=NULL;
    NewPerson=(person*)malloc(sizeof(person));
    if(NewPerson==NULL)
    {
        puts("Unable to access memory!\n");
        return NULL;
    }
    printf("Input name, surname and year of birth:\t");
    scanf(" %s %s %d", NewPerson->name, NewPerson->surname, &NewPerson->birthYear);
    return NewPerson;

}
int insertAfter(person* position, person* newPerson)
{
    newPerson->next=position->next;
    position->next=newPerson;
    return 0;
}

int freeList(person* head)
{
    person* temp=NULL;
    head=head->next;
    while (head)
    {
       temp = head;
       head=head->next;
       free(temp);
    }
    return 0;
}
void clearScreen() // source: https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c/36253316
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
