#ifndef CSVREADER_HPP
#define CSVREADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class csvReader
{
    public:

    static void readFromCsv(const std::string& path, char delimiter, double** x, double** y, size_t& size)
    {
        std::cout << "Reading file: " << path << std::endl;

        std::ifstream file(path);

        if(!file)
        {
            std::cout << "[ERROR] : Couldn't open file at : " << path << std::endl;
            return;
        }
        std::string line;

        size = 0;

        while(getline(file, line))
            size++;

        double* firstColumn = new double[size];
        double* secondColumn = new double[size];

        std::cout << "Lines in file: " << size << std::endl;
        file.clear();
        file.seekg(0, std::ios::beg);

        int lineCount = 0;
        while(std::getline(file,line))
        {
            std::stringstream lineStream(line);
            std::string cell;
            std::getline(lineStream, cell, delimiter);
            firstColumn[lineCount] = std::stod(cell);
            std::getline(lineStream, cell, delimiter);
            secondColumn[lineCount] = std::stod(cell);

            lineCount++;
        }

        *x = firstColumn;
        *y = secondColumn;
    }
};



#endif // CSVREADER_HPP