#include <stdio.h>
#include <stdbool.h>

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

// Function to add days to a date
void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {
    while (days_left_to_add > 0) {
        int days_this_month = days_in_month[*mm];
        if (*mm == 2 && is_leap_year(*yy)) {
            days_this_month += 1; 
        }

        int days_left_in_month = days_this_month - *dd;

        if (days_left_to_add > days_left_in_month) {
            days_left_to_add -= (days_left_in_month + 1);
            *dd = 1;

            if (*mm == 12) {
                *mm = 1;
                *yy += 1;
            } else {
                *mm += 1;
            }
        } else {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Check Leap Year\n");
    printf("2. Add Days to Date\n");
    printf("Enter 1 or 2: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int year;
        printf("Enter a year between 1800 and 10000: ");
        scanf("%d", &year);

        if (is_leap_year(year))
            printf("Leap Year\n");
        else
            printf("Not Leap Year\n");

    } else if (choice == 2) {
        int mm, dd, yy, days;
        printf("Enter date in format mm dd yyyy and number of days to add: ");
        scanf("%d %d %d %d", &mm, &dd, &yy, &days);

        add_days_to_date(&mm, &dd, &yy, days);
        printf("New date: %d %d %d\n", mm, dd, yy);
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}
