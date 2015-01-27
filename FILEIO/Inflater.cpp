//
//  Inflater.cpp
//  pj
//
//  Created by Damian Lajara on 11/2/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include "Inflater.h"
#include <fstream>
const string inflationError = "[ERROR] did not set ";
const string inflationSuccess = "[SUCCESS] set ";
const string inflationTransition = " to: ";

//For use with processing functions
const string hotel_ticket = "Hotel Ticket";
const string concert_ticket = "Concert Ticket";
const string cruise_ticket = "Cruise Ticket";
const string student_ticket = "Enrollment";

string beginProcessing(string name, string ticket) {
    return ") Processing " + name + "'s " + ticket + "...";
}
string doneProcessing(string name, string ticket) {
    return "...Done Processing " + name + "'s " + ticket;
}
 
const int MAX_DOCUMENT_TYPE = 20;
Validater validater;
HotelReceipt hotelReceipt[ MAX_DOCUMENT_TYPE];
CruiseTicket cruiseTicket[MAX_DOCUMENT_TYPE];
ConcertTicket concertTicket[MAX_DOCUMENT_TYPE];
StudentEnrollment studentEnrollment[MAX_DOCUMENT_TYPE];

void Inflater::inflateHotelTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile) {
    const string name = v.at(3);
    outputFile << "\n~~~~~~~~ " << name << "'s Invoice (Hotel Receipt #" << ticketCount+1 << ")" << " ~~~~~~~~" << endl;
    logFile << ticketCount+1 << beginProcessing(name, hotel_ticket) << endl;
    logFile << "[debug] Vector size is: " << v.size() << endl;
    
    if (validater.validHotelInput(v, v.at(0), logFile)) {
        hotelReceipt[ticketCount].setHotelName(v.at(0)); //line 0
        logFile << inflationSuccess + HotelReceipt::display_hotelName + inflationTransition << v.at(0) << endl;
        outputFile << HotelReceipt::display_hotelName << ": " << v.at(0) << endl;
    } else logFile << inflationError + HotelReceipt::display_hotelName << endl;
    
    if(validater.validHotelInput(v, v.at(1), logFile)) {
        hotelReceipt[ticketCount].setHotelAddress(v.at(1)); //line 1
        logFile << inflationSuccess + HotelReceipt::display_hotelAddress + inflationTransition << v.at(1) << endl;
        outputFile << HotelReceipt::display_hotelAddress << ": " << v.at(1) << endl;
    } else {
        logFile << inflationError + HotelReceipt::display_hotelAddress << endl;
        outputFile << "******[Error in displaying " + HotelReceipt::display_hotelAddress  + "]******" << endl; 
    }
    
    if(validater.validHotelInput(v, v.at(2), logFile)) {
        hotelReceipt[ticketCount].setHotelContactInfo(v.at(2)); //line 2
        logFile << inflationSuccess + HotelReceipt::display_hotelContactInfo + inflationTransition << v.at(2) << endl;
        outputFile << HotelReceipt::display_hotelContactInfo << ": " << v.at(2) << endl;
    } else logFile << inflationError + HotelReceipt::display_hotelContactInfo << endl;
    
    if(validater.validHotelInput(v, v.at(3), logFile)) {
        hotelReceipt[ticketCount].setGuestName(v.at(3)); //line 3
        logFile << inflationSuccess + HotelReceipt::display_guestName + inflationTransition << v.at(3) << endl;
        outputFile << HotelReceipt::display_guestName << ": " << v.at(3) << endl;
    } else logFile << inflationError + HotelReceipt::display_guestName << endl;
    
    if(validater.validHotelInput(v, v.at(4), logFile)) {
        hotelReceipt[ticketCount].setGuestContactInfo(v.at(4)); //line 4
        logFile << inflationSuccess + HotelReceipt::display_guestContactInfo + inflationTransition << v.at(4) << endl;
        outputFile << HotelReceipt::display_guestContactInfo << ": " << v.at(4) << endl;
    } else logFile << inflationError + HotelReceipt::display_guestContactInfo << endl;
    
    if(validater.validHotelInput(v, v.at(5), logFile)) {
        hotelReceipt[ticketCount].setRoomNumber(v.at(5)); //line 5
        logFile << inflationSuccess + HotelReceipt::display_roomNumber + inflationTransition << v.at(5) << endl;
        outputFile << HotelReceipt::display_roomNumber << ": " << v.at(5) << endl;
    } else logFile << inflationError + HotelReceipt::display_roomNumber << endl;
    
    if(validater.validHotelInput(v, v.at(6), logFile)) {
        hotelReceipt[ticketCount].setRoomRate(v.at(6)); //line 6
        logFile << inflationSuccess + HotelReceipt::display_roomRate + inflationTransition << v.at(6) << endl;
        outputFile << HotelReceipt::display_roomRate << ": " << v.at(6) << endl;
    } else logFile << inflationError + HotelReceipt::display_roomRate << endl;
    
    if(validater.validHotelInput(v, v.at(7), logFile)) {
        hotelReceipt[ticketCount].setLengthOfStay(v.at(7)); //line 7
        logFile << inflationSuccess + HotelReceipt::display_lengthOfStay + inflationTransition << v.at(7) << endl;
        outputFile << HotelReceipt::display_lengthOfStay << ": " << v.at(7) << endl;
    } else logFile << inflationError + HotelReceipt::display_lengthOfStay << endl;
    
    if(validater.validHotelInput(v, v.at(8), logFile)) {
        hotelReceipt[ticketCount].setExtraExpenses(v.at(8)); //line 8
        logFile << inflationSuccess + HotelReceipt::display_extraExpenses + inflationTransition << v.at(8) << endl;
        outputFile << HotelReceipt::display_extraExpenses << ": " << v.at(8) << endl;
    } else logFile << inflationError + HotelReceipt::display_extraExpenses << endl;
    
    if(validater.validHotelInput(v, v.at(9), logFile)) {
        hotelReceipt[ticketCount].setTax(v.at(9)); //line 9
        logFile << inflationSuccess + HotelReceipt::display_tax + inflationTransition << v.at(9) << endl;
        outputFile << HotelReceipt::display_tax << ": " << v.at(9) << endl;
    } else logFile << inflationError + HotelReceipt::display_tax << endl;
    
    if(validater.validHotelInput(v, v.at(10), logFile)) {
        hotelReceipt[ticketCount].setDeposit(v.at(10)); //line 10 == 11 lines
        logFile << inflationSuccess + HotelReceipt::display_deposit + inflationTransition << v.at(10) << endl;
        outputFile << HotelReceipt::display_deposit << ": " << v.at(10) << endl;
    } else logFile << inflationError + HotelReceipt::display_deposit << endl;
    
    if(hotelReceipt[ticketCount].getBalanceDue() >= 0 && hotelReceipt[ticketCount].getTotalAmount() >=0) {
        hotelReceipt[ticketCount].calculateTotalAmounts();
        logFile << inflationSuccess + HotelReceipt::display_balance + inflationTransition << hotelReceipt[ticketCount].getBalanceDue() << endl;
        logFile << inflationSuccess + HotelReceipt::display_total + inflationTransition << hotelReceipt[ticketCount].getTotalAmount() << endl;
        outputFile << HotelReceipt::display_balance + ": " << hotelReceipt[ticketCount].getBalanceDue() << endl;
        outputFile << HotelReceipt::display_total + ": " << hotelReceipt[ticketCount].getTotalAmount() << endl;
    } else logFile << "[DEBUG] Error in calculating total amounts!" << endl;
    logFile << doneProcessing(name, hotel_ticket) << endl << endl;
}

