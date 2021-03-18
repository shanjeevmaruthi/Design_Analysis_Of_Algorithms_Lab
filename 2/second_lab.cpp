#include<iostream>
#include<algorithm>
#include<chrono>
#include<fstream>

using namespace std::chrono;
using namespace std;

int n;
int t = 0;
void method_1 (int arr[], int k, int start = 0, int end = n-1){
	//cout<<"1";
	if(start == end){
		// cout<<"ended";
		return;
	}
	else{
		if(arr[start] + arr[end] == k){
			cout<<"\nPair Found: "<<arr[start]<<", "<<arr[end];
			start = start + 1;
		}
		else{
			if(arr[start] + arr[end] > k)
				end = end - 1;
			else{
				start = start + 1;
			}
		}
	}
	method_1(arr, k, start, end);
}

int calib (int arr[], int *k){

	if(arr[0] < 0){
		t = -arr[0];
		for(int i=0; i<n; i++)
			arr[i] += t;
		*k += 2*t;
		return t;
	}
	else{
		return t;
	}
	
}

void method_2 (int arr[], int *k){

	int size = arr[n], hash[100] = {0};

	t = calib(arr, k);
	cout<<"\nk = "<<*k;
	// for(int i=0; i<n; i++)
	// 	cout<<arr[i]<<" ";

	for(int i=0; i<n; i++){
		hash[arr[i]] += 1;
		int comp = *k - arr[i];
		if(comp >= 0){
			if(comp == arr[i] && hash[comp] > 1){
				cout<<"\nsamePair Found: "<<arr[i] - t<<", "<<comp - t;
			}
			else if(hash[comp] > 0){
				cout<<"\nPair Found: "<<arr[i] - t<<", "<<comp - t;
			}
		}
	}

	// for(int i=0; i<=n/2; i++){
	// 	int comp = *k - arr[i];
	// 	if(comp >= 0){
	// 		if(comp == arr[i] && hash[comp] > 1){
	// 			cout<<"\nsamePair Found: "<<arr[i] - t<<", "<<comp - t;
	// 		}
	// 		else if(hash[comp] > 0){
	// 			cout<<"\nPair Found: "<<arr[i] - t<<", "<<comp - t;
	// 		}
	// 	}
	// }
}

void method_3(int arr[], int k){

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			if(arr[i]+arr[j] == k){
				cout<<"\nPair Found: "<<arr[i] - t<<", "<<arr[j] - t;
			}
	}
}

int main (){

	// method to input array manually
	// cout<<"Enter number of elements of array";
	// cin>>n;

	// int arr[n];
	// for(int i=0; i<n; i++)
	// 	cin>>arr[i];
	// int k;
	// cout<<"Enter k";
	// cin>>k;

	fstream f1("output.csv", ios::app);

	// int i = 20;
	for(int i=2; i<=100; i++){
		// cout<<"test";
		n = i;
		srand(i);
		int arr1[n], arr2[n], arr3[n];
		cout<<endl;
		for(int j=0; j<n; j++){
			arr1[j] = arr2[j] = arr3[j]= rand()%100;
			cout<<" "<<arr2[j];
		}
		cout<<endl;
		int k = rand() % 100;
		cout<<"n = "<<n;
		cout<<"method 1\n";
		auto start1 = high_resolution_clock::now();
		sort(arr1, arr1 + n);
		method_1(arr1, k);
		auto stop1 = high_resolution_clock::now();
		cout<<"\nmethod 2\n";
		int temp = k;
		auto start2 = high_resolution_clock::now();
		sort(arr2, arr2 + n);
		method_2(arr2, &temp);
		auto stop2 = high_resolution_clock::now();
		cout<<"\nmethod 3\n";
		auto start3 = high_resolution_clock::now();
		method_3(arr3, k);
		auto stop3 = high_resolution_clock::now();

		duration<float> d1 = (stop1 - start1);
		duration<float> d2 = (stop2 - start2);
		duration<float> d3 = (stop3 - start3);
		
		f1<<n<<","<<d1.count()<<","<<d2.count()<<","<<d3.count()<<endl;

	}

	// sort(arr,arr + n);
	// method_1(arr, k);
	// cout<<endl;

	// method_2(arr, &k);
	// cout<<endl;

	// method_3(arr, k);
	// cout<<endl;
	return 1;
}