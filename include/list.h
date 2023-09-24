#ifndef LIST_H
#define LIST_H
#define NB_NOTES 10

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

typedef struct Student
{
    char name[15];
    char firstName[15];
    int grp;
    int notes[NB_NOTES];

} Student;

typedef struct  LstStudents
{
    Student std;
    struct LstStudents* next;
}LstStudents, *Liststd;



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
List pop_all_element_list(List li, int value);
List reverse_list(List li);
Liststd addStudent(Liststd lst);



#endif

