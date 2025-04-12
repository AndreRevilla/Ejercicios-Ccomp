#include <iostream>
using namespace std;

void merge(int *p, int *q){
    int *a=p;
    int tam=(q-p)*2; 
    
    for (int *r = a; r < a+tam/2; r++) {
        p=r;
        while (p<q) {
            if (*p > *q) {
                int temp = *p;
                *p = *q;
                *q = temp;
            }
            p++;
        }
        q++;
    }
}

int main(){
    int A[]={2,4,6,1,3,5};
    int tam = sizeof(A)/sizeof(A[0]);
    
    merge(A,A+tam/2);
    
    for (int *r = A; r < A + tam; r++) {
        cout << *r << " ";
    }
    
    return 0;
}
