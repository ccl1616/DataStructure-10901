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
        SparseMatrix resize(int i, int j);
    private:
        // Sparse representation
        int rows, cols, terms, capacity;
        MatrixTerm *smArray; 
};

SparseMatrix SparseMatrix::resize(int i, int j)
{
    // i for new row, j for new col
    SparseMatrix c(i,j,capacity);
    // 直轉橫
    if(rows > i){
        for every elements in smArray
            if its row >= i 
                add a term with (row= row-i, col=col+ #of old col, val)
            else add a term with (row, col, val)
    }
    else{
        for every elements in smArray
            if its col >= j
                add a term with (row = row+ #of old row, col = col - j, val)
            else add a term with (row, col, val)
    }
}