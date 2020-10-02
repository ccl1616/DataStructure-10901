#include <iostream>

class MatrixTerm { 
    friend SparseMatrix;
    int row, col, value; 
};

class SparseMatrix{ 
    public:
        // Construct, t is the capacity of nonzero terms
        SparseMatrix(int r, int c, int t);
        // Return the transpose of (*this) matrix
        SparseMatrix Transpose(void);
        // Return sum of *this and b
        SparseMatrix Add(SparseMatrix b);
        // Return the multiplication of *this and b
        SparseMatrix Multiply(SparseMatrix b); 
    private:
        // Sparse representation
        int rows, cols, terms, capacity;
        MatrixTerm *smArray; 
};

// fast transpose !