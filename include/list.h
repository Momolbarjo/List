#ifndef LIST_H
#define LIST_H
#include <termios.h>

typedef enum
{
    false,
    true
}Bool;

typedef struct  ListElement
{
    int nb;
    struct ListElement* next;
}ListElement, *List;

char getch();
List new_list(void);
List add_Chainon( int x);
Bool is_list_empty(List li);
int list_length(List li);
void print_list(List li);
List push_back_list(List li, int x);
List push_front_list(List li,int x);
List pop_back_list(List li);
List pop_front_list(List li);
List clear_list(List li);
List make_list_increasing(List li);
List insertSorted(List li, int x);
List sortList(List li);
List pop_element_list(List li,int value);


#endif

