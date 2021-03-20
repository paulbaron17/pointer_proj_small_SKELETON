//============================================================================
// Name        : pointer_proj_small.cpp
// Author      : pbaron
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
#include "../includes/constants.h"
#include "../includes/stringmanip.h"
#include "../includes/fileio.h"

using namespace KP;

int main(int argc, char *argv[]) {


	if (*argv[0] == HELP_CHAR) {
		cout << HELP_STRING1 << endl;
		cout << HELP_STRING2 << endl;
		return SUCCESS;
	} else if (argc != EXPECTED_NUMBER_ARGUMENTS) {
		cout << HELP_STRING2 << endl;
		return FAIL_WRONG_NUMBER_ARGS;
	} else {

		string inpu = argv[1];

		string outp = argv[2];
		string tag = argv[3];
		string tag_replacement = argv[4];
		string string1 = "";

		readFile(inpu, string1);

		const char *src = string1.c_str();
		const char *tmp_tag = tag.c_str();
		int numOfTags = findNumbOccurrences(src,tmp_tag);

		int len_str = strlen(src);
		int len_tag = strlen(tmp_tag);
		const char *tmp_tr = tag_replacement.c_str();
		int len_tr = strlen(tmp_tr);
		int memory = amountOfMemoryToAllocateForNewString(len_str, numOfTags, len_tag, len_tr);

		char *string2 = new char[memory];
		memset(string2, 0, memory * sizeof(char));


		replace(src, string2, tmp_tag,tmp_tr);

		string filename;
		writeFile(outp, string2);

		if(string2){
			delete [] string2;
			string2 = 0;
		}

	}
	return SUCCESS;
}
