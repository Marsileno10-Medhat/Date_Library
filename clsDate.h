#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "clsString.h"
using namespace std;

class clsDate {
private:
    short _Year, _Month, _Day;

public:
    clsDate() {};

    clsDate(short Year, short Month, short Day) {
        _Year = Year;
        _Month = Month;
        _Day = Day;
    }

    clsDate(string Date /*"YYYY/MM/DD"*/, string DateDelim = "/") {
        vector<string> vDate = clsString::Split(Date, DateDelim);
        _Year = stoi(vDate.at(0));
        _Month = stoi(vDate.at(1));
        _Day = stoi(vDate.at(2));
    }

    /// @brief set a value to the private member year
    void setYear(short Year) {
        _Year = Year;
    }

    /// @brief return the private member year value
    short getYear() {
        return _Year;
    }

    /// @brief set a value to the private member month
    void setMonth(short Month) {
        _Month = Month;
    }

    /// @brief return the private member month value
    short getMonth() {
        return _Month;
    }

    /// @brief set a value to the private member day
    void setDay(short Day) {
        _Day = Day;
    }

    /// @brief return the private member day value
    short getDay() {
        return _Day;
    }

    /// @brief checking if the year is a leap year or not
    static bool IsLeapYear(short Year) {
        return (Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
    }

    bool IsLeapYear() {
        return IsLeapYear(_Year);
    }

    /// @brief return the number of days in the year
    static short DaysInYear(short Year) {
        return (IsLeapYear(Year))? 366 : 365;
    }

    short DaysInYear() {
        return DaysInYear(_Year);
    }

    /// @brief return the number of hours in the year
    static short HoursInYear(short Year) {
        return DaysInYear(Year) * 24;
    }

    short HoursInYear() {
        return HoursInYear(_Year);
    }

    /// @brief return the number of minutes in the year
    static int MinutesInYear(short Year) {
        return HoursInYear(Year) * 60;
    }

    int MinutesInYear() {
        return MinutesInYear(_Year);
    }

    /// @brief return the number of seconds in the year
    static int SecondsInYear(short Year) {
        return MinutesInYear(Year) * 60;
    }

    int SecondsInYear() {
        return SecondsInYear(_Year);
    }

    /// @brief return the number of days in the month
    static short DaysInMonth(short Year, short Month) {
        if (Month < 1 || Month > 12) {
            return 0;
        }
        const short NumberOfDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (Month == 2)? ((IsLeapYear(Year))? 29 : 28) : NumberOfDays[Month - 1];
    }

    short DaysInMonth() {
        return DaysInMonth(_Year, _Month);
    }

    /// @brief return the number of hours in the month
    static short HoursInMonth(short Year, short Month) {
        return DaysInMonth(Year, Month) * 24;
    }

    short HoursInMonth() {
        return HoursInMonth(_Year, _Month);
    }

    /// @brief return the number of minutes in the month
    static int MinutesInMonth(short Year, short Month) {
        return HoursInMonth(Year, Month) * 60;
    }

    int MinutesInMonth() {
        return MinutesInMonth(_Year, _Month);
    }

    /// @brief return the number of seconds in the month
    static int SecondsInMonth(short Year, short Month) {
        return MinutesInMonth(Year, Month) * 60;
    }

    int SecondsInMonth() {
        return SecondsInMonth(_Year, _Month);
    }

    /// @brief return the day order in the week
    static short DayOrder(short Year, short Month, short Day = 1) {
        short a = (14 - Month) / 12;
        short y = Year - a;
        short m = Month + 12 * a - 2;
        return ((Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7);
    }

    static short DayOrder(clsDate Date) {
        return DayOrder(Date.getYear(), Date.getMonth(), Date.getDay());
    }

    short DayOrder() {
        return DayOrder(_Year, _Month, _Day);
    }

    /// @brief check if the date is valid or not
    static bool IsValidDate(clsDate Date) {
        short Day = Date.getDay();
        short Month = Date.getMonth();
        short Year = Date.getYear();

        if (Year < 1) {
            return false;
        }
        if (Month > 12 || Month < 1) {
            return false;
        }
        if (Day > DaysInMonth(Year, Month) || Day < 1) {
            return false;
        }
        return true;
    }

    bool IsValidDate() {
        return IsValidDate(*this);
    }

    /// @brief check if the date is valid or not
    static bool IsValidDate(short Year, short Month, short Day) {
        if (Year < 1) {
            return false;
        }
        if (Month >= 12 && Month <= 1) {
            return false;
        }
        if (Day > DaysInMonth(Year, Month) && Day < 1) {
            return false;
        }
        return true;
    }

    /// @brief check if the Day is valid or not
    static bool IsValidDay(short Day, short Month, short Year) {
        return (Day > DaysInMonth(Year, Month) || Day < 1)? false : true;
    }

    /// @brief check if the Day is valid or not
    static bool IsValidDay(clsDate Date) {
        short Day = Date.getDay();
        return (Day > DaysInMonth(Date.getYear(), Date.getMonth()) || Day < 1)? false : true;
    }

    bool IsValidDay() {
        return IsValidDay(*this);
    }

    /// @brief check if the Month is valid or not
    static bool IsValidYear(short Year) {
        return (Year >= 1)? true : false;
    }

    bool IsValidYear() {
        return IsValidYear(_Year);
    }

    /// @brief check if the Month is valid or not
    static bool IsValidMonth(short Month) {
        return (Month > 12 || Month < 1)? false : true;
    }

    bool IsValidMonth() {
        return IsValidMonth(_Month);
    }

    /// @brief return the short day name depending on the day order on the week
    static string DayShortName(short DayOfWeek) {
        string Days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
        return Days[DayOfWeek];
    }

    string DayShortName() {
        return DayShortName(DayOrder());
    }

    /// @brief return the short month name
    static string MonthShortName(short Month) {
        string Months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        return Months[Month];
    }

    string MonthShortName() {
        return MonthShortName(_Month);
    }

    /// @brief print monthly table calender
    static void PrintMonthlyCalender(short Year, short Month) {
        printf("  _______________[%s]_______________\n", MonthShortName(Month).c_str());
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        short CurrentDay = DayOrder(Year, Month);
        short DaysNumber = DaysInMonth(Year, Month);
        short i;

        for (i = 0; i < CurrentDay; i++) {
            printf("     ");
        }

        for (short x = 1; x <= DaysNumber; x++) {
            printf("%5d", x);
            
            if (++i == 7) {
                i = 0;
                printf("\n");
            }
        }
        printf("\n  __________________________________\n\n");
    }

    void PrintMonthlyCalender() {
        PrintMonthlyCalender(_Year, _Month);
    }

    /// @brief print yearly table calender
    static void PrintYearlyCalendar(short Year) {
        printf("\n  _________________________________\n");
        printf("\n           calendar - %d", Year);
        printf("\n  _________________________________\n\n");
        
        for (short i = 0; i < 12; i++) {
            PrintMonthlyCalender(Year, i);
        }
    }

    void PrintYearlyCalendar() {
        return PrintYearlyCalendar(_Year);
    }

    /// @brief return days number from the beginning of the year specific day.
    static short DaysFromBeginingOfYear(short Year, short Month, short Day) {
        if (!IsValidDate(Year, Month, Day)) {
            cout << "Invalid date value, non-existent date.";
        }

        short TotalDays = 0;
        for (short i = 1; i <= Month - 1; i++) {
            TotalDays += DaysInMonth(Year, i);
        }
        TotalDays += Day;
        return TotalDays;
    }

    short DaysFromBeginingOfYear() {
        return DaysFromBeginingOfYear(_Year, _Month, _Day);
    }

    /// @brief convert days number in year to a date within the same year
    // static clsDate ConvertTotalDaysToDateSameYear(short TotalDays, short Year) {

    //     short RemainingDays = TotalDays;
    //     short DaysInCurrentMonth = 0;
    //     short Month = 1;

    //     while (true) {
    //         DaysInCurrentMonth = DaysInMonth(Year, Month);

    //         if (DaysInCurrentMonth < RemainingDays) {
    //             RemainingDays -= DaysInCurrentMonth;
    //             Month++;
    //         }
    //         else {
    //             break;
    //         }
    //     }
    //     return clsDate(Year, Month, RemainingDays);
    // }

    // convert days number in year to a date
    static clsDate ConvertTotalDaysToDate(short TotalDays, short Year) {

        short RemainingDays = TotalDays;
        short DaysInCurrentMonth = 0;
        short Month = 1;

        if (TotalDays <= 0) {
            return clsDate(Year, 1, 1);
        }
        while (true) {
            DaysInCurrentMonth = DaysInMonth(Year, Month);

            if (DaysInCurrentMonth < RemainingDays) {

                RemainingDays -= DaysInCurrentMonth;
                if (Month == 12) {
                    Month = 1;
                    Year++;
                }
                else {
                    Month++;
                }
            }
            else {
                break;
            }
        }
        return clsDate(Year, Month, RemainingDays);
    }

    /// @brief add days to a date
    static clsDate AddDays(short DaysToAdd, clsDate& Date) {
        if (!IsValidDate(Date)) {
            cout << "Invalid date value, non-existent date.";
        }
        short TotalDays = DaysFromBeginingOfYear(Date.getYear(), Date.getMonth(), Date.getDay());
        return ConvertTotalDaysToDate(TotalDays, Date.getYear());
    }

    void AddDays(short DaysToAdd) {
        *this = AddDays(DaysToAdd, *this);
    }

    /// @brief checking if date1 before date2
    static bool IsDate1BeforeDate2(clsDate& Date1, clsDate& Date2) {
        if (!IsValidDate(Date1)) {
            cout << "Invalid date1 value, non-existent date.";
        }
        if (!IsValidDate(Date2)) {
            cout << "Invalid date2 value, non-existent date.";
        }
        short Year1 = Date1.getYear();
        short Month1 = Date1.getMonth();
        short Day1 = Date1.getDay();

        short Year2 = Date2.getYear();
        short Month2 = Date2.getMonth();
        short Day2 = Date2.getDay();

        if (Year1 < Year2) {
            return true;
        }
        else if (Year1 == Year2) {
            if (Month1 < Month2) {
                return true;
            }
            else if (Month1 == Month2) {
                if (Day1 > Day2) {
                    return true;
                }
            }
        }
        return false;
    }

    bool IsDate1BeforeDate2(clsDate& Date2) {

        return IsDate1BeforeDate2(*this, Date2); 
    }

    /// @brief checking if date1 equals date2
    static bool IsDate1EqulasDate2(clsDate& Date1, clsDate& Date2) {
        if (!IsValidDate(Date1)) {
            cout << "Invalid date1 value, non-existent date.";
        }
        if (!IsValidDate(Date2)) {
            cout << "Invalid date2 value, non-existent date.";
        }
        return (Date1.getYear() == Date2.getYear() && Date1.getMonth() == Date2.getMonth() && Date1.getDay() == Date2.getDay());
    }

    bool IsDate1EqulasDate2(clsDate Date2) {
        return IsDate1EqulasDate2(*this, Date2);
    }

    /// @brief checking if the month is december which is the last month in the year
    static bool IsLastMonthInYear(short Month) {
        return (Month == 12);
    }

    bool IsLastMonthInYear() {
        return IsLastMonthInYear(_Month);
    }

    /// @brief checking if the day is the last day in month
    static bool IsLastDayInMonth(clsDate& Date) {
        return (Date.getDay() == DaysInMonth(Date.getYear(), Date.getMonth()));
    }

    bool IsLastDayInMonth() {
        return IsLastDayInMonth(*this);
    }

    static bool IsDate1AfterDate2(clsDate& Date1, clsDate& Date2) {
        return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqulasDate2(Date1, Date2));
    }

    bool IsDate1AfterDate2(clsDate& Date2) {
        return IsDate1AfterDate2(*this, Date2);
    }

    /// @brief increase the date with only 1 day
    static clsDate IncreaseByOneDay(clsDate Date) {
        if (!IsValidDate(Date)) {
            cout << "Invalid date value, non-existent date.";
        }

        short Day = Date.getDay();
        short Month = Date.getMonth();
        short Year = Date.getYear();

        if (IsLastDayInMonth(Date)) {
            
            Day = 1;
            if (IsLastMonthInYear(Month)) {
                Year++;
                Month = 1;
            }
            else {
                Month++;
            }
        }
        else {
            Day++;
        }
        return clsDate(Year, Month, Day);
    }

    void IncreaseByOneDay() {
        *this = IncreaseByOneDay(*this);
    }

    static void Swap(clsDate& Date1, clsDate& Date2) {
        clsDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;
    }

    /// @brief calculate the different in days between date1 and date2
    static int DifferentInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {
        if (!IsValidDate(Date1)) {
            cout << "Invalid date1 value, non-existent date.";
        }
        if (!IsValidDate(Date2)) {
            cout << "Invalid date2 value, non-existent date.";
        }
        short Sign = 1;

        if (IsDate1EqulasDate2(Date1, Date2)) {
            return 0;
        }

        if(IsDate1AfterDate2(Date1, Date2)) {
            Swap(Date1, Date2);
            Sign = -1;
        }
        short Year1 = Date1.getYear();
        short Year2 = Date2.getYear();
        int Days = 0;

        for (short Year = Year1; Year < Year2; Year++) {
            Days += DaysInYear(Year);
        }
        Days += Date2.DaysFromBeginingOfYear() - Date1.DaysFromBeginingOfYear();

        return (IncludeEndDay)? ++Days * Sign : Days * Sign;
    }

    int DifferentInDays(clsDate& Date2, bool IncludeEndDay = false) {
        return DifferentInDays(*this, Date2, IncludeEndDay);
    }

    /// @brief calculate the different in days between date1 and date2 by increasing the day in the oldest date by one day
    static int DifferentInDaysByOne(clsDate& Date1, clsDate& Date2, bool IncludeEndDay = false) {
        int Days = 0;
        short Sign = 1;

        if (IsDate1AfterDate2(Date1, Date2)) {
            Swap(Date1, Date2);
            Sign = -1;
        }
        while (IsDate1BeforeDate2(Date1, Date2)) {
            Days++;
            Date1 = IncreaseByOneDay(Date1);
        }
        return (IncludeEndDay)? ++Days * Sign : Days * Sign;
    }

    int DifferentInDaysByOne(clsDate& Date2, bool IncludeEndDay = false) {
        return DifferentInDaysByOne(*this, Date2, IncludeEndDay);
    }

    static clsDate getSystemTime() {
        time_t t = time(0);
        tm* CurrentTime = localtime(&t);
        return clsDate((CurrentTime->tm_year + 1900), (CurrentTime->tm_mon + 1), (CurrentTime->tm_mday));
    }

    static short AgeInDays(clsDate BirthDate) {
        clsDate CurrentDate = getSystemTime();
        return DifferentInDays(BirthDate, CurrentDate, true);
    }

    /// @brief increase the date by certain number of days
    static clsDate IncreaseByDays(clsDate Date, int DaysToAdd) {
        for (int i = 0; i < DaysToAdd; i++) {
            Date = IncreaseByOneDay(Date);
        }
        return Date;
    }
    
    void IncreaseByDays(int DaysToAdd) {
        *this = IncreaseByDays(*this, DaysToAdd);
    }

    /// @brief increase the date by one weak
    static clsDate IncreaseByOneWeek(clsDate Date) {
        Date = IncreaseByDays(Date, 7);
        return Date;
    }

    void IncreaseByOneWeek() {
        *this = IncreaseByOneWeek(*this);
    }

    /// @brief increase the date by certain number of weeks
    static clsDate IncreaseByWeeks(clsDate Date, short WeeksToAdd) {
        for (int i = 0; i < WeeksToAdd; i++) {
            Date = IncreaseByOneWeek(Date);
        }
        return Date;
    }

    void IncreaseByWeeks(short WeeksToAdd) {
        *this = IncreaseByWeeks(*this, WeeksToAdd);
    }

    /// @brief increase the date by one month
    static clsDate IncreaseByOneMonth(clsDate Date, bool KeepEndOfMonth = false) {
        short Month = Date.getMonth();
        short Year = Date.getYear();
        short Day = Date.getDay();
        short NewDays = 0;

        if (Month == 12) {
            Month = 1;
            Year++;
        }
        else {
            Month++;
        }
        short DaysInCurrentMonth = DaysInMonth(Year, Month);

        if (Day > DaysInCurrentMonth) {
            NewDays = DaysInCurrentMonth;
        }
        else {
            NewDays = Day;
        }

        clsDate UpdatedDate(Year, Month, NewDays);
        if (KeepEndOfMonth && Day > DaysInCurrentMonth) {
            short DifferentDays = Day - DaysInCurrentMonth;
            UpdatedDate = IncreaseByDays(UpdatedDate, DifferentDays);
        }
        return UpdatedDate;
    }

    void IncreaseByOneMonth(bool KeepEndOfMonth = false) {
        *this = IncreaseByOneMonth(*this, KeepEndOfMonth);
    }

    /// @brief increase the date by certain number of months
    static clsDate IncreaseByMonths(clsDate Date, short MonthsToAdd, bool KeepEndOfMonth = false) {
        for (int i = 0; i < MonthsToAdd; i++) {
            Date = IncreaseByOneMonth(Date, KeepEndOfMonth);
        }
        return Date;
    }

    void IncreaseByMonths(short MonthsToAdd, bool KeepEndOfMonth = false) {
        *this = IncreaseByMonths(*this, MonthsToAdd, KeepEndOfMonth);
    }

    /// @brief Increase thee date by one year
    static clsDate IncreaseByOneYear(clsDate Date) {
        Date.setYear(Date.getYear() + 1);
        return Date;
    }

    void IncreaseByOneYear() {
        *this = IncreaseByOneYear(*this);
    }

    /// @brief increase the date by certain number of years
    static clsDate IncreaseByYears(clsDate Date, short YearsToAdd) {
        Date.setYear(Date.getYear() + YearsToAdd);
        return Date;
    }

    void IncreaseByYears(short YearsToAdd) {
        *this = IncreaseByYears(*this, YearsToAdd);
    }

    /// @brief increase the date by one decade
    static clsDate IncreaseByOneDecade(clsDate Date) {
        Date.setYear(Date.getYear() + 10);
        return Date;
    }

    void IncreaseByOneDecade() {
        *this = IncreaseByOneDecade(*this);
    }

    /// @brief increase the date by certain number of decades
    static clsDate IncreaseByDecades(clsDate Date, short DecadesToAdd) {
        Date.setYear(Date.getYear() + (DecadesToAdd * 10));
        return Date;
    }

    void IncreaseByDecades(short DecadesToAdd) {
        *this = IncreaseByDecades(*this, DecadesToAdd);
    }

    /// @brief increase the date by one century
    static clsDate IncreaseByOneCentury(clsDate Date) {
        Date.setYear(Date.getYear() + 100);
        return Date;
    }

    void IncreaseByOneCentury() {
        *this = IncreaseByOneCentury(*this);
    }

    /// @brief Increase te date by one millennium
    static clsDate IncreaseByOneMillennium(clsDate Date) {
        Date.setYear(Date.getYear() + 1000);
        return Date;
    }

    void IncreaseByOneMillennium() {
        *this = IncreaseByOneMillennium(*this);
    }

    /// @brief check if the day is the end of the week
    static bool IsEndOfWeek(clsDate Date) {
        return DayOrder(Date) == 6;
    }

    bool IsEndOfWeek() {
        return IsEndOfWeek(*this);
    }

    /// @brief check if the day is weekend
    static bool IsWeekEnd(clsDate Date) {
        short DayIndex = DayOrder(Date);
        return (DayIndex == 5 || DayIndex == 6);
    }

    bool IsWeekEnd() {
        return IsWeekEnd(*this);
    }

    /// @brief check if the day is business day or work day
    static bool IsBusinessDay(clsDate Date) {
        return !IsWeekEnd(Date);
    }

    bool IsBusinessDay() {
        return IsBusinessDay(*this);
    }

    /// @brief count the remaining days till the end of the week
    static short DaysUntilEndOfWeek(clsDate Date) {
        return 6 - DayOrder(Date);
    }

    short DaysUntilEndOfWeek() {
        return DaysUntilEndOfWeek(*this);
    }

    /// @brief count the remaining days till the end of the month
    static short DaysUntilEndOfMonth(clsDate Date1) {
        short Day = DaysInMonth(Date1.getMonth(), Date1.getYear());
        short Month = Date1.getMonth();
        short Year = Date1.getYear();

        clsDate EndOfMontDate(Year, Month, Day);
        return DifferentInDays(Date1, EndOfMontDate, true);
    }

    short DaysUntilEndOfMonth() {
        return DaysUntilEndOfMonth(*this);
    }

    /// @brief count the remaining days till the end of the year
    static short DaysUntilEndOfYear(clsDate Date1) {
        clsDate EndOfYearDate(Date1.getYear(), 12, 31);
        return DifferentInDays(Date1, EndOfYearDate, true);
    }

    short DaysUntilEndOfYear() {
        return DaysUntilEndOfYear(*this);
    }

    /// @brief calculate the actual vacation days from the weekends only.
    /// Add the public holidays manualy because it's different from country to another
    static short ActualVacationDays(clsDate DateFrom, clsDate DateTo) {
        short DaysCount = 0;
        if (IsDate1AfterDate2(DateFrom, DateTo)) {
            Swap(DateFrom, DateTo);
        }
        while (IsDate1BeforeDate2(DateFrom, DateTo)) {
            if(!IsWeekEnd(DateFrom)) {
                DaysCount++;
            }
            DateFrom = IncreaseByOneDay(DateFrom);
        }
        return DaysCount;
    }

    short ActualVacationDays(clsDate DateTo) {
        return ActualVacationDays(*this , DateTo);
    }

    /// @brief cauculate the vacation return date
    /// @return first working day
    static clsDate VacationReturnDate(clsDate DateFrom, short VacationDays) {
        while (VacationDays > 0) {
            if(IsBusinessDay(DateFrom)) {
                VacationDays--;
            }
                DateFrom = IncreaseByOneDay(DateFrom);
        }
        return DateFrom;
    }

    void CalculateVacationReturnDate(short VacationDays) {
        *this = VacationReturnDate(*this, VacationDays);
    }

    /// @brief check if date1 before, after, or equals date2 using enum.
    enum enDatesCompare {eBefore = -1, eEuqal = 0, eAfter = 1};

    static enDatesCompare CompareDates(clsDate Date1, clsDate Date2) {
        if (IsDate1BeforeDate2(Date1, Date2)) {
            return enDatesCompare::eBefore;
        }
        if (IsDate1EqulasDate2(Date1, Date2)) {
            return enDatesCompare::eEuqal;
        }
        return enDatesCompare::eAfter;
    }

    static string ConvertToString(clsDate Date, string Separator = "/") {
        return to_string(Date.getYear()) + Separator + to_string(Date.getMonth()) + Separator + to_string(Date.getDay());
    }

    string ConvertToString(string Separator = "/") {
        return ConvertToString(*this, Separator);
    }

    /// @brief Convert date to string date
    /// @return the date in string format
    static string FomatStringDate(clsDate Date, string DateForm = "YYYY/MM/DD") {
        string S_Date = "";
        S_Date = clsString::Replace(S_Date, "DD", to_string(Date.getDay()));
        S_Date = clsString::Replace(S_Date, "MM", to_string(Date.getMonth()));
        S_Date = clsString::Replace(S_Date, "YYYY", to_string(Date.getYear()));
        return S_Date;
    }

    string FomatStringDate(string DateForm = "YYYY/MM/DD") {
        return FomatStringDate(*this, DateForm);
    }

    /// @brief Convert string date to numbers date.
    /// @return return the date values as object from the class
    clsDate ConvertStringToDate(string S_Date, string Delim) {
        clsDate Date;
        vector<string> vDate = clsString::Split(S_Date, Delim);

        if (vDate.size() != 3) {
            cout << "\nInvalid date value, non-existent date.\n";
        }

        Date.setYear(stoi(vDate[0]));
        Date.setDay(stoi(vDate[2]));
        Date.setMonth(stoi(vDate[1]));

        if (!IsValidDate(Date)) {
            cout << "Invalid date value, non-existent date.";
        }
        return Date;
    }

};