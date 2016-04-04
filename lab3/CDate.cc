// ..................................................  
// CDate class definitions
// Adapted from Hagit Schechter, Jan 2007 for 2014W2 
// ..................................................

#include <iostream>
#include <string>
#include <cstdlib>
#include "CDate.h"

CDate::CDate(void){
	m_year = m_month = m_day = 0;
}

CDate::CDate(int year, int month, int day){
	setDate( year, month, day );        
}

CDate::CDate(int year, std::string month, int day){
	int temp_month = monthStr2Num(month);
	setDate( year, temp_month, day);
}

bool CDate::isValidDate(int year, int month, int day){
	if( isValidDay(year,month,day) == false){
		return false;
	}
	else{
		if((month < 1) || (month > 12)){
			return false;
		}
		if( year < 0){
			return false;
		}
		return true;
	}
}

bool CDate::isValidDate(int year, std::string month, int day){
	int temp_month = monthStr2Num(month);
	return isValidDate(year, temp_month, day);
}


int CDate::monthStr2Num(std::string month){
	if( month == "January")
		return 1;
	else if( month == "February")
		return 2;
	else if( month == "March")
		return 3;
	else if( month == "April")
		return 4;
	else if( month == "May")
		return 5;
	else if( month == "June")
		return 6;
	else if( month == "July")
		return 7;
	else if( month == "August")
		return 8;
	else if( month == "September")
		return 9;
	else if(month == "October")
		return 10;
	else if(month == "November")
		return 11;
	else if( month == "December")
		return 12;
	else
		return -1;

}

bool CDate::isValidDay(int year, int month, int day){
	if ((day < 1) || (day > 31)) return false;

	switch (month) {
		case 1: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 3: if((day < 1) || (day > 31))
				return false;
			else
				return true;
		case 5: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 7: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 8: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 10: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 12: if((day < 1) || (day > 31)) 
				return false;
			else
				return true;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				if (day <=28)
					return true;
				else
					return false;
			} else if ((year % 400) == 0) {
				if (day <= 29)
					return true;
				else
					return false;
			} else if ((year % 100) == 0) {
				if (day <= 28)
					return true;
				else
					return false;
			} else {
				if (day <= 29)
					return true;
				else
					return false;
			}
			
		case 4: if((day < 1) || (day > 30)) 
				return false;
			else
				return true;
		case 6: if((day < 1) || (day > 30)) 
				return false;
			else
				return true;
		case 9: if((day < 1) || (day > 30)) 
				return false;
			else
				return true;
		case 11: if((day < 1) || (day > 30)) 
				return false;
			else
				return true;
		default: return false;
		
	}
}

void CDate::setDate(int year, int month, int day){
	if(isValidDate(year, month, day)){    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate(int year, std::string month, int day){
	int temp_month=monthStr2Num(month);
	setDate(year,temp_month,day);
}

void CDate::print(void){
	std::cout << m_year << "/" << m_month << "/" << m_day << std::endl;
}

int CDate::getDate(void){
	return (m_year * 10000) + (m_month * 100) + m_day;
}

