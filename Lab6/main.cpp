#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    Queue bankQueue;
    const int MAX_LINE = 10;
    int serviced = 0;
    int turnedAway = 0;
    int tellerIdle = 0;
    char nextCustomer = 'A';

    srand(time(0));

    for (int i = 0; i < 100; ++i) {
        // Simulate arrival (2x chance)
        if (rand() % 3 < 2) {
            if (!bankQueue.isFull()) {
                bankQueue.enqueue(nextCustomer);
                nextCustomer = (nextCustomer == 'Z') ? 'A' : nextCustomer + 1;
            } else {
                turnedAway++;
            }
        }

        // Simulate service
        if (rand() % 3 == 0) {
            if (!bankQueue.isEmpty()) {
                bankQueue.dequeue();
                serviced++;
            } else {
                tellerIdle++;
            }
        }

        bankQueue.display();
    }

    std::cout << "\n--- Simulation Statistics ---\n";
    std::cout << "Serviced customers: " << serviced << std::endl;
    std::cout << "Customers left in line: " << bankQueue.size() << std::endl;
    std::cout << "Customers turned away: " << turnedAway << std::endl;
    std::cout << "Teller idle moments: " << tellerIdle << std::endl;

    return 0;
}
