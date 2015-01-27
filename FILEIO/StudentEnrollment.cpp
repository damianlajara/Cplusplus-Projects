//  OOProject
//
//  Created by Damian Lajara on 9/24/14.
//  Copyright (c) 2014 OOP. All rights reserved.
//

#include "StudentEnrollment.h"

//Initialize static variables here, since they cannot be initialized inline in the header file
const string StudentEnrollment::display_schoolName= "School Name";
const string StudentEnrollment::display_schoolContactInfo = "School Contact Information";
const string StudentEnrollment::display_studentName = "Student Name Description";
const string StudentEnrollment::display_studentContactInfo = "Student Contact Information";
const string StudentEnrollment::display_studentStatusInfo = "Student Status Information";
const string StudentEnrollment::display_studentDepartment = "Student Department";
const string StudentEnrollment::display_studentMajor = "Student's Major";
const string StudentEnrollment::display_studentYearsLeftToGraduate = "Years left To graduate";
const string StudentEnrollment::display_studentCourseSchedule = "Student's Course Schedule";
const string StudentEnrollment::display_studentCourseFees = "Course Fees";
const string StudentEnrollment::display_studentFinancialAid = "Student's Financial Aid";
const string StudentEnrollment::display_studentOutsandingBalance = "Student's Outstanding balance";


StudentEnrollment::StudentEnrollment() {
  schoolName = "";
  schoolContactInfo = "";
  StudentName = "";
  studentContactInfo = "";
  studentStatusInfo = "";
  StudentDepartment = "";
  StudentMajor = "";
  studentYearsLeftToGraduate = "";
  studentCourseSchedule = "";
  studentCourseFees = "";
  studentFinancialAid = "";
  studentOutsandingBalance = 0.0;
}

void StudentEnrollment::setSchoolName(string newSchoolName) {
    schoolName = newSchoolName;
}
void StudentEnrollment::setSchoolContactInfo(string newSchoolContactInfo) {
    schoolContactInfo = newSchoolContactInfo;
}
void StudentEnrollment::setStudentName(string newStudentName) {
    StudentName = newStudentName;
}
void StudentEnrollment::setStudentContactInfo(string newStudentContactInfo) {
    studentContactInfo = newStudentContactInfo;
}
void StudentEnrollment::setStudentStatusInfo(string newStudentStatusInfo) {
    studentStatusInfo = newStudentStatusInfo;
}
void StudentEnrollment::setStudentDepartment(string newStudentDepartment) {
    StudentDepartment = newStudentDepartment;
}
void StudentEnrollment::setStudentMajor(string newStudenMajor) {
    StudentMajor = newStudenMajor;
}
void StudentEnrollment::setStudentYearsLeftToGraduate(string yearsLeft) {
    studentYearsLeftToGraduate = yearsLeft;
}
void StudentEnrollment::setStudentCourseSchedule(string newCourseSchedule) {
    studentCourseSchedule = newCourseSchedule;
}
void StudentEnrollment::setStudentCourseFees(string newCourseFees) {
    studentCourseFees = newCourseFees;
}
void StudentEnrollment::setStudentFinancialAid(string newFinancialAid) {
    studentFinancialAid = newFinancialAid;
}
string StudentEnrollment::getSchoolName() {
    return schoolName;
}
string StudentEnrollment::getSchoolContactInfo() {
    return schoolContactInfo;
}
string StudentEnrollment::getStudentName() {
    return StudentName;
}
string StudentEnrollment::getStudentContactInfo() {
    return studentContactInfo;
}
string StudentEnrollment::getStudentStatusInfo() {
    return studentStatusInfo;
}
string StudentEnrollment::getStudentDepartment() {
    return StudentDepartment;
}
string StudentEnrollment::getStudentMajor() {
    return StudentMajor;
}
string StudentEnrollment::getStudentYearsLeftToGraduate() {
    return studentYearsLeftToGraduate;
}
string StudentEnrollment::getStudentCourseSchedule() {
    return studentCourseSchedule;
}
string StudentEnrollment::getStudentCourseFees() {
    return studentCourseFees;
}
string StudentEnrollment::getStudentFinancialAid() {
    return studentFinancialAid;
}
float StudentEnrollment::getStudentOutsandingBalance() {
    return studentOutsandingBalance;
}

void StudentEnrollment::calculateTotalAmounts() {
    string resultString = studentCourseFees + " " + studentFinancialAid;
    //cout << "Result string: " << resultString << endl;
    float _studentCourseFees, _studentFinancialAid;
    std::istringstream iss(resultString);
    iss >> _studentCourseFees >> _studentFinancialAid;
    studentOutsandingBalance =  _studentCourseFees - _studentFinancialAid;
}