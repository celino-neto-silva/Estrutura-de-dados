#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *prox;
}
node;

typedef struct queue{
    struct node *begin;
    struct node *end; 
}
queue;

node* aux;

queue* create_queue(){
    queue* q = (queue*) malloc(sizeof(queue));

    if(q == NULL){
        printf("Error occurred during the process of create_queue()\n");
        return NULL;
    }
    
    q->begin = NULL;
    q->end = NULL;
    
    return q;
}

void insert_queue(queue* my_queue){
    node* new = (node*) malloc(sizeof(node));
    if(new == NULL){
        printf("Unexpected error occurred!\n");
        return;
    }
    
    printf("->Insert a number: ");
    scanf("%d", &new->num);
    new->prox = NULL;

    if(my_queue->begin == NULL){
        my_queue->begin = new;
        my_queue->end = new;
    }
    else{
        my_queue->end->prox = new;
        my_queue->end = new;
    }
    printf("Number inserted with success!\n");
}

void query_queue(queue* my_queue){
    if(my_queue->begin == NULL){
        printf("Queue is empty, there's nothing to see here!\n");
    }
    else{
        aux = my_queue->begin;
        do{
            printf(" %d ", aux->num);
            aux = aux->prox;
        }
        while(aux != NULL);
    }
}

void remove_element_queue(queue* my_queue){
    if(my_queue->begin == NULL){
        printf("There's nothing to remove here!\n");
    }
    else{
        aux = my_queue->begin;
        printf("\nNumber %d removed!\n", my_queue->begin->num);
        my_queue->begin = my_queue->begin->prox;
        free(aux);
    }
}

void freeing_queue(queue* my_queue){
    if(my_queue->begin == NULL){
        printf("Queue is empty!\n");
    }
    else{
        aux = my_queue->begin;
        do{
            my_queue->begin = my_queue->begin->prox;
            free(aux);
            aux = my_queue->begin;
        }
        while(aux != NULL);
        printf("\nQueue is freed with success!\n");
    }
}

int main(void){
    queue *my_queue = create_queue();
    for(int i = 0; i < 3; i++){
        insert_queue(my_queue);
    }
    query_queue(my_queue);
    remove_element_queue(my_queue);
    query_queue(my_queue);
    freeing_queue(my_queue);
    return 0;
}










