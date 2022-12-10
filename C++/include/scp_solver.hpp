#include <iostream>
#include <vector>

/**
 * @brief Solver for the SCP problem 
 * 
 * @return std::vector<std::string> As a report returns an string vector with
 *         position 0: The filename with the data used to solve
 *         position 1: The problem's columns
 *         position 2: The problem's rows
 *         position 3: The solver best solution founded 
 *         position 4: If the solution passes the restrictions
 *         position 5: The method used to solve the problem (algorithm)
 *         position 6: The solution founded
 */
std::vector<std::string> InitSolverScp();