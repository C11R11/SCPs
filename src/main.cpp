#include <Hello.hpp>
#include <vector>
#include <iostream>

/**
 * 
 */
int main() 
{
    HelloWorld world;
    world.say();

        std::cout << "hello: \n";


    const int rows = 200;
    const int columns = 1000;
    double cost[columns] = {0};
    double solution[columns] = {0};
    double sparse[rows][columns] = {0};

    //Calculation of objective function
    double objective = 0;

    for(size_t columnIndex = 0; columnIndex < columns; columnIndex++)
    {
        objective =+ cost[columnIndex] * solution[columnIndex];   
    }

    std::cout << "objective: " << objective;
    
    return 0;
}