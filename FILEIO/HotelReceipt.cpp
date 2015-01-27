//  OOProject
//
//  Created by Damian Lajara on 9/24/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//
#include <sstream>
#include "HotelReceipt.h"
using std::cout;
using std::endl;
using std::stringstream;

const string HotelReceipt::display_hotelName = "Hotel Name";
const string HotelReceipt::display_hotelAddress = "Hotel Address";
const string HotelReceipt::display_hotelContactInfo = "Hotel Contact Info";
const string HotelReceipt::display_guestName = "Guest Name";
const string HotelReceipt::display_guestContactInfo = "Guest Contact Info";
const string HotelReceipt::display_roomNumber = "Room Number";
const string HotelReceipt::display_roomRate = "Room Rate";
const string HotelReceipt::display_lengthOfStay = "Length Of Stay";
const string HotelReceipt::display_extraExpenses = "Extra Expenses";
const string HotelReceipt::display_tax = "Tax";
const string HotelReceipt::display_deposit = "Deposit";
const string HotelReceipt::display_balance = "Balance";
const string HotelReceipt::display_total = "Total";

HotelReceipt::HotelReceipt() {
    //cout << "[DEBUG] Object created\n";
    hotelName = "";
    hotelAddress = "";
    hotelContactInfo = "";
    guestName = "";
    guestContactInfo = "";
    roomNumber = "";
    roomRate = "";
    lengthOfStay = "";
    extraExpenses = "";
    tax = "";
    balanceDue = 0.0;
    deposit = "";
    totalAmount = 0.0;
}

HotelReceipt::~HotelReceipt() {
    //cout << "[DEBUG] Object destroyed\n";
}

void HotelReceipt::setHotelName(string newHotelName) {
    hotelName = newHotelName;
}
void HotelReceipt::setHotelAddress(string newHotelAddress) {
    hotelAddress = newHotelAddress;
}
void HotelReceipt::setHotelContactInfo(string newHotelContactInfo) {
    hotelContactInfo = newHotelContactInfo;
}
void HotelReceipt::setGuestName(string newGuestName) {
    guestName = newGuestName;
}
void HotelReceipt::setGuestContactInfo(string newGuestContactInfo) {
    guestContactInfo = newGuestContactInfo;
}
void HotelReceipt::setRoomNumber(string newRoomNumber) {
    roomNumber = newRoomNumber;
}
void HotelReceipt::setRoomRate(string newRoomRate) {
    roomRate = newRoomRate;
}
void HotelReceipt::setLengthOfStay(string newLength) {
    lengthOfStay = newLength;
}
void HotelReceipt::setExtraExpenses(string newExtraExpenses) {
    extraExpenses = newExtraExpenses;
}
void HotelReceipt::setTax(string taxAmount) {
    tax = taxAmount;
}
void HotelReceipt::setDeposit(string newDepositAmount) {
    deposit = newDepositAmount;
}

string HotelReceipt::getHotelName() {
    return hotelName;
}
string HotelReceipt::getHotelAddress() {
    return hotelAddress;
}
string HotelReceipt::getHotelContactInfo() {
    return hotelContactInfo;
}
string HotelReceipt::getGuestName() {
    return guestName;
}
string HotelReceipt::getGuestContactInfo() {
    return guestContactInfo;
}
string HotelReceipt::getRoomNumber() {
    return roomNumber;
}
string HotelReceipt::getRoomRate() {
    return roomRate;
}
string HotelReceipt::getLengthOfStay() {
    return lengthOfStay;
}
string HotelReceipt::getExtraExpenses() {
    return extraExpenses;
}
string HotelReceipt::getTax() {
    return tax;
}
float HotelReceipt::getBalanceDue() {
    return balanceDue;
}
string HotelReceipt::getDeposit() {
    return deposit;
}
float HotelReceipt::getTotalAmount() {
    return totalAmount;
}

void HotelReceipt::calculateTotalAmounts() {
    float rate, length, expenses, deposits, taxes;
    tax = tax.substr(0, tax.length()-1); //remove percent sign for calculation
    string resultString = roomRate + " " + lengthOfStay + " " + extraExpenses + " " + deposit + " " + tax;
    //[DEBUG] cout << "Result string: " << resultString << endl;
    std::istringstream iss(resultString);
    iss >> rate >> length >> expenses >> deposits >> taxes;
    //[DEBUG] cout << "Result convert: " << rate << " " << length << " " << expenses << " "  << deposits << " "  << taxes << endl;
    //((room rate * number of days) + extra expenses - Deposits) //0.0847 (divide percent by 100)
    //Instead of doing: [balanceDue = (stof(roomRate) * stof(lengthOfStay)) + stof(extraExpenses) - stof(deposit);], just use string stream
    //[DEBUG] cout << "(" << rate << " * " << length << ") + " << expenses << " - " << deposits << endl;
    balanceDue = (rate * length) + expenses - deposits;
    //[DEBUG] cout << balanceDue << " + (" << balanceDue << " * (" << taxes/100 << "))" << endl;
    totalAmount = balanceDue + (balanceDue * (taxes/100));
    //[DEBUG] cout << "Total Amount Due:" << totalAmount << endl;
}