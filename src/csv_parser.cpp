#include "csv_parser.h"

#include <format>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace backtester 
{

    std::vector<Bar> load_csv(const std::string& filename) 
    {
        std::ifstream inputFile(filename);
        std::vector<Bar> output{};

        if (!inputFile.is_open()) 
        {
            throw std::runtime_error(std::format("Could not open file: {}", filename));
        }

        std::string line;

        // skip the first 2 rows
        std::getline(inputFile, line);
        std::getline(inputFile, line);

        // process entries
        while (std::getline(inputFile, line)) 
        {
            std::istringstream ss(line);
            std::string date, close, high, low, open, volume;

            std::getline(ss, date, ',');
            std::getline(ss, close, ',');
            std::getline(ss, high, ',');
            std::getline(ss, low, ',');
            std::getline(ss, open, ',');
            std::getline(ss, volume);

            output.emplace_back(Bar{
                date, std::stod(close), std::stod(high),
                std::stod(low), std::stod(open), std::stol(volume)
            });
        }

        return output;
    }
} // namespace backtester
