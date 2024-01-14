#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readFileLines(const string& filename) {
    vector<string> lines;
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cerr << "Error opening the file." << endl;
        
        return lines; 
    }

    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();
    return lines;
}

vector<int> extractNumbers(const string& line) {
    vector<int> numbers;

    size_t pos = line.find_first_of("0123456789");
    while (pos != string::npos) {
        size_t endPos = line.find_first_not_of("0123456789", pos);

        string numberSubstring = line.substr(pos, endPos - pos);

        if (!numberSubstring.empty()) {
            
            for (char digit : numberSubstring) {
                int singleDigit = digit - '0';
                numbers.push_back(singleDigit);
            }

            if (numbers.size() >= 2) {
                int combinedNumber = numbers[0] * 10 + numbers[numbers.size() - 1];
                numbers.push_back(combinedNumber);
            }
            else if (numbers.size() == 1) {
                
                int combinedNumber = numbers[0] * 10 + numbers[0];
                numbers.push_back(combinedNumber);
            }
        }

        pos = line.find_first_of("0123456789", endPos);
    }

    return numbers;
}

int printRightmostNumberAndGetSum(const vector<string>& lines) {
    int sum = 0;

    for (const auto& line : lines) {
        
        vector<int> numbers = extractNumbers(line);

        
        if (numbers.size() > 1) {
            int rightmostNumber = numbers[numbers.size() - 1];
            cout << "Rightmost number: " << rightmostNumber << endl;

            sum += rightmostNumber;
        }
        else {
            cout << "Rightmost number not found" << endl;
        }
    }

    return sum;
}

int main() {
    string filename = "C:\\Users\\singh\\OneDrive\\Desktop\\input.txt"; 

    vector<string> lines = readFileLines(filename);

    int sum = printRightmostNumberAndGetSum(lines);

    cout << "Sum of rightmost numbers: " << sum << endl;

    return 0;
}

