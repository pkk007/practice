#include<stdio.h>
#include<string.h>
#define MAX 20

struct stack{
    char arr[MAX];
    int top;
}s;

void push(char item){
    if (s.top == (MAX - 1))
        printf ("STACK OVERFLOW\n");
    else{
        s.top++;
        s.arr[s.top] = item;
    }
}

void pop(){
    if (s.top == - 1){
        printf ("STACK UNDERFLOW\n");
    }
    else{
        s.top--;
    }
}

int main(){
    char exp[MAX];
    int i = 0;
    s.top = -1;
    printf("\nINPUT THE EXPRESSION : ");
    scanf("%s", exp);
    for(i = 0;i < strlen(exp);i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(exp[i]);
            continue;
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(exp[i] == ')'){
                if(s.arr[s.top] == '(')
                    pop();
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if(exp[i] == ']'){
                if(s.arr[s.top] == '[')
                    pop();
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
            if(exp[i] == '}'){
                if(s.arr[s.top] == '{')
                    pop();
                else{
                    printf("\nUNBALANCED EXPRESSION\n");
                    break;
                }
            }
        }
    }
    if(s.top == -1)
        printf("\nBALANCED EXPRESSION\n");
    else
        printf("\nNOT BALANCED EXPRESSION\n");
}