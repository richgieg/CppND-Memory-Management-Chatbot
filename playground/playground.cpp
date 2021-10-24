#include <iostream>
#include <memory>

class Test {
public:
    int a = 0;
};

int main() {
    std::unique_ptr<Test> test {new Test()};
    std::cout << test.get()->a << "\n";
}
