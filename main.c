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
    struct date input_date;
    input_date = InputDate();

    int amountOfDays = day_of_the_year(input_date);

    // Ausgabe
    printf("Day of year: %d", amountOfDays);
    return 0;
}
