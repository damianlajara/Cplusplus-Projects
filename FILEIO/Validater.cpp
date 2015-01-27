//
//  Validater.cpp
//  pj
//
//  Created by Damian Lajara on 11/2/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include "Validater.h"
#include <fstream>

//Sample test cases
/* Room Number >= 1
 * Room Rate >= 1
 * Number of Days of Stay >=1
 * Extra Expenses >= 0
 * Taxes >= 0
 * Deposit >= 0
 */

//initializing static variables
const string validationError = "Error in validating ";
const string validationSuccess = "Validating ";
const string completed = "Done!";
//regex_error class for regular expression errors
//Usually the error is that the regex was timeout!

//const regex emailParser("[a-zA-z0-9._]*+[@]+[a-zA-Z]*+[.]+[a-zA-Z]*");
static const regex emailParser("^[\\w.]+\\@[a-zA-Z]+\\.[a-z]+$");//Upgraded email parser
static const regex floatParser("^[0-9]+\\.[0-9]{2}$");//two decimal precision
static const regex intParser("^[0-9]+$");
static const regex fullNameParser("^[a-zA-Z]+\\s+[a-zA-Z]\\.{1}\\s+[a-zA-Z]+$");
static const regex hotelNameParser("^[a-zA-Z]+\\s{0,1}[a-zA-Z]*$");
static const regex percentageParser("^([0-9]|[0-9]\\.[0-9]{2})\\%$");//TODO: added an extra '\' before the percent sign?...check if it works!
static const regex addressParser("^[0-9]{1,3}\\s?[a-zA-Z0-9]*\\s{1}[0-9a-zA-Z]+\\s*(St|Street|Ave|Avenue)\\,\\s{1}([a-zA-Z]+\\s{1}[a-zA-Z]+)$");
static const regex phoneNumberParser("^\\d{3}\\-\\d{3}\\-\\d{4}$"); //phone number
static const regex simpleNameParser("^(\\s?[a-zA-Z]+)+$");
static const regex stringParser("^(\\s?[a-zA-Z'-]+.?)+[\\;|\\.|\\!\\,]?$");
static const regex timeParser("^([1-9]|1[0-2]):([0-5][0-9])\\s?(am|AM|pm|PM)$");
static const regex dateParser("^(0?[1-9]|1[0-2])\\/(0?[1-9]|1[0-9]|2[0-9]|3[0-1])\\/((18|19\\d{2})|(20[0-9]|201[0-9]))$");//up to 2019
static const regex cabinNumber("^([A-Z][0-9]{1,3})$");
static const regex courseSchedule("^([A-Z]{2,}\\s?[0-9]{3}(\\,{1}\\s?|\\,{0}))*$");

/*As soon as the programs reads a line from the file, it will come here and trim it, then return it so it can be added to the vector!*/
string Validater::trim(string& str) {
    //cout << "[DEBUG] Original string: " << str << endl;
    // search from end of str until no char of 'whitespaces' is found
    string trim_chars = " \t";
    string::size_type pos = str.find_last_not_of(trim_chars);
    if(pos != string::npos) {
        //if there are trailing whitespaces erase them
        str.erase(pos + 1);
        pos = str.find_first_not_of(trim_chars);
        //if there are leading whitespaces erase them
        if(pos != string::npos) {
            str.erase(0, pos);
        }
    }
    else {
        //string is either all spaces or empty, so clear the whole string
        str.erase(str.begin(), str.end());
    }
    //cout << "[DEBUG] Trimmed string: " << str << endl;
    return str;
}

//USE THIS TO VALIDATE IF A NUMBER IS GREATER THAN OR EQUAL TO THE MIN AND LESS THAN OR EQUAL TO THE MAX!
//Ex: deposit >= 0, so validateNumber(deposit, 0);
//Ex: tax >= 0, and <= 10, so validateNumber(tax, 0, 10);
bool Validater::validNumber(int num, int min, int max = 1000) {//by default the max is 1000
    /*Tip: Only use this function if min is greater than 0, since the regex takes care of 0 and negative numbers!*/
    
    //bool result = num >= min && num <= max;//DEBUG
    //cout << "Is " << num << " >= " << min << " and <= " << max << "? " << result << endl << endl;
    return num >= min && num <= max;
}

