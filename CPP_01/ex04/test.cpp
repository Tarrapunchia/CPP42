#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string     inputs[3];
    std::ifstream   inputFile;
    std::ofstream   outputFile;
    std::string     outputFileName;
    std::string     buf;

    if (argc < 3)
        return 0;
    for (size_t i = 0; i < argc - 1; i++)
        inputs[i] = argv[i + 1];
    
    inputFile.open(inputs[0]);
    if (!inputFile)
    {
        std::cerr << "Failed to open file " << inputs[0] << "." << std::endl;
        return 0;
    }
    outputFileName = inputs[0] + ".replace";
    outputFile.open(outputFileName);
    if (!outputFile)
    {
        std::cerr << "Failed to open file " << outputFileName << "." << std::endl;
        return 0;
    }
    std::string::size_type pos = 0;
    while (std::getline(inputFile, buf))
    {
        while ((pos = buf.find(inputs[1])) != std::string::npos)
        {
            buf = buf.substr(0, pos) + inputs[2] + buf.substr(pos+ inputs[1].length());
            pos += inputs[2].length();
        }
        outputFile << buf << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
