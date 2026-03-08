#include <stdio.h>

/*
/  EECS 348 Lab 5: Isaiah Jenks
/  This program generates a sales report for a given year, utilizing hardcoded data for
/  monthly sales and month names. It includes functions to display monthly sales,
/  summarize key statistics such as minimum, maximum, and average sales, calculate
/  six-month moving averages, and sort sales data from highest to lowest.
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
void monthlySalesReport(const double salesNumbers[SIZE], const char* nameOrder[SIZE], int year) {
    printf("\nMonthly Sales Report for %d\n\n", year);
    printf("Month       Sales\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%-11s %.2f\n", nameOrder[i], salesNumbers[i]);
    }
}

// Show the minimum, maximum, and average monthly sales.
void salesSummaryReport(const double salesNumbers[SIZE]) {
    double min = salesNumbers[0];
    int minIndex = 0;
    double max = salesNumbers[0];
    int maxIndex = 0;
    double sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += salesNumbers[i];
        if (salesNumbers[i] < min) {
            min = salesNumbers[i];
            minIndex = i;
        }
        if (salesNumbers[i] > max) {
            max = salesNumbers[i];
            maxIndex = i;
        }
    }
    double average = sum / SIZE;

    printf("\nSales summary report:\n\n");
    printf("Minimum sales:  %.2f (%s)\n", min, monthNames[minIndex]);
    printf("Maximum sales:  %.2f (%s)\n", max, monthNames[maxIndex]);
    printf("Average sales:  %.2f\n", average);
}

// Show the six-month moving average.
// To provide practical results the data should be in chronological order
void sixMonthMovingAverageReport(const double salesNumbers[SIZE], const char* nameOrder[SIZE]) {
    printf("\nSix-Month moving average report:\n\n");
    for (int stringIndex = 0; stringIndex <= SIZE - 6; stringIndex++) {
        double sum = 0;

        // Calculate the sum of the next six months of sales starting from month i
        for (int i = stringIndex; i < stringIndex + 6; i++) {
            sum += salesNumbers[i];
        }
        double average = sum / 6;

        // Concatenate the month names for the range of months being averaged
        char monthRange[10 * 2 + 1];
        { // Scope for temporary index variables
            int charIndex = 0;
            while(nameOrder[stringIndex][charIndex] != '\0') {
                monthRange[charIndex] = nameOrder[stringIndex][charIndex];
                charIndex++;
            }
            monthRange[charIndex] = '-';
            int beginNextMonthIndex = charIndex + 1;
            charIndex = 0;
            while(nameOrder[stringIndex + 5][charIndex] != '\0') {
                monthRange[charIndex + beginNextMonthIndex] = nameOrder[stringIndex + 5][charIndex];
                charIndex++;
            }
            monthRange[charIndex + beginNextMonthIndex] = '\0';
        }

        printf("%-21s %.2f\n", monthRange, average);
    }
}

// Display the sales from highest to lowest.
void salesReportHighestToLowest(const double salesNumbers[SIZE], const char* nameOrder[SIZE]) {
    // Create copies for sorting
    double sortedSales[SIZE];
    const char* sortedMonths[SIZE];
    for (int i = 0; i < SIZE; i++) { // Fill the copies
        sortedSales[i] = salesNumbers[i];
        sortedMonths[i] = nameOrder[i];
    }
    
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month       Sales\n");

    // Bubble sort the sales in descending order while modifying sortedMonths in parallel to maintain the correct month-sales association
    for (int i = 0; i < SIZE - 1; i++) { // For each element in the array (except the last one)
        for (int j = 0; j < SIZE - i - 1; j++) { // For each element up to the last unsorted element
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
    printf("\n\n");

    monthlySalesReport(monthSales, monthNames, currentYear);

    salesSummaryReport(monthSales);

    sixMonthMovingAverageReport(monthSales, monthNames);

    salesReportHighestToLowest(monthSales, monthNames);

    printf("\n\n");

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