void Inflater::inflateConcertTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile) {
    const string name = v.at(7);
    outputFile << "\n~~~~~~~~ " << name << "'s Invoice (Concert Ticket #" << ticketCount+1 << ")" << " ~~~~~~~~" << endl;
    logFile << ticketCount+1 << beginProcessing(name, concert_ticket) << endl;
    //logFile << "[debug] Vector size is: " << v.size() << endl;
    
    if (validater.validConcertInput(v, v.at(0), logFile)) {
        concertTicket[ticketCount].setServiceProviderName(v.at(0)); //line 0
        logFile << inflationSuccess + ConcertTicket::display_serviceProviderName + inflationTransition << v.at(0) << endl;
        outputFile << ConcertTicket::display_serviceProviderName << ": " << v.at(0) << endl;
    } else logFile << inflationError + ConcertTicket::display_serviceProviderName << endl;
    
    if(validater.validConcertInput(v, v.at(1), logFile)) {
        concertTicket[ticketCount].setServiceProviderContactInfo(v.at(1)); //line 1
        logFile << inflationSuccess + ConcertTicket::display_serviceProviderContactInfo + inflationTransition << v.at(1) << endl;
        outputFile << ConcertTicket::display_serviceProviderContactInfo << ": " << v.at(1) << endl;
    } else logFile << inflationError + ConcertTicket::display_serviceProviderContactInfo << endl;
    
    if(validater.validConcertInput(v, v.at(2), logFile)) {
        concertTicket[ticketCount].setShowName(v.at(2)); //line 2
        logFile << inflationSuccess + ConcertTicket::display_showName + inflationTransition << v.at(2) << endl;
        outputFile << ConcertTicket::display_showName << ": " << v.at(2) << endl;
    } else logFile << inflationError + ConcertTicket::display_showName << endl;
    
    if(validater.validConcertInput(v, v.at(3), logFile)) {
        concertTicket[ticketCount].setShowVenue(v.at(3)); //line 3
        logFile << inflationSuccess + ConcertTicket::display_showVenue + inflationTransition << v.at(3) << endl;
        outputFile << ConcertTicket::display_showVenue << ": " << v.at(3) << endl;
    } else logFile << inflationError + ConcertTicket::display_showVenue << endl;
    
    if(validater.validConcertInput(v, v.at(4), logFile)) {
        concertTicket[ticketCount].setShowDate(v.at(4)); //line 4
        logFile << inflationSuccess + ConcertTicket::display_showDate + inflationTransition << v.at(4) << endl;
        outputFile << ConcertTicket::display_showDate << ": " << v.at(4) << endl;
    } else logFile << inflationError + ConcertTicket::display_showDate << endl;
    
    if(validater.validConcertInput(v, v.at(5), logFile)) {
        concertTicket[ticketCount].setStartTime(v.at(5)); //line 5
        logFile << inflationSuccess + ConcertTicket::display_startTime + inflationTransition << v.at(5) << endl;
        outputFile << ConcertTicket::display_startTime << ": " << v.at(5) << endl;
    } else logFile << inflationError + ConcertTicket::display_startTime << endl;
    
    if(validater.validConcertInput(v, v.at(6), logFile)) {
        concertTicket[ticketCount].setEndingTime(v.at(6)); //line 6
        logFile << inflationSuccess + ConcertTicket::display_endingTime + inflationTransition << v.at(6) << endl;
        outputFile << ConcertTicket::display_endingTime << ": " << v.at(6) << endl;
    } else logFile << inflationError + ConcertTicket::display_endingTime << endl;
    
    if(validater.validConcertInput(v, v.at(7), logFile)) {
        concertTicket[ticketCount].setGuestName(v.at(7)); //line 7
        logFile << inflationSuccess + ConcertTicket::display_guestName + inflationTransition << v.at(7) << endl;
        outputFile << ConcertTicket::display_guestName << ": " << v.at(7) << endl;
    } else logFile << inflationError + ConcertTicket::display_guestName << endl;
    
    if(validater.validConcertInput(v, v.at(8), logFile)) {
        concertTicket[ticketCount].setGuestContactInfo(v.at(8)); //line 8
        logFile << inflationSuccess + ConcertTicket::display_guestContactInfo + inflationTransition << v.at(8) << endl;
        outputFile << ConcertTicket::display_guestContactInfo << ": " << v.at(8) << endl;
    } else logFile << inflationError + ConcertTicket::display_guestContactInfo << endl;
    
    if(validater.validConcertInput(v, v.at(9), logFile)) {
        concertTicket[ticketCount].setSeatNumber(v.at(9)); //line 9
        logFile << inflationSuccess + ConcertTicket::display_seatNumber + inflationTransition << v.at(9) << endl;
        outputFile << ConcertTicket::display_seatNumber << ": " << v.at(9) << endl;
    } else logFile << inflationError + ConcertTicket::display_seatNumber << endl;
    
    if(validater.validConcertInput(v, v.at(10), logFile)) {
        concertTicket[ticketCount].setTicketPrice(v.at(10)); //line 10 == 11 lines
        logFile << inflationSuccess + ConcertTicket::display_ticketPrice + inflationTransition << v.at(10) << endl;
        outputFile << ConcertTicket::display_ticketPrice << ": " << v.at(10) << endl;
    } else logFile << inflationError + ConcertTicket::display_ticketPrice << endl;
    
    if(validater.validConcertInput(v, v.at(11), logFile)) {
        concertTicket[ticketCount].setTax(v.at(11)); //line 10 == 11 lines
        logFile << inflationSuccess + ConcertTicket::display_tax + inflationTransition << v.at(11) << endl;
        outputFile << ConcertTicket::display_tax << ": " << v.at(11) << endl;
    } else logFile << inflationError + ConcertTicket::display_tax << endl;
    
    if(validater.validConcertInput(v, v.at(12), logFile)) {
        concertTicket[ticketCount].setExtraInfo(v.at(12)); //line 10 == 11 lines
        logFile << inflationSuccess + ConcertTicket::display_extraInfo + inflationTransition << v.at(12) << endl;
        outputFile << ConcertTicket::display_extraInfo << ": " << v.at(12) << endl;
    } else logFile << inflationError + ConcertTicket::display_extraInfo << endl;
    
    if(concertTicket[ticketCount].getTotalCost() >=0) {
        concertTicket[ticketCount].calculateTotalAmounts();
        logFile << inflationSuccess + ConcertTicket::display_totalCost + inflationTransition << concertTicket[ticketCount].getTotalCost() << endl;
        outputFile << ConcertTicket::display_totalCost + ": " << concertTicket[ticketCount].getTotalCost() << endl;
    } else logFile << "[DEBUG] Error in calculating total amount!" << endl;
    logFile << doneProcessing(name, concert_ticket) << endl << endl;
}

