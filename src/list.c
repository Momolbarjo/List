#include <stdio.h>
#include <stdlib.h>
#include "list.h"



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
    ListElement *element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Erreur: Probleme d'allocation dynamique.\n");
        exit(1);

    }

    element->nb = x;
    element->next = NULL;

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

    ListElement *element;

    element= malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr,"Erreur: Probleme d'allocation dynamique.\n");
        exit(1);

    }

    element->nb = x;

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
