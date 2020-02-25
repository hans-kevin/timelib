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

void input_date(int *day, int *month, int *year)
{

    int dayTemp = *day;
    int monthTemp = *month;
    int yearTemp = *year;

    while(exists_date(dayTemp, monthTemp, yearTemp) == 0)
    {
        printf("Please enter a year:\n");
        scanf("%d", &yearTemp);
        printf("Please enter a month:\n");
        scanf("%d", &monthTemp);
        printf("Please enter a day\n");
        scanf("%d", &dayTemp);
    }

    *day = dayTemp;
    *month = monthTemp;
    *year = yearTemp;
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
    int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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
    if(_is_year_valid(year) == 0) { return 0;}
    if(month < 1 || month > 12) {return 0;}
    if(day < 1 || day > get_days_for_month(month, year)) {return 0;}
    return 1;
}

int _is_year_valid(int year)
{
    return (year > 1582 && year < 2401);
}
