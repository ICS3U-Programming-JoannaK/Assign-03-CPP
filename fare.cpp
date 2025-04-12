// Copyright 2025 Joanna Keza All rights reserved
//
// Created by: Joanna Keza
// Data: April 7, 2025
// This program calculates the correct bus fare
// based on the passenger’s age, time of day,
// and student / senior status

#include <iostream>
#include <string>
#include <iomanip>


int main() {
    // declare the constants
    const float OC_STUDENT = 4.00;
    const float OC_SENIOR = 3.20;
    const float OC_ADULT = 4.00;
    const float TTC_STUDENT = 2.40;
    const float TTC_SENIOR = 2.30;
    const float TTC_ADULT = 3.35;

    // declare the variables
    std::string ageString;
    std::string dayString;
    std::string busSystemString;
    int ageInteger;

    // Display greeting card
    std::cout << "************************************" << std::endl;
    std::cout << "************************************" << std::endl;
    std::cout << "*            Hello user !          *" << std::endl;
    std::cout << "************************************" << std::endl;
    std::cout << "************************************\n"
              << std::endl;
    std::cout << "\n"
              << std::endl;

    // get the user's age as a string
    std::cout << "Enter your age: ";
    std::cin >> ageString;

    // Convert the age string to an integer
    try {
        ageInteger = std::stoi(ageString);
        if (ageInteger < 1) {
            std::cout << "\nPlease enter a valid age" << std::endl;
        }
        // Ask which transit system the user is going to use
        std::cout << "Which transit system are you using today: ";
        std::cin >> busSystemString;
        // Ask the user for the day of the week
        std::cout << "What day is today (eg; Monday, Thursday): ";
        std::cin >> dayString;
        if (dayString != "Monday" &&
            dayString != "Tuesday" &&
            dayString != "Wednesday" &&
            dayString != "Thursday" &&
            dayString != "Friday" &&
            dayString != "Saturday" && 
            dayString != "Sunday") {
            std::cout << "\nPlease enter a valid day. For example; Monday, etc."
                      << std::endl;
        }
        else {
            if (busSystemString == "OC-Transpo") {
                if (ageInteger <= 10) {
                    // Children under 10 do not have to pay the fare
                    std::cout << "\nThere is no fare! have a great day!"
                              << std::endl;
                } else if (ageInteger > 10 && ageInteger < 65) {
                    std::cout << std::fixed << std::setprecision(2);
                    std::cout << "\nYour fare is $ " << OC_ADULT << std::endl;
                } else if (ageInteger >= 65) {
                    if (dayString == "Wednesday" || dayString == "Sunday") {
                        std::cout << "\nThere is no fare, have a great day"
                                  << std::endl;
                    } else {
                        std::cout << std::fixed << std::setprecision(2);
                        std::cout << "\nThe fare is $ " << OC_SENIOR << std::endl;
                    }
                }
            }
        }
        // Catch erroneous input for age
    } catch (std::invalid_argument) {
        std::cout << ageString << " is not a valid input" << std::endl;
    }
    // This will display after everything
    std::cout << "\n";
    std::cout << "Thank you for using my program \n";
    std::cout << "I hope you have a wonderful day !\n";
    std::cout << "\n";
}