#include <stdio.h>
/*
/  EECS 348 Lab 5: Isaiah Jenks
/  
*/

//////////////// jail for hardcoded constants /////////////////
#define SIZE 12

const double monthSales[SIZE] = {
    23458.01,
    40112.00,
    56011.85,
    37820.88,
    37904.67,
    60200.22,
    72400.31,
    56210.89,
    67230.84,
    68233.12,
    80950.34,
    95225.22
};

const char* monthNames[SIZE] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const int currentYear = 2024;
///////////////////////////////////////////////////////////////

// Display the month and sales in two columns.
void monthlySalesReport(double salesNumbers[SIZE], const char* nameOrder[SIZE], int year) {
    printf("Monthly Sales Report for %d\n", year);
    printf("Month       Sales\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%-11s $%.2f\n", nameOrder[i], salesNumbers[i]);
    }
}

// Show the minimum, maximum, and average monthly sales.
void salesSummaryReport(double sales[SIZE]) {
    double min = sales[0];
    int minIndex = 0;
    double max = sales[0];
    int maxIndex = 0;
    double sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += sales[i];
        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }
    double average = sum / SIZE;

    printf("\nSales summary report:\n");
    printf("Minimum sales:  $%.2f (%s)\n", min, monthNames[minIndex]);
    printf("Maximum sales:  $%.2f (%s)\n", max, monthNames[maxIndex]);
    printf("Average sales:  $%.2f\n", average);
}

// Show the six-month moving average.
void sixMonthMovingAverageReport(double sales[SIZE]) {
    printf("\nSix-Month moving average report:\n");
    for (int i = 0; i <= 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        double average = sum / 6;
        printf("%9s-%-9s    $%.2f\n", monthNames[i], monthNames[i + 5], average);
    }
}

// Display the sales from highest to lowest.
void salesReportHighestToLowest(double sortedSales[SIZE], const char* sortedMonths[SIZE]) { // Initialy unsorted
    printf("\nSales report (highest to lowest):\n");
    printf("Month       Sales\n");

    // Bubble sort the sales in descending order while modifying sortedMonths in parallel to maintain the correct month-sales association
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {
                // Swap sales
                double tempSales = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = tempSales;

                // Swap month names
                const char* tempMonths = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonths;
            }
        }
    }

    // Display the sorted sales
    for (int i = 0; i < SIZE; i++) {
        printf("%-11s $%.2f\n", sortedMonths[i], sortedSales[i]);
    }
}

int main() {
    monthlySalesReport(monthSales, monthNames, currentYear);
    salesSummaryReport(monthSales);
    sixMonthMovingAverageReport(monthSales);
    salesReportHighestToLowest(monthSales, monthNames);

    /*
    Monthly Sales Report for 2024
    Month       Sales
    January     23458.01
    February    40112.00
    March       56011.85
    April       37820.88
    May         37904.67
    June        60200.22
    July        72400.31
    August      56210.89
    September   67230.84
    October     68233.12
    November    80950.34
    December    95225.22

    Sales summary report:
    Minimum sales:  23458.01 (January)
    Maximum sales:  95225.22 (December)
    Average sales:  57979.86

    Six-Month moving average report:
    January-June    42584.61
    February-July   50741.66
    March-August    53424.80
    April-September 55294.64
    May-October     60363.34
    June-November   67537.62
    July-December   73375.12

    Sales report (highest to lowest):
    Month       Sales
    December    $95225.22
    November    $80950.34
    July        $72400.31
    October     $68233.12
    September   $67230.84
    June        $60200.22
    August      $56210.89
    March       $56011.85
    February    $40112.00
    May         $37904.67
    April       $37820.88
    January     $23458.01
    */

    return 0;
}