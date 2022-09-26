// 计算日期
#include <stdio.h>

void get_date(int n) {
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_month2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_year[4] = {366, 365, 365, 365};

    int year = 2000, month = 1;
    while (n > days_in_year[year % 4]) {
        n -= days_in_year[year % 4];
        ++year;
    }

    if (year % 4 != 0) {
        while (n > days_in_month[month]) {
            n -= days_in_month[month];
            ++month;
        } 
    } else {
        while (n > days_in_month2[month]) {
            n -= days_in_month2[month];
            ++month;
        }
    }
    int day = n + 1;
    printf("%d-%d-%d", year, month, day);
}

void get_week(int n) {
    char *names[7] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};
    printf(" %s\n", names[n % 7]);
}

int main() {
    int n;
    printf("input n: ");
    scanf("%d", &n);
    get_date(n);
    get_week(n);
}