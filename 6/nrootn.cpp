#include<iostream>
#include<math.h>
using namespace std;

int main (){

    // int n;
    // cout<<"Enter value of n\n";
    // cin>>n;


    for(int q=0; q<100000; q++)
    {
        int arr[q];

        for(int i=0; i<q; i++)
            arr[i] = 1;

        int flag = 0;
        for(int i=2; i<=sqrt(q); i++){
            int j;
            for(j=i-1; j<q; j+=i);

            if(j-i==q-1){
                // cout<<q<<" is not Prime\n";
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        cout<<q<<" is prime\n";
    }
    
    return 0;
}