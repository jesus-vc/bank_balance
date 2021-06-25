
//  Created by Jesus Vasquez-Cipriano on 10/27/20.
//  Copyright © 2020 Jesus Vasquez-Cipriano. All rights reserved.
  
**SUMMARY**
 * Function: int main()
 * Input: User inputs various data types to calculate accumulated interest.
 * Output: Returns 0 on success.
 * Procedure: Calculates and displays accumulated interest through a while loop and switch statement that repeatedly calls additional functions based on user input.
  
**Future Revisions Will Evaluate:**
    1. Adjust the rounding of decimal values for each iteration in function show_balance() in order to compute accurate values.
    2. Adjust the return type of pay(), given the return type may be an integer (-1 or -2) or a double. Alternatively, re-structure program to assign pay() with only 1 return type.
    3. Adding code (potentially global variables) that allows the show_balance() function to store and process a continous stream of new borrow and pay inputs. For example, currently, once show_balance() processes successfully the first time, it fails to store current_balance for future user payment and borrow inputs.
