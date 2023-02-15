#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, j, k, t, start, final;
    char str[20], str1[20];
    const char* filename = "TaiwanTravelGuide.txt";
    FILE* input_file = fopen(filename, "r");
    FILE* fp = fopen("s1104559.txt", "wb");

    struct node{
	int number;
	char name[20];
	struct node *next;
    };
    struct node *first = NULL, *curr, *temp, *compare;

    if(!input_file)
        exit(EXIT_FAILURE);

    for(i = 0; i < 205; i++){
	t = 0;
	fscanf(input_file, "%s", str1);
	
	k = 0;
	for(j = 0; j < strlen(str1); j++){
	    if(str1[j] != '.' && str1[j] != ',' && str1[j] != ';' && str1[j] != ')' && str1[j] != '('){
		start = j;
		break;
	    }
	}

        for(j = strlen(str1)-1; j >= 0; j--){
            if(str1[j] != '.' && str1[j] != ',' && str1[j] != ';' && str1[j] != ')' && str1[j] != '('){
                final = j;
                break;
            }
        }

	for(j = start; j <= final; j++){
            str[k] = str1[j];
            k++;
	}

	str[k] = '\0';
	
	compare = first;

	while(compare != NULL){
	    if(strcasecmp(compare -> name, str) == 0){
		compare -> number += 1;
		t = 1;
	    }
	    compare = compare -> next;
	}

	if(t == 0){
	    curr = (struct node *)malloc(sizeof(struct node));
	    strcpy(curr -> name, str);
	    curr -> number = 1;
	    curr -> next = NULL;

	    if(first == NULL){
	        first = curr;
		temp = curr;
	    }else{
		temp -> next = curr;
	        temp = curr;
	    }
	}
    }

    curr = first;

    while(curr != NULL){
	printf("%-14s %d\n", curr -> name, curr -> number);
	fprintf(fp,"%-14s %d\n", curr -> name, curr -> number);
	curr = curr -> next;
    }

    fclose(fp);
    fclose(input_file);
}

