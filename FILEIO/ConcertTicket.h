//  OOProject
//
//  Created by Damian Lajara on 9/25/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __OOProject__ConcertTicket__
#define __OOProject__ConcertTicket__

#include <sstream>
#include <iostream>
using std::string;

/**
 * Name of Service Provider;
 * Contact Information of Service Provider;
 * Name of Show;
 * Show Venue;
 * Date of Show;
 * Start Time;
 * Ending Time;
 * Name of Guest;
 * Contact Information Guest;
 * Seat Number;
 * Ticket Price
 * Taxes;
 * Total Cost;
 * Extra Information.
 */

class ConcertTicket {
    public:
        ConcertTicket();
        void setServiceProviderName(string providerName);
        void setServiceProviderContactInfo(string contactInfo);
        void setShowName(string newShowName);
        void setShowVenue(string venue);
        void setShowDate(string date);
        void setStartTime(string sTime);
        void setEndingTime(string eTime);
        void setGuestName(string name);
        void setGuestContactInfo(string contactInfo);
        void setSeatNumber(string seat);
        void setTicketPrice(string price);
        void setTax(string taxes);
        void setExtraInfo(string info);
    
        void calculateTotalAmounts();
    
        string getServiceProviderName();
        string getServiceProviderContactInfo();
        string getShowName();
        string getShowVenue();
        string getShowDate();
        string getStartTime();
        string getEndingTime();
        string getGuestName();
        string getGuestContactInfo();
        string getSeatNumber();
        string getTicketPrice();
        string getTax();
        float getTotalCost();
        string getExtraInfo();
    
        //static variables
        const static string display_serviceProviderName;
        const static string display_serviceProviderContactInfo;
        const static string display_showName;
        const static string display_showVenue;
        const static string display_showDate;
        const static string display_startTime;
        const static string display_endingTime;
        const static string display_guestName;
        const static string display_guestContactInfo;
        const static string display_seatNumber;
        const static string display_ticketPrice;
        const static string display_tax;
        const static string display_extraInfo;
        const static string display_totalCost;
    
    private:
        string serviceProviderName;
        string serviceProviderContactInfo;
        string showName;
        string showVenue;
        string showDate;
        string startTime;
        string endingTime;
        string guestName;
        string guestContactInfo;
        string seatNumber;
        string ticketPrice;
        string tax;
        float totalCost;
        string extraInfo;
};

#endif /* defined(__OOProject__ConcertTicket__) */