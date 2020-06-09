#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "matcalculator.h"
using namespace std;
int main()
{
    string name;
    cout << " Enter Your Name:  ";
    cin >> name;
    cout << "----------------------------" << endl;
    mode:
    cout << " Welcome to " << name << " Matrix Calculator" <<endl;
    cout << " -------------------------------------------------- " << endl << endl << endl;
    matcalculator<int>DVD;
    DVD.mainMenu();
    return 0;
}
