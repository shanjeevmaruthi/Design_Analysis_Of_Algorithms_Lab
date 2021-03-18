#include<iostream>

using namespace std;

void merge_sort(int arr[], int s, int e);
void merge(int arr[], int s, int mid, int e);

int main (){

	int arr[] = {1, -6};
	merge_sort(arr, 0, 1);

	for(int j=0; j<=1; j++)
		cout<<arr[j]<<" ";
	
	return 0;

}

void merge3(int arr[], int s, int mid1, int mid2, int e){

	int temp[e-s+1];
	int i = 0;
	
	int l = s;
	int mid = mid1 + 1;
	int r = mid2 + 1;
	
	while( l<=mid1 && r<=e && mid<= mid2){

		if(arr[r] < arr[mid]){
			if(arr[r] < arr[l]){
				temp[i] = arr[r];
				r++;
				i++;
			}
			else{
				temp[i] = arr[l];
				l++;
				i++;
			}
		}
		else{
			if(arr[mid] < arr[l]){
				temp[i] = arr[mid];
				mid++;
				i++;
			}
			else{
				temp[i] = arr[l];
				l++;
				i++;
			}
		}

	}

	
	
	
	
	while(l <= mid1){
		temp[i] = arr[l];
		i++; l++;
	}

	while(r <= e){
		temp[i] = arr[r];
		i++; r++;
	}

	while(mid <= mid2){
		temp[i] = arr[mid];
		i++; mid++;
	}
	cout<<endl;
	for(int j=0; j<i; j++){
		arr[s+j] = temp[j];
		// cout<<arr[j]<<" ";
	}
}

void merge(int arr[], int s, int mid, int e){

	for(int j=s; j<=e; j++)
		cout<<arr[j]<<" ";
	cout<<"merge\n";
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
		cout<<temp[j]<<" ";
	}
	// getchar();
}

void merge_sort(int arr[], int s, int e){

	if( e-s+1>=3 ){
		// cout<<"merge_sort\n";
		int mid1 = (s + e)/3;
		int mid2 = mid1 + 1 + (s + e)/3;
		
		merge_sort(arr, s, mid1);
		// cout<<"1done";
		merge_sort(arr, mid1 + 1, mid2);
		// cout<<"2done";
		merge_sort(arr, mid2 + 1, e);
		// cout<<"3done";
		merge(arr, s, mid1, mid2);
		cout<<"merge_1 complete\n";
		merge(arr, s, mid2, e);
		cout<<"merge_2 complete\n";
	}
	else if( e-s + 1 == 2){

		if(arr[e] < arr[s]){
			int tmp = arr[e];
			arr[e] = arr[s];
			arr[s] = tmp;
		}
	}

}