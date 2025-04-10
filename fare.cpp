// Copyright 2025 Joanna Keza All rights reserved
//
// Created by: Joanna Keza
// Data: April 7, 2025
// This program calculates the correct bus fare
// based on the passenger’s age, time of day,
// and student / senior status

#include <iostream>
#include <string>


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
    int busSystemInteger;

    // Display greeting card
    std::cout << "************************************" << std::endl;
    std::cout << "************************************" << std::endl;
    std::cout << "*            Hello user !          *" << std::endl;
    std::cout << "************************************" << std::endl;
    std::cout << "************************************\n" << std::endl;
    std::cout << "\n" << std::endl;

    // get the user's age
    std::cout << "Enter your age: ";
    std::cin >> ageString;

    try {
        ageInteger = std::stoi(ageString);
        if (ageInteger < 1) {
            std::cout << "Please enter a valid age";
        }
        std::cout << "What day is today (eg; Monday, Thursday):";
        std::cin >> dayString;
        std::cout << "Which transit system? (OC Transpo/TTC Toronto):";
        std::cin >> busSystemInteger;
    } catch (std::invalid_argument) {
        std::cout << ageString << "is not a valid input";
    }
        try {
            busSystemString = std::to_string(busSystemInteger);
            if (busSystemString == "OC Transpo") {
            if (ageInteger > 10 && ageInteger < 65) {
                std::cout << "Your fare is $ " << OC_ADULT << std::endl;
                    } else if (ageInteger > 65) {
                if (dayString == "Wednesday" || dayString == "Sunday") {
                        std::cout << "There is no fare, have a great day";
                    }
                }
            } else if (ageInteger < 10) {
                std::cout << "There is no fare! It is free, have a great day!";
                }
            if (busSystemString == "TTC Toronto") {
                if (ageInteger >= 19 && ageInteger < 65) {
                    std::cout << "Your fare is $ " << TTC_ADULT << std::endl;
                    } else if (ageInteger >= 65) {
                    std::cout << "Your fare is $ " << TTC_SENIOR << std::endl;
                    } else if (ageInteger > 13 && ageInteger < 18) {
                    std::cout << "Your fare is $ " << TTC_STUDENT << std::endl;
                    } else if (ageInteger <= 12) {
                    std::cout << "There is no fare, have a great day!";
                }
            }
        } catch (std::invalid_argument) {
            std::cout << busSystemInteger << " is not a valid input.";
        }
    }
