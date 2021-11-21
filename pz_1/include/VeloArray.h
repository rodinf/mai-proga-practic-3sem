#ifndef VELOARRAY_H
#define VELOARRAY_H

#define VELO_MAX 100
#define VELO_MIN -100
#define VELO_UNDEFINED -101



class VeloArray
{
    public:
        VeloArray(const VeloArray &CopyVeloArray);
        VeloArray(const int _size);
        virtual ~VeloArray();
        void printAll();
        void initBy(const int &_number);
        void setValue(const int &_value, const int _position);
        int getValue(const int _position);
        void appendValue(const int &_value);
        int sumWith(const VeloArray &SecondVeloArray);
        int subtractWith(const VeloArray &SecondVeloArray);

    protected:

    private:
        int *array;
        int size;
        bool checkValue(const int &_value);
};

#endif // VELOARRAY_H
