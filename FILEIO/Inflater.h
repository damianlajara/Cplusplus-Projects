//
//  Inflater.h
//  pj
//
//  Created by Damian Lajara on 11/2/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __pj__Inflater__
#define __pj__Inflater__
#include <iostream>
#include <vector>
#include "Validater.h"
using namespace std;

class Inflater {
public:
    void inflateHotelTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile);
    void inflateConcertTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile);
    void inflateCruiseTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile);
    void inflateStudentTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile);
};

#endif /* defined(__pj__Inflater__) */
