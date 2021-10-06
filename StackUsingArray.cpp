#include <stdio.h>

struct stack{
	int size;
	int* data;
};

void initialize(stack* arr, int len){
	arr->size = len;
	arr->data = new int [len];
} 

void input(stack* arr){
	int i = 0;
	while(i<arr->size)
	{
		scanf("%d", &arr->data[i]);
		i++;
	}
}

void display(stack* arr){
	int i = 0;
    int counter = 0;
    while (i < arr->size)
    {
    	if(counter != 10)
    	{
	        printf("%d\t", arr->data[i]);
	        i++;
	        counter++;
		}
		else
		{
			printf("\n%d\t", arr->data[i]);
	        i++;
	        counter = 1;	
		}
    }
    
    printf("\n");
}

void push(stack* arr){
	printf("Enter a number you want to push: ");
	arr->size++;
	scanf("%d", &arr->data[arr->size-1]);
}

void pop(stack* arr){
	printf("Number popped out - %d\n", arr->data[arr->size-1]);
	arr->size--;
}

int continuefn(){
	int ch, flag;
	printf("\n\nDo you want to continue? (press 1 for yes, any other input would be considered as no): ");
	scanf("%d", &ch);
				
	if(ch == 1)
		flag = 0;
	else 
		flag = 1;
	
	return flag;
}

int isEmpty(stack* arr){
	if(arr->size == 0)
		return 0;
	
	return 1;
}

void destory(stack* arr){
	delete [] arr->data;
}

int main(){
	stack arr;
	int len;
	printf("Enter the length of your stack - ");
	scanf("%d", &len);
	
	initialize(&arr, len);
	
	printf("Enter your numbers:\n");
	input(&arr);
	
	int choice, flag = 0;
	printf("\n\nMenu\n\n1.Push\n2.Pop\n3.Display\n");
	
	
	do
	{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: {
				push(&arr);
				
				printf("The stack is now -\n");
				display(&arr);
				
				flag = continuefn();
				
				break;
			}
			
			case 2:{
				int check = isEmpty(&arr);
				if(check == 0)
					printf("Stack is empty");
				else 
				{
					pop(&arr);
				
					printf("The stack is now -\n");
					display(&arr);
				}
				
				flag = continuefn();
				
				break;
			}
			
			case 3:{
				display(&arr);
					
				flag = continuefn();
				
				break;
			}
			default: printf("Not a valid choice!!");
		}
		
	}while(flag == 0);
	
	
	return 0;
}
