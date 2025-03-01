#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex balance_mutex; // Mutex to prevent race conditions
int balance = 1000;  // Shared resource (bank balance)

void withdraw(int id, int amount) {
    std::lock_guard<std::mutex> lock(balance_mutex); // Lock mutex
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Thread " << id << " withdrew $" << amount
                  << ". Remaining balance: $" << balance << std::endl;
    } else {
        std::cout << "Thread " << id << " tried to withdraw $" << amount
                  << " but insufficient funds!\n";
    }
}

int main() {
    std::vector<std::thread> threads;

    // Simulate multiple withdrawals
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(withdraw, i, 300);
    }

    for (auto &t : threads) {
        t.join();
    }

    std::cout << "Final balance: $" << balance << std::endl;
    return 0;
}
