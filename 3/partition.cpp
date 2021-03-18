#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int calc_score (string, int[]);
int len (string);

int n;

int main (){

	cout<<"Enter the number of elements\n";
	cin>>n;

	int arr[n];
	cout<<"Enter the elements";
	for(int i=0; i<n; i++)
		cin>>arr[i];

	char base[n];
	for(int i=0; i<n/2; i++)
		base[i] = '1';
	
	for(int i=n/2; i<n; i++)
		base[i] = '0';
	string str = base;
	str[n] = '\0';

	int min_score, size = len(str);

	cout<<"Length of string = "<<len(str);
	
	int A_sum = 0, B_sum = 0;

	for(int i=0; i<n; i++){
		cout<<str[i];
		if(str[i] == '1'){
			A_sum += arr[i];
		}
		if(str[i] == '0'){
			B_sum += arr[i];
		}
	}

	sort(str.begin(), str.end());

	min_score = abs(A_sum - B_sum);
	
	string min_str = str;
	cout<<" - "<<min_score<<endl;
	
	next_permutation(str.begin(), str.end());


	do{
		int score;
		if(len(str) == n){

			int A_sum = 0, B_sum = 0, temp = 0;

			for(int i=0; i<n; i++){
				// cout<<str[i];
				if(str[i] == '1'){
					A_sum += arr[i];
					temp++;
				}
				if(str[i] == '0'){
					B_sum += arr[i];
					temp++;
				}
			}
			score = abs(A_sum - B_sum);
			if(temp == size){
				cout<<str<<" - "<<score<<endl;
				
				if(score < min_score){
					min_str = str;
					min_score = score;
				}
			}
		}

	}while(next_permutation(str.begin(), str.end()));

	cout<<"\n\n\n------------------------------\n\nPartitions with max sum: "<<min_str<<endl<<endl;


}


int calc_score (string str, int arr[]){

	int A_sum = 0, B_sum = 0;

	for(int i=0; i<n; i++){
		cout<<str[i];
		if(str[i] == '1'){
			A_sum += arr[i];
		}
		if(str[i] == '0'){
			B_sum += arr[i];
		}
	}

	return abs(A_sum - B_sum);
}

int len (string str){

	int i = 0;
	while(str[i] != '\0')
		i++;

	return i;

}