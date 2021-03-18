#include<iostream>
#include<math.h>
#include<string.h>

#define max_bits 8
using namespace std;

int prod[][40] = {0};

int decToBinary(int n, int bin[]) 
{ 

	int bit = 0;
	if(n == 0){
		bin[0] = 0;
		return 1;
	}
	int i = 0;
	while(n !=0 ){
		
		bin[i] = n%2;
		n = n/2;
		i++;
	}
	cout<<i<<endl;

	return i;
}

void mult(int bin[], int prod[][40], int l){

	int t = 0;
	while (t < l){
		// cout<<endl<<"t = "<<t;
		int i=0, b=0;
		for(i; i<t; i++){
			prod[t][i] = 0;
		}
		
		if(bin[t] == 1){
			for(i, b; b<l; b++, i++){
				prod[t][i] = bin[b];
			}
		}
		else{
			for(i, b; b<l; b++, i++){
				prod[t][i] = 0;
			}
		}


		t++;
	}
	
	// cout<<endl;
	// 	for(int q=0; q<l; q++){
	// 		cout<<endl;
	// 		for(int p=0; p<2*l; p++){
	// 			cout<<prod[q][p];
	// 		}
	// 	}



	int sum = 0, carry = 0;
	for(int i=1; i<l; i++){
		
		for(int j=0; j<2*l; j++){
			sum = carry + prod[0][j] + prod[i][j];
			prod[0][j] = sum % 2;
			carry = sum / 2;
		}
	}

	// cout<<endl;
	// 	for(int q=0; q<l; q++){
	// 		cout<<endl;
	// 		for(int p=0; p<2*l; p++){
	// 			cout<<prod[q][p];
	// 		}
	// 	}

}


int main (){

	int n;
	cout<<"Enter any positive number\n";
	cin>>n;
	 
	int bits = ceil(log2f(n)) + 1;

	int bin[20], l = 0;

	for(int q=0; q<l; q++){
		cout<<endl;
		for(int p=0; p<2*l; p++){
			prod[q][p] = 0;
		}
	}

	l = decToBinary(n, bin);

	for(int i=0; i<l; i++)
		cout<<bin[i];
	cout<<endl;

	mult(bin, prod, l);

	cout<<"The product in binary is: ";
	for(int i=2*l-1; i>=0; i--)
		cout<<prod[0][i];

	cout<<endl;

}	