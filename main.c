#include <stdio.h>
#include <stdlib.h> // To include system("cls")
#include <string.h>
#include <ctype.h> // Include ctype.h for the toupper function

// Define constants for the maximum number of days and entries
#define MaximumDays 31
#define MaxEntries 2

// Global variables for financial management
int dayOfMonth;
float balance, totalExpenses, monthlyIncome, totalIncome;
char answer1;
int targetDay;
char answer3;

// Define a structure to hold expense details
typedef struct {
    int dayOfMonth;
    char category[30];
    float amount;
} Expense;

// Declare a 2D array of Expense to hold expenses for each day
Expense expenses[MaximumDays][MaxEntries];

// Function prototypes
float Income();
void monthlyReport();
void investmentPlans();
void checkExpenses();
void enterExpenses();
void ReturnOrExit();
void checkElectricityBill();
void water_bill();
void ReturnOrExit();

// Main function: displays the user menu and handles user input
int main() {
    int choice;
    do {
        system("cls"); // Clear the screen for a clean menu display
        printf("\n\t\t\t**************************************\n");
        printf("\t\t\t***** Finance Management System ******\n");
        printf("\t\t\t**************************************\n\n");

        // Menu options for the user
        printf("\t1. Enter Expenses\n\n");
        printf("\t2. Check Current Bill for Units\n\n");
        printf("\t3. Check Water Bill for Units\n\n");
        printf("\t4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch case to navigate through user choices
        switch (choice) {
            case 1:
                enterExpenses(); // Enter expenses
                break;
            case 2:
                checkElectricityBill(); // Check electricity bill
                break;
            case 3:
                water_bill(); //check water bill 
                break;
            case 4:
                printf ("\n\tThank you for using the Financial Management System! \n\n\n");
                break;
            default:
                printf("\t\n\nInvalid choice. Please enter a number between 1 and 4.\n\n\n");
        }
    } while (choice != 4);

    return 0; // End of program
}



// Function to generate a monthly report of finances
void monthlyReport() {
    printf("\n\t\t -------- Monthly Report -------- \n");
    printf(" Total income = %.2f \n Total expenses = %.2f \n Remaining balance = %.2f \n", totalIncome, totalExpenses, balance);

    investmentPlans(); // Suggest investment plans based on remaining balance
}



// Function to get the user's monthly income
float Income() {
    float monthlyIncome;
    printf("\nEnter monthly income: Rs.");
    scanf("%f", &monthlyIncome);
    return monthlyIncome;
}



// Function for the user to enter expenses
void enterExpenses() {
    totalExpenses = 0; // Reset total expenses
    totalIncome = Income(); // Get monthly income

    while (1) {
        system("cls"); // Clear the screen
        printf("\n\t---- Enter your expenses (Day / Expense Category / Amount) ----\n\n");

        // Collect expense details from the user
        printf("Day of month: ");
        scanf("%d", &dayOfMonth);

        // Validate the day of the month
        if (dayOfMonth <= 0 || dayOfMonth > MaximumDays) {
            printf("Invalid day. Please enter a day between 1 and %d.\n", MaximumDays);
            continue;
        }

        // Find an empty slot for the new expense entry
        int Entries = 0;
        while (Entries < MaxEntries && expenses[dayOfMonth - 1][Entries].dayOfMonth != 0) {
            Entries++;
        }

        // Check if the day's entries are full
        if (Entries >= MaxEntries) {
            printf("Maximum entries for the day %d reached.\n", dayOfMonth);
            break;
        }

        // Record the expense
        expenses[dayOfMonth - 1][Entries].dayOfMonth = dayOfMonth;
        printf("\nEnter Expense Category: \n");
        printf("\t Food  |  Pets  |  Groceries  |  Transport  |  Health\n");
        scanf("%s", expenses[dayOfMonth - 1][Entries].category);
        printf("Enter amount: Rs.");
        scanf("%f", &expenses[dayOfMonth - 1][Entries].amount);

        // Update total expenses
        totalExpenses += expenses[dayOfMonth - 1][Entries].amount;

        // Ask the user if they want to add another expense
        printf("\nDo you want to add another expense? (Y/N)");
        scanf(" %c", &answer1);
        if (toupper(answer1) == 'N') {
            break; // Exit the loop if the user does not want to add more expenses
        } else if (toupper(answer1) != 'Y') {
            printf("Invalid input. Please enter 'Y' for Yes, or 'N' for No.\n");
        }
    }

    // Update the balance and call checkExpenses to continue
    balance = totalIncome - totalExpenses;
    checkExpenses();
}



// Function to check expenses for a specific day
void checkExpenses() {
    char answer2; // Use a different variable to avoid confusion
    do {
        system("cls"); // Clear the screen
        printf("\n\tDo you want to check expenses for a specific day? (Y/N): ");
        scanf(" %c", &answer2);

        if (toupper(answer2) == 'Y') {
            printf("Enter the day: ");
            scanf("%d", &targetDay);

            // Validate the day
            if (targetDay < 1 || targetDay > MaximumDays) {
                printf("Invalid date. Please enter a date between 1 and %d.\n", MaximumDays);
            } else {
                // Display expenses for the selected day
                printf("Expenses for day %d:\n", targetDay);
                int found = 0; // Flag to check if any expenses were found
                for (int i = 0; i < MaxEntries; i++) {
                    if (expenses[targetDay - 1][i].dayOfMonth == targetDay) {
                        found = 1; // Mark as found
                        printf("\tCategory: %s, Amount: Rs.%.2f\n", expenses[targetDay - 1][i].category, expenses[targetDay - 1][i].amount);
                    }
                }
                if (!found) {
                    printf("\tNo expenses recorded for this day.\n");
                }
            }
        }
    } while (toupper(answer2) == 'Y'); // Loop if the user wants to check another day

    // Call monthlyReport if the user does not want to check more expenses
    if (toupper(answer2) == 'N') {
        monthlyReport();
    }
}




// Function to return to the main menu or exit the program
void ReturnOrExit() {
    char choice;
    do {
        printf("\nDo you want to return to the main menu? (Y/N): ");
        scanf(" %c", &choice);
        choice = toupper(choice); // Convert choice to uppercase for consistency

        if (choice == 'Y') {
            main(); // Call main to return to the menu
            break;
        } else if (choice == 'N') {
            printf("\nThank you for using the Financial Management System!\n");
            exit(0); // Exit the program
        } else {
            printf("Invalid choice. Please enter 'Y' for Yes, or 'N' for No.\n");
        }
    } while (choice != 'Y' && choice != 'N'); // Loop until a valid choice is made
}



// Electricity Bill Calculater

void checkElectricityBill() { 

 printf("Electricity Tariff Revision\n");

    printf("----------------------------------------------------------------------------------\n");
    printf("Block\t\t\tEnergy Charge (Rs. /kWh)\tFixed Charge (Rs. /Month)\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Consumption 0 - 60 kWh per month\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Block 1 : 0 - 30 kWh\t8.00\t\t\t\t120.00\n");
    printf("Block 2 : 31 - 60 kWh\t10.00\t\t\t\t240.00\n\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Consumption above 60 kWh per month\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("Block 1 : 0 - 60 kWh\t16.00\t\t\t\tN/A\n");
    printf("Block 2 : 61 - 90 kWh\t16.00\t\t\t\t360.00\n");
    printf("Block 3 : 91 - 120 kWh\t50.00\t\t\t\t960.00\n");
    printf("Block 4 : 121 - 180 kWh\t50.00\t\t\t\t960.00\n");
    printf("Block 5 : Above 180 kWh\t75.00\t\t\t\t1500.00\n");
    printf("----------------------------------------------------------------------------------\n");

    const int charge0_30 = 8;   // Rs/kWh
    const int charge31_60 = 10;   // Rs/kWh

    const int charge0_60 = 16;   // Rs/kWh
    const int charge61_91 = 16;   // Rs/kWh
    const int charge91_120 = 50;   // Rs/kWh
    const int charge121_180 = 50;   // Rs/kWh
    const int chargeAbove180 = 75;   // Rs/kWh

    const int fixed0_30 = 120;   // Rs/Month
    const int fixed31_60 = 240;   // Rs/Month

    const int fixed0_60 = 0;   // Rs/Month
    const int fixed61_90 = 360;   // Rs/Month
    const int fixed91_120 = 960;   // Rs/Month
    const int fixed121_180 = 960;   // Rs/Month
    const int fixedAbove180 = 1500;   // Rs/Month

    printf("\nElectricity Bill Calculator\n");

    int previousReading, currentReading, totalUnits, totalAmount;
    char calculateAnother;

    do {
        do {
            printf("\nEnter Your Previous Meter Reading (Integer) : ");
            scanf("%d", &previousReading);

            printf("\n(Note: Current reading should be greater than previous reading.)\n");
            printf("Enter Your Current Meter Reading (Integer) : ");
            scanf("%d", &currentReading);

        // Check if current reading is greater than previous reading
        } while (currentReading < previousReading);

        totalUnits = currentReading - previousReading;

        printf("Total Units : %d\n", totalUnits);

        if (totalUnits > 0 && totalUnits <= 60) {
            printf("Consumption 0 - 60 kWh per month\n");

            if (totalUnits <= 30) {
                totalAmount = (totalUnits * charge0_30) + fixed0_30;
            } else {
                totalAmount = (30 * charge0_30) + ((totalUnits - 30) * charge31_60) + fixed31_60;
            }

        } else if (totalUnits > 60 && totalUnits <= 180) {
            printf("Consumption above 60 kWh per month\n");
            if (totalUnits <= 60) {
                totalAmount = (totalUnits * charge0_60) + fixed0_60;
            } else if (totalUnits <= 90) {
                totalAmount = (60 * charge0_60) + ((totalUnits - 60) * charge61_91) + fixed61_90;
            } else if (totalUnits <= 120) {
                totalAmount = (60 * charge0_60) + (30 * charge61_91) + ((totalUnits - 90) * charge91_120) + fixed91_120;
            } else if (totalUnits <= 180) {
                totalAmount = (60 * charge0_60) + (30 * charge61_91) + (30 * charge91_120) + ((totalUnits - 120) * charge121_180) +  fixed121_180;
            }
        } else if (totalUnits > 180) {
            printf("Consumption above 180 kWh per month\n");
            totalAmount = (totalUnits * chargeAbove180) + fixedAbove180;
        }
        printf("----------------------------------------------------------------------------------\n");
        printf("\nTotal Amount: Rs. %d/=\n", totalAmount);
        printf("----------------------------------------------------------------------------------\n");
        do {
            printf("\nDo you want to calculate another bill? (Y/N): ");
            scanf(" %c", &calculateAnother);

            if (calculateAnother != 'Y' && calculateAnother != 'y' && calculateAnother != 'N' && calculateAnother != 'n') {
                printf("Invalid input. Please enter either Y or N.\n");
            }

        } while (calculateAnother != 'Y' && calculateAnother != 'y' && calculateAnother != 'N' && calculateAnother != 'n');

    } while (calculateAnother == 'Y' || calculateAnother == 'y');

    printf("\nThank you for using the Electricity Bill Calculator!\n");
    ReturnOrExit();

}   


void water_bill() {
    // Define  arrays
    int usage_charges[] = {60, 80, 100, 110, 130, 160, 180, 210, 240, 270, 300};
    int service_charges[] = {300, 300, 300, 400, 500, 600, 1500, 3000, 3500, 4000, 4500};
    int units_range[] = {6, 11, 16, 21, 26, 31, 41, 51, 76, 101};
    int units[] = {5,5,5,5,5,5,10,10,25,25};

    // Input: month
    char month[10];

    printf("Enter month: ");
    scanf("%s", month);


    //Display the last month meter reading
    char input_yn;
    printf("Do you want to know last month's meter reading?\nPlease enter (Y/N): ");
    scanf(" %c", &input_yn);

    while (input_yn == 'y' || input_yn == 'Y') {
        FILE *flmr;
        flmr = fopen("last_reading.txt", "r");
        char last_reading[100];

        if (flmr == NULL) {
            printf("Sorry, No readings in the file\n");
            break;
        } else {
            fscanf(flmr, "%s", last_reading);
            printf("Last month's meter reading: %s\n", last_reading);
            fclose(flmr);
            break;
        }
    }

    // Input: last month's meter reading and current month's meter reading
    int lastMonthReading, currentMonthReading;

    printf("\nEnter last month's meter reading: ");
    scanf("%d", &lastMonthReading);

    printf("Enter current month's meter reading: ");
    scanf("%d", &currentMonthReading);

    // Calculate the units consumed
    int units_consumed = currentMonthReading - lastMonthReading;
    int length = sizeof(units_range) / sizeof(units_range[0]);

    // Find the appropriate rate and service charge based on units consumed
    int rate, service_charge;
    int usage_charge = 0 , sumunits= 0;
    for (int i = 0; i <= length; i++) {
        if (units_consumed < units_range[i]) {
            service_charge = service_charges[i];
            usage_charge = usage_charge + (units_consumed-sumunits)*usage_charges[i];
            break;
        }else{
            usage_charge = usage_charge + units[i]*usage_charges[i];
            sumunits = sumunits + units[i];
        }
    }


    // Calculate the total bill
    int totalBill = usage_charge + service_charge;

    // Display the result
    printf("\n%s Water Bill Details:\n\n", month);
    printf("\tUnits Consumed: %d\n", units_consumed);
    printf("\tUsage Charge: Rs.%d.00\n", usage_charge);
    printf("\tService Charge: Rs.%d.00\n", service_charge);
    printf("\tTotal Bill: Rs.%d.00\n", totalBill);

    // Update the file with the current month's reading
    FILE *flmr = fopen("last_reading.txt", "w");
    if (flmr != NULL) {
        fprintf(flmr, "%d", currentMonthReading);
        fclose(flmr);
    }

    // Update the file with monthly repot

    FILE *fwb = fopen("water_bills.txt", "a");
    if (fwb != NULL) {
        fprintf(fwb, "\n%s Water Bill Details:\n\n", month);
        fprintf(fwb, "\tUnits Consumed: %d\n", units_consumed);
        fprintf(fwb, "\tUsage Charge: Rs.%d.00\n", usage_charge);
        fprintf(fwb, "\tService Charge: Rs.%d.00\n", service_charge);
        fprintf(fwb, "\tTotal Bill: Rs.%d.00\n", totalBill);
        fprintf(fwb, "\n");
        fclose(fwb);
    }else{
        printf("Can't print in the file");
    }

}



// Investment Plans

void investmentPlans() {
   
    int bank ,fd_period ,fd_year;
    char answer3;
    float fd_amount ,interest_rate ,interest ,total_interest;
    printf("\n\tDo you want any Financial Investment advice for your Remaining Balance..? (Y/N)  ");
    scanf("%s",&answer3);



    if(answer3=='n' || answer3=='N')
        {
        printf("\n\t\t\t\t\t--*|\t THANK YOU.!\t|*--\n");
            ReturnOrExit();
        }
    else if(answer3=='y' || answer3=='Y')
    { if(balance>=5000){ //if the balance<5000 we can't open a FD.
         LOOP:
        while(1){
        printf("\n\t\t\t\t\tPlease select a Bank for Transactions. \n");
        printf("\n\t\t\t\t\t|\tPeople's Bank - 1\t|\n");
        printf("\t\t\t\t\t|\tBank of Ceylon - 2\t|\n");
        printf("\n\t\t\tEnter Bank Code : ");
        scanf("%d",&bank);
            if(bank>2 || bank<1){
              printf("\n\t\t\t\t* Invalid input. Please enter 1 or 2. *\n");
              continue;
            }
            switch(bank){
                case 1: //People's Bank
                    printf("\t\t\t\t\t\tPEOPLE'S BANK\n");
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 5,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<5000){
                            printf("\n\t* Please enter amount between Rs. 5000.00 /- and Rs. %.2f /- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 9.00 %% \n");
                                        interest_rate=9.00/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 10.50 %% \n");
                                        interest_rate=10.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}

                    break;

                case 2:
                    if(balance>=10000){ //if the balance < 10000 we can't open FD in BOC.
                    printf("\t\t\t\t\t\tBANK OF CEYLON\n"); //Bank of Ceylon.
                    while(1){
                        printf("\n\tYour Remaining Balance is %.2f /-\n",balance);
                        printf("\tPlease enter the amount you wish to deposit (Minimum deposit Rs. 10,000/-) : Rs. ");
                        scanf("%f",&fd_amount);
                        if(fd_amount>balance || fd_amount<10000){
                            printf("\n\t* Please enter amount between Rs. 10000.00 /- and Rs. %.2f/- *\n",balance);
                           continue;}
                        while(1){
                            printf("\n\t\t\t\t\tPlease select the deposit period \n");
                            printf("\n\t\t\t\t\t|\t01 year deposit - 1\t|\n");
                            printf("\t\t\t\t\t|\t02 year deposit - 2\t|\n");
                            printf("\t\t\t\t\t|\t05 year deposit - 3\t|\n");
                            printf("\n\t\t\tEnter Deposit Code : ");
                            scanf("%d",&fd_period);
                                if(fd_period>3 || fd_period<1){
                                    printf("\n\t\t\t\t* Invalid input. *");
                                continue;}
                                    switch(fd_period){
                                    case 1:
                                        printf("\n\t\tInterest rate is \t= 8.00 %% \n");
                                        interest_rate=8.00/100;
                                        fd_year=1;
                                        break;
                                    case 2:
                                        printf("\n\t\tInterest rate is \t= 8.50 %% \n");
                                        interest_rate=8.50/100;
                                        fd_year=2;
                                        break;
                                    case 3:
                                        printf("\n\t\tInterest rate is \t= 9.50 %% \n");
                                        interest_rate=9.50/100;
                                        fd_year=5;
                                        break;
                                    }
                        break;}

                    break;}
                    break;
                    }else
                    printf("\n\t\t** You don't have enough balance to go for a INVESTMENT PLAN in BOC Bank. **\n"); goto LOOP;
                }

        break; }

    interest=fd_amount*interest_rate;
    printf("\t\tThe Annual Interest you get for a deposit of Rs. %.2f /- is \t= Rs. %.2f /-\n",fd_amount ,interest);
        total_interest=fd_year*interest;
    printf("\t\tTotal Interest after %d year/years \t\t\t\t\t= Rs. %.2f /-\n\n",fd_year ,total_interest);
    printf("\n\t\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
    ReturnOrExit();

    }
    } else {
        printf("\n\t\t** You don't have enough balance to go for an INVESTMENT PLAN. **\n");
        printf("\n\t\t\t\t----*|\t  THANK YOU.!\t|*----\n\n");
        ReturnOrExit();
    }
}



   