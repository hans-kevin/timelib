#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

struct date
{
    int year;
    int month;
    int day;
};

int day_of_the_year(struct date input_date);
struct date InputDate();
int is_leapyear(int year);
int get_days_for_month(struct date input_date);
int exists_date(struct date input_date);
int _is_year_valid(int year);


#endif // TIMELIB_H_INCLUDED
