#include<stdio.h>

int main() 
{ 
    int locks, stocks, barrels, tlocks = 0, tstocks = 0, tbarrels = 0;
    float lprice = 45.0, sprice = 30.0, bprice = 25.0, sales = 0, comm;
    
    printf("Enter the number of locks (-1 to exit):\n");
    while(scanf("%d", &locks) && locks != -1) 
    { 
        if (locks < 1 || locks > 70) {
            printf("Locks must be between 1 and 70\n");
            printf("Enter the number of locks (-1 to exit):\n");
            continue;  // go back to ask for valid locks
        }

        printf("Enter the number of stocks:\n");
        scanf("%d", &stocks);
        if (stocks < 1 || stocks > 80) {
            printf("Stocks must be between 1 and 80\n");
            printf("Enter the number of locks (-1 to exit):\n");
            continue;  // restart input for locks
        }

        printf("Enter the number of barrels:\n");
        scanf("%d", &barrels);
        if (barrels < 1 || barrels > 90) {
            printf("Barrels must be between 1 and 90\n");
            printf("Enter the number of locks (-1 to exit):\n");
            continue;  // restart input for locks
        }

        // Accumulate totals only if all inputs are valid
        tlocks += locks;
        tstocks += stocks;
        tbarrels += barrels;
        
        printf("Total locks = %d, Total stocks = %d, Total barrels = %d\n", tlocks, tstocks, tbarrels);
        
    }

    if(tlocks > 0 && tstocks > 0 && tbarrels > 0) 
    {
        sales = (tlocks * lprice) + (tstocks * sprice) + (tbarrels * bprice);
        printf("Total sales: %.2f\n", sales);

        // Commission Calculation
        if(sales > 1800) 
            comm = 0.10 * 1000 + 0.15 * 800 + 0.20 * (sales - 1800);
        else if(sales > 1000)
            comm = 0.10 * 1000 + 0.15 * (sales - 1000);
        else
            comm = 0.10 * sales;

        printf("Commission: %.2f\n", comm);
    } 
    else 
        printf("No sales\n");

    return 0; 
}
