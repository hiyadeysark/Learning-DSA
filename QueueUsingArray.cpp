#include <stdio.h>

struct queue{
	int size;
	int* data;
};

void initialize(queue* arr, int len){
	arr->size = len;
	arr->data = new int [len];
} 

void input(queue* arr){
	int i = 0;
	while(i<arr->size)
	{
		scanf("%d", &arr->data[i]);
		i++;
	}
}

void display(queue* arr){
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

void enqueue(queue* arr){
	printf("Enter a number you want to enqueue: ");
	arr->size++;
	scanf("%d", &arr->data[arr->size-1]);
}

void dequeue(queue* arr){
	printf("Number dequeued - %d\n", arr->data[0]);
	int i = 0;
	while(i<arr->size-1)
	{
		arr->data[i] = arr->data[i+1];
		i++;
	}
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

int isEmpty(queue* arr){
	if(arr->size == 0)
		return 0;
	
	return 1;
}

void destory(queue* arr){
	delete [] arr->data;
}

int main(){
	queue arr;
	int len;
	printf("Enter the length of your queue - ");
	scanf("%d", &len);
	
	initialize(&arr, len);
	
	printf("Enter your numbers:\n");
	input(&arr);
	
	int choice, flag = 0;
	printf("\n\nMenu\n\n1.Enqueue\n2.Dequeue\n3.Display\n");
	
	
	do
	{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: {
				enqueue(&arr);
				
				printf("The queue is now -\n");
				display(&arr);
				
				flag = continuefn();
				
				break;
			}
			
			case 2:{
				int check = isEmpty(&arr);
				if(check == 0)
					printf("Queue is empty");
				else 
				{
					dequeue(&arr);
				
					printf("The queue is now -\n");
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
