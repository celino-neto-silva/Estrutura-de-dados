#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *prev;
    struct node *prox;
}
node;

typedef struct double_linked_list
{
    struct node *begin;
    struct node *end;
}
double_linked_list;

node* aux1;
node* aux2;
node* ant;

double_linked_list* create_double_list(){
    double_linked_list* lst = (double_linked_list*) malloc(sizeof(double_linked_list));
    if (lst == NULL)
    {
        printf("Error unexpected occurred during the process of creation list!\n");
        return NULL;
    }

    lst->begin = NULL;
    lst->end = NULL;
    
    return lst;
}

void insert_begin(double_linked_list* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Error unexpected occurred during the process of creation list!\n");
        return;
    }
    
    printf("->Insert a number at the begin: ");
    scanf(" %d", &new->num);

    if(my_list->begin == NULL){
        new->prev = NULL;
        new->prox = NULL;
        my_list->begin = new;
        my_list->end = new;
    }
    else{
        new->prev = NULL;
        
        new->prox = my_list->begin;
        my_list->begin->prev = new;

        my_list->begin = new;
    }
}

void insert_end(double_linked_list* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Error unexpected occurred during the process of creation list!\n");
        return;
    }
    
    printf("->Insert a number at the end: ");
    scanf(" %d", &new->num);

    if(my_list->begin == NULL){
        new->prev = NULL;
        new->prox = NULL;
        my_list->begin = new;
        my_list->end = new;
    }
    else{
        new->prox = NULL;
        new->prev = my_list->end;
        my_list->end->prox = new;
        my_list->end = new;
    }
}

void show_list_b_e(double_linked_list* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
        return;
    }
    aux1 = my_list->end;
    do
    {
        printf(" %d", aux1->num);
        aux1 = aux1->prev;
    }
    while(aux1 != NULL);
}

void show_list_e_b(double_linked_list* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
        return;
    }
    aux1 = my_list->begin;
    do
    {
        printf(" %d", aux1->num);
        aux1 = aux1->prox;        
    }
    while(aux1 != NULL); 
}

void remove_element(double_linked_list* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
        return;
    }
    
    int number;
    int found = 0;

    printf("\n->What's number do you want to remove?:");
    scanf(" %d", &number);

    aux1 = my_list->begin;

    do
    {
        if(aux1->num == number){
            found++;
            if(aux1 == my_list->begin){
                my_list->begin = aux1->prox;
                if(my_list->begin != NULL){
                    my_list->begin->prev = NULL;
                }
                free(aux1);
                aux1 = my_list->begin;
            }
            else if(aux1 == my_list->end){
                my_list->end = my_list->end->prev;
                my_list->end->prox = NULL;
                free(aux1);
                aux1 = NULL;
            }
            else{
                aux1->prev->prox = aux1->prox;
                aux1->prox->prev = aux1->prev;

                aux2 = aux1->prox;
                free(aux1);
                aux1 = aux2;
            }
            break;
        }
        else{
            aux1 = aux1->prox;
        }
    }
    while(aux1 != NULL);
}

int main(void){
    double_linked_list* my_list = create_double_list();
    for (int i = 0; i < 3; i++)
    {
        insert_begin(my_list);
    }
    
    for (int i = 0; i < 3; i++)
    {
        insert_end(my_list);
    }
    printf("\nPrinting from end to the begin\n");
    printf("--------------------------------\n");
    
    show_list_e_b(my_list);
    
    remove_element(my_list);

    printf("\nPrinting from begin to the end\n");
    printf("--------------------------------\n");

    show_list_b_e(my_list);
}