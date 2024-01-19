#include <iostream>
#include <thread>
#include <chrono>
const int SIZE = 10;
char Buffer[SIZE];
int in = 0, out = 0;
int count = 0;
// P1 processor

bool stopFlag = false;

void producerThread()
{
    while (!stopFlag)
    {
        while (count == SIZE)
            ;
        Buffer[in] = 'a';
        in = (in + 1) % SIZE;
        count++;
    }
}
// P2 processor
void consumerThread()
{
    while (!stopFlag)
    {
        while (count == 0)
            ;
        char item = Buffer[out];
        out = (out + 1) % SIZE;
        count--;
    }
}

int main()
{
    std::thread producer(producerThread);
    std::thread consumer(consumerThread);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    stopFlag = true;
    producer.join();
    consumer.join();
    std::cout << "Finished" << std::endl;
    return 0;
}