void Inflater::inflateCruiseTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile) {
    const string name = v.at(1);
    outputFile << "\n~~~~~~~~ " << name << "'s Invoice (Cruise Ticket #" << ticketCount+1 << ")" << " ~~~~~~~~" << endl;
    logFile << ticketCount+1 << beginProcessing(name, cruise_ticket) << endl;
    //logFile << "[debug] Vector size is: " << v.size() << endl;
    
    if (validater.validCruiseInput(v, v.at(0), logFile)) {
        cruiseTicket[ticketCount].setCruiseLineName(v.at(0)); //line 0
        logFile << inflationSuccess + CruiseTicket::display_cruiseLineName + inflationTransition << v.at(0) << endl;
        outputFile << CruiseTicket::display_cruiseLineName << ": " << v.at(0) << endl;
    } else logFile << inflationError + CruiseTicket::display_cruiseLineName << endl;
    
    if(validater.validCruiseInput(v, v.at(1), logFile)) {
        cruiseTicket[ticketCount].setPassengerName(v.at(1)); //line 1
        logFile << inflationSuccess + CruiseTicket::display_passengerName + inflationTransition << v.at(1) << endl;
        outputFile << CruiseTicket::display_passengerName << ": " << v.at(1) << endl;
    } else logFile << inflationError + CruiseTicket::display_passengerName << endl;
    
    if(validater.validCruiseInput(v, v.at(2), logFile)) {
        cruiseTicket[ticketCount].setPassengerContactInfo(v.at(2)); //line 2
        logFile << inflationSuccess + CruiseTicket::display_passengerContactInfo + inflationTransition << v.at(2) << endl;
        outputFile << CruiseTicket::display_passengerContactInfo << ": " << v.at(2) << endl;
    } else logFile << inflationError + CruiseTicket::display_passengerContactInfo << endl;
    
    if(validater.validCruiseInput(v, v.at(3), logFile)) {
        cruiseTicket[ticketCount].setDepartureDate(v.at(3)); //line 3
        logFile << inflationSuccess + CruiseTicket::display_departureDate + inflationTransition << v.at(3) << endl;
        outputFile << CruiseTicket::display_departureDate << ": " << v.at(3) << endl;
    } else logFile << inflationError + CruiseTicket::display_departureDate << endl;
    
    if(validater.validCruiseInput(v, v.at(4), logFile)) {
        cruiseTicket[ticketCount].setDepartureTime(v.at(4)); //line 4
        logFile << inflationSuccess + CruiseTicket::display_departureTime + inflationTransition << v.at(4) << endl;
        outputFile << CruiseTicket::display_departureTime << ": " << v.at(4) << endl;
    } else logFile << inflationError + CruiseTicket::display_departureTime << endl;
    
    if(validater.validCruiseInput(v, v.at(5), logFile)) {
        cruiseTicket[ticketCount].setCruiseShipName(v.at(5)); //line 5
        logFile << inflationSuccess + CruiseTicket::display_cruiseShipName + inflationTransition << v.at(5) << endl;
        outputFile << CruiseTicket::display_cruiseShipName << ": " << v.at(5) << endl;
    } else logFile << inflationError + CruiseTicket::display_cruiseShipName << endl;
    
    if(validater.validCruiseInput(v, v.at(6), logFile)) {
        cruiseTicket[ticketCount].setPassengerOutboundCabinNum(v.at(6)); //line 6
        logFile << inflationSuccess + CruiseTicket::display_passengerOutboundCabinNum + inflationTransition << v.at(6) << endl;
        outputFile << CruiseTicket::display_passengerOutboundCabinNum << ": " << v.at(6) << endl;
    } else logFile << inflationError + CruiseTicket::display_passengerOutboundCabinNum << endl;
    
    if(validater.validCruiseInput(v, v.at(7), logFile)) {
        cruiseTicket[ticketCount].setReturnDate(v.at(7)); //line 7
        logFile << inflationSuccess + CruiseTicket::display_returnDate + inflationTransition << v.at(7) << endl;
        outputFile << CruiseTicket::display_returnDate << ": " << v.at(7) << endl;
    } else logFile << inflationError + CruiseTicket::display_returnDate << endl;
    
    if(validater.validCruiseInput(v, v.at(8), logFile)) {
        cruiseTicket[ticketCount].setReturnTime(v.at(8)); //line 8
        logFile << inflationSuccess + CruiseTicket::display_returnTime + inflationTransition << v.at(8) << endl;
        outputFile << CruiseTicket::display_returnTime << ": " << v.at(8) << endl;
    } else logFile << inflationError + CruiseTicket::display_returnTime << endl;
    
    if(validater.validCruiseInput(v, v.at(9), logFile)) {
        cruiseTicket[ticketCount].setPassengerReturnCabinNum(v.at(9)); //line 9
        logFile << inflationSuccess + CruiseTicket::display_passengerReturnCabinNum + inflationTransition << v.at(9) << endl;
        outputFile << CruiseTicket::display_passengerReturnCabinNum << ": " << v.at(9) << endl;
    } else logFile << inflationError + CruiseTicket::display_passengerReturnCabinNum << endl;
    
    if(validater.validCruiseInput(v, v.at(10), logFile)) {
        cruiseTicket[ticketCount].setTicketCost(v.at(10)); //line 10 == 11 lines
        logFile << inflationSuccess + CruiseTicket::display_ticketCost + inflationTransition << v.at(10) << endl;
        outputFile << CruiseTicket::display_ticketCost << ": " << v.at(10) << endl;
    } else logFile << inflationError + CruiseTicket::display_ticketCost << endl;
    
    if(validater.validCruiseInput(v, v.at(11), logFile)) {
        cruiseTicket[ticketCount].setExtraCharges(v.at(11)); //line 10 == 11 lines
        logFile << inflationSuccess + CruiseTicket::display_extraCharges + inflationTransition << v.at(11) << endl;
        outputFile << CruiseTicket::display_extraCharges << ": " << v.at(11) << endl;
    } else logFile << inflationError + CruiseTicket::display_extraCharges << endl;
    
    if(validater.validCruiseInput(v, v.at(12), logFile)) {
        cruiseTicket[ticketCount].setTax(v.at(12)); //line 10 == 11 lines
        logFile << inflationSuccess + CruiseTicket::display_tax + inflationTransition << v.at(12) << endl;
        outputFile << CruiseTicket::display_tax << ": " << v.at(12) << endl;
    } else logFile << inflationError + CruiseTicket::display_tax << endl;
    
     if(validater.validCruiseInput(v, v.at(13), logFile)) {
        cruiseTicket[ticketCount].setExtraInfo(v.at(13)); //line 10 == 11 lines
        logFile << inflationSuccess + CruiseTicket::display_extraInfo + inflationTransition << v.at(13) << endl;
         outputFile << CruiseTicket::display_extraInfo << ": " << v.at(13) << endl;
    } else logFile << inflationError + CruiseTicket::display_extraInfo << endl;

    if(cruiseTicket[ticketCount].getTotalCost() >=0) {
        cruiseTicket[ticketCount].calculateTotalAmounts();
        logFile << inflationSuccess + ConcertTicket::display_totalCost + inflationTransition << cruiseTicket[ticketCount].getTotalCost() << endl;
        outputFile << CruiseTicket::display_totalCost + ": " << cruiseTicket[ticketCount].getTotalCost() << endl;
    } else logFile << "[DEBUG] Error in calculating total amount!" << endl;
    logFile << doneProcessing(name, cruise_ticket) << endl << endl;
}

