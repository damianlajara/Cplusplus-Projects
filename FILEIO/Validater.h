//
//  Validater.h
//  pj
//
//  Created by Damian Lajara on 11/2/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __pj__Validater__
#define __pj__Validater__

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "HotelReceipt.h"
#include "CruiseTicket.h"
#include "ConcertTicket.h"
#include "StudentEnrollment.h"

using namespace std;

class Validater {
public:
    //bool alphabetic(string input);
    static string trim(string& str);
    bool validHotelInput(vector<string>& v, string input, ofstream& logFile);
    bool validConcertInput(vector<string>& v, string input, ofstream& logFile);
    bool validCruiseInput(vector<string>& v, string input, ofstream& logFile);
    bool validStudentInput(vector<string>& v, string input, ofstream& logFile);
    bool validNumber(int num, int min, int max);
    bool validTax(float num);
    bool validPrice(float num);
    
};
#endif /* defined(__pj__Validater__) */
