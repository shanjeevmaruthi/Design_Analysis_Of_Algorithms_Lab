#include<iostream>

using namespace std;

void Logic1(int[], int);

void Logic2(int[], int);
void heapsort (int heap[], int heapsize, int arr[]);
void heapify (int heap[], int heapsize);

void multiplicity(int arr[], int n);


int main (){

	int n;
	cout<<"Enter number of elements\n";
	cin>>n;

	cout<<"Enter the elements of the array\n";
	int A[n];
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	// Logic1(A, n);
	Logic2(A, n);

}

void Logic1(int arr[], int n){

	for(int i=0; i<n; i++){
		int max = 0;

		for(int j=0; j<n-i; j++){
			if(arr[j] > arr[max])
				max = j;
		}

		int temp = arr[max];
		arr[max] = arr[n-i-1];
		arr[n-i-1] = temp;
	}
	
	multiplicity(arr, n);

}

void Logic2(int arr[], int n){


	int heap[n+1], heapsize = 1;

	for(int i=0; i<n; i++){
		heap[heapsize] = arr[i];
		heapify(heap, heapsize);
		heapsize++;
	}

	for(int i=1; i<=n; i++)
		cout<<heap[i]<<" ";

	heapsort(heap, n, arr);
	cout<<endl;
	// cout<<"Post heapsort";
	// for(int i=0; i<n; i++)
	// 	cout<<arr[i]<<endl;

	multiplicity(arr, n);

}

void heapsort (int heap[], int heapsize, int arr[]){

	int size = heapsize;
	// cout<<"heapsixe = "<< heapsize;
	// printf("SORT:\n");
	for(int i=1; i<=size; i++){

		// printf("\ni = %d, %d ", i, heap[1]);
		arr[i-1] = heap[1];

		heap[1] = heap[heapsize--];
		// printf("\nafter printing:%d", heap[1]);
		int j = 1;
		int min;
		while(2*j <= heapsize){
			
			if(heapsize >= (2*j + 1))
				if(heap[2*j + 1] > heap[2*j]){
					min = 2*j;
				}
				else{
					min = 2*j + 1;
				}
			else{
				min = 2*j;
			}
			if(heap[j] > heap[min]){
				int temp = heap[j];
				heap[j] = heap[min];
				heap[min] = temp;
				j = min;
			}
			else{
				break;
			}
			
		}

		
	}

}

void heapify (int heap[], int heapsize){

	int i = heapsize;

	while(i/2 >= 1){

		if(heap[i] < heap[i/2]){
			// printf("if");
			int temp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = temp;
		}

		i = i/2;
	}
	
}

void multiplicity(int arr[], int n){

	cout<<"\n\n------------------------\nMultiplicity of the elements\n\n";

	int num = arr[0], count = 1, i;
	for(i=1; i<n; i++){

		if(num == arr[i]){
			count++;
		}
		else{
			cout<<arr[i-1]<<" - "<<count<<endl;
			num = arr[i];
			count = 1;
		}
	}

	cout<<arr[i-1]<<" - "<<count<<endl<<endl;
}