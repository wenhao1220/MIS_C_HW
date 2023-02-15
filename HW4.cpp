#include <stdio.h>

int main(){
    int i, j, k, a, b, first[10000], second[10000];

    do{
        printf("Please input the number of generations(>0): ");
        scanf("%d", &i);
    }while(i <= 1);

    first[0] = 1;
    second[0] = 1;
    for(k = 1; k < 10000; k++){
	first[k] = 0;
	second[k] = 0;
    }

    for(j = 1; j <= i; j++){
	if(j == 1 || j == 2)
	    printf("第 %03d 代數量:1\n", j);
	else{
	    b = 0;
	    if(j % 2 == 0){		
		for(a = 0; a < 10000; a++){
		    if((first[a] + second[a]) >= 10)
			first[a + 1] += 1;
		    if((first[a] + second[a]) > 0)
			b = a;
		    first[a] = (first[a] + second[a]) % 10;
		}
		
		printf("第 %03d 代數量:", j);
		for(a = b; a >= 0; a--)
		   printf("%d", first[a]);
		printf("\n");

	    }else{
		for(a = 0; a < 10000; a++){
		    if((second[a] + first[a]) >= 10)
			second[a + 1] += 1;
		    if((second[a] + first[a]) > 0)
			b = a;
		    second[a] = (second[a] + first[a]) % 10;
		}

		printf("第 %03d 代數量:", j);
		for(a = b; a >= 0; a--)
		    printf("%d", second[a]);
		printf("\n");
	    }
	}
    }
}

