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

    printf("Please enter a year:\n");
    scanf("%d", &year);
    printf("Please enter a month:\n");
    scanf("%d", &month);
    printf("Please enter a day\n");
    scanf("%d", &day);

    input_date(&day, &month, &year);

    int amountOfDays = day_of_the_year(day, month, year);

    // Ausgabe
    printf("Day of year: %d", amountOfDays);
    return 0;
}
