#include <iostream>
using namespace std;

void multiplicacion(int (*M)[3][3]){
    int *p0 = **M;
    int *p1 = **M + 9;
    int *p2 = **M + 18;
    int n=0;
    
    for (int *p = p0; p < p0 + 3; p++) {
        int distancia1 = p - p0;
        for (int *q = p1; q < p1 +3; q++){
            int distancia2 = q - p1;
            *(p2+n) = (*(p0 + distancia1*3)) * (*(p1 + distancia2)) + (*(p0 + (distancia1*3) + 1)) * (*(p1 + distancia2 + 3)) + (*(p0 + (distancia1*3) + 2)) * (*(p1 + distancia2 + 6));
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