bool Validater::validTax(float num) {
    /* min tax rate is 0, since it can be tax free and max tax rate is 10% */
    return num >= 0.0 && num <= 10.0;
}

bool Validater::validPrice(float num) {
    /*Price can be 0, since tickets can be free, and max is 1,000 because anything over 1,000 for a ticket is unheard of*/
    return num >= 0 && num <= 1000.0;
}

bool Validater::validHotelInput(vector<string>& v, string input, ofstream& logFile) {
    //TODO: Create the variables that I know are needed, and statically create them above, so save memory
    //Like taxes and ticket prices/rates, since we know all of them use those
    
    istringstream iss(input);//Create it once here, to save memory consumption as opposed to creating it everytime you need it
    
    if(input == v.at(0)) {
        //process hotel name
        logFile << validationSuccess + HotelReceipt::display_hotelName + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + HotelReceipt::display_hotelName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(1)) {
        //process hotel address
        logFile << validationSuccess + HotelReceipt::display_hotelAddress + ": " << input << "...";
        if(!regex_match(input, addressParser)) {
            logFile << validationError + HotelReceipt::display_hotelAddress << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(2)) {
        //process hotel contact info
        logFile << validationSuccess + HotelReceipt::display_hotelContactInfo + ": " << input << "...";
        if(!regex_match(input, phoneNumberParser)) {
            logFile << validationError + HotelReceipt::display_hotelContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(3)) {
        //process guest name
        logFile << validationSuccess + HotelReceipt::display_guestName + ": " << input << "...";
        if(!regex_match(input, fullNameParser)) {
            logFile << validationError + HotelReceipt::display_guestName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(4)) {
        //process guest contact information
        logFile << validationSuccess + HotelReceipt::display_guestContactInfo + ": " << input << "...";
        if(!regex_match(input, emailParser)) {
            logFile << validationError + HotelReceipt::display_guestContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(5)) {
        //process room number
        int roomNum;
        iss >> roomNum; //convert to num to validate
        logFile << validationSuccess + HotelReceipt::display_roomNumber + ": " << input << "...";
        if(!iss || !regex_match(input, intParser) || !validNumber(roomNum, 1)) {//if conversion doesn't work or number is NOT valid or if the regex DOESN'T match, then show error
            logFile << validationError + HotelReceipt::display_roomNumber << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(6)) {
        //process room rate
        float rate;
        iss >> rate;
        logFile << validationSuccess + HotelReceipt::display_roomRate + ": " << input << "...";
        if(!iss || ((!regex_match(input, floatParser)) || !validPrice(rate))) {// rate >= 1
            logFile << validationError + HotelReceipt::display_roomRate << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(7)) {
        //process length of stay
        float length;
        iss >> length;
        logFile << validationSuccess + HotelReceipt::display_lengthOfStay + ": " << input << "...";
        if(!iss || !regex_match(input, intParser) || !validNumber(length, 1, 31)) {//length >=1, <= 31 (only stay at hotel for 31 days max)
            logFile << validationError + HotelReceipt::display_lengthOfStay << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(8)) {
        //process extra expenses
        logFile << validationSuccess + HotelReceipt::display_extraExpenses + ": " << input << "...";
        if(!regex_match(input, floatParser)) {//expenses >= 0
            logFile << validationError + HotelReceipt::display_extraExpenses << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(9)) {//todo: make sure that when tax is 0, calculations still work! in the cpp files
        //process taxes
        float tax;
        iss >> tax;
        logFile << validationSuccess + HotelReceipt::display_tax + ": " << input << "...";
        if(!iss || !regex_match(input, percentageParser) || !validTax(tax)) {
            logFile << validationError + HotelReceipt::display_tax << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(10)) {
        //process deposit
        logFile << validationSuccess + HotelReceipt::display_deposit + ": " << input << "...";
        if(!regex_match(input, intParser)) {//TODO: deposit >= 0 && <= total price (Can't deposit more than is due)
            logFile << validationError + HotelReceipt::display_deposit << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else {
        logFile << "Error! invalid arguments for invalidHotelInput" << endl;
        return true;
    }
}

bool Validater::validConcertInput(vector<string>& v, string input, ofstream& logFile) {
    istringstream iss(input);
    if(input == v.at(0)) {
        //process service provider name
        logFile << validationSuccess + ConcertTicket::display_serviceProviderName + ": " << input << "...";
        if(!regex_match(input, stringParser)) {
            logFile << validationError + ConcertTicket::display_serviceProviderName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(1)) {
        //process service provider contact info
        logFile << validationSuccess + ConcertTicket::display_serviceProviderContactInfo + ": " << input << "...";
        if(!regex_match(input, phoneNumberParser)) {
            logFile << validationError + ConcertTicket::display_serviceProviderContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(2)) {
        //process show name
        logFile << validationSuccess + ConcertTicket::display_showName + ": " << input << "...";
        if(!regex_match(input, stringParser)) {
            logFile << validationError + ConcertTicket::display_showName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(3)) {
        //process show venue
        logFile << validationSuccess + ConcertTicket::display_showVenue + ": " << input << "...";
        if(!regex_match(input, stringParser)) {
            logFile << validationError + ConcertTicket::display_showVenue << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(4)) {
        //process show date
        logFile << validationSuccess + ConcertTicket::display_showDate + ": " << input << "...";
        if(!regex_match(input, dateParser)) {
            logFile << validationError + ConcertTicket::display_showDate << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(5)) {
        //process start time
        logFile << validationSuccess + ConcertTicket::display_startTime + ": " << input << "...";
        if(!regex_match(input, timeParser)) {
            logFile << validationError + ConcertTicket::display_startTime << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(6)) {
        //process ending time
        logFile << validationSuccess + ConcertTicket::display_endingTime + ": " << input << "...";
        if(!regex_match(input, timeParser)) {
            logFile << validationError + ConcertTicket::display_endingTime << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(7)) {
        //process guest name
        logFile << validationSuccess + ConcertTicket::display_guestName + ": " << input << "...";
        if(!regex_match(input, fullNameParser)) {
            logFile << validationError + ConcertTicket::display_guestName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(8)) {
        //process guest contact info
        logFile << validationSuccess + ConcertTicket::display_guestContactInfo + ": " << input << "...";
        if(!regex_match(input, emailParser)) {
            logFile << validationError + ConcertTicket::display_guestContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(9)) {
        //process seat number
        float seatNum;
        iss >> seatNum;
        logFile << validationSuccess + ConcertTicket::display_seatNumber + ": " << input << "...";
        if(!iss || !regex_match(input, intParser) || !validNumber(seatNum, 1)) { //> 0 < 1000
            logFile << validationError + ConcertTicket::display_seatNumber << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(10)) {
        //process ticket price
        float price;
        iss >> price;
        logFile << validationSuccess + ConcertTicket::display_ticketPrice + ": " << input << "...";
        if(!iss || !regex_match(input, floatParser) || !validPrice(price)) {
            logFile << validationError + ConcertTicket::display_ticketPrice << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(11)) {
        //process tax
        float tax;
        iss >> tax;
        logFile << validationSuccess + ConcertTicket::display_tax + ": " << input << "...";
        if(!iss || !regex_match(input, percentageParser) || !validTax(tax)) {//taxes >= 0, since it can be tax free like in oregon or montana
            logFile << validationError + ConcertTicket::display_tax << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    
    else if(input == v.at(12)) {
        //process extra info
        logFile << validationSuccess + ConcertTicket::display_extraInfo + ": " << input << "...";
        if(!regex_match(input, stringParser)) {
            logFile << validationError + ConcertTicket::display_extraInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    
    else {
        logFile << "Error! invalid arguments for invalidConcertInput" << endl;
        return true;
    }
}

bool Validater::validCruiseInput(vector<string>& v, string input, ofstream& logFile) {
    istringstream iss(input);
    if(input == v.at(0)) {
        //process cruise line name
        logFile << validationSuccess + CruiseTicket::display_cruiseLineName + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + CruiseTicket::display_cruiseLineName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(1)) {
        //process passenger name
        logFile << validationSuccess + CruiseTicket::display_passengerName + ": " << input << "...";
        if(!regex_match(input, fullNameParser)) {
            logFile << validationError + CruiseTicket::display_passengerName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(2)) {
        //process contact info
        logFile << validationSuccess + CruiseTicket::display_passengerContactInfo + ": " << input << "...";
        if(!regex_match(input, emailParser)) {
            logFile << validationError + CruiseTicket::display_passengerContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(3)) {
        //process departure date
        logFile << validationSuccess + CruiseTicket::display_departureDate + ": " << input << "...";
        if(!regex_match(input, dateParser)) {
            logFile << validationError + CruiseTicket::display_departureDate << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(4)) {
        //process departure time
        logFile << validationSuccess + CruiseTicket::display_departureTime + ": " << input << "...";
        if(!regex_match(input, timeParser)) {
            logFile << validationError + CruiseTicket::display_departureTime << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(5)) {
        //process cruise ship name
        logFile << validationSuccess + CruiseTicket::display_cruiseShipName + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + CruiseTicket::display_cruiseShipName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(6)) {
        //process Outbound Passenger Cabin Number
        logFile << validationSuccess + CruiseTicket::display_passengerOutboundCabinNum + ": " << input << "...";
        if(!regex_match(input, cabinNumber)) {
            logFile << validationError + CruiseTicket::display_passengerOutboundCabinNum << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(7)) {
        //process return date
        logFile << validationSuccess + CruiseTicket::display_returnDate + ": " << input << "...";
        if(!regex_match(input, dateParser)) {
            logFile << validationError + CruiseTicket::display_returnDate << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(8)) {
        //process retuern time
        logFile << validationSuccess + CruiseTicket::display_returnTime + ": " << input << "...";
        if(!regex_match(input, timeParser)) {
            logFile << validationError + CruiseTicket::display_returnTime << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(9)) {
        //process Return Passenger Cabin Number
        logFile << validationSuccess + CruiseTicket::display_passengerReturnCabinNum + ": " << input << "...";
        if(!regex_match(input, cabinNumber)) {
            logFile << validationError + CruiseTicket::display_passengerReturnCabinNum << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(10)) {
        //process ticket cost
        float price;
        iss >> price;
        logFile << validationSuccess + CruiseTicket::display_ticketCost + ": " << input << "...";
        if(!iss || !regex_match(input, floatParser) || !validPrice(price)) {
            logFile << validationError + CruiseTicket::display_ticketCost << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(11)) {
        //process extra charges
        logFile << validationSuccess + CruiseTicket::display_extraCharges + ": " << input << "...";
        if(!regex_match(input, floatParser)) {// >= 0 and < infinite(as much as the user wants to spend, so no limit)
            logFile << validationError + CruiseTicket::display_extraCharges << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(12)) {
        //process tax
        float tax;
        iss >> tax;
        logFile << validationSuccess + CruiseTicket::display_tax + ": " << input << "...";
        if(!iss || !regex_match(input, percentageParser) || !validTax(tax)) {
            logFile << validationError + CruiseTicket::display_tax << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    
    else if(input == v.at(13)) {
        //process extra info
        logFile << validationSuccess + CruiseTicket::display_extraInfo + ": " << input << "...";
        if(!regex_match(input, stringParser)) {
            logFile << validationError + CruiseTicket::display_extraInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    
    else {
        logFile << "Error! invalid arguments for invalidCruiseInput" << endl;
        return true;
    }
}

bool Validater::validStudentInput(vector<string>& v, string input, ofstream& logFile) {
    if(input == v.at(0)) {
        //process school name
        logFile << validationSuccess + StudentEnrollment::display_schoolName + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + StudentEnrollment::display_schoolName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(1)) {
        //process school contact info
        logFile << validationSuccess + StudentEnrollment::display_schoolContactInfo + ": " << input << "...";
        if(!regex_match(input, phoneNumberParser)) {
            logFile << validationError + StudentEnrollment::display_schoolContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(2)) {
        //process student name
        logFile << validationSuccess + StudentEnrollment::display_studentName + ": " << input << "...";
        if(!regex_match(input, fullNameParser)) {
            logFile << validationError + StudentEnrollment::display_studentName << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(3)) {
        //process contact info
        logFile << validationSuccess + StudentEnrollment::display_studentContactInfo + ": " << input << "...";
        if(!regex_match(input, emailParser)) {
            logFile << validationError + StudentEnrollment::display_studentContactInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(4)) {
        //process student status info
        logFile << validationSuccess + StudentEnrollment::display_studentStatusInfo + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + StudentEnrollment::display_studentStatusInfo << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(5)) {
        //process student department
        logFile << validationSuccess + StudentEnrollment::display_studentDepartment + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + StudentEnrollment::display_studentDepartment << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(6)) {
        //process student major
        logFile << validationSuccess + StudentEnrollment::display_studentMajor + ": " << input << "...";
        if(!regex_match(input, simpleNameParser)) {
            logFile << validationError + StudentEnrollment::display_studentMajor << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(7)) {
        //process years left to graduate
        /*Since the need to convert isnt heavily relied upon in this student ticket, no need to create one main, can simply create it everytime as the need arises*/
        istringstream iss(input);
        float years;
        iss >> years;
        logFile << validationSuccess + StudentEnrollment::display_studentYearsLeftToGraduate + ": " << input << "...";
        if(!iss || !regex_match(input, intParser) || !validNumber(years, 0, 4)) {//>= 0, if 0, then it means senior level, and <=4, since u cant go passed 4 years
            logFile << validationError + StudentEnrollment::display_studentYearsLeftToGraduate << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(8)) {
        //process student course schedule
        logFile << validationSuccess + StudentEnrollment::display_studentCourseSchedule + ": " << input << "...";
        if(!regex_match(input, courseSchedule)) {
            logFile << validationError + StudentEnrollment::display_studentCourseSchedule << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else if(input == v.at(9)) {
        //process student course fees
        logFile << validationSuccess + StudentEnrollment::display_studentCourseFees + ": " << input << "...";
        if(!regex_match(input, floatParser)) {//>=0 can be free tuition, and < infinite (no limit since depends on amount of classes and degrees taken)
            logFile << validationError + StudentEnrollment::display_studentCourseFees << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
        
    }
    else if(input == v.at(10)) {
        //process student financial aid
        /*Since the need to convert isnt heavily relied upon in this student ticket, no need to create one main, can simply create it everytime as the need arises*/
        istringstream iss(input);
        float finaid;
        iss >> finaid;
        logFile << validationSuccess + StudentEnrollment::display_studentFinancialAid + ": " << input << "...";
        if(!regex_match(input, floatParser) || !validNumber(finaid, 0, 6000)) {// >=0 since u don't always recieve financial aid, and < 6K per semester
            logFile << validationError + StudentEnrollment::display_studentFinancialAid << endl;
            return false;
        } else {
            logFile << completed << endl;
            return true;
        }
    }
    else {
        logFile << "Error! invalid arguments for invalidStudentInput" << endl;
        return true;
    }
}

