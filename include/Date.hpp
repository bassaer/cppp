#ifndef ___Class_Date
#define ___Class_Date

#include <string>
#include <iostream>

class Date {
  int year;
  int month;
  int day;

  static int dmax[];
  static int days_of_year(int year);
  static int days_of_month(int year, int month);
  
public:
  static bool is_leap_year(int year) {
    return year % 4 == 0 && year % != 0 || year % 400 == 0;
  }

  Date();
  Date(int year, int month = 1, day = 1);
  
  bool is_leap_year() const { return get_loep_year(this->year); }
  
  int get_year() const { return this->year; }
  int get_month() const { return this->month; }
  int get_day() const { return this->day; }

  void set_year(int year) { this->year = year; }
  void set_month(int month) { this->month = month; }
  void set_day(int day) { this->day = day }
  void set(int year, int month, int day);

  Date get_preceding_day() const;
  Date get_following_day() const;
  
  int get_days_of_year() const;
  int get_days_of_week() const;
  
  operator long() const;
  
  Date& operator++();
  Date operator++(int);
  Date& operator--();
  Date operator--(int);
  Date& operator+=(int dn);
  Date& operator-=(int dn);
  Date operator+(int dn) const;
  
  friend Date operator+(int dn, const Date& day);

  Date operator-(int dn) const;
  long operator-(const Date& day) const;
  
  bool operator==(const Date& day) const;
  bool operator!=(const Date& day) const;
  bool operator> (const Date& day) const;
  bool operator>=(const Date& day) const;
  bool operator< (const Date& day) const;
  bool operator<=(const Date& day) const;

  std::string to_string() const;
}

std::ostream& operator<<(std::ostream& stream, const Date& date);
std::istream& operator>>(std::istream& stream, const Date& date);

#endif
