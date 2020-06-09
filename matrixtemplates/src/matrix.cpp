#include "matrix.h"

template <class Type>
matrix<Type>::matrix(){}

/**==================================================================**/

template <class Type>
matrix<Type>::matrix(int nRows,int nCols)
{
    rows = nRows;
    cols = nCols;
    content = new Type* [rows];
    for(int i=0; i<rows; i++)
        content[i] = new Type [cols];
}

/**==================================================================**/

template <class Type>
matrix<Type>::~matrix()
{
    for (int i=0; i < rows; i++)
        delete[] content[i];
    delete [] content;
}

/**==================================================================**/

template <class Type>
matrix<Type>::matrix(const matrix& rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;
    content = new Type* [rows];
    for(int i=0; i<rows; i++)
        content[i] = new Type [cols];
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            content[i][j] = rhs.content[i][j];
}

/**==================================================================**/

template <class Type>
matrix<Type>& matrix<Type>::operator=(const matrix& rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;
    content = new Type* [rows];
    for(int i=0; i<rows; i++)
        content[i] = new Type [cols];
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            content[i][j] = rhs.content[i][j];
    return *this;
}

/**==================================================================**/

template <class Type>
int matrix<Type>::getRows()
{
    return rows;
}

/**==================================================================**/

template <class Type>
int matrix<Type>::getCols()
{
    return cols;
}

/**==================================================================**/

template <class Type>
matrix<Type> matrix<Type>::operator+ (matrix mat)
{
    matrix res(rows, cols);
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++)
                res.content[i][j] = content[i][j] + mat.content[i][j];
    return res;
}

/**==================================================================**/

template <class Type>
matrix<Type> matrix<Type>::operator- (matrix mat)
{
    matrix res(rows, cols);
        for (int i=0; i<rows; i++)
            for (int j=0; j<this->cols; j++)
                res.content[i][j] = content[i][j] - mat.content[i][j];
    return res;
}

/**==================================================================**/

template <class Type>
matrix<Type>matrix<Type>::operator* (matrix mat)
{
    matrix res (rows, mat.cols);
        for (int i=0; i<res.rows; i++)
            for (int j=0; j<res.cols; j++)
            {
                int sum=0;
                for (int k=0; k<cols; k++)
                    sum += content[i][k] * mat.content[k][j];
                res.content[i][j] = sum;
            }
        return res;
}

/**==================================================================**/

template <class Type>
matrix<Type> matrix<Type>:: Transpose()
{
    matrix transpose(cols, rows);
    for (int i=0; i < transpose.rows; i++)
        for (int j=0; j < transpose.cols; j++)
            transpose.content[i][j] = content[j][i];
    return transpose;
}

