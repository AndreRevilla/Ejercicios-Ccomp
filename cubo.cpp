#include <iostream>
using namespace std;

int main()
{
    int M[3][3][3] ={{{1,2,3},{4,5,6},{7,8,9}},{{10,11,12},{13,14,15},{16,17,18}},{{0,0,0},{0,0,0},{0,0,0}}};
    
    /*for(int *p=**M+18; p<**M+27 ; p++){
        cout<<*p;
    }*/

    int *p0 = **M;
    int *p1 = **M + 9;
    int *p2 = **M + 18;

    for (int i = 0; i < 9; i++) {
        *(p2 + i) = (*(p0 + i)) * (*(p1 + i)) + (*(p0 + i + 1)) * (*(p1 + i + 3)) + (*(p0 + i + 2)) * (*(p1 + i + 6));
    }

    // Mostrar la matriz resultado
    for (int *p = **M + 18; p < **M + 27; p++) {
        cout << *p << " ";
        if ((p - (**M + 18) + 1) % 3 == 0)
            cout << endl;
    }

    return 0;
}
