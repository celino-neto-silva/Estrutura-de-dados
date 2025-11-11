#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node *prox;
}node;

typedef struct stack{
    struct node *top;
}stack;

node *aux;

stack* create_stack(){
    stack* st = (stack*) malloc(sizeof(stack));
    if(st != NULL){
        st->top = NULL;
    }
    else{
        printf("Error occured during the process of the function create_stack()\n");
        return NULL;
    }
    return st;
}

void insert_stack(stack* my_stack){
    node* new = (node*) malloc(sizeof(node));
    
    printf("->Insert a number: ");
    scanf("%d", &new->num);

    new->prox = my_stack->top;
    my_stack->top = new;

    printf("Ok! Number inserted\n");
}

void query_stack(stack* my_stack){
    if(my_stack->top == NULL){
        printf("Stack empty! Therre's nothing to see\n");
        return;
    }
    else{
        aux = my_stack->top;
        do{
            printf("Number: %d\n", aux->num);
            aux = aux->prox;
        }while(aux != NULL);        
    }
}

void remove_element_stack(stack* my_stack){
    if(my_stack->top == NULL){
        printf("Stack empty! Therre's nothing to see\n");
        return;        
    }
    else{
        aux = my_stack->top;
        printf("Number %d removed!\n", my_stack->top->num);
        my_stack->top = my_stack->top->prox;
        free(aux);
    }
}

void freeing_stack(stack* my_stack){
    if(my_stack->top == NULL){
        printf("Stack empty! Therre's nothing to see\n");
        return;
    }
    else{
        aux = my_stack->top;
        do{
            my_stack->top = my_stack->top->prox;
            free(aux);
            aux = my_stack->top;
        }
        while(aux != NULL);
        printf("All the stack is cleaned!\n");
    }
}

int main(void){
    stack* my_stack = create_stack();
    for(int i = 0; i < 3; i++){
        insert_stack(my_stack);
    }
    query_stack(my_stack);
    remove_element_stack(my_stack);
    printf("All the stack below: \n");
    query_stack(my_stack);
    freeing_stack(my_stack);
    return 0;
}