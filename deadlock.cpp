#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutexA, mutexB;  // Two shared mutexes

void taskA() {
    std::lock(mutexA, mutexB);  // Lock both at the same time
    std::lock_guard<std::mutex> lockA(mutexA, std::adopt_lock);
    std::lock_guard<std::mutex> lockB(mutexB, std::adopt_lock);
    std::cout << "Task A completed\n";
}

void taskB() {
    std::lock(mutexA, mutexB);  // Lock both at the same time
    std::lock_guard<std::mutex> lockA(mutexA, std::adopt_lock);
    std::lock_guard<std::mutex> lockB(mutexB, std::adopt_lock);
    std::cout << "Task B completed\n";
}

int main() {
    std::thread t1(taskA);
    std::thread t2(taskB);

    t1.join();
    t2.join();

    return 0;
}
