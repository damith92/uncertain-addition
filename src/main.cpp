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
	iss.str(line) ;
	iss >> numSampA;

	std::cout << std::to_string(numSampA) << std::endl ;
	
	samplesA = (double *) calloc(numSampA, sizeof(double));
	
	for (int i = 0 ; i < numSampA; i++) {
		
		//std::getline(aFile, &samplesA[i]);
		std::getline(aFile, line);
		iss.clear();
		iss.str(line) ;
		iss >> samplesA[i];
		//&samplesA[i] = std::stod(std::to_string(line));
		
	}
	
	aFile.close();
	
	
	bFile.open("input-B.txt");
	
	//std::getline(bFile, numSampB);
	std::getline(bFile, line);
	iss.str(line) ;
	iss.clear();
	iss >> numSampB ;
	
	samplesB = (double *) calloc(numSampB, sizeof(double));
	
	for (int i = 0 ; i < numSampB; i++) {
		
		//std::getline(bFile, &samplesB[i]);
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

	
	
	
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}
