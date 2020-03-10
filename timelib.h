/**
  * @author Robin Gerwe & Markus Möhlenkamp
  * @date 2020-03-10
  * This program is to compute the amount of days in the year for a give date.
  * It factors in leap years in the Gregorian calendar. See: https://en.wikipedia.org/wiki/Gregorian_calendar
  * Limits the highest year to 2400.
**/

#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int year;
    int month;
    int day;
};

int day_of_the_year(struct date input_date);
struct date input_date();
int is_leapyear(int year);
int get_days_for_month(struct date input_date);
int exists_date(struct date input_date);
int _is_year_valid(int year);


#endif // TIMELIB_H_INCLUDED
