#include <iostream>
#include <iomanip>  // For setw(), setprecision(), fixed
#include <cmath>    // For pow()

using namespace std;

// Function prototypes
float calculateMonthlyPayment(float price, float monthlyRate, int months);
float calculateTotalPaid(float monthlyPayment, int months);
float calculateInterestPaid(float totalPaid, float price);

// Main function
int main() {
    // Variables for input
    float price, apr;
    int years;

    // Gather input from the user
    cout << "Enter the car price: ";
    cin >> price;

    cout << "Enter the payoff period (in years): ";
    cin >> years;

    cout << "Enter the Annual Percentage Rate (APR) in %: ";
    cin >> apr;

    // Convert years to months and APR to monthly rate
    int months = years * 12;
    float monthlyRate = apr / 100 / 12;

    // Calculate monthly payment, total paid, and interest paid
    float monthlyPayment = calculateMonthlyPayment(price, monthlyRate, months);
    float totalPaid = calculateTotalPaid(monthlyPayment, months);
    float interestPaid = calculateInterestPaid(totalPaid, price);

    // Display results with formatting using setw()
    cout << fixed << setprecision(2);  // Set decimal precision to 2

    // Print formatted output
    cout << setw(25) << left << "Price:" << setw(10) << right << price << endl;
    cout << setw(25) << left << "Term (Years):" << setw(10) << right << years << endl;
    cout << setw(25) << left << "Rate (APR):" << setw(10) << right << apr << "%" << endl;
    cout << setw(25) << left << "Payment:" << setw(10) << right << monthlyPayment << endl;

    // Print line separator
    cout << string(50, '-') << endl;

    cout << setw(25) << left << "Interest Paid:" << setw(10) << right << interestPaid << endl;
    cout << setw(25) << left << "Total Paid:" << setw(10) << right << totalPaid << endl;

    return 0;
}

// Function to calculate the monthly payment
float calculateMonthlyPayment(float price, float monthlyRate, int months) {
    return price * monthlyRate / (1 - pow(1 + monthlyRate, -months));
}

// Function to calculate the total amount paid
float calculateTotalPaid(float monthlyPayment, int months) {
    return monthlyPayment * months;
}

// Function to calculate the total interest paid
float calculateInterestPaid(float totalPaid, float price) {
    return totalPaid - price;
}
