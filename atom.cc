#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

// If you change the following to be atomic -> normal int
// it will be not thread-safe any more.
std::atomic<int> a(5);

void work() {
    a += 5; // Performed atomically.
}

int main() {
    std::thread t1{work};
    std::thread t2{work};

    t1.join();
    t2.join();

    if (a != 15) {
      std::cout << a << std::endl; // Will always output 15.
    }
}

