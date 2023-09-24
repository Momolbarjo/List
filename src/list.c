#include <stdio.h>
#include <stdlib.h>
#include "list.h"

char getch() {
    char buf = 0;
    struct termios old = {0};

    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    // Get the terminal attributes for the standard input (0) and store them in the old struct.
    // If tcgetattr() returns a value less than 0, an error occurred, and perror() prints an error message.

    old.c_lflag &= ~ICANON;// Disable canonical mode in the local flags of the terminal attributes.
    old.c_lflag &= ~ECHO;  // Disable echoing of input characters in the local flags of the terminal attributes.
    old.c_cc[VMIN] = 1;// Set the minimum number of characters to read to 1.
    old.c_cc[VTIME] = 0;// Set the timeout in tenths of a second to 0.

    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");// Set the terminal attributes for the standard input (0) to the modified attributes stored in the old struct.

    if (read(0, &buf, 1) < 0)
        perror ("read()"); // Read a single character from the standard input (0) and store it in the buf variable.

    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");// Set the terminal attributes for the standard input (0) to the modified attributes stored in the old struct.

    return buf;
}

List new_list(void)
{
    return NULL;
}

List add_Chainon( int x)
{
    ListElement *element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Erreur: Probleme d'allocation dynamique.\n");
        exit(1);

    }

    element->nb = x;
    element->next = NULL;

    return element;
}

Bool is_list_empty(List li){

    if (li == NULL){
        return true;
    }

    return false;
}

int list_length(List li)
{
    int size=0;
    if (!is_list_empty(li))
    {
        while (li != NULL)
        {
            size++;
            li=li->next;
        }
    }
    return size;
}

void print_list(List li)
{
    if(is_list_empty(li))
    {
        printf("La liste est vide\n");
        return;
    }

    while(li->next != NULL)
    {
        printf("%d->", li->nb);
        li = li->next;

    }

    if(li->next == NULL){
        
        printf("%d",li->nb);
    }
    
    

    printf("\n");

}

List push_back_list(List li, int x)
{
    ListElement *element = add_Chainon(x);

    if(is_list_empty(li))
    {
        return element;
    }
    
    ListElement *tmp;
    tmp=li;

    while(tmp->next != NULL)
    {
        tmp=tmp->next;
    }

    tmp->next = element;
    
    return li;

}

List push_front_list(List li,int x)
{

    ListElement *element= add_Chainon(x);


    if(is_list_empty(li))
    {
        element->next=NULL;
    }
    else
    {
          element->next= li;  
    }

    return element;
}

List pop_back_list(List li)
{
    if(is_list_empty(li))
    {
        return new_list();
    }

    if(li->next == NULL)
    {
        free(li);
        li = NULL;

        return new_list();
    }
    else
    {
        ListElement *tmp= li;
        ListElement *before = li;

        while(tmp->next != NULL )
        {
            before = tmp;
            tmp = tmp->next;

        }

        before ->next = NULL;
        free(tmp);
        tmp = NULL;

        return li;
        
    }


}


List pop_front_list(List li)
{

    if(is_list_empty(li))
    {
        return new_list();
    }

    ListElement *element;
    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Erreur: Probleme d'allocation dynamique.\n");
        exit(1);

    }


    element = li->next;

    free(li);
    li = NULL;

    return element;
}

List clear_list(List li)
{
   if(is_list_empty(li))
    {
        return new_list();
    }

    while(li != NULL)
    {
        li = pop_front_list(li);
    }

}

List sortList(List li) {
    if (li == NULL || li->next == NULL) {
        return li; // La liste est déjà triée ou vide
    }

    List sortedList = NULL;
    ListElement* current = li;

    while (current != NULL) {
        ListElement* next = current->next;
        sortedList = insertSorted(sortedList, current->nb);
        current = next;
    }

    return sortedList;
}

List insertSorted(List li, int x) {
    ListElement* newelem = add_Chainon(x);
    ListElement* current = li;
    ListElement* previous = NULL;

    while (current != NULL && current->nb < x) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        newelem->next = li;
        return newelem; // Nouveau nœud devient la nouvelle tête de liste
    } else {
        previous->next = newelem;
        newelem->next = current;
        return li; // La tête de liste reste inchangée
    }
}


List pop_element_list(List li, int value) {
    if (is_list_empty(li)) {
        return li; 
    }

    ListElement* current = li;
    ListElement* previous = NULL;

    while (current != NULL && current->nb != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return li;
    }

    if (previous == NULL) {
        li = li->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    return li;
}

List pop_all_element_list(List li, int value) {
    if (is_list_empty(li)) {
        return li; 
    }

    ListElement* current = li;
    ListElement* previous = NULL;

    while (current != NULL && current->nb != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return li;
    }

    if (previous == NULL) {
        li = li->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    return li;
}
