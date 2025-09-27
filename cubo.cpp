#include <iostream>
using namespace std;

void multiplicacion(int (*M)[3][3]){
    int *p0 = **M;
    int *p1 = **M + 9;
    int *p2 = **M + 18;
    int n=0;
    
    for (int *p = p0; p < p1; p+=3) {
        for (int *q = p1; q < p1+3; q++){
            *(p2+n) = (*(p + 0) * (*(q + 0))) + (*(p + 1) * (*(q + 3))) + (*(p + 2) * (*(q + 6)));
            n++;
        }
        
    }
    
    for (int *p = **M + 18; p < **M + 27; p++) {
        cout << *p << " ";
        if ((p - (**M + 18) + 1) % 3 == 0)
            cout << endl;
    }
}

int main()
{
    int M[3][3][3] ={{{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{0,0,0},{0,0,0},{0,0,0}}};

    multiplicacion(M);

    return 0;
}
