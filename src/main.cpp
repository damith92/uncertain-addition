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
	std::getline(aFile, line);
	iss.str(line) ;
	iss >> numSampA;

	std::cout << "No of \"A\" samples = " << std::to_string(numSampA) << std::endl ;
	
	samplesA = (double *) calloc(numSampA, sizeof(double));
	
	for (int i = 0 ; i < numSampA; i++) {
		
		std::getline(aFile, line);
		iss.clear();
		iss.str(line) ;
		iss >> samplesA[i];
		
	}
	
	aFile.close();
	
	bFile.open("input-B.txt");
	
	std::getline(bFile, line);
	iss.clear();
	iss.str(line) ;
	iss >> numSampB ;

	std::cout << "No of \"B\" samples = " << std::to_string(numSampB) << std::endl ;
	
	samplesB = (double *) calloc(numSampB, sizeof(double));
	
	for (int i = 0 ; i < numSampB; i++) {
		
		std::getline(bFile, line);
		iss.str(line) ;
		iss.clear();
		iss >> samplesB[i];
		
	}
	
	bFile.close();
	
	A = libUncertainDoubleDistFromSamples(samplesA, numSampA);
	
	B = libUncertainDoubleDistFromSamples(samplesB, numSampB);
	
	C = A + B ;
	
	std::cout << "Implicit calculation :" << std::endl ;
	
	std::cout << "A = " << A << std::endl ;
	std::cout << "B = " << B << std::endl ;
	
	std::cout << "C = A + B = " << C << std::endl ;
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}

