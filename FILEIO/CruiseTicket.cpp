//  OOProject
//
//  Created by Damian Lajara on 9/25/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include "CruiseTicket.h"

const string CruiseTicket::display_cruiseLineName = "Cruise Line Name";
const string CruiseTicket::display_passengerName = "Passenger Name";
const string CruiseTicket::display_passengerContactInfo = "Passenger Contact Info";
const string CruiseTicket::display_departureDate = "Departure Date";
const string CruiseTicket::display_departureTime = "Departure Time";
const string CruiseTicket::display_cruiseShipName = "Cruise Ship Name";
const string CruiseTicket::display_passengerOutboundCabinNum = "Passenger Outbound Cabin Num";
const string CruiseTicket::display_returnDate = "Return Date";
const string CruiseTicket::display_returnTime = "Return Time";
const string CruiseTicket::display_passengerReturnCabinNum = "Passenger Return Cabin Num";
const string CruiseTicket::display_ticketCost = "Ticket Cost";
const string CruiseTicket::display_extraCharges = "Extra Charges";
const string CruiseTicket::display_tax = "Tax";
const string CruiseTicket::display_extraInfo = "Extra Info";
const string CruiseTicket::display_totalCost = "Total Cost";

CruiseTicket::CruiseTicket() {
  cruiseLineName = "";
  passengerName = "";
  passengerContactInfo = "";
  departureDate = "";
  departureTime = "";
  cruiseShipName = "";
  passengerOutboundCabinNum = "";
  returnDate = "";
  returnTime = "";
  passengerReturnCabinNum = "";
  ticketCost = "";
  extraCharges = "";
  tax = "";
  totalCost = 0.0;
  extraInfo = "";
}
void CruiseTicket::setCruiseLineName(string newCruiseLineName) {
    cruiseLineName = newCruiseLineName;
}
void CruiseTicket::setPassengerName(string newPassengerName) {
    passengerName = newPassengerName;
}
void CruiseTicket::setPassengerContactInfo(string newPassengerContactInfo) {
    passengerContactInfo = newPassengerContactInfo;
}
void CruiseTicket::setDepartureDate(string newDepartureDate) {
    departureDate = newDepartureDate;
}
void CruiseTicket::setDepartureTime(string newDepartureTime) {
    departureTime = newDepartureTime;
}
void CruiseTicket::setCruiseShipName(string newCruiseShipName) {
    cruiseShipName = newCruiseShipName;
}
void CruiseTicket::setPassengerOutboundCabinNum(string outboundCabinNum) {
    passengerOutboundCabinNum = outboundCabinNum;
}
void CruiseTicket::setReturnDate(string newReturnDate) {
    returnDate = newReturnDate;
}
void CruiseTicket::setReturnTime(string newReturnTime) {
    returnTime = newReturnTime;
}
void CruiseTicket::setPassengerReturnCabinNum(string returnCabinNum) {
    passengerReturnCabinNum = returnCabinNum;
}
void CruiseTicket::setTicketCost(string newTicketCost) {
    ticketCost = newTicketCost;
}
void CruiseTicket::setExtraCharges(string newExtraCharges) {
    extraCharges = newExtraCharges;
}
void CruiseTicket::setTax(string newTax) {
    tax = newTax;
}
void CruiseTicket::setExtraInfo(string newExtraInfo) {
    extraInfo = newExtraInfo;
}

string CruiseTicket::getCruiseLineName() {
    return cruiseLineName;
}
string CruiseTicket::getPassengerName() {
    return passengerName;
}
string CruiseTicket::getPassengerContactInfo() {
    return passengerContactInfo;
}
string CruiseTicket::getDepartureDate() {
    return departureDate;
}
string CruiseTicket::getDepartureTime() {
    return departureTime;
}
string CruiseTicket::getCruiseShipName() {
    return cruiseShipName;
}
string CruiseTicket::getPassengerOutboundCabinNum() {
    return passengerOutboundCabinNum;
}
string CruiseTicket::getReturnDate() {
    return returnDate;
}
string CruiseTicket::getReturnTime() {
    return returnTime;
}
string CruiseTicket::getPassengerReturnCabinNum() {
    return passengerReturnCabinNum;
}
string CruiseTicket::getTicketCost() {
    return ticketCost;
}
string CruiseTicket::getExtraCharges() {
    return extraCharges;
}
string CruiseTicket::getTax() {
    return tax;
}
float CruiseTicket::getTotalCost() {
    return totalCost;
}
string CruiseTicket::getExtraInfo() {
    return extraInfo;
}

void CruiseTicket::calculateTotalAmounts() {
    tax = tax.substr(0, tax.length()-1); //remove percent sign for calculation
    string resultString = ticketCost + " " + extraCharges + " " + tax;
    //[DEBUG] cout << "Result string: " << resultString << endl;
    float _ticketCost, _extraCharges, _tax;
    std::istringstream iss(resultString);
    iss >> _ticketCost >> _extraCharges >> _tax;
    float balance = _ticketCost + _extraCharges;
    totalCost =  balance + (balance * (_tax/100));
}

