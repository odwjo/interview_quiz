#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    while(1){
        gets(input);
        if(input[0] == 'q')
            break;
        //printf("%s", input);
        char stack[100] = {0};
        int stack_top = 0;
        int index = 0;
        int input_length = strlen(input);
        while(index < input_length){
            if(input[index] == '(' ||
                input[index] == '[' ||
                input[index] == '{')
                stack[stack_top++] = input[index];
            else if(input[index] == ')' ||
                input[index] == ']' ||
                input[index] == '}'){
                if(stack_top == 0){
                    index --;
                    break;

                }
                char top = stack[stack_top - 1];
                if(top == '(')
                    top = ')';
                else if(top == '[')
                    top = ']';
                else if(top == '{')
                    top = '}';
                if(input[index] == top)
                    stack_top --;
                else{
                    index --;
                    break;
                }
            }
            index ++;
        }
        if(stack_top == 0 && index == input_length)
            printf("Crect\n");
        else
            printf("Error\n");

    }
    return 0;
}

