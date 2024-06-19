//Matthew Keaton 06-09-2024

#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main() {
    int fahrenheit;
    string city;

    //open input file
    ifstream inputFile("FahrenheitTemperature.txt");

    //condition to see if input file opened
    if (!inputFile.is_open()) {
        cout << "Input file not opened!" << endl;
        return 1;
    }

    //open output file
    ofstream outputFile("CelsiusTemperature.txt");

    //condition to see if the output file opened
    if (!outputFile.is_open()) {
        cout << "Output file not opened!" << endl;
        return 1;
    }


    //loop to read each city name and temp
    while (inputFile >> city >> fahrenheit) {
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;
        outputFile << city << " " << celsius << endl;
    }

    //close both files
    inputFile.close();
    outputFile.close();

    return 0;




}