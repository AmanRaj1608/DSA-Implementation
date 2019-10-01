#include<bits/stdc++.h>
using namespace std;
#define fast_io  ios_base::sync_with_stdio(false);cin.tie(NULL);

void add(int a[8][8], int b[8][8], int n, int c[8][8]) {
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return;
}

void subt(int a[8][8], int b[8][8], int n,int c[8][8]) {
    // int n = 8;
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
    return;
}

void answer(int a[8][8], int b[8][8], int n,int c[8][8]) {
    // Best Case
    if(n==2) {
        int a1 = a[0][0], b1 = a[0][1], c1 = a[1][0], d1 = a[1][1];
        int e1 = b[0][0], f1 = b[0][1], g1 = b[1][0], h1 = b[1][1];
        int p1 = a1*(f1-h1);
        int p2=(a1+b1)*h1; 
        int p3=(c1+d1)*e1;
        int p4=d1*(g1-e1);
        int p5=(a1+d1)*(e1+h1);
        int p6=(b1-d1)*(g1+h1);
        int p7=(a1-c1)*(e1+f1);
        c[0][0]=a1*e1+b1*g1;
        c[0][1]=a1*f1+b1*h1;
        c[1][0]=c1*e1+d1*g1;
        c[1][1]=c1*f1+d1*h1;
        return;
    }
    int a11[8][8];
    int a12[8][8];
    int a21[8][8];
    int a22[8][8];
    int b11[8][8];
    int b12[8][8];
    int b21[8][8];
    int b22[8][8];

    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            a11[i][j]=a[i][j];
            b11[i][j]=b[i][j];

            a21[i][j]=a[i+(n/2)][j];
            b21[i][j]=b[i+(n/2)][j];

            a12[i][j]=a[i][j+(n/2)];
            b12[i][j]=b[i][j+(n/2)];

            a22[i][j]=a[i+(n/2)][j+(n/2)];
            b22[i][j]=b[i+(n/2)][j+(n/2)];
        }
    }

    int m1[8][8];
    int m2[8][8];
    int m3[8][8];
    int m4[8][8];
    int m5[8][8];
    int m6[8][8];
    int m7[8][8];

    int temp1[8][8];
    int temp2[8][8];

    subt(b12,b22,n/2,temp1);
    answer(a11,temp1,n/2,m1);

    add(a11,a12,n/2,temp1);
    answer(temp1,b22,n/2,m2);

    add(a21,a22,n/2,temp1);
    answer(temp1,b11,n/2,m3);

    subt(b21,b11,n/2,temp1);
    answer(a22,temp1,n/2,m4);

    add(a11,a22,n/2,temp1);
    add(b11,b22,n/2,temp2);
    answer(temp1,temp2,n/2,m5);

    subt(a12,a22,n/2,temp1);
    add(b21,b22,n/2,temp2);
    answer(temp1,temp2,n/2,m6);

    subt(a11,a21,n/2,temp1);
    add(b11,b12,n/2,temp2);
    answer(temp1,temp2,n/2,m7);

    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            c[i][j]=m5[i][j]+m4[i][j]-m2[i][j]+m6[i][j];
            c[i+(n/2)][j]=m3[i][j]+m4[i][j];
            c[i][j+(n/2)]=m1[i][j]+m2[i][j];
            c[i+(n/2)][j+(n/2)]=m1[i][j]+m5[i][j]-m3[i][j]-m7[i][j];
        }
    }
    return;
}

int32_t main() {
    fast_io
    int n = 8;
    int a[8][8] = {
        {11, 2, 3, 4, -15, 6, 17, 8},
        {3, -7, 16, 5, 14, 3, 22, 1},
        {22, 3, 6, 25, 24, 23, 12, 3},
        {7, 6, 35, 4, 23, 2, -11, 22},
        {25, 6, 7, 28, 11, -12, 3, 4},
        {6, -15, 8, 7, 24, 3, 23, -4},
        {-11, 2, 2, -11, 5, 6, 27, 18},
        {12, 7, 24, 15, 6, 17, 8,19}
    };
    int b[8][8] = {
        {5, 12, 8, -11, 4, 18, 6, 2},
        {-23, 15, 9, 7, 22, 11, 14, 16},
        {-5, -18, 23, 28, -34, 24, 6, 9},
        {7, 14, 11, 6, 9, -4, -7, 6},
        {4, 5, -6, -7, 8, 9, 10, -11},
        {12, -13, 14, 15, 16, -17, 19, 19},
        {-20, 21, 22, -23, 24, -25, 26, 27},
        {4, 3, 2, 1, 9, 8, 7,6}
    };
    int c[8][8];
/*
    A = |A11 A12|
        |A21 A22|
    B = |B11 B12|
        |B21 B22|
    C = |C11 C12|
        |C21 C22|
    M1 = (A11 + A22) (B11 + B22)
    M2 = (A21 + A22)B11
    M3 = A11(B12 − B22)
    M4 = A22(B21 − B11)
    M5 = (A11 + A12)B22
    M6 = (A21 − A11)(B11 + B12)
    M7 = (A12 − A22)(B21 + B22)
*/
    answer(a,b,8,c);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
