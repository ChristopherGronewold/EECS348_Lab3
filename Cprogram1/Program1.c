#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MONTH_COUNT 12
#define MAX_LINE_LENGTH 100

void read_sales(float sales[MONTH_COUNT]);
void print_sales(float sales[MONTH_COUNT], char month_names[12][15]);
void print_summary(float sales[MONTH_COUNT], char month_names[12][15]);
void print_moving_averages(float sales[MONTH_COUNT], char month_names[12][15]);
void print_sorted_sales(float sales[MONTH_COUNT], char month_names[12][15]);

int main()
{
    float sales[MONTH_COUNT];
    char month_names[12][15] = {"January", "February", "March", "April",
    		"May", "June", "July", "August", "September", "October",
			"November", "December"};
    read_sales(sales);
    print_sales(sales, month_names);
    print_summary(sales, month_names);
    print_moving_averages(sales, month_names);
    print_sorted_sales(sales, month_names);
    return 0;
}

void read_sales(float sales[MONTH_COUNT])
{
    FILE *fp;
    int i = 0;
    fp = fopen("input.txt", "r");
    while (fscanf(fp, "%f", &sales[i]) != EOF)
    {
        i++;
    }
    fclose(fp);
}

void print_sales(float sales[MONTH_COUNT], char month_names[12][15])
{
    int i;

    printf("Monthly sales report for 2022\n");
    printf("Month      Sales\n");
    for (i = 0; i < MONTH_COUNT; i++) {
        printf("%-11s$%-11.2f\n", month_names[i], sales[i]);
    }
}

void print_summary(float sales[MONTH_COUNT], char month_names[12][15])
{
    int i;
    int min = 0;
    int max = 0;
    float sum = 0;
    for (i = 0; i < MONTH_COUNT; i++)
    {
        if (sales[i] < sales[min])
        {
            min = i;
        }
        if (sales[i] > sales[max])
        {
            max = i;
        }
        sum += sales[i];
    }
    printf("\nSales Summary\n");
    printf("Minimum sales: $%.2f (%s)\n", sales[min], month_names[min]);
    printf("Maximum sales: $%.2f (%s)\n", sales[max], month_names[max]);
    printf("Average sales: $%.2f\n", sum / MONTH_COUNT);
}

void print_moving_averages(float sales[MONTH_COUNT], char month_names[12][15])
{
    int i;
    float sum;
    printf("\nSix-Month Moving Average Report:\n");
    for (i = 0; i < MONTH_COUNT - 5; i++)
    {
        sum = sales[i] + sales[i + 1] + sales[i + 2] + sales[i + 3] + sales[i + 4] + sales[i + 5];
        printf("%-11s - %-11s $%.2f\n", month_names[i], month_names[i+5], sum / 6);
    }
}

void print_sorted_sales(float sales[MONTH_COUNT], char month_names[12][15])
{
    int i, j, p;
    int max = -1;
    int printed[15];
    int in_printed;
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month       Sales\n");
    for (i = 0; i < MONTH_COUNT; i++)
    {
    	max = -1;
        for (j = 0; j < MONTH_COUNT; j++)
        {
        	in_printed = 0;
        	for (p = 0; p < 15; p++) {
        		if (printed[p] == j) {
        			in_printed = 1;
        		}
        	}
        	if (max == -1) {
        		if (in_printed == 0) {
                    max = j;
        		}
        	}
        	else if ((sales[j] > sales[max]) && in_printed == 0)
            {
                max = j;
            }
        }
        printed[i] = max;
        printf("%-11s $%.2f\n", month_names[max], sales[max]);
    }
}
