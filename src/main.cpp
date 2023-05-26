#include <iostream>
#include <fstream>
#include <uncertain.h>
#include <string.h>

int main(int argc, char *  argv[]) {
	
	std::ifstream aFile, bFile;
	
	double * samplesA;
	double * samplesB;
	
	int            numSampA, numSampB;
	double         A, B, C;

	std::string line;
	std::istringstream iss;

	
	aFile.open ("file.txt");
	
	std::getline(aFile, line);
	iss(line) ;
	iss >> numSampA ;
	
	samplesA = calloc(numSampA, sizeof(double));
	
	for (int i = 0 ; i < numSampA; i++) {
		
		//std::getline(aFile, &samplesA[i]);
		std::getline(aFile, line);
		iss(line) ;
		iss >> &samplesA[i];
		
	}
	
	aFile.close();
	
	
	bFile.open ("file.txt");
	
	//std::getline(bFile, numSampB);
	std::getline(bFile, line);
	iss(line) ;
	iss >> numSampB ;
	
	samplesB = calloc(numSampB, sizeof(double));
	
	for (int i = 0 ; i < numSampB; i++) {
		
		//std::getline(bFile, &samplesB[i]);
		std::getline(bFile, line);
		iss(line) ;
		iss >> &samplesB[i];
		
	}
	
	bFile.close();
	
	A = libUncertainDoubleDistFromSamples(samplesA, numSampA);
	
	B = libUncertainDoubleDistFromSamples(samplesB, numSampB);
	
	C = A + B ;
	
	std::cout << "Implicit calculation :" << std::endl ;
	
	std::cout << "A = " << A << std::endl ;
	std::cout << "B = " << B << std::endl ;
	
	std::cout << "C = A + B = " << C < std::endl ;
	
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}
