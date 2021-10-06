#include <stdio.h>

struct stack{
	int data;
	stack* next;
};

stack* initialize(int val){
	stack* node = new stack;
	
	node->data = val;
	node->next = NULL;
	
	return node;
}

void push (stack** head, int val){
	stack* newNode = initialize(val);
	
	if(head == NULL)
	{
		*head = newNode;
		return;
	}
	
	newNode->next = *head;
	*head = newNode;
	
}

int pop(stack** head, int* pop){
	if(*head == NULL)
		return 0;
	
	*pop = (*head)->data;
	
	stack* tobepopped = *head;
	*head = tobepopped->next;
	delete tobepopped;
	
	return 1;
}

void display(stack* node){	
	if(node == NULL)
	{
		printf("Stack empty\n");
		return;
	}
	
	printf("%d\n", node->data);
	
	if(node->next == NULL)
		return;
	else{
		node = node->next;
		display(node);
	}
}



int main()
{	
	int flag = 0;
	stack* head = NULL;
	do
	{
		int choice;
		printf("\n1. Push\n2. Pop\n3. Display\nInput your choice: ");
		
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: {
				printf("Enter the number you want to push: ");
				int num;
				scanf("%d", &num);
				push(&head, num);
				break;	
			}
			
			case 2: {
				int poppednum;
				int check = pop(&head, &poppednum);
				if(check == 0)
					printf("Stack is empty\n");
				else 
					printf("Popped num is: %d\n", poppednum);
				break;
			}
			case 3: {
				display(head);
				break;
			}
			
			default: printf("Error!!");
		}
		
		printf("Do you want to continue?(press 1 for yes, 2 for no, any other input will be considered no): ");
		int ch;
		scanf("%d", &ch);
		if(ch == 1)
			flag = 0;
		else 
			flag = 1;
	}while(flag == 0);
	
	return 0;
}
