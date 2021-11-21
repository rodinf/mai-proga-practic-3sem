#include <iostream>
#include "VeloArray.h"

using namespace std;

int main()
{
    VeloArray<int> velo(4);

    velo.printAll();

    velo.setValue(1, -1);
    velo.setValue(999, 0);
    velo.printAll();
    velo.getValue(1);
    velo.appendValue(5);
    velo.printAll();

    VeloArray<int> velo_dva(4);

    //velo.distanceWith(velo_dva);

    std::cout << std::endl;

    return 0;
}
