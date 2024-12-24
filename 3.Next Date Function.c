#include <stdio.h>
#include <stdbool.h>

// Function to check if the year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 2: // February
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6: 
        case 9: 
        case 11: // April, June, September, November
            return 30;
        default: // January, March, May, July, August, October, December
            return 31;
    }
}

// Function to calculate the next date
void nextDate(int day, int month, int year) {
    // Validate the year
    if (year < 1812 || year > 2018) {
        printf("Year must be between 1812 and 2018\n");
        return;
    }

    // Validate the month
    if (month < 1 || month > 12) {
        printf("Month must be between 1 and 12\n");
        return;
    }

    // Validate the day
    int daysInMonth = getDaysInMonth(month, year);
    if (day < 1 || day > daysInMonth) {
        printf("Day must be between 1 and %d for month %d in year %d\n", daysInMonth, month, year);
        return;
    }

    // Increment the day
    day++;

    // Handle overflow of days in the current month
    if (day > daysInMonth) {
        day = 1;
        month++; // Move to the next month

        // Handle overflow of months (move to next year if month > 12)
        if (month > 12) {
            month = 1;  // R eset month to January
            year++;     // Move to the next year
        }
    }

    // Ensure the year is still within the valid range
    if (year > 2018) {
        printf("Year exceeds the limit of 2018\n");
    } else {
        printf("Next date is: %02d/%02d/%d\n", day, month, year);
    }
}

int main() {
    int day, month, year;

    // Take user input for the date
    printf("Enter the day, month, year: ");
    scanf("%d %d %d", &day, &month, &year);

    // Call the function to calculate the next date
    nextDate(day, month, year);

    return 0;
}

