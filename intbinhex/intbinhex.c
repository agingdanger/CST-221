#include <stdio.h>
void bynary(int k);
void hexadecimul(int k);
//int translate(int i);


int main(void){

	int k;
	printf("Enter a number between 0 and 4095\n");
	scanf("%d", &k);
	
	printf("Output in binary:\n");
	//bynary(&k);
	printf("\n");
	
	hexadecimul(&k);
	//translate(&a);
	return 0;
}


void bynary( int k){
	
	int bin[32], j;
	int i = 1;	
	while(k != 0)
	{
		bin[i++] = k % 2;
		k = k / 2;
	}
	
	for(j = i - 1; j > 0; j--)
	{
		printf("%d", bin[j]);
	}
}


void hexadecimul( int s){
	printf("%x\n", s);
}
