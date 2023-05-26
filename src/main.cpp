#include <iostream>
#include <fstream>
#include <uncertain.h>
#include <string.h>

int main(int argc, char *  argv[]) {
	
	ifstream aFile, bFile;
	
	double * samplesA;
	double * samplesB;
	
	int            numSampA, numSampB;
	double         A, B, C;

	
	aFile.open ("file.txt");
	
	getline(aFile, numSampA);
	
	samplesA = calloc(numSampA, sizeof(double));
	
	for (int i = 0 ; i < numSampA; i++) {
		
		getline(aFile, &samplesA[i]);
		
	}
	
	aFile.close();
	
	
	bFile.open ("file.txt");
	
	getline(aFile, numSampB);
	
	samplesB = calloc(numSampB, sizeof(double));
	
	for (int i = 0 ; i < numSampB; i++) {
		
		getline(aFile, &samplesB[i]);
		
	}
	
	bFile.close();
	
	A = libUncertainDoubleDistFromSamples(samplesA, numSampA);
	
	B = libUncertainDoubleDistFromSamples(samplesB, numSampB);
	
	C = A + B ;
	
	cout << "Implicit calculation :" << endl ;
	
	cout << "A = " << A << endl ;
	cout << "B = " << B << endl ;
	
	cout << "C = A + B = " << C < endl ;
	
	
	free(samplesA);
	
	free(samplesB);

	return 0;
}
