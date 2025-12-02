#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node* prox;
    struct node* prev;
}
node;

typedef struct double_list_sorted{
    struct node* begin;
    struct node* end;
}
double_list_sorted;

node* aux1;
node* aux2;

double_list_sorted* create_list(){
    double_list_sorted* lst = (double_list_sorted*) malloc(sizeof(double_list_sorted));

    if(lst == NULL){
        printf("Unexpected error occurred hapened!\n");
        return NULL;
    }

    lst->begin = NULL;
    lst->end = NULL;

    return lst;
}

void insert_list(double_list_sorted* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Unexpected error occurred hapened!\n");
        return;        
    }

    printf("->Insert a number: ");
    scanf("%d", &new->num);

    if(my_list->begin == NULL){
        new->prev = NULL;
        new->prox = NULL;
        my_list->begin = new;
        my_list->end = new;
    }
    else{
        aux1 = my_list->begin;
        
        while(aux1 != NULL && new->num > aux1->num){
            aux1 = aux1->prox;
        }

        if(aux1 == my_list->begin){
            new->prox = my_list->begin;
            new->prev = NULL;
            my_list->begin->prev = new;
            my_list->begin = new;

        }
        else if(aux1 == NULL){
            my_list->end->prox = new;
            new->prev = my_list->end;
            my_list->end = new;
            my_list->end->prox = NULL;
        }
        else{
            new->prox = aux1;
            aux1->prev->prox = new;
            new->prev = aux1->prev;
            aux1->prev = new;
        }
    }
}

void show_list(double_list_sorted* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
        return;
    }

    aux1 = my_list->begin;
    do
    {
        printf(" %d ", aux1->num);
        aux1 = aux1->prox;
    }
    while(aux1 != NULL);
}

void remove_element(double_list_sorted* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
        return;
    }
    
    int n;
    printf("\n->What number do you want to remove?: \n");
    scanf(" %d", &n);
    aux1 = my_list->begin;
    do
    {
        if (aux1->num == n)
        {
            if (aux1 == my_list->begin)
            {
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
        else
        {
            aux1 = aux1->prox;
        }
        
    }
    while(aux1 != NULL);
}

int main(void){
    double_list_sorted* my_list = create_list();
    for(int i = 0; i < 6; i++){
        insert_list(my_list);
    }

    show_list(my_list);
    remove_element(my_list);
    show_list(my_list);
}