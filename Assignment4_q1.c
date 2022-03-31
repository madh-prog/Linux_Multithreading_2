/******************************************************************************
Madhuri Mahajan
2.Write a program where a structure of information passed to pthread task function, and display
structure of information.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<string.h>
struct my_Struct{
	int index;
	int value;
	char name[20];
};
void* my_Func(void *new_struct){
	struct my_Struct *struct_ptr = (struct my_Struct*) new_struct;
    printf("index: %d  |  value: %d  |  name:%s\n", struct_ptr->index, struct_ptr->value,struct_ptr->name);
	
}
int main()
{
    //int n;
	struct my_Struct mystruct_1[5];
	//printf("Enter the records you want to add : ");
	//scanf("%d",&n);
	printf("\nEnter 5 numbers and name:\n");
	for (int i=0; i<5; i++){
		scanf("%d", &mystruct_1[i].value);
		mystruct_1[i].index = i;
	}
	printf("\nEnter 5 name:\n");
	for (int i=0; i<5; i++)
	{
	    scanf("%s",mystruct_1[i].name);
	}
	pthread_t tid[5];
	for(int i=0; i<5; i++){
		pthread_create(&(tid[i]), NULL, my_Func, &mystruct_1[i]);
	}
	for (int i=0; i<5; i++){	
		pthread_join(tid[i], NULL);
	}
}