#include <fstream>
#include <deque>

using namespace std;

class Filer {
public:
    int deque_to_file(deque<string> deq, string filename) {
        try {
            ofstream file(filename.c_str(), ios::trunc);
            for (string i : deq) {
                file << i << '\n';
            }
            file.close();
            return 0;
        }
        catch (const std::exception e) {
            return 1;
        }
    }
    deque<string> deque_from_file(string filename) {
        deque<string> result;
        try {
            ifstream file(filename.c_str());
            string line;
            if(!file) {
                throw runtime_error("file can't be opened");
            }
            while (getline(file, line)) {
                result.push_back(line);
            }
        }
        catch (const std::exception e) {
            throw runtime_error("Error while reading deque from file");
        }
        return result;
    }
};
