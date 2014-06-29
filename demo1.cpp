
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "csv_lib.h"
using namespace std;


const string filename = "worksheetMarking.csv" ;

int main()
{
	vector< vector<string>> sheet ;
	sheet = read_CSV(filename) ;
	sheet = blank_to_zero(sheet , 1, 95, 1, 8) ;
	write_CSV(filename, sheet) ;
	return 0 ;
}

