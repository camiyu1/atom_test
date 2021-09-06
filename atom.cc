#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

// If you change the following to be atomic -> normal int
// it will be not thread-safe any more.
int a = 5;
std::atomic<int> b(0);


void work() {
    a += 5; // Performed atomically.
}

void test() {
    b ++;
}

int main() {
    while(true) {
      std::thread t1{work};
      std::thread t2{work};
      std::thread t3{test};

      t1.join();
      t2.join();
      t3.join();

      if ( a != 15) {
        std::cout << a << std::endl; // Will always output 15.
        std::cout << "b = " << b << std::endl;
      }
      a = 5;
    }
}

