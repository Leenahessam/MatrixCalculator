#include "matcalculator.h"
template <class Type>
matcalculator <Type> ::matcalculator()
{
}
template<class Type>
int matcalculator <Type> ::mainMenu()
{
    while(true)
    {
        node:
        cout << " 1- Perform Matrix Addition       " << endl;
        cout << " 2- Perform Matrix Subtraction    " << endl;
        cout << " 3- Perform Matrix Multiplication " << endl;
        cout << " 4- Matrix Transpose              " << endl;
        cout << " 0- EXIT                          " << endl;
        int x;
        cout << " Enter Your Operation Number:  ";
        cin >> x;
        cout << endl;
        matrix<Type>mat1;
        matrix<Type>mat2;

        ///--------------------------------------------------------

        if(x==1 || x==2 || x==3)
        {
            cout << " Enter First Matrix Data" << endl;
            cin >> mat1;
            cout << endl;
            cout << " Enter Second Matrix Data" <<endl;
            cin >> mat2;
        }

        switch(x)
        {
        case 0:
            return 0;

        case 1:
            if((mat1.getRows() == mat2.getRows()) && (mat1.getCols() == mat2.getCols()))
            {
                cout << " The Sum Of Two Matrices is   " << endl;
                cout << mat1 + mat2 <<endl;
            }
            else
                cout << endl << "Invalid operation :(" << endl;
            break;

        case 2:
            if((mat1.getRows() == mat2.getRows()) && (mat1.getCols() == mat2.getCols()))
            {
                cout << " The Subtract Of Two Matrices is   " << endl;
                mat1 = mat1 - mat2;
                cout << mat1 <<endl;
            }
            else
                cout << endl << "Invalid operation :(" << endl;
            break;

        case 3:
            if(mat1.getCols() == mat2.getCols())
            {
                cout << " The Multiplication Of Two Matrices is   " << endl;
                mat1 = mat1 * mat2;
                cout << mat1 <<endl;
            }
            else
                cout << endl << "Invalid operation :(" << endl;
            break;

        case 4:
            cout << " Enter Matrix Data" << endl;
            cin >> mat1;
            cout << " The Transpose Of The Matrix is   " << endl;
            cout << mat1.Transpose() << endl;
            break;

        default:
            goto node;
        }
    }

}
///---------------------------------------------------------
template <class Type>
matcalculator <Type> ::~matcalculator()
{
}
