/**
  * @author Robin Gerwe & Markus Möhlenkamp
  * @date 2020-03-10
  * This program is to compute the amount of days in the year for a give date.
  * It factors in leap years in the Gregorian calendar. See: https://en.wikipedia.org/wiki/Gregorian_calendar
  * Limits the highest year to 2400.
**/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    // date is structured as year, month and day
    struct date inputDate;

    inputDate = input_date();

    int amountOfDays = day_of_the_year(inputDate);

    // Output
    printf("Day of year: %d", amountOfDays);
    return 0;
}
