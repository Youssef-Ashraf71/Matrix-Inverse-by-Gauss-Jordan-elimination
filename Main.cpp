// Youssef Ashraf Mohamed >> section 2 >> bench number 52 >> Assignment 2 : SOlVE for Inverse of an N*N matrix
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
void PrintMatrix(float** Mat, int n, int m) {
    int i,j;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            cout<<Mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void PrintInverse(float** ar, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = n; j < m; j++) {
            cout<<fixed<<setprecision(3)<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}
void GetInverse(float** matrix, int dim) {
    int i=0,j=0,k=0;
    cout<<"<<Matrix>> :: "<<endl;
    PrintMatrix(matrix, dim, dim);
    // put identity matrix within the augmented matrix
    int NewDim=2*dim; // number of columns of the augmented matrix
    for (i=0;i<dim;i++) {
        for (j=dim;j<NewDim;j++) {
                matrix[i][j]=0;
        }
    }
    for (i=0;i<dim;i++) {
        for (j=0;j<NewDim;j++) {
            if ((j-i)==dim)
                matrix[i][j]=1;
        }
    }
  //  PrintMatrix(matrix,dim,NewDim);
    // swapping rows by sorting them on their leading numbers of 1st column
     for (i=dim-1;i>=1;i--) {
        if (matrix[i-1][0]<matrix[i][0]) {
            float* tmpswap = matrix[i];
            matrix[i]=matrix[i-1];
            matrix[i-1]=tmpswap;
        }
    }
 // for tracing show the changes done to the matrix before using row operations
    cout<<"<<Matrix UPDATED>> :: "<<endl;
    PrintMatrix(matrix,dim,NewDim);
    // using gauss elimination >> do some row operations to get the ones to easily solve for the inverse
    for (i=0;i<dim;i++) {
        for (j=0;j<dim; j++) {
            if (j!=i) {
               float factor = matrix[j][i] / matrix[i][i];
                for (k=0;k<NewDim;k++) {
                    matrix[j][k] -= matrix[i][k] * factor ;
                    // Multiply each row by a nonzero integer.
                    //  here we do the row operation by multiplying the row by the factor and subtracting to get ones
                    //  we apply this to the whole augmented matrix
                    //  gauss elimination method
                }
            }
        }
    }
    // Divide each row by the diagonal element
    for (i=0;i<dim;i++) {
         float factor = matrix[i][i];
        for (j=0;j<NewDim;j++) {
            matrix[i][j] /=factor;
        }
    }
     cout<<"<<Inverse Matrix>> :: "<<endl;
    PrintInverse(matrix,dim,NewDim);
}
int main()
{
    int order,i,j,k;
    cin>>order; // n*n dimension of the matrix
    float** matrix = new float*[order*2];
    for (i=0;i<order;i++){
        matrix[i] = new float[order*2];
    }
    for (i=0;i<order;i++){
       for(j=0;j<order;j++){
           cin>>matrix[i][j];
       }
    }
    GetInverse(matrix, order);
    return 0;
}
