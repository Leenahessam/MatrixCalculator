#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

template <class Type>

class matrix
{
    private:
        int rows;
        int cols;
        Type **content;

    public:
        matrix();
        matrix(int rows,int cols);
        ~matrix();
        matrix(const matrix& other);
        matrix& operator=(const matrix& other);
        int getRows();
        int getCols();
        matrix operator+ (matrix mat);
        matrix operator- (matrix mat);
        matrix operator* (matrix mat);
        matrix Transpose();

        friend istream& operator>> (istream& in, matrix<Type>& mat)
        {
            cout << " Enter the number of rows: ";
            in >> mat.rows;
            cout << " Enter the number of columns: ";
            in >> mat.cols;
            mat.content = new Type*[mat.rows];
            for(int i=0; i < mat.rows; i++)
                mat.content[i] = new Type [mat.cols];
            for(int i=0; i < mat.rows; i++)
                for(int j=0; j < mat.cols; j++){
                    cout << " Enter the element of the row " << i+1 << " and column " <<j+1<<": ";
                    in>>mat.content[i][j];
                }
            return in;
        }


        friend ostream& operator<< (ostream& out, matrix<Type> mat)
        {
            for(int i=0; i< mat.rows; i++){
                for(int j=0; j< mat.cols; j++)
                    out << " " << mat.content[i][j] << " ";
                out << endl;
            }
            out << endl;
            return out;
        }
};

template class matrix<int>;
template class matrix<float>;
template class matrix<double>;

#endif // MATRIX_H

