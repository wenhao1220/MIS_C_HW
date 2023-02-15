#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
    struct node{
	char name[6];
	struct node *next;
	struct node *previous;
    };
	
    struct node *first = NULL, *last = NULL, *curr, *tra = NULL;
    int count;
    char name[100];
	
    do{
	printf("Please input name #1: ");
	scanf("%s", name);
		
	if(strlen(name) != 5 && strcmp(name,"0") != 0)
            printf("Input Error\n");
            
    }while(strlen(name) != 5 && strcmp(name,"0") != 0);
	
    count = 1;
	
    while(strcmp(name,"0") != 0){
	curr = (struct node *)malloc(sizeof(struct node));
	strcpy(curr -> name, name);
	curr -> next = NULL;
		
		
	if(first == NULL){
	    first = last = curr;
	}else{
	    if(strcasecmp(curr -> name, first -> name) < 0){
		curr -> next = first;
		first -> previous = curr;
		first = curr;
	    }else if(strcasecmp(curr -> name, last -> name) >= 0){
		last -> next = curr;
		curr -> previous = last;
		last = curr;
	    }
	    else {
		tra = first;
				
		while(tra -> next != NULL){
		    tra = tra -> next;
					
		    if(strcasecmp(curr -> name, tra -> name) < 0){
			curr -> previous = tra -> previous; 
			curr -> next = tra;
			tra -> previous -> next = curr;
			tra -> previous = curr;
			break;
		    }
		}
	    }
	}
		
	count++;
		
	do{
	    printf("Please input name #%d: ", count);
	    scanf("%s", name);
		
	    if(strlen(name) != 5 && strcmp(name,"0") != 0)
            	printf("Input Error\n");
            
	}while(strlen(name) != 5 && strcmp(name,"0") != 0);
    }
	
    curr = first;

    printf("\n-----\n");
    while(curr != NULL){
	printf("%s\n", curr -> name);
	curr = curr -> next;
    }
	
    curr = last;

    printf("-----\n?\n-----\n");	
    while(curr != NULL){
	printf("%s\n", curr -> name);
	curr = curr -> previous;
    }

    printf("-----");
}

