//  OOProject
//
//  Created by Damian Lajara on 9/24/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __OOProject__HotelReceipt__
#define __OOProject__HotelReceipt__

#include <stdio.h>
#include <iostream>
using std::string;

/**
 * FILE FORMAT!...
 * Name of Hotel
 * Address of Hotel
 * Contact Information of Hotel
 * Name of Guest
 * Contact Information of Guest
 * Room Number
 * Room Rate
 * Number of Days of Stay
 * Extra Expenses
 * Taxes
 * Deposit
 ------------------------------
 * //Calculated in the program
 * Balance Due[before taxes] ((room rate * number of days) + extra expenses - Deposits) //0.0847 (divide percent by 100)
 * Total Amount[after taxes] (Balance Due + (Balance Due * taxes))
 */

class HotelReceipt {
    public:
        HotelReceipt();
        ~HotelReceipt();
        
        void setHotelName(string newHotelName);
        void setHotelAddress(string newHotelAddress);
        void setHotelContactInfo(string newHotelContactInfo);
        void setGuestName(string newGuestName);
        void setGuestContactInfo(string newGuestContactInfo);
        void setRoomNumber(string newRoomNumber);
        void setRoomRate(string newRoomRate);
        void setLengthOfStay(string newLength);
        void setExtraExpenses(string newExtraExpenses);
        void setTax(string taxAmount);
        void setDeposit(string newDepositAmount);
    
        void calculateTotalAmounts();
    
        string getHotelName();
        string getHotelAddress();
        string getHotelContactInfo();
        string getGuestName();
        string getGuestContactInfo();
        string getRoomNumber();
        string getRoomRate();
        string getLengthOfStay();
        string getExtraExpenses();
        string getTax();
        float getBalanceDue();
        string getDeposit();
        float getTotalAmount();
    
        //static variables
        const static string display_hotelName;
        const static string display_hotelAddress;
        const static string display_hotelContactInfo;
        const static string display_guestName;
        const static string display_guestContactInfo;
        const static string display_roomNumber;
        const static string display_roomRate;
        const static string display_lengthOfStay;
        const static string display_extraExpenses;
        const static string display_tax;
        const static string display_deposit;
        const static string display_balance;
        const static string display_total;
    
    private:
        string hotelName;
        string hotelAddress;
        string hotelContactInfo;
        string guestName;
        string guestContactInfo;
        string roomNumber;
        string roomRate;
        string lengthOfStay;
        string extraExpenses;
        string tax;
        float balanceDue;
        string deposit;
        float totalAmount;
    
    
};

#endif /* defined(__OOProject__HotelReceipt__) */