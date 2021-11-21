#include <iostream>
#include "VeloArray.h"

VeloArray::VeloArray(const int _size) : size(_size)
{
    array = new int[_size];

    for(int i = 0; i < size; i++)
        array[i] = VELO_UNDEFINED;

    std::cout << "New class " << this << " constructed" << std::endl;
}

VeloArray::VeloArray(const VeloArray &CopyVeloArray)
{
    this->size = CopyVeloArray.size;
    this->array = new int[this->size];
    this->array = CopyVeloArray.array;

    std::cout << "New class " << this << " copied from " << &CopyVeloArray << std::endl;
}


VeloArray::~VeloArray()
{
    std::cout << "Class " << this << " destructed" << std::endl;
    delete[] array;
}

void VeloArray::printAll()
{
    std::cout << "Values of " << this << ":\t";

    for(int i = 0; i < size; i++)
        std::cout << array[i] << "\t";

    std::cout << std::endl;
}

void VeloArray::initBy(const int &_number)
{
    for(int i = 0; i < size; i++)
        array[i] = _number;
}

bool VeloArray::checkValue(const int &_value)
{
    return (_value >= VELO_MIN && _value <= VELO_MAX) ? true : false;
}

void VeloArray::setValue(const int &_value, const int _position)
{
    if (_position >= 0 && _position <= size && checkValue(_value)) {
        array[_position] = _value;
        std::cout
        << "Value " << _value
        << " has been set at position " << _position
        << " of " << this
        << std::endl;
    } else {
        std::cout
        << "Error: cannot set value " << _value
        << " at position " << _position
        << " of " << this
        << std::endl;
    }
}

int VeloArray::getValue(const int _position)
{
    if (_position >= 0 && _position <= size) return array[_position];
    else return VELO_UNDEFINED;
}

void VeloArray::appendValue(const int &_value)
{
    if(checkValue(_value))
    {
        int *newArr = new int[this->size + 1];

        for(int i = 0; i < this->size; i++)
            newArr[i] = this->array[i];

        newArr[this->size] = _value;

        delete[] this->array;

        this->array = newArr;
        this->size++;
    }
    else {
        std::cout
        << "Error while appending value " << _value <<  " to " << this
        << ": value does not fits at [" << VELO_MIN << "; " << VELO_MAX << "]"
        << std::endl;
    }
}

int VeloArray::sumWith(const VeloArray &SecondVeloArray)
{
    int sum = 0;

    for(int i = 0; i < this->size; i++)
        sum += this->array[i];

    for(int i = 0; i < SecondVeloArray.size; i++)
        sum += SecondVeloArray.array[i];

    return sum;
}

int VeloArray::subtractWith(const VeloArray &SecondVeloArray)
{
    int subt = 0;

    for(int i = 0; i < this->size; i++)
        subt += this->array[i];

    for(int i = 0; i < SecondVeloArray.size; i++)
        subt -= SecondVeloArray.array[i];

    return subt;
}
