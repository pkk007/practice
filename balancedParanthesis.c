#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char arr[20];
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
        s->top--;
    }
}

int main(){
    char exp[20];
    int i = 0;
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);

    for(i = 0; i<strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(s,exp[i]);
        }
        else if(s->top!=-1 && (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')){
            if(exp[i] == ')'){
                if(s->arr[s->top] == '(')
                    pop(s);
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if(exp[i] == ']'){
                if(s->arr[s->top] == '[')
                    pop(s);
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if(exp[i] == '}'){
                if(s->arr[s->top] == '{')
                    pop(s);
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if(isEmpty(s))
        printf("\nBALANCED EXPRESSION\n");
    else
        printf("\nNOT BALANCED EXPRESSION\n");

}
