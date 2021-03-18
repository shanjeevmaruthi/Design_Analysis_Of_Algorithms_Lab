#include<iostream>
#define k 3
#define n 3

using namespace std;

void L1 (int arr[][n], int dest[]);
void sort (int arr1[], int arr2[], int dest[], int, int);
void L2 (int arr[][n], int start, int end);
void L3 (int arr[][n], int dest[]);
void L5 (int arr[][n], int dest[]);
void heapify ();
struct node
{ 
  int data;
  struct node *lptr;
  struct node *rptr;
 };
 struct node *tptr=NULL;
void insert(int x);
void inorder(struct node* ptr);

int dest[n*k], size = 0;

struct min_heap{
	int data;
	int ptr;
}heap[k];

int main (){
	
	int arr[k][n]={{1, 2, 4}, 
			{0, 7, 8},
			{-13, 6, 7}
			};
	
   L2(arr,0,2);

//	L1(arr, dest);                  // merge two at a time 
	
	// L3(arr, dest);                  // pointer logic
	
	// L5(arr, dest);
	
	for(int i=0; i<n*k; i++){           // printing the array
		cout<<dest[i]<<" ";
	}
	cout<<endl;  

	
	/*for(int i=0;i<k;i++)            //treesort
	   for(int j=0;j<n;j++)
	       insert(arr[i][j]);
	    
	        inorder(tptr);*/
	        return 0;
}

void L1 (int arr[][n], int dest[]){
	
		
	sort(arr[0], arr[1], dest, n, n);
	
	for(int i=2; i<k; i++){
			
		int temp[i*n] = {0};
		for(int j=0; j<i*n; j++)
			temp[j] = dest[j];
		
		sort(temp, arr[i], dest, n*i, n);
		
	}

}

void sort (int arr1[], int arr2[], int dest[], int a, int b){

	int ptr_dest = 0, ptr1 = 0, ptr2 = 0;
	
	while(ptr1 != a && ptr2 != b){
		
		if(arr1[ptr1] < arr2[ptr2]){
			dest[(ptr_dest)++] = arr1[ptr1++];
		}
		else if (arr1[ptr1] > arr2[ptr2]){
			dest[(ptr_dest)++] = arr2[ptr2++];
		}
		else{
			dest[(ptr_dest)++] = arr1[ptr1++];
			dest[(ptr_dest)++] = arr2[ptr2++];
		}
	}
	
	while(ptr1 != a){
		dest[(ptr_dest)++] = arr1[ptr1++];
	}
	
	while(ptr2 != b){
		dest[(ptr_dest)++] = arr2[ptr2++];
	}
}

void L2 (int arr[][n], int start, int end)
{  static int count=1;
	if(start>end) return;
  else if (start==end) {
	  int temp1[n*count];
	  int l_count;
	  if(count==1)l_count=0;
	  else l_count=count;
     for(int i=0;i<n*l_count;i++)temp1[i]=dest[i];
	 sort(arr[start],temp1,dest,n,n*l_count);
		 count=l_count+1;
	 }
  else if (end-start==1)
  {   
	  int temp1[n*2],temp2[n*count];
	  int l_count;
	  if(count==1)l_count=0;
	  else l_count=count;
     for(int i=0;i<n*l_count;i++)temp2[i]=dest[i];
	 sort(arr[start],arr[end],temp1,n,n);
	 sort(temp1,temp2,dest,n*2,n*l_count);
	count=l_count+2;
	}
    else
  {
	int mid=(start+end)/2;
	L2(arr,start,mid);
	L2(arr,mid+1,end);
	  
  }	
}

void L3 (int arr[][n], int dest[]){

	int ptr[k] = {0};
	int ex[k] = {0};
	int q = 0;
	while( q < n*k ){
		
		int min, adr;
		for(int i=0; i<k; i++){
			if(ptr[i] < n){
				min = arr[i][ptr[i]];
				adr = i;
				break;
			}
		}
		
		
		for(int i=0; i<k; i++){
			if(ptr[i] < n){
				if(arr[i][ptr[i]] < min){
					min = arr[i][ptr[i]];
					adr = i;
				}
			}
		}
		
		//cout<<"\nmin = "<<min<<"\nadr = "<<adr<<endl;
		dest[q] = min;
		ptr[adr] += 1;	
		q++;
	}
	
	
	
}
 
void insert(int x){

	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->rptr=NULL;
	temp->lptr=NULL;
	if(tptr==NULL)
		{tptr=temp;}
    else
	{
		struct node* pptr=NULL;
		struct node* ptr=tptr;
	while(ptr!=NULL){        { 
			pptr=ptr;
		if(x<ptr->data)
			{ ptr=ptr->lptr;}
		else
			{ptr=ptr->rptr;}
		}
        if(x<pptr->data)
			pptr->lptr=temp;
		else 
			pptr->rptr=temp;
	}
	}
}          
void inorder(struct node* ptr){
    if(ptr!=NULL)
    {
		inorder(ptr->lptr);  
		printf(" %d ",ptr->data);
		inorder(ptr->rptr);
    }
}

void L5 (int arr[][n], int dest[]){

	int ptr[k] = {0};
	int ex[k] = {0};
	int q = 0;
	while( q < n*k ){
		
		int min, adr;
		for(int i=0; i<k; i++){
			if(ptr[i] < n){
				min = arr[i][ptr[i]];
				adr = i;
				break;
			}
		}
		
		size = 1;
		for(int i=0; i<k; i++){
			if(ptr[i] < n){
					heap[size].data = arr[i][ptr[i]];
					heap[size].ptr = i;
					heapify();
					size++;
			}
		}
		min = heap[1].data;
		adr = heap[1].ptr;
		//cout<<"\nmin = "<<min<<"\nadr = "<<adr<<endl;
		dest[q] = min;
		ptr[adr] += 1;	
		q++;
	}
	
	
}

void heapify (){

	int i = size;

	while(i/2 >= 1){

		if(heap[i].data < heap[i/2].data){
			// printf("if");
			min_heap temp = heap[i];
			heap[i] = heap[i/2];
			heap[i/2] = temp;
		}

		i = i/2;
	}
	
}