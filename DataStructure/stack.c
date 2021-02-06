#include <stdio.h>
#include <conio.h>

int arr[4];
int MAXSIZE = 4;
int top = -1;

int isEmpty(){
    if(top == -1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if(top == MAXSIZE)
        return 1;
    else 
        return 0;
}

void push(int item){
    if(!isFull()){
        top = top+1;
        arr[top] = item;
    }
    else{
        printf("Stack OverFlow!");
    }
}

void pop(){
    if(!isEmpty()){
        printf("%d", arr[top]);
        top = top-1;
    }
    else{
        printf("UnderFlow");
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    pop();
    pop();
    pop();
}