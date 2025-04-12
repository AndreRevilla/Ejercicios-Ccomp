#include <iostream>
using namespace std;

int main(){
    int A[]={2,4,6,1,3,5};
    int tam=sizeof(A)/sizeof(A[0]);
    int *p=A;
    int *q=(A+tam/2);

    for (int *r = A; r < A + tam / 2; r++) {
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
    
    for (int *r = A; r < A + tam; r++) {
        cout << *r << " ";
    }
    
    return 0;
}
