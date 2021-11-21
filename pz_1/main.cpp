#include <iostream>
#include "VeloArray.h"

using namespace std;

int main()
{
    VeloArray velo(10);

    velo.printAll();

    velo.setValue(1, 0);
    velo.printAll();
    std::cout << "Value at position 0:\t" << velo.getValue(0) << "\n";

    std::cout << std::endl;

    VeloArray velo_dva(velo);
    velo_dva.printAll();
    velo_dva.appendValue(10);
    velo_dva.printAll();

    std::cout << std::endl;

    std::cout << "Sum of "
    << &velo << " and " << &velo_dva
    << " is\t" << velo.sumWith(velo_dva) << std::endl;

    std::cout << "Subt of "
    << &velo << " and " << &velo_dva
    << " is\t" << velo.subtractWith(velo_dva) << std::endl;

    std::cout << std::endl;

    return 0;
}
