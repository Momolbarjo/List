#include <stdio.h>
#include "list.h"

int main(void)
{
    List mylist = new_list();

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

    print_list(clear_list(mylist));
    //print_list(pop_front_list(mylist));
    


    return 0;
}
