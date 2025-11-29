#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *prox;
}node;

typedef struct linked_list_sorted
{
    struct node *begin;
    struct node *end;
}linked_list_sorted;

node* aux1;
node* aux2;

linked_list_sorted* create_linked_list_sorted(){
    linked_list_sorted* list = (linked_list_sorted*) malloc(sizeof(linked_list_sorted));
    if(list == NULL){
        printf("Error occurred during the creation of the list.\n");
        return NULL;
    }
    list->begin = NULL;
    list->end = NULL;
    return list;
}

void insert_list(linked_list_sorted* my_list){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Error occurred during the creation of the list.\n");
        return;
    }

    printf("->Insert a number: ");
    scanf("%d", &new->num);

    if(my_list->begin == NULL){
        my_list->begin = new;
        my_list->end = new;
        my_list->end->prox = NULL;
    }
    else{
        aux1 = my_list->begin;
        aux2 = NULL;

        while(aux1 != NULL && new->num > aux1->num){
            aux2 = aux1;
            aux1 = aux1->prox;
        }

        if(aux2 == NULL){
            new->prox = my_list->begin;
            my_list->begin = new;
        }
        else if(aux1 == NULL){
            my_list->end->prox = new;
            my_list->end = new;
            my_list->end->prox = NULL;
        }
        else{
            aux2->prox = new;
            new->prox = aux1;
        }
    }
    printf("Number inserted with success!\n");
}

void show_list(linked_list_sorted* my_list){
    if (my_list->begin == NULL){
        printf("There's nothing to show here!\n");
        return;
    }
    else{
        aux1 = my_list->begin;
        do
        {
            printf(" %d ", aux1->num);
            aux1 = aux1->prox;
        } while (aux1 != NULL);
    }
    
}

void remove_element(linked_list_sorted* my_list){
    if (my_list->begin == NULL)
    {
        printf("List is empty there's nothing to remove here!");
        return;
    }
    else{
        int number;
        int found;
        aux2 = NULL;
        aux1 = my_list->begin;

        printf("\nWhat number do you to remove?");
        scanf(" %d", &number);

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
                break;
            }
            else{
                aux2 = aux1;
                aux1 = aux1->prox;
            }   
        } while (aux1 != NULL);       
    }
    
}
int main (void){
    linked_list_sorted* my_list = create_linked_list_sorted();
    
    for (int i = 0; i < 5; i++)
    {
        insert_list(my_list);
    }
       
    show_list(my_list);
    remove_element(my_list);
    show_list(my_list);

    remove_element(my_list);
    show_list(my_list);
}