#include<stdio.h>
#include<math.h>
int euclid_rec (int a, int b){			//a > b

	if( a%b == 0){
		return b;
	}

	euclid_rec(b, a%b);
}

int euclid_iter (int a, int b){

	while( a%b != 0 && b != 0){
		int temp = a;
		a = b;
		b = temp%b;

	}
	return b;

}

int method_2_rec (int a, int b){

	static int d = 0;
	if( a == b)
		return a*pow(2, d);
	else{

		if( a%2 == 0 && b%2 == 0){
			a = a/2;
			b = b/2;
			d++;
		}
		else if( a%2 == 0)
				a = a/2;
				else if( b%2 == 0)
					b = b/2;
					else if( a>b )
						a = (a-b)/2;
						else
							b = (b-a)/2;				
	}
	method_2_rec(a, b);
}

int method_2_iter (int a, int b){

	int d = 0;
	
	while(1){
		if( a == b)
			return a*pow(2, d);
		else{

			if( a%2 == 0 && b%2 == 0){
				a = a/2;
				b = b/2;
				d++;
			}
			else if( a%2 == 0)
					a = a/2;
					else if( b%2 == 0)
						b = b/2;
						else if( a>b )
							a = (a-b)/2;
							else
								b = (b-a)/2;				
		}
	}
}

int rithic_iter (int a, int b){

	int gcd = 1, i = 1;
	while( i <= b){

		if( a%i == 0 && b%i == 0 ){
			gcd = i;
			i++;
		}
		else{
			i++;
		}
	}
	return gcd;

}

int rithic_rec (int a, int b, int i){

	if( a%i == 0 && b%i == 0){
		return i;
	}
	else{
		rithic_rec(a, b, i-1);
	}


}

int extended_ritbash_iter (int arr[], int n){

	int least = arr[0];
	// for(int i=1; i<n; i++)
	// 	if(arr[i] < least)
	// 		least = arr[i];

	while( least > 0){
		int flag = 1;
		for(int j=0; j<n; j++)
			if(arr[j]%least != 0){
				flag = 0;
				break;
			}
		if(flag == 1)
			return least;
		else
			least --;
	}
}

int extended_ritbash_rec (int arr[], int n, int num){

	int flag = 1;
	for(int j=0; j<n; j++)
		if(arr[j]%num != 0){
			flag = 0;
			break;
		}

	if(flag == 1){
		return num;
	}
	else
		extended_ritbash_rec(arr, n, num-1);
	
	
}

int mod (int *x){

	if( *x < 0 )
		return -(*x);
	else
		return *x;
	

}

void main (){

	int a, b, arr[20], n, flag = 0;

	printf("Enter the 2 numbers\n");
	scanf("%d%d", &a, &b);

	a = mod(&a);
	b = mod(&b);

	if( a == 0 && b == 0){
		printf("\nGCD of %d, %d using euclid_rec = NOT_DEFINED", a, b);
		printf("\nGCD of %d, %d using euclid_iter = NOT_DEFINED", a, b);
		printf("\nGCD of %d, %d using method_2_rec = NOT_DEFINED", a, b);
		printf("\nGCD of %d, %d using method_2_iter = NOT_DEFINED", a, b);
		printf("\nGCD of %d, %d using rithiic_iter = NOT_DEFINED", a, b);
		printf("\nGCD of %d, %d using rithiic_rec = NOT_DEFINED", a, b);
	}
	else if(a == 0 || b == 0){
		if( b == 0)
			b = a;
		printf("\nGCD of %d, %d using euclid_rec = %d", a, b, b);
		printf("\nGCD of %d, %d using euclid_iter = %d", a, b, b);
		printf("\nGCD of %d, %d using method_2_rec = %d", a, b, b);
		printf("\nGCD of %d, %d using method_2_iter = %d", a, b, b);
		printf("\nGCD of %d, %d using rithiic_iter = %d", a, b, b);
		printf("\nGCD of %d, %d using rithiic_rec = %d", a, b, b);
	}
	else{
		printf("\nGCD of %d, %d using euclid_rec = %d", a, b, euclid_rec(a, b));
		printf("\nGCD of %d, %d using euclid_iter = %d", a, b, euclid_iter(a, b));
		printf("\nGCD of %d, %d using method_2_rec = %d", a, b, method_2_rec(a, b));
		printf("\nGCD of %d, %d using method_2_iter = %d", a, b, method_2_iter(a, b));
		printf("\nGCD of %d, %d using rithiic_iter = %d", a, b, rithic_iter(a, b));
		printf("\nGCD of %d, %d using rithiic_rec = %d", a, b, rithic_rec(a, b, b));

	}

	printf("\nEnter number of elements\n");
	scanf("%d", &n);
	printf("Enter elements of array\n");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
		arr[i] = mod(&arr[i]);
		if(arr[i] ==  0){
			i--;
			n--;
		}

	}
	if(n == 0){
		printf("\nGCD of elements using extended_ritbash_iter = NOT_DEFINED");
		printf("\nGCD of elements using extended_ritbash_rec = NOT_DEFINED");	
	}
	else{
		printf("\nGCD of elements using extended_ritbash_iter = %d", extended_ritbash_iter(arr, n));
		printf("\nGCD of elements using extended_ritbash_rec = %d\n", extended_ritbash_rec(arr, n, arr[0]));
	}



}