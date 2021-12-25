#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <array>

class timer
{
public:
    timer(std::string point) : m_point{point}
    {
        m_start_point = std::chrono::high_resolution_clock::now();
    }

    ~timer()
    {
        auto endclock = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_point).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endclock).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << "time used by : " << m_point << " was : " << ms << " ms" << std::endl;
    }

private:
    std::string m_point;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_point;
};

int test_vector(int idx)
{

    std::vector<int> vec;

    for (int i{}; i < 1000; ++i)
    {
        vec.push_back(1);
    }

    for (int i{}; i < 1000; ++i)
    {
        vec[i] += 1;
    }

    return vec[idx];
}

int test_array(int idx)
{
    std::array<int, 1000> arr;

    for (int i{}; i < 1000; ++i)
    {
        arr[i] = 1;
    }

    for (int i{}; i < 1000; ++i)
    {
        arr[i] += 1;
    }

    return arr[idx];
}
int main()
{

    {
        timer t1{"vector test"};
        for (int i{}; i < 1000; ++i)
        {
            test_vector(i);
        }
    }

    {
        timer t2{"array test"};
        for (int i{}; i < 1000; ++i)
        {
            test_array(i);
        }
    }
}
