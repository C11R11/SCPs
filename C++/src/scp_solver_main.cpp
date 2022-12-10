#include <scp_solver.hpp>

int main() 
{
    std::vector<std::string> quickReport = InitSolverScp();

    std::cout << "Entry filename: " << quickReport[0].c_str() <<std::endl;
    std::cout << "Columns: " << quickReport[1].c_str() <<std::endl;
    std::cout << "Rows: " << quickReport[2].c_str() <<std::endl;
    std::cout << "Best Solution found: " << quickReport[3].c_str() <<std::endl;
    std::cout << "Pass restrictions: " << quickReport[4].c_str() <<std::endl;
    std::cout << "Algorithm used: " << quickReport[5].c_str() <<std::endl;
    std::cout << "Solution: " << quickReport[6].c_str() <<std::endl;
}