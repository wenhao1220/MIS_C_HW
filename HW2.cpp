#include <stdio.h>

int main(){
    char c;
    int total, n, type = 0, num_count = 0;

    while(num_count != 10){
	printf("請輸入檢查的統一證號:");
	type = 0;
	total = 0;
	num_count = 0;

        for(n = 1; n <= 11; n++){
            scanf("%c", &c);

            if(n == 1){
		printf("統一證號 ");
		
                if(isalpha(c)){
                    num_count += 1;
                    printf("%c", c);
                    c = toupper(c);

                    if(c >= 'A' && c <= 'H')
                        c = c - 55;
                    else if(c >= 'J' && c <= 'N')
                        c = c - 56;
                    else if(c >= 'P' && c <= 'V')
                        c = c - 57;
                    else if(c >= 'X' && c <= 'Y')
                        c = c - 58;
                    else if(c == 'W')
                        c = 32;
                    else if(c == 'Z')
                        c = 33;
                    else if(c == 'I')
                        c = 34;
                    else if(c == 'O')
                        c = 35;
		    total += (c / 10) + (c % 10)*9;
                }else{
                    printf("%c", c);
                    type = 1;
                }

	    }else if(n >= 2 && n <= 10){
		if(isdigit(c)){
                    num_count += 1;
                    printf("%c", c);
                    c = c - '0';

                    if(n == 10)
                        total += (c * 1);
                    else
                        total += (c * (10 - n));
                    
                }else{
                    printf("%c", c);

                    if(type == 0)
                        type = 2;
                }
	    } 
	}
	
	if(num_count != 10){
	    if(type == 1)
		printf(" 格式錯誤，第一碼須為英文字母\n");
	    else if(type == 2)
		printf(" 格式錯誤，後九碼須為數字\n");
	}else{
	    if(total % 10 == 0)
	        printf(" 合法\n");
	    else
		printf(" 不合法\n");
	    }
    }
}

