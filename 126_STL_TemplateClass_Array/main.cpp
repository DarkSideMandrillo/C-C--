#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
    int size{N}; // how do we get the N?
    T values[N]; // N serve saperla al momento della compilazione!

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        os << "[ ";
        for (const auto &val : arr.values)
            os << val << " ";
        os << "]" << std::endl;
        return os;
    }

public:
    Array() = default;
    Array(T initVal)
    {
        for (auto &item : values)
            item = initVal;
    }
    void fill(T val)
    {
        for (auto &item : values)
            item = val;
    }
    int getSize() const
    {
        return size;
    }
    // overload subscript operator for easy use
    T &operator[](int index)
    {
        return values[index];
    }
};

int main()
{
    Array<int, 5> nums;
    std::cout << "The size of num is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of num is: " << nums.getSize() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 1000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2{1};
    std::cout << "The size of num2 is: " << nums2.getSize() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings{std::string{"Frank"}};
    std::cout << "The size of strings is: " << strings.getSize() << std::endl;
    std::cout << strings << std::endl;
}