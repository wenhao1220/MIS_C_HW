#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, w, i, j, k, t = false, s, m;
    
    while(t == false){
	printf("�п�J�A�Q�n�t�Ͼ𪺼h��(1~15�B���_��):");
        scanf("%d", &n);
	if(n % 2 == 1 && n <= 15)
	    t = true;
	else
	    printf("��J���~�Э��s��J\n");
    }

    w = 3 + 2*n;
    for(i = 1; i <= n; i++){
	for(j = i; j <= i + 2; j++){
	    for(k = 1; k <= (w - (2*j-1)) / 2; k++)
		printf("-");
	    for(k = 1; k <= (2*j-1); k++)
		printf("*");
	    for(k = 1; k <= (w - (2*j-1)) / 2; k++)
		printf("-");
	    printf("\n");
	}
    }
    
    for(s = 1; s <= n/2 + 1; s++){
	for(m = 1; m <= (n/2 + 1.5) + 1; m++)
	    printf("-");
	for(m = 1; m <= n; m++)
	    printf("*");
	for(m = 1; m <= (n/2 + 1.5) + 1; m++)
	    printf("-");
	printf("\n");
    }
}

