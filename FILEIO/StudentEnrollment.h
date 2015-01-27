//  OOProject
//
//  Created by Damian Lajara on 9/24/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#ifndef __OOProject__StudentEnrollment__
#define __OOProject__StudentEnrollment__

#include <sstream>
#include <iostream>
using std::string;

/**
 * Name of School
 * Contact Information of School
 * Name of Student
 * Contact Information of Student
 * Student Status Information;
 * Department
 * Major;
 * Estimated Years to Graduation
 * Schedule of Courses //use counter (if it reaches the 9th line, we know its a course schedule, so input it all into the array)
 * Course Fees
 * Financial Aid Information
 * Outstanding Balance on Payments
 */


class StudentEnrollment {
    public:
        StudentEnrollment();
    
        void setSchoolName(string newSchoolName);
        void setSchoolContactInfo(string newSchoolContactInfo);
        void setStudentName(string newStudentName);
        void setStudentContactInfo(string newStudentContactInfo);
        void setStudentStatusInfo(string newStudentStatusInfo);
        void setStudentDepartment(string newStudentDepartment);
        void setStudentMajor(string newStudenMajor);
        void setStudentYearsLeftToGraduate(string yearsLeft);
        void setStudentCourseSchedule(string newCourseSchedule);
        void setStudentCourseFees(string newCourseFees);
        void setStudentFinancialAid(string newFinancialAid);
    
        void calculateTotalAmounts();
    
        string getSchoolName();
        string getSchoolContactInfo();
        string getStudentName();
        string getStudentContactInfo();
        string getStudentStatusInfo();
        string getStudentDepartment();
        string getStudentMajor();
        string getStudentYearsLeftToGraduate();
        string getStudentCourseSchedule();
        string getStudentCourseFees();
        string getStudentFinancialAid();
        float getStudentOutsandingBalance();
    
    
    //static to_string methdods instead of hardcoding them in inflater and validater
    static const string display_schoolName;
    static const string display_schoolContactInfo;;
    static const string display_studentName;
    static const string display_studentContactInfo;
    static const string display_studentStatusInfo;
    static const string display_studentDepartment;
    static const string display_studentMajor;
    static const string display_studentYearsLeftToGraduate;
    static const string display_studentCourseSchedule;
    static const string display_studentCourseFees;
    static const string display_studentFinancialAid;
    static const string display_studentOutsandingBalance;

    
    private:
        string schoolName;
        string schoolContactInfo;
        string StudentName;
        string studentContactInfo;
        string studentStatusInfo;
        string StudentDepartment;
        string StudentMajor;
        string studentYearsLeftToGraduate;
        string studentCourseSchedule;
        string studentCourseFees;
        string studentFinancialAid;
        float studentOutsandingBalance;
    
};

#endif /* defined(__OOProject__StudentEnrollment__) */