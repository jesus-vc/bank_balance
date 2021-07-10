//
//  main.c
//
//  Created by Jesus Vasquez-Cipriano on 7/10/21.
//  Copyright © 2021 Jesus Vasquez-Cipriano. All rights reserved.
//

 /* ********************************************
  
 * SUMMARY
 * Function: int main()
 * Input: User inputs various data types to calculate accumulated interest.
 * Output: Returns 0 on success.
 * Procedure: Calculates and displays accumulated interest through a while loop and switch statement that repeatedly calls additional functions based on user input.
  
  * Future Revisions Will Evaluate:
    1. Adjust the rounding of decimal values for each iteration in function show_balance() in order to compute accurate values.
    2. Adjust the return type of pay(), given the return type may be an integer (-1 or -2) or a double. Alternatively, re-structure program to assign pay() with only 1 return type.
    3. Adding code (potentially global variables) that allows the show_balance() function to store and process a continous stream of new borrow and pay inputs. For example, currently, once show_balance() processes successfully the first time, it fails to store current_balance for future user payment and borrow inputs.
  
 ******************************************* */

#include <stdio.h>

int menu(void);
double get_rate(void);
double show_balance(int terms, double amount, double rate);
double pay(double payment_amount, double current_balance);
double borrow(double borrow_amount, double current_balance);

int main() {

    int choice = 0;
    double current_balance = 0.0;
    double result = 0.0;
    int terms = 0;
    double rate = 0.0;
    //Future Revision: Are these two function declarations below necessary, if I integrate global variables above main()?
    double payment_amount = 0.0;
    double borrow_amount = 0.0;
    
    while (choice!=4) {
        choice = menu();
        switch (choice) {
        case 1:
                rate = get_rate();
                printf("Now, give me your terms (# of months borrowing) as an integer number: ");
                scanf("%d",&terms);
                result = show_balance(terms,current_balance,rate);
                printf("Your current balance is: $%.2lf\n", result);
                break;
        case 2:
                printf("How much are you paying?\n");
                scanf("%lf", &payment_amount);
                result = pay(payment_amount,current_balance);
                if (result == -1.00 || result == -2.00) {
                    printf("Invalid Payment Amount: Your payment amount of %lf is either larger than your current balance or a negative number. Try again next time.\n", payment_amount);
                }
                else {
                    current_balance = result;
                    printf("Current balance is now: $%.2lf\n", current_balance);
                }
                break;
        case 3:
                printf("How much are you borrowing?\n");
                scanf("%lf", &borrow_amount);
                result = borrow(borrow_amount,current_balance);
                if (result != -1) {
                    current_balance = result;
                }
                else {
                    printf("Invalid Borrow Amount: Your borrow amount of %lf appears to be a negative number. Try again next time.\n", borrow_amount);
                }
                break;
        }
    }
    puts("Thank you. Goodbye.");
    return(0);
}

/* Function Procedure: Return a valid menu selection. */
int menu () {
    int choice = 0;
    do {
        puts("Welcome. Type 1, 2, 3, or 4, based on desired action: ");
        puts("1. show balance");
        puts("2. make payment");
        puts("3. borrow cash");
        puts("4. quit");
        scanf("%d",&choice);
    } while (choice<1 || choice>4);
    return(choice);
}

/* Function Procedure: Return a valid rate selection. */
double get_rate() {
    double rate = 0.0;
    do {
        puts("Give me your desired rate. This message repeats until you enter a valid number: between 0 to 1. You  may enter a decimal: ");
        scanf("%lf",&rate);
    } while(rate<0 || rate>1);
    return(rate);
}

/* Function Procedure: Return accumulated interest based on the user-defined terms and rate. */
double show_balance(int terms, double amount, double rate) {
    //Future Addition: if (terms == 0 && rate == 0.0) {{for loop ....}}
        for (int i = 0; i < terms; i++) {
        amount += (amount*rate);
        //Test: printf("i = %d, rate = %lf, amount = %lf\n", i, rate, amount);
    }
    return(amount);
}

/* Function Procedure: Return the user's new balance based on a valid user payment amount. */
double pay (double payment_amount, double current_balance) {
    if (payment_amount < 0) {
        return(-1);
    }
    else if (payment_amount > current_balance) {
        return(-2);
    }
    else {
        //Test: printf("current_balance = %lf, payment_amount = %lf", current_balance, payment_amount);
        return(current_balance-payment_amount);
    }
}
/* Function Procedure: Return the user's new balance based on a valid borrow amount.  */
double borrow(double borrow_amount, double current_balance) {
    if (borrow_amount < 0) {
        return(-1);
    }
    else {
        return(borrow_amount+current_balance);
    }
}
