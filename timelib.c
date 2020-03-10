#include "timelib.h"
int day_of_the_year(struct date input_date)
{
    //Errechne den Tag des Jahres. Addiere die vorherigen Tage
    int amountOfDays = 0;
    struct date currentDate;
    currentDate.day = input_date.day;
    currentDate.year = input_date.year;
//    input_date.day = currentDate.day;
//    input_date.year = currentDate.year;
    currentDate.month = 0;
    int i = 0;
    for(i = 0; i < input_date.month - 1; i++)
    {

        currentDate.month = i + 1;
        amountOfDays += get_days_for_month(currentDate);
    }
    amountOfDays += input_date.day;
    return amountOfDays;
}

struct date InputDate()
{
    struct date input_date;
    do
    {
        printf("Please enter a year:\n");
        scanf("%d", &input_date.year);
        printf("Please enter a month:\n");
        scanf("%d", &input_date.month);
        printf("Please enter a day\n");
        scanf("%d", &input_date.day);
    }
    while(exists_date(input_date) == 0);

    return input_date;
}

int is_leapyear(int year)
{
    if(!_is_year_valid(year))
    {
            return -1;
    }
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

int get_days_for_month(struct date input_date)
{
    int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(is_leapyear(input_date.year))
    {
        days_in_months[1] = 29;
    }
    else if(is_leapyear(input_date.year))
    {
        days_in_months[1] = 28;
    }
    return days_in_months[input_date.month -1];
}

int exists_date(struct date input_date)
{
    if(_is_year_valid(input_date.year) == 0) { return 0;}
    if(input_date.month < 1 || input_date.month > 12) {return 0;}
    if(input_date.day < 1 || input_date.day > get_days_for_month(input_date)) {return 0;}
    return 1;
}

int _is_year_valid(int year)
{
    return (year > 1582 && year < 2401);
}
