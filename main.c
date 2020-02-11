#include <stdio.h>
#include <stdlib.h>

/*
Author: Robin Gerwe & Markus Möhlenkamp
Datum: 2020-02-11
Programm zur Auswertung des Tag des Jahres von einem vorgegebenen Datum

*/

//Funktionen ankündigen
int day_of_the_year(int day, int month, int year);
int is_leapyear(int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int _is_year_valid(int year);

//Anzahl der Tage in den Monaten
int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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



int day_of_the_year(int day, int month, int year)
{
    //Errechne den Tag des Jahres. Addiere die vorherigen Tage
    int amountOfDays = 0;
    int i = 0;
    for(i = 0; i < month - 1; i++)
    {
        amountOfDays += get_days_for_month(i + 1, year);
    }
    amountOfDays += day;
    return amountOfDays;
}

int is_leapyear(int year)
{
    if(!_is_year_valid(year))
    {
            return -1;
    }
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

int get_days_for_month(int month, int year)
{
    if(is_leapyear(year))
    {
        days_in_months[1] = 29;
    }
    else if(is_leapyear(year))
    {
        days_in_months[1] = 28;
    }
    return days_in_months[month -1];
}

int exists_date(int day, int month, int year)
{
    if(!_is_year_valid(year)) { return 0;}
    if(month < 1 || month > 12) {return 0;}
    if(get_days_for_month(month, year) > day || day < 1) {return 0;}
    return 1;
}

int _is_year_valid(int year)
{
    return (year > 1582 && year < 2401);
}
