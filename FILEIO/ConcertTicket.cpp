//  OOProject
//
//  Created by Damian Lajara on 9/25/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include "ConcertTicket.h"

const string ConcertTicket::display_serviceProviderName = "Service Provider Name";
const string ConcertTicket::display_serviceProviderContactInfo = "Service Provider Contact Info";
const string ConcertTicket::display_showName = "Show Name";
const string ConcertTicket::display_showVenue = "Show Venue";
const string ConcertTicket::display_showDate = "Show Date";
const string ConcertTicket::display_startTime = "Start Time";
const string ConcertTicket::display_endingTime = "Ending Time";
const string ConcertTicket::display_guestName = "Guest Name";
const string ConcertTicket::display_guestContactInfo = "Guest Contact Info";
const string ConcertTicket::display_seatNumber = "Seat Number";
const string ConcertTicket::display_ticketPrice = "Ticket Price";
const string ConcertTicket::display_tax = "Tax";
const string ConcertTicket::display_extraInfo = "Extra Info";
const string ConcertTicket::display_totalCost = "Total Cost";

ConcertTicket::ConcertTicket() {
  serviceProviderName = "";
  serviceProviderContactInfo = "";
  showName = "";
  showVenue = "";
  showDate = "";
  startTime = "";
  endingTime = "";
  guestName = "";
  guestContactInfo = "";
  seatNumber = "";
  ticketPrice = "";
  tax = "";
  totalCost = 0.0;
  extraInfo = "";
}
void ConcertTicket::setServiceProviderName(string providerName) {
    serviceProviderName = providerName;
}
void ConcertTicket::setServiceProviderContactInfo(string contactInfo) {
    serviceProviderContactInfo = contactInfo;
}
void ConcertTicket::setShowName(string newShowName) {
    showName = newShowName;
}
void ConcertTicket::setShowVenue(string venue) {
    showVenue = venue;
}
void ConcertTicket::setShowDate(string date) {
    showDate = date;
}
void ConcertTicket::setStartTime(string sTime) {
    startTime = sTime;
}
void ConcertTicket::setEndingTime(string eTime) {
    endingTime = eTime;
}
void ConcertTicket::setGuestName(string name) {
    guestName = name;
}
void ConcertTicket::setGuestContactInfo(string contactInfo) {
    guestContactInfo = contactInfo;
}
void ConcertTicket::setSeatNumber(string seat) {
    seatNumber = seat;
}
void ConcertTicket::setTicketPrice(string price) {
    ticketPrice = price;
}
void ConcertTicket::setTax(string taxes) {
    tax = taxes;
}
void ConcertTicket::setExtraInfo(string info) {
    extraInfo = info;
}
string ConcertTicket::getServiceProviderName() {
    return serviceProviderName;
}
string ConcertTicket::getServiceProviderContactInfo() {
    return serviceProviderContactInfo;
}
string ConcertTicket::getShowName() {
    return showName;
}
string ConcertTicket::getShowVenue() {
    return showVenue;
}
string ConcertTicket::getShowDate() {
    return showDate;
}
string ConcertTicket::getStartTime() {
    return startTime;
}
string ConcertTicket::getEndingTime() {
    return endingTime;
}
string ConcertTicket::getGuestName() {
    return guestName;
}
string ConcertTicket::getGuestContactInfo() {
    return guestContactInfo;
}
string ConcertTicket::getSeatNumber() {
    return seatNumber;
}
string ConcertTicket::getTicketPrice() {
    return ticketPrice;
}
string ConcertTicket::getTax() {
    return tax;
}
float ConcertTicket::getTotalCost() {
    return totalCost;
}
string ConcertTicket::getExtraInfo() {
    return extraInfo;
}

void ConcertTicket::calculateTotalAmounts() {
    tax = tax.substr(0, tax.length()-1); //remove percent sign for calculation
    string resultString = ticketPrice + " " + tax;
    //[DEBUG] cout << "Result string: " << resultString << endl;
    float _ticketPrice, _tax;
    std::istringstream iss(resultString);
    iss >> _ticketPrice >> _tax;
    //strip the percent sign
    totalCost = _ticketPrice + (_ticketPrice * (_tax/100));
}
