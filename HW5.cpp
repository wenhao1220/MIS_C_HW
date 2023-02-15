#include <stdio.h>
#include <string.h>

int main(){
    int i, j, k, count, t = 0, correct = 0, total, a;
    char enter[100], c;
    char name[43][6] = {"Anita", "Beryl", "Chloe", "Doris", "Emily", "Flora", "Grace", "Helga", 
			"Irene", "Josie", "Kathy", "Lorna", "Madge", "Naomi", "Olive", "Pancy", 
                        "Rhoda", "Sonia", "Terri", "Viola", "Wendy", "Alvin", "Basil", "Clyde", 
                        "Duane", "Elmer", "Floyd", "Giles", "Homer", "Irwin", "Jamie", "Keith",
                        "Lewis", "Miles", "Nicky", "Ozzie", "Percy", "Reule", "Simon", "Teddy", 
                        "Urban", "Vince", "Willy"};

    srand((unsigned)time(0));
    i = rand() % 43;

    while(correct == 0){

    	do{
	    scanf("%s", enter);

	    count = 0;

	    while(enter[count] != '\0'){
		if(!isalpha(enter[count]))
		    break;
		count += 1;
	    }
	    
	    if(count != 5){
		t = 0;
		printf("\033[31mInput Error\033[0m\n");
	    }else
		t = 1;

	}while(t == 0);

	total = 0;
	for(j = 0; j <= 4; j++){
	    if(toupper(enter[j]) == toupper(name[i][j])){
		total += 1;
		printf("\033[42m%c\033[0m", toupper(enter[j]));
	    }else{
		k = 0;
		for(a = 0; a <= 4; a++){
		    if(toupper(enter[j]) == toupper(name[i][a])){
			k = 1;
			break;
		    }
		}

		if(k == 1)
		    printf("\033[43m%c\033[0m", toupper(enter[j]));
		else
		    printf("\033[47m%c\033[0m", toupper(enter[j])); 
		}
	    }
	
	printf("\n");

	if(total == 5){
	    correct = 1;
	    printf("\033[101m[BINGO]\033[0m\n");
	}else
	    correct = 0;
    }
}

