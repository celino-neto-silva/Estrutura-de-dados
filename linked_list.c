#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *prox;
}node;

typedef struct linked_list{
    struct node* begin;
    struct node* end;
}linked_list;

node* aux1;
node* aux2;

linked_list* create_list(){
    linked_list* list = (linked_list*) malloc(sizeof(linked_list));
    if(list == NULL){
        printf("Error occurred during the creation of the list.\n");
        return NULL;
    }
    list->begin = NULL;
    list->end = NULL;
    return list;
}

void insert_begin(linked_list* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Error unexpected occurred.\n");
        return;
    }

    printf("->Insert a number: ");
    scanf("%d", &new->num);

    if(my_list->begin == NULL){
        my_list->begin = new;
        new->prox = NULL;
        my_list->end = new;
    }
    else{
        new->prox = my_list->begin;
        my_list->begin = new;
    }

    printf("Number inserted with success!\n");
}

void insert_end(linked_list* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Error unexpected occurred.\n");
        return;
    }
    
    printf("->Insert a number: ");
    scanf("%d", &new->num);
    
    if(my_list->begin == NULL){
        my_list->begin = new;
        new->prox = NULL;
        my_list->end = new;
    }
    else{
        my_list->end->prox = new;
        my_list->end = new;
        my_list->end->prox = NULL;
    }
    printf("Number inserted with success!\n");
}

void show_list(linked_list* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing to see here!\n");
    }
    else{
        aux1 = my_list->begin;
        do
        {
            printf(" %d ", aux1->num);
            aux1 = aux1->prox;
        }while(aux1 != NULL);
        
    }
}

void remove_list(linked_list* my_list){
    if(my_list->begin == NULL){
        printf("The List is empty!\n");
        return;
    }

    int number = 0;
    int found = 0;
    aux2 = NULL;

    printf("\nWhat number do you want remove?: ");
    scanf("%d", &number);

    aux1 = my_list->begin;
    do
    {
        if(aux1->num == number){
            found++;
            if(aux1 == my_list->begin){
                my_list->begin = aux1->prox;
                free(aux1);
                aux1 = my_list->begin;
            }
            else if(aux1 == my_list->end){
                aux2->prox = NULL;
                my_list->end = aux2;
                free(aux1);
                aux1 = NULL;
            }
            else{
                aux2->prox = aux1->prox;
                free(aux1);
                aux1 = aux2->prox; 
            }
        }
        else{
            aux2 = aux1;
            aux1 = aux1->prox;
        }
    }
    while(aux1 != NULL);
    
    if(found > 0){
        printf("Number removed with success!\n");
    }
    else{
        printf("Number didn't found!\n");
    }
}

void freeing_list(linked_list* my_list){
    if(my_list->begin == NULL){
        printf("There's nothing here to free!\n");
        return;
    }
    
    aux1 = my_list->begin;
    do
    {
        my_list->begin = my_list->begin->prox;
        free(aux1);
        aux1 = my_list->begin;
    }   
    while(aux1 != NULL);

    printf("\nList freed with success!\n");
}

int main(void){
    linked_list* my_list = create_list();
    
    for(int i = 0; i < 3; i++){
        insert_begin(my_list);
    }
    
    for(int i = 0; i < 3; i++){
        insert_end(my_list);
    }
    
    show_list(my_list);

    remove_list(my_list);

    show_list(my_list);
    
    freeing_list(my_list);
    return 0;
}