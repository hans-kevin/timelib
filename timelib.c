/**
  * @author Robin Gerwe & Markus Möhlenkamp
  * @date 2020-03-10
  * This program is to compute the amount of days in the year for a give date.
  * It factors in leap years in the Gregorian calendar. See: https://en.wikipedia.org/wiki/Gregorian_calendar
  * Limits the highest year to 2400.
**/

#include "timelib.h"

/**
  * Calculates the day of the year by given date. Adds the days of the month till the current month and then adds the current days.
  * @param inputDate
  * @return amountOfDays
**/
int day_of_the_year(struct date inputDate)
{
    int amountOfDays = 0;
    struct date currentDate;

    currentDate.day = inputDate.day;
    currentDate.year = inputDate.year;
    currentDate.month = 0;

    int i = 0;
    for(i = 0; i < inputDate.month - 1; i++)
    {
        currentDate.month = i + 1;
        amountOfDays += get_days_for_month(currentDate);
    }
    amountOfDays += inputDate.day;
    return amountOfDays;
}

/**
  * Request date till the date is valid.
  * @return inputDate : returns the given date.
**/
struct date input_date()
{
    struct date inputDate;
    do
    {
        printf("Please enter a year:\n");
        scanf("%d", &inputDate.year);
        printf("Please enter a month:\n");
        scanf("%d", &inputDate.month);
        printf("Please enter a day\n");
        scanf("%d", &inputDate.day);
    }
    while(exists_date(inputDate) == 0);

    return inputDate;
}

/**
 * Checks whether a given year is a leap year.
 * see more: https://stackoverflow.com/a/11595914
 * @param year
 * @return -1 if the given year is not valid.
 * @return 0 if the given year is not a leap year.
 * @return 1 if the given year is a leap year.
 **/
int is_leapyear(int year)
{
    if(!_is_year_valid(year))
    {
            return -1;
    }
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

/**
  * Adjusts days of February for leap year and returns the days of the given month.
  * @param inputDate
  * @return days_in_month for the given month.
**/
int get_days_for_month(struct date inputDate)
{
    int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(is_leapyear(inputDate.year))
    {
        days_in_months[1] = 29;
    }
    else if(is_leapyear(inputDate.year))
    {
        days_in_months[1] = 28;
    }
    return days_in_months[inputDate.month -1];
}

/**
  * Checking, if the input date is valid. Checks if Year, Month and Day are in their boundaries.
  * Calls is_year_valid.
  * Checks if the given month id between 1 and 12.
  * Checks if the given day is between 1 and get_days_for_month for the given month.
  * @param inputDate
  * @return 1 if the date is valid.
  * @return 0 if the date is not valid.
**/
int exists_date(struct date inputDate)
{
    if(_is_year_valid(inputDate.year) == 0) { return 0;}
    if(inputDate.month < 1 || inputDate.month > 12) {return 0;}
    if(inputDate.day < 1 || inputDate.day > get_days_for_month(inputDate)) {return 0;}
    return 1;
}

/**
  * Checking, if the year is between 1582 and 2401.
  * @param year
  * @return 1 if the year is valid.
  * @return 0 if the year is not valid.
**/
int _is_year_valid(int year)
{
    return (year > 1582 && year < 2401);
}
