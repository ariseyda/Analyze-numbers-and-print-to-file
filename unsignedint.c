#include<stdio.h>

//Write C source code for a computer program that receives an unsigned integer from user and decomposes it to its digits and stores the digits in an array. 
//If the entered value has n digits, the digits array should have n elements. 
//The 0th element of the digits array should be the units digit of the entered value. 
//The 1st element of the digits array should be the tens digit of the entered value an so on. 
//After decomposition, save the number and its digits to a text file and print the digits array like example console output given below. 
//Receiving integers should continue until zeros is being entered and each result should be added to the text file. 
 
//enter an unsigned integer: 123456 
//123456 = 1x10^5 + 2x10^4 + 3x10^3 + 4x10^2 + 5x10^1 + 6x10^0 

int main(){
	
	FILE *f=fopen("unsigned_int.txt","w");
	unsigned int n;
	int count=0;
	
	printf("Enter an unsigned integer:");
	scanf("%u",&n);
	int a=n;
	
	while(n>0){
		
		n=n/10;
		count++;
	}
	n=a;
	int i=count-1;
	int *array[count];
	while(n>0){
		array[i]=n%10;
		n=n/10;
		i--;
	}
	
	int k=count-1;
	int j;
	for(j=0;j<count;j++){
		fprintf(f,"%d",array[j]);
	}
	fprintf(f,"=");
	for(j=0;j<count;j++){
		fprintf(f,"%dx%d^%d",array[j],10,k);
		k--;
		if(j<count-1){
			fprintf(f,"+");
		}
	}


	fclose(f);
	return 0;
}
