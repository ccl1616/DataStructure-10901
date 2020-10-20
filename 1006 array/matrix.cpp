#include <iostream>

class Matrix{ 
    public:
        // Construct
        Matrix(int r, int c);
        // Return the transpose of (*this) matrix
        Matrix Transpose(void);
        // Return sum of *this and b
        Matrix Add(Matrix b);
        // Return the multiplication of *this and b
        Matrix Multiply(Matrix b); 
    private:
        // Array representation
        int **a;
        int rows;
        int cols; 
};

Matrix Matrix::Transpose(void){ 
    Matrix c(cols, rows);
    for (int i=0; i< rows; i++)
        for (int j=0; j< cols; j++) 
            c.a[j][i]=a[i][j];
    return c; 
}
Matrix Matrix::Add(Matrix b){ 
    Matrix c(cols, rows);
    for (int i=0; i< rows; i++)
        for (int j=0; j< cols; j++) 
            c.a[j][i] = a[i][j]+b.a[i][j];
    return c; 
}

Matrix Matrix::Multiply(Matrix b){ 
    Matrix c(cols, rows);
    for (int i=0; i< rows; i++)
        for (int j=0; j< cols; j++) {
            int sum = 0;
            for(int k = 0; k < cols; k ++) //this cols == a's #col
                sum = a[i][k] * b.a[k][j];
            c.a[i][j] = sum;
        }
    return c; 
}