void Inflater::inflateStudentTicket(vector<string>& v, int ticketCount, ofstream& logFile, ofstream& outputFile) {
    const string name = v.at(2);
    outputFile << "\n~~~~~~~~ " << name << "'s Enrollment Record (Student Enrollment #" << ticketCount+1 << ")" << " ~~~~~~~~" << endl;
    logFile << ticketCount+1 << beginProcessing(name, student_ticket) << endl;
    //logFile << "[debug] Vector size is: " << v.size() << endl;
    
    if (validater.validStudentInput(v, v.at(0), logFile)) {
        studentEnrollment[ticketCount].setSchoolName(v.at(0)); //line 0
        logFile << inflationSuccess + StudentEnrollment::display_schoolName + inflationTransition << v.at(0) << endl;
        outputFile << StudentEnrollment::display_schoolName << ": " << v.at(0) << endl;
    } else logFile << inflationError + StudentEnrollment::display_schoolName << endl;
    
    if(validater.validStudentInput(v, v.at(1), logFile)) {
        studentEnrollment[ticketCount].setSchoolContactInfo(v.at(1)); //line 1
        logFile << inflationSuccess + StudentEnrollment::display_schoolContactInfo + inflationTransition << v.at(1) << endl;
        outputFile << StudentEnrollment::display_schoolContactInfo << ": " << v.at(1) << endl;
    } else logFile << inflationError + StudentEnrollment::display_schoolContactInfo << endl;
    
    if(validater.validStudentInput(v, v.at(2), logFile)) {
        studentEnrollment[ticketCount].setStudentName(v.at(2)); //line 2
        logFile << inflationSuccess + StudentEnrollment::display_studentName + inflationTransition << v.at(2) << endl;
        outputFile << StudentEnrollment::display_studentName << ": " << v.at(2) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentName << endl;
    
    if(validater.validStudentInput(v, v.at(3), logFile)) {
        studentEnrollment[ticketCount].setStudentContactInfo(v.at(3)); //line 3
        logFile << inflationSuccess + StudentEnrollment::display_studentContactInfo + inflationTransition << v.at(3) << endl;
        outputFile << StudentEnrollment::display_studentContactInfo << ": " << v.at(3) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentContactInfo << endl;
    
    if(validater.validStudentInput(v, v.at(4), logFile)) {
        studentEnrollment[ticketCount].setStudentStatusInfo(v.at(4)); //line 4
        logFile << inflationSuccess + StudentEnrollment::display_studentStatusInfo + inflationTransition << v.at(4) << endl;
        outputFile << StudentEnrollment::display_studentStatusInfo << ": " << v.at(4) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentStatusInfo << endl;
    
    if(validater.validStudentInput(v, v.at(5), logFile)) {
        studentEnrollment[ticketCount].setStudentDepartment(v.at(5)); //line 5
        logFile << inflationSuccess + StudentEnrollment::display_studentDepartment + inflationTransition << v.at(5) << endl;
        outputFile << StudentEnrollment::display_studentDepartment << ": " << v.at(5) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentDepartment << endl;
    
    if(validater.validStudentInput(v, v.at(6), logFile)) {
        studentEnrollment[ticketCount].setStudentMajor(v.at(6)); //line 6
        logFile << inflationSuccess + StudentEnrollment::display_studentMajor + inflationTransition << v.at(6) << endl;
        outputFile << StudentEnrollment::display_studentMajor << ": " << v.at(6) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentMajor << endl;
    
    if(validater.validStudentInput(v, v.at(7), logFile)) {
        studentEnrollment[ticketCount].setStudentYearsLeftToGraduate(v.at(7)); //line 7
        logFile << inflationSuccess + StudentEnrollment::display_studentYearsLeftToGraduate + inflationTransition << v.at(7) << endl;
        outputFile << StudentEnrollment::display_studentYearsLeftToGraduate << ": " << v.at(7) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentYearsLeftToGraduate << endl;
    
    if(validater.validStudentInput(v, v.at(8), logFile)) {
        studentEnrollment[ticketCount].setStudentCourseSchedule(v.at(8)); //line 8
        logFile << inflationSuccess + StudentEnrollment::display_studentCourseSchedule + inflationTransition << v.at(8) << endl;
        outputFile << StudentEnrollment::display_studentCourseSchedule << ": " << v.at(8) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentCourseSchedule << endl;
    
    if(validater.validStudentInput(v, v.at(9), logFile)) {
        studentEnrollment[ticketCount].setStudentCourseFees(v.at(9)); //line 9
        logFile << inflationSuccess + StudentEnrollment::display_studentCourseFees + inflationTransition << v.at(9) << endl;
        outputFile << StudentEnrollment::display_studentCourseFees << ": " << v.at(9) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentCourseFees << endl;
    
    if(validater.validStudentInput(v, v.at(10), logFile)) {
        studentEnrollment[ticketCount].setStudentFinancialAid(v.at(10)); //line 10 == 11 lines
        logFile << inflationSuccess + StudentEnrollment::display_studentFinancialAid + inflationTransition << v.at(10) << endl;
        outputFile << StudentEnrollment::display_studentFinancialAid << ": " << v.at(10) << endl;
    } else logFile << inflationError + StudentEnrollment::display_studentFinancialAid << endl;

    if(studentEnrollment[ticketCount].getStudentOutsandingBalance() >=0) {
        studentEnrollment[ticketCount].calculateTotalAmounts();
        logFile << inflationSuccess + StudentEnrollment::display_studentOutsandingBalance + inflationTransition << studentEnrollment[ticketCount].getStudentOutsandingBalance() << endl;
        outputFile << StudentEnrollment::display_studentOutsandingBalance + ": " << studentEnrollment[ticketCount].getStudentOutsandingBalance() << endl;
    } else logFile << "[DEBUG] Error in calculating student balance!" << endl;
    logFile << doneProcessing(name, student_ticket) << endl << endl;
}
