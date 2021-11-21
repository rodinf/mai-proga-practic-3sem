#ifndef VELOARRAY_H
#define VELOARRAY_H

#define VELO_MAX 100
#define VELO_MIN -100
#define VELO_UNDEFINED -101

template<typename T>
class VeloArray
{
    public:
        VeloArray(const VeloArray<T> &CopyVeloArray);
        VeloArray(const int _size);
        virtual ~VeloArray();
        void printAll();
        void initBy(const T &_number);
        void setValue(const T &_value, const int _position);
        T getValue(const int _position);
        void appendValue(const T &_value);
        T sumWith(const VeloArray<T> &SecondVeloArray);
        T subtractWith(const VeloArray<T> &SecondVeloArray);
        //T distanceWith(const VeloArray<T> &SecondVeloArray);

    protected:

    private:
        T *array;
        int size;
        bool checkValue(const T &_value);
};

#endif // VELOARRAY_H
