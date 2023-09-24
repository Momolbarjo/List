#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "list.h"

int main(void)
{
    //List mylist = new_list();
    Liststd stdlst = NULL;
    srand(time(NULL));

    /*int size=0;
    Bool end=false;
    long tmp=2;
    

    printf("Combien de puissances de 2 voulez vous voir?\n");
    scanf("%d",&size);

    for(int i=0;i<size;i++)
    {
    
        mylist = push_back_list(mylist,tmp);
        tmp*=2;

    }

    print_list(mylist);

    while(!end)
    {

        printf("Voulez-vous continuer? (y/n)\n");
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
            printf("Merci de ressaisir\n");
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
    

    printf("nombre d'elements : %d\n",list_length(mylist));

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
    print_listd(stdlst);
    stdlst=addStudent(stdlst);
    print_listd(stdlst);
    Listbygrp(stdlst,2);


    
    while (stdlst != NULL)
    {
        Liststd temp = stdlst;
        stdlst = stdlst->next;
        free(temp);
    }
    
    return 0;
}
