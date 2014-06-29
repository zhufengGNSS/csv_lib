
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "csv_lib.h"

using namespace std ;

void write_CSV(string file_name, vector<vector<string>> sheet)
 {
	 ofstream fout( file_name );
	 
	 for (int i=0 ; i<sheet.size() ; i++) 
	 {
		 for (int j=0 ; j<sheet[i].size() ; j++) 
		 {
			 fout << sheet[i][j] << "," ;
		 }
		 fout << endl;  
	 }
	 fout.close() ;
 }


vector<vector<string>> read_CSV(string file_name)
{
	vector <vector <string>> sheet;
	ifstream fin( file_name );
	while (fin)
	{
		string str;
		if (!getline( fin, str )) break;
		istringstream ss( str );
		vector <string> row;

		while (ss)
		{
			string str;
			if (!getline( ss, str, ',' )) break;
			row.push_back( str );
		}

		sheet.push_back( row );
	}

	if (!fin.eof())
	{
		cerr << "Something is wrong." << endl  ;
	}

	fin.close() ;
	return sheet ;
}

void print_data(vector<vector<string>> sheet)
{
	for (int i=0 ; i<sheet.size() ; i++)
	{
		//cout << sheet[i].size() << endl ;
		for (int j=0 ; j< sheet[i].size() ; j++)
		{
			cout << sheet[i][j] <<" " ;
		}
		cout << endl ;
	}
}



vector<vector<string>> blank_to_zero(vector<vector<string>> sheet, int row_begin, int row_end, int col_begin, int col_end)
{
	for (int i=row_begin ; i<row_end ; i++)
	{
		for (int j=col_begin ; j< col_end ; j++)
		{
			if (sheet[i][j].length() == 0)
			{
				sheet[i][j] = "0" ; 
			}
		}
	}
	return sheet ;
	

}
