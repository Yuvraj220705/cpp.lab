#include <iostream>
using namespace std;

class FileManager {
private:
    char* filename;

public:
    FileManager(const char* name) {
        filename = new char[strlen(name) + 1];
        strcpy(filename, name);
    }

    FileManager(const FileManager& other) {
        filename = new char[strlen(other.filename) + 1];
        strcpy(filename, other.filename);
    }

    ~FileManager() {
        delete[] filename;
        cout << "File Manager cleaned up" << endl;
    }

    void display() const {
        cout << "File: " << filename << endl;
    }

    void setFilename(const char* newName) {
        delete[] filename;
        filename = new char[strlen(newName) + 1];
        strcpy(filename, newName);
    }
};

int main() {
    FileManager file1("document.txt");
    FileManager file2 = file1;

    file2.setFilename("new_document.txt");
    file1.display();
    file2.display();

    return 0;
}

