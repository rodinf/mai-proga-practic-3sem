#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <math.h>

#include "VeloArray.h"

template<typename T>
VeloArray<T>::VeloArray(const int _size) : size(_size)
{
    if(_size <= 0) {
        std::cout << "Error while creating object: wrong length" << std::endl;
        throw std::bad_alloc();
        return;
    }

    array = new T[_size];

    for(int i = 0; i < size; i++)
        array[i] = VELO_UNDEFINED;

    std::cout << "New object " << this << " constructed" << std::endl;
}

template<typename T>
VeloArray<T>::VeloArray(const VeloArray<T> &CopyVeloArray)
{
    this->size = CopyVeloArray.size;
    this->array = new T[this->size];
    this->array = CopyVeloArray.array;

    std::cout << "New object " << this << " copied from " << &CopyVeloArray << std::endl;
}

template<typename T>
VeloArray<T>::~VeloArray()
{
    std::cout << "Object " << this << " destructed" << std::endl;
    delete[] array;
}

template<typename T>
void VeloArray<T>::printAll()
{
    std::cout << "Values of " << this << ":\t";

    for(int i = 0; i < size; i++)
        std::cout << array[i] << "\t";

    std::cout << std::endl;
}

template<typename T>
void VeloArray<T>::initBy(const T &_value)
{
    if(checkValue(_value)) {
        for(int i = 0; i < size; i++)
            array[i] = _value;
    }
    else {
        throw std::invalid_argument("Error while init: Invalid argument");
    }
}

template<typename T>
bool VeloArray<T>::checkValue(const T &_value)
{
    return (_value >= VELO_MIN && _value <= VELO_MAX) ? true : false;
}

template<typename T>
void VeloArray<T>::setValue(const T &_value, const int _position)
{
    try {
        if (_position >= 0 && _position <= size) {
            if(checkValue(_value)) {
                array[_position] = _value;
                std::cout
                << "Value " << _value
                << " has been set at position " << _position
                << " of " << this
                << std::endl;
            }
            else {
                throw std::invalid_argument("Invalid argument");
            }
        }
        else {
            std::out_of_range("Out of range");
        }
    }
    catch(std::out_of_range &e) {
        std::cout << "Error setting value " << _value << " at position " << _position << ": " << e.what() << std::endl;
    }
    catch(std::invalid_argument &e) {
        std::cout
        << "Error setting value " << _value << " at position " << _position << ": " << e.what()
        << std::endl;
    }
}

template<typename T>
T VeloArray<T>::getValue(const int _position)
{
    if (_position >= 0 && _position <= size && array[_position] != NULL) return array[_position];
    else throw std::out_of_range("Error getting value: Out of range");
}

template<typename T>
void VeloArray<T>::appendValue(const T &_value)
{
    if(checkValue(_value))
    {
        T *newArr = new T[this->size + 1];

        for(int i = 0; i < this->size; i++)
            newArr[i] = this->array[i];

        newArr[this->size] = _value;

        delete[] this->array;

        this->array = newArr;
        this->size++;
    }
    else {
        throw std::invalid_argument("Error appending value: Invalid argument");
    }

}

template<typename T>
T VeloArray<T>::sumWith(const VeloArray<T> &SecondVeloArray)
{
    T sum = 0;

    for(int i = 0; i < this->size; i++)
        sum += this->array[i];

    for(int i = 0; i < SecondVeloArray.size; i++)
        sum += SecondVeloArray.array[i];

    return sum;
}

template<typename T>
T VeloArray<T>::subtractWith(const VeloArray<T> &SecondVeloArray)
{
    T subt = 0;

    for(int i = 0; i < this->size; i++)
        subt += this->array[i];

    for(int i = 0; i < SecondVeloArray.size; i++)
        subt -= SecondVeloArray.array[i];

    return subt;
}

/*template<typename T>
T VeloArray<T>::distanceWith(const VeloArray<T> &SecondVeloArray)
{
    if(typeid(this).name() == typeid(SecondVeloArray).name())
        std::cout<<"ok";
    else
            std::cout<<typeid(this).name() <<"\t"<<typeid(SecondVeloArray).name() ;
}
*/
template class VeloArray<int>;
template class VeloArray<float>;
