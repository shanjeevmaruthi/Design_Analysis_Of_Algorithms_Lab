#include<iostream>

using namespace std;

int heap[10], n=1;

void heapsort();
void heapify();

int main (){

	int arr[] = {9, 4, 1, 2, 4, 5, 9, 5}, size = 8;

	for(int i=0; i<size; i++){

		heap[n] = arr[i];
		heapify();
		n++;
	}
	n--;
	printf("\nAfter inserting:");
	for(int j=1; j<=n; j++)
		printf("%d ", heap[j]);
	printf("\n");
	cout<<"n = "<<n;
	heapsort();

}

void heapsort (){

	int size = n;
	printf("SORT:\n");
	for(int i=1; i<=size; i++){

		printf("\n%d ", heap[1]);

		heap[1] = heap[n--];
		// printf("\nafter printing:%d", heap[1]);
		int j = 1;
		int min;
		while(2*j <= n){
			
			if(n >= (2*j + 1))
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

void heapify (){

	int i = n;

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