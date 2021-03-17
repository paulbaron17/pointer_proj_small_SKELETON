#include <iostream>
#include <fstream>
#include <string>
#include "../includes/constants.h"
#include "../includes/fileio.h"

using namespace std;

int writeFile(std::string &filename, char *contents) {
	ofstream myOutputfile;
	if (contents == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}

	myOutputfile.open(filename.c_str());

	if (myOutputfile.is_open() == false) {
		return FAIL_CANNOT_OPEN_FILE;
	}

	myOutputfile << contents;
	myOutputfile.close();

	return SUCCESS;
}

int readFile(std::string &filename, std::string &contents) {

	ifstream myInputFile;
	myInputFile.open(filename.c_str(), ios::in);
	if (myInputFile.is_open()) {

		while (!myInputFile.eof()) {
			getline(myInputFile, contents);
			cout << contents;
		}
		myInputFile.close();
	}
	return SUCCESS;
}
