#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * s){
    if(s-> top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack * s){
    if(s->top == s->size-1)
        return 1;
    else
        return 0;
}

void push(struct stack * s, int data){
    if(isFull(s))
        printf("STACK OVERFLOW\n");
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

void pop(struct stack * s){
    if(isEmpty(s))
        printf("STACK UNDERFLOW\n");
    else{
        printf("%d\n",s->arr[s->top]);
        s->top--;
    }
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    //now push some element;
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);

    //now pop some element;
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    return 0;
}