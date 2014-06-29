
// Load the .csv file into vectors of vectors of string.
std::vector<std::vector<std::string>> read_CSV(std::string file_name) ;

// Write the edited sheet back into a .csv file.
void write_CSV(std::string file_name, std::vector<std::vector<std::string>> sheet) ;

// Print the loaded sheet on console.
void print_data(std::vector<std::vector<std::string>> sheet) ;

// initiate the loaded sheet with zeros.
std::vector<std::vector<std::string>> blank_to_zero(std::vector<std::vector<std::string>> sheet,
	int row_begin, int row_end, int col_begin, int col_end) ;
	
	
