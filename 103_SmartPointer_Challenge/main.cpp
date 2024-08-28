#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// Creo puntatore unico di un vettore di puntatori condivisi di istanze di Test

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vector,int &num)
{
    int data{};
    for (size_t i = 0; i < num; i++)
    {
        std::cout << "Enter a value for the object " << i << ": ";
        std::cin >> data;
        // std::shared_ptr<Test> ptr = std::make_shared<Test>(data);
        // vector.push_back(ptr);
        vector.push_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vector)
{
    std::cout << "Display vector data:" << std::endl
              << "===================" << std::endl;
    for (auto &vec : vector) // uso il ref & per non fare una copia inutile
        std::cout << vec->get_data() << std::endl;
    std::cout << "===================" << std::endl;
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}
