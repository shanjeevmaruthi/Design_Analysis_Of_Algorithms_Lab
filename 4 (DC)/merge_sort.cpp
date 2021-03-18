#include<iostream>

using namespace std;

void merge_sort(int arr[], int s, int e);
void merge(int arr[], int s, int mid, int e);

int main (){

	int arr[] = {1, 6, 2, -5, 10};
	merge_sort(arr, 0, 4);

	for(int j=0; j<=4; j++)
		cout<<arr[j]<<" ";
	
	return 0;

}

void merge(int arr[], int s, int mid, int e){

	int temp[e-s+1];
	int i = 0;
	int l = s;
	int r = mid+1;
	while( l<=mid && r<=e ){

		if(arr[l] < arr[r]){
			temp[i] = arr[l];
			l++;
			i++;
		}
		else if(arr[l] > arr[r]){
			temp[i] = arr[r];
			r++;
			i++;
		}
		else if(arr[l] == arr[r]){
			temp[i] = arr[r];
			i++;
			r++;
			temp[i] = arr[l];
			i++;
			l++;
		}

	}

	while(l <= mid){
		temp[i] = arr[l];
		i++; l++;
	}

	while(r <= e){
		temp[i] = arr[r];
		i++; r++;
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		arr[s+j] = temp[j];
		// cout<<arr[j]<<" ";
	}
}

void merge_sort(int arr[], int s, int e){

	if(s < e){

		int mid = (s + e)/2;

		
		merge_sort(arr, s, mid);
		merge_sort(arr, mid+1, e);

		merge(arr, s, mid, e);

	}

}
