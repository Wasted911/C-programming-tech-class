//C++ 
/*
C++ Function to determine library fines
Author: Wambua Ebenezar Muuo
Reg No:BSCIT-05-0153/2024
Date:21/01/2025
Version 1.2
*/
#include <iostream>
#include <string>
using namespace std;
//Function prototype
int calculateFine(int overdueDays);
int main()
{
	//variable declaration
    int dd1, mm1, yy1, dd2, mm2, yy2, overduedays = 0;
    int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string bookID;
    
    cout << "Enter due date (dd mm yyyy): " << endl;
    cin >> dd1 >> mm1 >> yy1;

    cout << "Enter return date (dd mm yyyy): " << endl;
    cin >> dd2 >> mm2 >> yy2;
    
    cout << "Enter Book ID : " << endl;
    cin >> bookID;

    // Check for leap year and adjust February
    if ((yy1 % 4 == 0 && yy1 % 100 != 0) || (yy1 % 400 == 0)) 
	{
        days_in_month[1] = 29;  // Leap year
    }
    
 //Calculate overdue days for the same month
    if (yy1 == yy2) 
	{
        if (mm1 == mm2)
        {
            overduedays = dd2 - dd1;  
        } 
        else {
            // Calculate overdue days across months
            overduedays = (days_in_month[mm1 - 1] - dd1) + dd2; 
            for (int i = mm1; i < mm2 - 1; i++) 
			{
                overduedays += days_in_month[i];
            }
        }
    } 
    else {
        // Handle case when return year is different
        cout << "Calculation across years is not implemented yet!" << endl;
        return 1;
    }

    // Calculate and display the fine
    int fine = calculateFine(overduedays);
    
    cout << "\nBook ID : " << bookID << endl;
    cout << "Due date : " << dd1 << "/" << mm1 << "/" << yy1 << endl;
    cout << "Return date : " << dd2 << "/" << mm2 << "/" << yy2 << endl;
    cout << "Overdue days = " << overduedays << endl;
    cout << "Total fine = " << fine << " KSH" << endl;
    
    return 0;
}
//Function definition
int calculateFine(int overdueDays) 
{
    	if(overdueDays<=7)
	{
		return 20 * overdueDays;
	}
	else if(overdueDays > 8 && overdueDays <= 14)
	{
        return 50 * overdueDays;
	}
	else if(overdueDays > 14)
	{
		return 100 *overdueDays;
	}
	else
	{
		return 0;
	}
}