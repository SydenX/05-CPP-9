#include <iostream>

bool isFileReadable (const std::string& name) {
	if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    }
	std::cerr << "File \"" << name << "\" do not exist." << std::endl;
	return false;
}


int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Use: ./btc <CSV file>" << std::endl;
		return 1;
	}
	if (!isFileReadable(argv[1]))
		return 1;
	return 0;
}