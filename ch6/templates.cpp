#include <iostream>
#include <string>

template <typename T>
T max(T a, T b) {
    return a > b ? a : b;
}

template <typename T, typename U>
T add(T a, U b) {
    return a + b;
}

template <typename T1, typename T2>
class Pair {

private:
    T1 first;
    T2 second;

    public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    T1 getFirst() {
        return first;
    }
    T2 getSecond() {
        return second;
    }

};

template <typename T, int Size>
class FixedArray {
    T data[Size];
};

template<>
const char* max<const char*>(const char* a, const char* b) {
    return std::strlen(a) > std::strlen(b) ? a : b;
}



int main() {
    int a = 10;
    int b = 20;
    int c = max(a, b);
    std::cout << max(a:4.5, 3.2 b:) << std::endl;
    std::cout << max(a: 'a', b: 'D') << std::endl;
    std::cout << max(a: 'a', b: 'D') << std::endl;
    std::cout << max(a:"Hello", b:"World") <<std::endl;
    // std::cout << max(30.0, 30) << std::endl
    // std::cout << max(30, 30.1) << std::endl

    std::cout << add(a:10, b:20.5) <<

    Pair<int, double> p1(f:10, s:20.5);
    Pair<std::string, char> p2(f:"Hello", s:'!');
    Pair<std::string, float> p3(f:"Hello", s:3.14);
    std::cout << p1.getFirst() << std::endl;
    std::cout << p1.getSecond() << std::endl;
    std::cout << p2.getFirst() << std::endl;
    std::cout << p2.getSecond() << std::endl;
    std::cout << p3.getFirst() << std::endl;
    std::cout << p3.getSecond() << std::endl;
}