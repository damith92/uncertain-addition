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

	//std::istringstream iss;

	std::string line ;
	
	aFile.open("input-A.txt");
	
	std::getline(aFile, line);
	std::cout << line << std::endl ;
	
	
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}
