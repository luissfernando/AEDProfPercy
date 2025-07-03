#include <iostream>
using namespace std;
void reservarM(int **&M,int f,int c){
    M = new int*[f];
    for(int i=0;i<c;i++){
        *(M+i) = new int[c];
    }
}
void reservarM3D(int ***&M,int n){
    M = new int**[n];
    for(int i=0;i<n;i++){
        *(M+i) = new int*[n];
        for(int j=0;j<n;j++){
            *(*(M+i)+j) = new int[n];
        }
    }
}
void mostrar (int **M,int f,int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<< *(*(M+i)+j)<<" ";
        }
        cout<<endl;

    }
}
int** multiplicationM(int **A,int **B,int n){
    int **tmp;
    reservarM(tmp,n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(tmp+i)+j) = 0;
            for(int k=0;k<n;k++){
                *(*(tmp+i)+j) = *(*(tmp+i)+j) + *(*(A+i)+k) * *(*(B+k)+j);
            }
        }
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    int **M;

    return 0;
}
