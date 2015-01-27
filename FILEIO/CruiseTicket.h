//  OOProject
//
//  Created by Damian Lajara on 9/25/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __OOProject__CruiseTicket__
#define __OOProject__CruiseTicket__

#include <sstream>
#include <iostream>
using std::string;

/**
 * Name of Cruise Line;
 * Name of Traveler or Passenger;
 * Contact Information of Traveler;
 * Date of Departure;
 * Time of Departure;
 * Name of Cruise Ship;
 * Outbound Passenger Cabin Number;
 * Date of Return;
 * Time of Return;
 * Return Passenger Cabin Number;
 * Cost of Ticket;
 * Extra Charges;
 * Taxes;
 * Extra Information
 * ---------------------------
 * totalCost is calculated in program
 */

class CruiseTicket{
    public:
        CruiseTicket();
        void setCruiseLineName(string newCruiseLineName);
        void setPassengerName(string newPassengerName);
        void setPassengerContactInfo(string newPassengerContactInfo);
        void setDepartureDate(string newDepartureDate);
        void setDepartureTime(string newDepartureTime);
        void setCruiseShipName(string newCruiseShipName);
        void setPassengerOutboundCabinNum(string outboundCabinNum);
        void setReturnDate(string newReturnDate);
        void setReturnTime(string newReturnTime);
        void setPassengerReturnCabinNum(string returnCabinNum);
        void setTicketCost(string newTicketCost);
        void setExtraCharges(string newExtraCharges);
        void setTax(string newTax);
        void setExtraInfo(string newExtraInfo);
    
        void calculateTotalAmounts();
    
        string getCruiseLineName();
        string getPassengerName();
        string getPassengerContactInfo();
        string getDepartureDate();
        string getDepartureTime();
        string getCruiseShipName();
        string getPassengerOutboundCabinNum();
        string getReturnDate();
        string getReturnTime();
        string getPassengerReturnCabinNum();
        string getTicketCost();
        string getExtraCharges();
        string getTax();
        float getTotalCost();
        string getExtraInfo();
    
        //static variables that can be accessed outside the class without an object
        static const string display_cruiseLineName;
        static const string display_passengerName;
        static const string display_passengerContactInfo;
        static const string display_departureDate;
        static const string display_departureTime;
        static const string display_cruiseShipName;
        static const string display_passengerOutboundCabinNum;
        static const string display_returnDate;
        static const string display_returnTime;
        static const string display_passengerReturnCabinNum;
        static const string display_ticketCost;
        static const string display_extraCharges;
        static const string display_tax;
        static const string display_extraInfo;
        static const string display_totalCost;
    
    private:
        string cruiseLineName;
        string passengerName;
        string passengerContactInfo;
        string departureDate;
        string departureTime;
        string cruiseShipName;
        string passengerOutboundCabinNum;
        string returnDate;
        string returnTime;
        string passengerReturnCabinNum;
        string ticketCost;
        string extraCharges;
        string tax;
        float totalCost;
        string extraInfo;
    
};

#endif /* defined(__OOProject__CruiseTicket__) */