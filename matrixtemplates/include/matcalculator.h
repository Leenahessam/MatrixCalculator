#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H

#include "matrix.h"
using namespace std;
template <class Type>
class matcalculator
{
    public:
        matcalculator();
        int mainMenu();
        virtual ~matcalculator();
};

template class matcalculator<int>;
template class matcalculator<float>;
template class matcalculator<double>;

#endif // MATRIXCALCULATOR_H

