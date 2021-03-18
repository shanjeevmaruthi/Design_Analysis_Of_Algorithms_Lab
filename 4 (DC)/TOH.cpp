#include<iostream>
using namespace std;

// Toh( s,d,a)
// {
//   if(disk==1)
//       //move from source to dest
//   else
//   {  Toh(disk-1,s,a);
//       //move disk from s to d
//      Toh(disk-1,a,d,s);      
//   }
      

// }
char s = 's', d = 'd', a = 'a';
void toh(int disk, char s, char d, char a){

    if(disk == 1)
        printf("moved 1 from %c to %c using %c\n", s, d, a);

    else{
        toh(disk - 1, s, a, d);
        printf("moved %d from %c to %c\n", disk, s, d);
        toh(disk -1, a, d, s);
    }

}

int main (int argc, char** argv){

    toh(5, s, d, a);
    return 1;
}