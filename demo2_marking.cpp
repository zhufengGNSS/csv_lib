// Written by Amin Suzani.
// Searches students by part of Student number, first name, or last name. 
// Immediately updates their grade in comma separated file.

// Instructions:
// Save your excel sheet as a comma separated file (.csv).
// The changes are saved immediately to the .csv file while program runs.
// WARNING: Make sure the .csv file is not open in MS office. Changes won't be saved while the spreadsheet is open.


#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>
#include "csv_lib.h"
using namespace std;

#define START_ROW 1

const string filename = "worksheetMarking.csv" ;

int main()
{
	vector< vector<string>> sheet ;

	int col ;
	cout << "Which column you are marking (First column is 0)?" << endl ;
	cin >> col ;

	cout << "In order to exit, type finish instead of stdID. Don't leave the csv file open, otherwise changes won't be saved." << endl ;

	while(true)
	{
		sheet = read_CSV(filename) ;
		cout << endl << "Enter <beginning of the stdID or name> <grade>"<< endl; 
		string stdid, grade ;
		cin >> stdid ;
		if (stdid == "finish")
			break ;
		cin >> grade ;

		string expression = "(" + stdid + ")(.*)" ;
		regex e(expression) ;

		bool found = false ;
		for (int i=START_ROW ; i<sheet.size() ; i++)
		{
				if ( regex_match (sheet[i][3],e) || regex_match (sheet[i][0],e) || regex_match (sheet[i][1],e) )
				{
					cout << sheet[i][1] << " " << sheet[i][0] << " " << sheet[i][3]<< ", current mark:"<< sheet[i][col] << ", Right? (y/n)" << endl; 
					string response ;
					cin >> response ;
					if (response == "y")
					{
						found = true ;
						sheet[i][col] = grade ;
						write_CSV(filename, sheet) ;
						cout <<"Mark " << grade << " Saved." << endl ;	
						break ;
					}
				}
		}
		if (!found)
			cout << "Not found." << endl; 

	}
	return 0 ;

}
