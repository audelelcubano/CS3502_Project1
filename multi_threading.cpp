#include <iostream>
#include <thread>
#include <vector>

void printHello(int id) {
    std::cout << "Hello from thread " << id << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    
    // Create 5 threads
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(printHello, i);
    }

    // Join all threads (wait for them to finish)
    for (auto &t : threads) {
        t.join();
    }

    return 0;
}
