//
//  main.cpp
//  pj
//
//  Created by Damian Lajara on 11/2/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Inflater.h"
#include "Validater.h"
using std::vector;
Inflater inflater;
/*If someone else is going to run this program, change this directory to wherever you downloaded all of these files*/
const string currentDirectory = "/Users/Damian/Xcode_C++/FILEIO/FILEIO/";

void readAndInflate(string type, ofstream& logFile, ofstream& outputFile) {
    logFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
    vector<string> v;
    ifstream file;
    if(type == "hotel") file.open("input.txt");
    else if(type == "concert") file.open("concertInput.txt");
    else if(type == "cruise") file.open("cruiseInput.txt");
    else if(type == "studentEnrollment") file.open("studentInput.txt");
    else {
        cout << "Error in argument for 'readAndInflate()'" << endl;
        exit(1);
    }
    string line;
    int counter = 0;
    int ticketCount = -1; // we set it to 0 when we first get a line from the file
    if(file.is_open()) {
        while(getline(file, line)) { //get whole line
            ticketCount++; //keep track of what line we are in (every line represents a new object)
            stringstream ss(line);
            while(getline(ss, line , '|')) { //idividual words in line
                //cout << "[DEBUG] got line from file: " << line << endl;
                line = Validater::trim(line); //trim is a static function from validater class
                v.push_back( line );
                //cout << "[DEBUG] Pushed line to vector: " << line << endl << endl;
                counter++;
            }
            //finished filling the vector. Now time to parse them
            if(type == "hotel") inflater.inflateHotelTicket(v, ticketCount, logFile, outputFile);
            else if(type == "concert") inflater.inflateConcertTicket(v, ticketCount, logFile, outputFile);
            else if(type == "cruise") inflater.inflateCruiseTicket(v, ticketCount, logFile, outputFile);
            else if(type == "studentEnrollment") inflater.inflateStudentTicket(v, ticketCount, logFile, outputFile);
            else {
                cout << "Error in method for inflater object" << endl;
                exit(1);
            }
            
            v.clear();
            counter = 0; //reset counter for next line
        }
    } else cout << "File is not opened!" << endl; //todo: output to log file
}

int main(int argc, char *argv[]) {
    //With this approach it only create the file ONCE
    //So i'm Passing files as parameters since validater and inflater use the same file, so creating two files of the same file is redundant
    //also this way, the file is always truncated at the beginning, and everything is appended since it never has to re-open the file
    ofstream logFile(currentDirectory + "logFile.txt");
    if(!logFile) cout << "Log File didnt work!\n";
    if(!logFile.is_open()) cout << "Log File didnt open!\n";
    ofstream outputFile(currentDirectory + "outputFile.txt", ios::trunc);
    if(!outputFile) cout << "File didnt work!\n";
    if(!outputFile.is_open()) cout << "File didnt open!\n";
    readAndInflate("hotel", logFile, outputFile);
    readAndInflate("concert", logFile, outputFile);
    readAndInflate("cruise", logFile, outputFile);
    readAndInflate("studentEnrollment", logFile, outputFile);
    return 0;
}