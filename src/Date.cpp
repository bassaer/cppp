#include <ctime>
#include <sstream>
#include <iostream>
#include "Date.hpp"

using namespace std;

int Date::dmax[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date::get_days_of_year(int year)
{
  return 365 + is_leap_year(year);
}

int Date::get_days_of_month(int year, int month)
{
  return dmax[month - 1] + (month == 2 && is_leap_year(year));
}

Date::Date()
{
  time_t current = time(NULL);
  struct tm* local = localtime(&current);
  this->year = local->tm_year + 1900;
  this->month = local->tm_mon + 1;
  this->day = local->tm_mday;
}

Date::Date(int year, int month, int day)
{
  set(year, month, day);
}

void Date::set(int year, int month, int day)
{
  this->year = year;
  this->month = month;
  this->day = day;
}

Date Date::get_preceding_day() const
{
  Date date(*this);
  return --date;
}

Date Date::get_following_day() const
{
  Date date(*this);
  return ++date;
}

int Date::get_days_of_year() const
{
  int days = this->day;
  for(int i = 0; i < this->month; i++) {
    days += get_days_of_month(this->year, i);
  }
  return days;
}

int Date::get_days_of_week() const
{
  int year = this->year;
  int month = this->month;

  if (month == 1 || month == 2) {
    year--;
    month += 12;
  }
  return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) /5 + this->day) % 7;
}

Date::operator long() const
{
  return *this - Date(1970, 1, 1);
}

Date& Date::operator++()
{
  if (this->day < get_days_of_month(this->year, this->month)) {
    this->day++;
    return *this;
  } else if (++this->month > 12) {
    this->year++;
    this->month = 1;
  } 
  this->day = 1;
  return *this;
}

Date Date::operator++(int)
{
  Date date(*this);
  ++(*this);
  return date;
}

Date& Date::operator--()
{
  if (this->day > 1) {
    this->day--;
    return *this;
  } else if(--this->month <= 1) {
     this->year--;
     this->month = 12;
  }
  this->day = get_days_of_month(this->year, this->month);
  return *this;
}
Date Date::operator--(int)
{
  Date date(*this);
  --(*this);
  return date;
}

Date& Date::operator+=(int dn)
{
  if (dn < 0) {
    return *this -= dn;
  }
  this->day += dn;
  while (this->day > get_days_of_month(this->year, this->month)) {
    this->day -= get_days_of_month(this->year, this->month);
    if (++this->month > 12) {
      this->year++;
      this->month = 1;
    }
  }
  return *this;
}

Date& Date::operator-=(int dn)
{
  if (dn < 0) {
    return *this -= dn; 
  }
  this->day -= dn;
  while (this->day < 1) {
    if (--this->month < 1) {
      this->year--;
      this->month = 12;
    }
    this->day += get_days_of_month(this->year, this->month);
  }
  return *this;
}

Date Date::operator+(int dn) const
{
  Date date(*this);
  return date += dn;
}

Date operator+(int dn, const Date& day)
{
  return day + dn;
}

Date Date::operator-(int dn) const
{
  Date date(*this);
  return date -= dn;
}

long Date::operator-(const Date& day) const
{
  long diff;
  long compared_day = this->get_days_of_year();
  long comparer_day = day.get_days_of_year();

  if (this->year > day.get_year()) {
    diff = compared_day - comparer_day;
  } else if (this->year > day.get_year()) {
    diff = get_days_of_year(day.get_year()) - comparer_day + compared_day;
    for (int y = day.get_year() + 1; y < this->year; y++) {
      diff += get_days_of_year(y);
    }
  } else {
    diff = -(get_days_of_year(this->year) - compared_day - comparer_day);
    for (int y = this->year + 1; y < day.get_year(); y++) {
      diff -= get_days_of_year(y);
    }
  }
  return diff;
}

bool Date::operator==(const Date& day) const
{
  return this->year == day.get_year() &&
    this->month == day.get_month() &&
    this->day == day.get_day();
}

bool Date::operator!=(const Date& day) const
{
  return !(*this == day);
}

bool Date::operator>(const Date& day) const
{
  if (this->year > day.get_year()) return true;
  if (this->year < day.get_year()) return false;
  if (this->month > day.get_month()) return true;
  if (this->month < day.get_month()) return false;
  return this->day > day.get_day();
}

bool Date::operator>=(const Date& day) const
{
  return !(*this < day);
}

bool Date::operator<(const Date& day) const
{
  if (this->year < day.get_year()) return true;
  if (this->year > day.get_year()) return false;
  if (this->month < day.get_month()) return true;
  if (this->month > day.get_month()) return false;
  return this->day < day.get_day();
}

bool Date::operator<=(const Date& day) const
{
  return !(*this > day);
}

string Date::to_string() const
{
  ostringstream out;
  out << this->month << "/" << this->day << "/" << this->year;
  return out.str();
}

ostream& operator<<(ostream& out, const Date& date)
{
  return out << date.to_string();
}

istream& operator>>(istream& in, Date& date)
{
  int year, month, day;
  char slash;
  in >> month >> slash >> day >> slash >> year;
  date = Date(year, month, day);
  return in;
}
