#include <iostream>
#include <thread>
#include <vector>

void printHello(int id) {
    std::cout << "Hello from thread " << id << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(printHello, i);
    }

    for (auto &t : threads) {
        t.join();
    }

    return 0;
}
