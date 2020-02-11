#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"
/*
Author: Robin Gerwe & Markus Möhlenkamp
Datum: 2020-02-11
Programm zur Auswertung des Tag des Jahres von einem vorgegebenen Datum

*/

int main()
{
    int year = 0;
    int month = 0;
    int day = 0;
    int i = 0;

    // Gebe ein gültiges Jahr ein
    do {
        printf("Please enter a year:\n");
        scanf("%d", &year);
    }
    while(!_is_year_valid(year));

    //Gebe ein gültigen Monat ein
    do
    {
        printf("Please enter a month:\n");
        scanf("%d", &month);
    } while(!(0 < month && month <= 12));

    //Gebe ein gültigen Tag ein
    do
    {
        printf("Please enter a day\n");
        scanf("%d", &day);
    } while(!(day > 0 && day <= get_days_for_month(month, year)));

    int amountOfDays = day_of_the_year(day, month, year);
    //Ausgabe
    printf("Day of year: %d", amountOfDays);
    return 0;
}
