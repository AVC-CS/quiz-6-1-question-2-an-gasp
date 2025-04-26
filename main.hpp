#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int writeFile(const string &filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Could not open file for writing.\n";
        return 0;
    }

    int numEmployees;
    cout << "Enter the number of Employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        cout << "Enter Employee " << i + 1 << " information: ";
        cin >> id >> name >> department >> salary;

        outFile << id << " " << name << " " << department << " " << salary << "\n";
    }

    outFile.close();
    return numEmployees;
}

int readFile(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Could not open file for reading.\n";
        return 0;
    }

    int numEmployees = 0;
    string line;

    cout << "Employee information from '" << filename << "':\n";
    while (getline(inFile, line)) {
        cout << line << "\n";
        ++numEmployees;
    }

    inFile.close();
    return numEmployees;
}