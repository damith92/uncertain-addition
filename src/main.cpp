#include <iostream>
#include <fstream>
#include <uncertain.h>
#include <string>
#include <sstream>

int main(int argc, char *  argv[]) {
	
	std::ifstream aFile, bFile;
	
	double * samplesA;
	double * samplesB;
	
	int            numSampA, numSampB;
	double         A, B, C;

	std::istringstream iss;

	std::string line ;
	
	aFile.open("input-A.txt");

	if (aFile == NULL)
			{
				std::cout << "No file read" <<std::endl;
				exit(EXIT_FAILURE);
			}
	
	std::getline(aFile, line);
	

	iss.str(line) ;
	iss >> numSampA;

	std::cout << std::to_string(numSampA) << std::endl ;
	
	
	
	
	
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}
