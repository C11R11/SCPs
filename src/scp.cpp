#include <vector>
#include <iostream>
#include <string>
#include <fstream>

std::ofstream outfile("results.txt");
int rows = 0;
int columns = 0;
std::vector<std::vector<double>> sparse;

void split(const std::string &s, char c,
           std::vector<std::string> &v)
{
    std::string::size_type i = 0;
    std::string::size_type j = s.find(c);

    while (j != std::string::npos)
    {
        v.push_back(s.substr(i, j - i));
        i = ++j;
        j = s.find(c, j);

        if (j == std::string::npos)
        {
            std::string stringFound = s.substr(i, s.length());
            if (stringFound.compare("") != 0)
                v.push_back(stringFound);
        }
    }
}

void LoadData(std::vector<double> &cost, std::vector<std::vector<double>> &sparse)
{
    std::string myText;

    // int rows = 0;
    // int columns = 0;
    std::string filename = "scp410.txt";

    // Read from the text file
    //std::ifstream MyReadFile("../input/scp410.txt");
    std::ifstream MyReadFile(filename);

    std::cout << "Reading: -->" << std::endl;
    outfile << "File: " << filename <<std::endl;

    if (MyReadFile.fail())
    {
        std::cout << "xx/ ";
    }
    // Use a while loop together with the getline() function to read the file line by line
    else
    {
        //rows and columns
        std::getline(MyReadFile, myText);
        std::vector<std::string> v;
        split(myText, ' ', v);

        rows = stod(v[0]);
        columns = stod(v[1]);

        outfile << "rows ->" << rows << std::endl;
        outfile << "columns ->" << columns << std::endl;

        int valuesCounter = 0;

        // iterate looking for all columns costs
        while (valuesCounter < columns)
        {
            if (std::getline(MyReadFile, myText))
            {
                // Output the text from the file
                std::cout << myText << std::endl;

                std::vector<std::string> v;

                split(myText, ' ', v);

                for (int i = 0; i < v.size(); ++i)
                {
                    cost.push_back(stod(v[i]));
                    valuesCounter++;
                }
            }
        }

        int rowsCount = 0;

        while (rowsCount < rows)
        {
            std::getline(MyReadFile, myText);
            //std::cout << "getline ->" << myText << std::endl;
            int sparseCount = stod(myText);
            valuesCounter = 0;

            //std::cout << "sparse ->" << sparseCount << std::endl;
            //std::cout << "new row " << std::endl;
            std::vector<double> row(columns, 0.0);

            // iterate looking for all columns costs
            while (valuesCounter < sparseCount)
            {
                if (std::getline(MyReadFile, myText))
                {
                    // Output the text from the file
                    std::cout << myText << std::endl;

                    v.clear();
                    //std::cout << "row.size" << row.size() << " "
                    //          << "v.size" << v.size() << std::endl;
                    split(myText, ' ', v);
                    //std::cout << "row.size" << row.size() << " "
                   //           << "v.size" << v.size() << std::endl;

                    for (int i = 0; i < v.size(); ++i)
                    {
                        //std::cout << "Activating... " << i << "index " << stoi(v[i]) << std::endl;
                        //based 1
                        row[stod(v[i]) - 1] = 1;
                        valuesCounter++;
                    }
                }
            }
            sparse.push_back(row);
            rowsCount++;
        }
    }

    outfile << std::endl << std::endl;

    // Close the file
    MyReadFile.close();
}

void MakeRandomSolution(std::vector<double> &solution)
{
    //random solution
    for (size_t i = 0; i < columns; i++)
    {
        solution[i] = rand() % 2;
    }

}

bool CheckRestrictions(std::vector<double> &solution)
{
    bool checkRestrictions = true;

    //Restrictions ChecK
    outfile << "Checking restrictions..." << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        double rowSum = 0.0;
        for (size_t j = 0; j < columns; j++)
        {
            rowSum = rowSum + sparse[i][j]*solution[j];
            
        }

        if(rowSum == 0)
        {
            checkRestrictions = false;
            outfile << "row " << i+1 << " not covered"<< std::endl;    
        }
    }

    return checkRestrictions;
}


int main()
{
    const int rows = 200;
    const int columns = 1000;

    std::vector<double> costs; //(columns);
    std::vector<double> solution{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
                                 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                                 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
                                 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
                                 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
                                 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
                                 0, 0};

    
    //double sparse[rows][columns] = {0};

    LoadData(costs, sparse);

    //objective function computation
    double objective = 0;


    //random solution
    // for (size_t i = 0; i < columns; i++)
    // {
    //     //solution[i] = rand() % 2;
    // }

    outfile << "COST" << std::endl;
    for (size_t i = 0; i < columns; i++)
    {
        outfile << costs[i] << " ";
    }
    outfile << std::endl << std::endl;

    outfile << "sparse matrix" << std::endl;
    for (size_t i = 0; i < sparse.size(); i++)
    {
        std::vector<double> row;
        row = sparse[i];
        //outfile << "ROW " << i << "size " << row.size() << std::endl;

        for (size_t j = 0; j < row.size(); j++)
        {
            outfile << sparse[i][j] << " ";
        }
        outfile << std::endl;
    }
    outfile << std::endl << std::endl;

    bool checkRestrictions = false;
    int attempts = 150;
    int solutionsCounter = 0;

    outfile << "Finding a good solution..." << std::endl << std::endl;

    double bestSolution = 999999999;

    while(solutionsCounter < attempts)
    {
        outfile << "attempt " << solutionsCounter << std::endl;
        MakeRandomSolution(solution);
        checkRestrictions = CheckRestrictions(solution);

        objective = 0;

        //Optimal calculation
        for (size_t columnIndex = 0; columnIndex < columns; columnIndex++)
        {
            objective = objective + costs[columnIndex] * solution[columnIndex];
        }

        outfile << "objective function value: " << objective << std::endl << std::endl;

        outfile << "SOLUTION" << std::endl;
        for (size_t i = 0; i < columns; i++)
        {
            outfile << solution[i] << " ";
        }
        outfile << std::endl << std::endl;

        if (bestSolution > objective)
        {
            bestSolution = objective;
        }

        solutionsCounter++;
    }

    outfile << "Best solution: " << bestSolution << std::endl << std::endl;

    if(checkRestrictions)
    {
        outfile << "solution OK" << std::endl;    
    }
    else 
    {
        checkRestrictions = false;
        outfile << "restrictions FAILED" << std::endl;    
    }

    outfile.close();

    return 0;
}