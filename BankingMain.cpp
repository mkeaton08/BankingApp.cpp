//Matthew Keaton 06-09-2024

#include <iostream>
#include <iomanip>
using namespace std;

//declare class
class Investment {

    //add public data members
    public:
        //initialize class members with constructor
        Investment(double initial, double monthly, double annualRate, int years) {
        initialAmount = initial;
        monthlyDeposit = monthly;
        annualInterest = annualRate;
        numYears = years;
        }

        //create function to display and get user input
        void displayInitialValues() {
            cout << "********** Data Input *************" << endl;
            cout << "Initial Investment Amount: $";
            cin >> initialAmount;
            cout << "Monthly Deposit: $";
            cin >> monthlyDeposit;
            cout << "Annual Interest: %";
            cin >> annualInterest;
            cout << "Number of years: ";
            cin >> numYears;
            cout << "Press enter to continue . . ." << endl;
            cin.ignore();
            cin.get();
        }

        //create function to display without deposit and initialize variables
        void displayWithoutDeposits() {
            double totalAmount = initialAmount;
            double interest = 0.0;

            cout << "Balance and Interest without Additional Monthly Deposits" << endl;
            cout << "========================================================" << endl;
            cout << setw(6) << "Year" << setw(20) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
            cout << "--------------------------------------------------------" << endl;

            //loop to go through each year
            for (int i = 1; i <= numYears; ++i) {
                interest = calcInterest(totalAmount, 0); //call function to calculate interest
                totalAmount += interest; //update interest to total amount

                //display year, total amount, and interest for the year without deposit
                cout << setw(6) << i << setw(20) << fixed << setprecision(2) << totalAmount << setw(25) << interest << endl;
            }
        }
        //create function to display with deposit and initialize variables
        void displayWithDeposits() {
            double totalAmount = initialAmount;
            double interest = 0.0;

            cout << "Balance and Interest with Additional Monthly Deposits" << endl;
            cout << "========================================================" << endl;
            cout << setw(6) << "Year" << setw(20) << "Year End Balance" << setw(25) << "Year End Earned Interest" << endl;
            cout << "--------------------------------------------------------" << endl;

            //loop through each year
            for (int i = 1; i <= numYears; ++i) {
                double yearlyInterest = 0.0;
                //loop for months in a year
                for (int j = 0; j < 12; ++j) {
                    interest = calcInterest(totalAmount, monthlyDeposit); //call function to calculate interest
                    yearlyInterest += interest; //add interest to yearly interest
                    totalAmount += monthlyDeposit + interest; //add monthly deposit and interest to total amount
                }

            //display year, total amount, and yearly interest with deposit
            cout << setw(6) << i << setw(20) << fixed << setprecision(2) << totalAmount << setw(25) << yearlyInterest << endl;
            }
        }
    //add private data members
    private:
        double initialAmount;
        double monthlyDeposit;
        double annualInterest;
        int numYears;

        //private member function to calculate interest
        double calcInterest(double totalAmount, double monthlyDeposit) {
            return (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);
        }
};

//create main function to run program
int main() {
    double initialAmount;
    double monthlyDeposit;
    double annualInterest;
    int numYears;

    //create object from class Investment and initialize variables
    Investment invest(initialAmount, monthlyDeposit, annualInterest, numYears);

    //call functions
    invest.displayInitialValues();
    invest.displayWithoutDeposits();
    invest.displayWithDeposits();

    return 0;
}