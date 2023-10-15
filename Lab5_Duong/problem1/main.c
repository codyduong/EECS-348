/**
 * Author: Cody Duong 3050266
 * I could've made this multiple files but I always hated dealing with header files in C, so I didn't.
 */

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12
typedef struct
{
  char *month;
  double sales;
} SalesData;

// Read data in
void readSalesData(SalesData *salesData, char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  for (int i = 0; i < MONTHS; i++)
  {
    fscanf(fp, "%lf\n", &salesData[i].sales);
  }

  fclose(fp);
}

// Calculate the minimum, maximum, and average sales
void calculateSalesSummary(SalesData *salesData, SalesData *minSales, SalesData *maxSales, double *avgSales)
{
  *minSales = salesData[0];
  *maxSales = salesData[0];
  *avgSales = 0.0;

  for (int i = 0; i < MONTHS; i++)
  {
    if (salesData[i].sales < minSales->sales)
    {
      minSales->sales = salesData[i].sales;
    }

    if (salesData[i].sales > maxSales->sales)
    {
      maxSales->sales = salesData[i].sales;
    }

    *avgSales += salesData[i].sales;
  }

  *avgSales /= MONTHS;
}

// Calculate the six-month moving averages
void calculateSixMonthMovingAverages(SalesData *salesData, double *sixMonthMovingAverages)
{
  for (int i = 0; i < MONTHS - 5; i++)
  {
    sixMonthMovingAverages[i] = (salesData[i].sales + salesData[i + 1].sales + salesData[i + 2].sales + salesData[i + 3].sales + salesData[i + 4].sales + salesData[i + 5].sales) / 6.0;
  }
}

// Sort the sales data from highest to lowest
void sortSalesDataBySales(SalesData *salesData)
{
  for (int i = 0; i < MONTHS - 1; i++)
  {
    for (int j = i + 1; j < MONTHS; j++)
    {
      if (salesData[i].sales < salesData[j].sales)
      {
        SalesData temp = salesData[i];
        salesData[i] = salesData[j];
        salesData[j] = temp;
      }
    }
  }
}

void printSalesData(SalesData *salesData, char *filename, char *header)
{
  FILE *fp = fopen(filename, "a");
  if (fp == NULL)
  {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  fprintf(fp, "%s\n", header);

  for (int i = 0; i < MONTHS; i++)
  {
    fprintf(fp, "%s\t$%.2f\n", salesData[i].month, salesData[i].sales);
  }

  // Add trailing line
  fprintf(fp, "\n");

  fclose(fp);
}

void printSalesSummaryToFile(SalesData minSalesMonth, SalesData maxSalesMonth, double avgSales, char *filename)
{
  FILE *fp = fopen(filename, "a");
  if (fp == NULL)
  {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  fprintf(fp, "Sales summary:\n");
  fprintf(fp, "Minimum sales:\t$%.2f (%s)\n", minSalesMonth.sales, minSalesMonth.month);
  fprintf(fp, "Maximum sales:\t$%.2f (%s)\n", maxSalesMonth.sales, maxSalesMonth.month);
  fprintf(fp, "Average sales:\t$%.2f\n", avgSales);

  // Add trailing line
  fprintf(fp, "\n");

  fclose(fp);
}

void printSixMonthMovingAveragesReportToFile(double *sixMonthMovingAverages, char *filename)
{
  FILE *fp = fopen(filename, "a");
  if (fp == NULL)
  {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  fprintf(fp, "Six-Month Moving Average Report:\n");
  fprintf(fp, "January\t- June\t$%.2f\n", sixMonthMovingAverages[0]);
  fprintf(fp, "February\t- July\t$%.2f\n", sixMonthMovingAverages[1]);
  fprintf(fp, "March\t- August\t$%.2f\n", sixMonthMovingAverages[2]);
  fprintf(fp, "April\t- September\t$%.2f\n", sixMonthMovingAverages[3]);
  fprintf(fp, "May\t- October\t$%.2f\n", sixMonthMovingAverages[4]);
  fprintf(fp, "June\t- November\t$%.2f\n", sixMonthMovingAverages[5]);
  fprintf(fp, "July\t- December\t$%.2f\n", sixMonthMovingAverages[6]);

  // Add trailing line
  fprintf(fp, "\n");

  fclose(fp);
}

int main()
{
  SalesData salesData[MONTHS] = {
      {"January", 0.0},
      {"February", 0.0},
      {"March", 0.0},
      {"April", 0.0},
      {"May", 0.0},
      {"June", 0.0},
      {"July", 0.0},
      {"August", 0.0},
      {"September", 0.0},
      {"October", 0.0},
      {"November", 0.0},
      {"December", 0.0},
  };
  readSalesData(salesData, "input.txt");

  // Calculate the sales summary
  SalesData minSalesData, maxSalesData;
  double avgSales;
  calculateSalesSummary(salesData, &minSalesData, &maxSalesData, &avgSales);

  // Calculate the six-month moving averages
  double sixMonthMovingAverages[MONTHS - 5];
  calculateSixMonthMovingAverages(salesData, sixMonthMovingAverages);

  // Delete the old output if there is one
  FILE *fp = fopen("output.txt", "r");
  if (fp != NULL)
  {
    // Delete the output.txt file
    fclose(fp);
    remove("output.txt");
  }

  // Print the sales report and sales summary report to files
  printSalesData(salesData, "output.txt", "Monthy sales report for 2022");
  printSalesSummaryToFile(minSalesData, maxSalesData, avgSales, "output.txt");
  printSixMonthMovingAveragesReportToFile(sixMonthMovingAverages, "output.txt");
  // Resort and print the Sales Report
  sortSalesDataBySales(salesData);
  printSalesData(salesData, "output.txt", "Sales Report (Highest to Lowest)");

  return 0;
}