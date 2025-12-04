#include <fstream>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

struct Range {
	Range(std::string s) {
		std::stringstream ss(s);
		char delimiter = '-';
		std::string line;
		std::vector<std::string> range;

		while (std::getline(ss, line, delimiter)) {
			range.push_back(line);
			std::cout << line << std::endl;
		}

		this->min = std::stoll(range[0]);
		this->max = std::stoll(range[1]);
	};

	long long min;
	long long max;
};

void addInvalidIDs(std::string filename) {
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		throw std::runtime_error("Could not open file, aborting");
	}

	char delimiter = ',';
	std::string line;
	std::vector<Range> ranges;

	while (std::getline(inputFile, line, delimiter)) {
		ranges.push_back(Range(line));
	}
}

int main() {

	try {
		addInvalidIDs("input.txt");
	}
	catch (const std::runtime_error& e){
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}