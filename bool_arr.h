#ifndef BOOL_ARR_H
#define BOOL_ARR_H

class bool_arr
{
private:
    int n;
    int *arr;

public:
    bool_arr(int size)
    {
        n = size;
        arr = new int[n / 32 + 1];
        int arr_size = n / 32 + 1;
        for (int i = 0; i < arr_size; i++)
        {
            arr[i] = 0;
        }
    }

    void set_value(int index, bool b)
    {

        if (index >= n)
        {
            return;
        }

        int arr_i = index / 32;
        int k = index % 32;
        int number = arr[arr_i];

        if (b == true)
        {
            number = number | (1 << k);
        }
        else
        {
            if (number & (1 << k))
                number = number ^ (1 << k);
        }

        arr[arr_i] = number;
    }
    bool chek(int index)
    {
        int arr_i = index / 32;
        int k = index % 32;
        int number = arr[arr_i];
        int bit = (number >> k) & 1U;
        if (bit == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int size()
    {
        return n;
    }
};


#endif
