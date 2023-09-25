#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
    //List mylist = new_list();
    Liststd stdlst = NULL;
    char worstStudent[30];
    srand(time(NULL));

    /*int size=0;
    Bool end=false;
    long tmp=2;
    

    printf("How many power of 2?\n");
    scanf("%d",&size);

    for(int i=0;i<size;i++)
    {
    
        mylist = push_back_list(mylist,tmp);
        tmp*=2;

    }

    print_list(mylist);

    while(!end)
    {

        printf("Do you want to continue? (y/n)\n");
        int choice = getch(); 
        
        if(choice=='y')
        {
            mylist = push_back_list(mylist,tmp);
            print_list(mylist);
            tmp*=2;
        
        }
        else if(choice== 'n')
        {
            end=true;
        }
        else{
            printf("Please enter again\n");
        }
        
    }

    clear_list(mylist);


    print_list(mylist);

    mylist=add_Chainon(12);
    mylist = push_back_list(mylist,36);
    print_list(mylist);
    mylist = push_front_list(mylist,12);
    mylist = push_front_list(mylist,15);
    print_list(mylist);
    mylist = push_back_list(mylist,26);
    print_list(mylist);
    

    printf(" They are: %d elements\n",list_length(mylist));

    mylist=sortList(mylist);
    print_list(mylist);

    for(int i=0;i<10;i++)
    {
        int randvalue= rand()%6;
        mylist=push_back_list(mylist,randvalue);
    }

    print_list(mylist);
    mylist=pop_all_element_list(mylist,2);
    print_list(mylist);

    mylist=reverse_list(mylist);
    print_list(mylist);*/

    
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    stdlst=addStudent(stdlst);
    print_listd(stdlst);
    //Listbygrp(stdlst,2);
    
    if(findStudent("r","a",stdlst)==NULL)
    {
    	printf("The student doesn't exist\n");
    }
    else
    {	printf("The average of the student is%f\n",moyTab(stdlst->std.notes,NB_NOTES));
    }
    
    double average= AverageAllStudents(stdlst,worstStudent);

    if(average <=0)
    {
    	printf("There is no students\n");
    }
    else
    {
    	printf("The Average of the promotion is  %f\n",average);
        printf("The worst student is %s\n ",worstStudent);

   }
    
    while (stdlst != NULL)
    {
        Liststd temp = stdlst;
        stdlst = stdlst->next;
        free(temp);
    }        
    return 0;
}
