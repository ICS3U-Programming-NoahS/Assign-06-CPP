// Copyright (c) 2023 Noah Smith All rights reserved.
//
// Created by: Noah Smith
// Date: Dec. 18th, 2023
// This program asks you to enter 2 lists of different elements.
// The program will then display the two lists joined together
// and the two lists joined together with alternating elements.

#include <iostream>
#include <list>

std::list <std::string> joinList(
    std::list<std::string> firstList,
    std::list<std::string> secondList
) {
    // Create a copy of the first list
    // source: programming-idioms.org/idiom/166/concatenate-two-lists/2306/cpp
    std::list<std::string> joinedList = firstList;

    // Concatenate lists using insert
    // source: programming-idioms.org/idiom/166/concatenate-two-lists/2306/cpp)
    joinedList.insert(joinedList.end(), secondList.begin(), secondList.end());

    // return joined list
    return joinedList;
}

std::list <std::string> alternateList(
    std::list<std::string> firstList,
    std::list<std::string> secondList
) {
    // Declare variables
    std::list<std::string> alternatedList;

    // Initialize size of list
    int sizeOfList = firstList.size();

    // Use for loop to alternate elements of the 2 lists
    for (int counter = 0; counter < (2 * sizeOfList); counter+=2) {
        alternatedList.push_back(firstList.front());
        alternatedList.push_back(secondList.front());

        // remove first element from each list
        firstList.pop_front();
        secondList.pop_front();
    }

    // Return alternated list
    return alternatedList;
}

int main() {
    // Greeting and instructions
    std::cout << "" << std::endl;
    std::cout << "This program asks you to";
    std::cout << " enter 2 lists of different elements." << std::endl;
    std::cout << " The program will then";
    std::cout << " display the two lists joined together " << std::endl;
    std::cout << "and the two lists joined together";
    std::cout << " with alternating elements:" << std::endl;
    std::cout << "(A, 1, B, 2, C, 3)" << std::endl;
    std::cout << "(A, B, C, 1, 2, 3)" << std::endl;
    std::cout << "To end a list type in 'end'." << std::endl;
    std::cout << "*** The lists must be the same size! ***";
    std::cout << "" << std::endl;

    // Declare variables
    std::string list1Element, list2Element;

    // Initialize empty lists
    std::list<std::string> list1, list2;

    // get elements of first list
    do {
        std::cout << "Enter an element for the first list: ";
        std::cin >> list1Element;
        std::cout << std::endl;
        // if the user enters "end"
        if (list1Element == "end") {
            // break out of the loop
            break;
        } else {
            // add element to end of list
            list1.push_back(list1Element);
        }
    } while (true);

    // Get elements of second list
    do {
        std::cout << "Enter an element for the second list: ";
        std::cin >> list2Element;
        std::cout << std::endl;
        // if the user enters "end"
        if (list2Element == "end") {
            // if the lists are not the same size
            if (list1.size() != list2.size()) {
                std::cout << "The lists must be the same size!";
            } else {
                // break out of loop
                break;
            }
        } else {
            // add element to end of list
            list2.push_back(list2Element);
        }
    } while (true);

    // Function calls
    std::list<std::string> joinedList = joinList(list1, list2);
    std::list<std::string> alternatedList = alternateList(list1, list2);

    // Display joined list
    // source: https://en.cppreference.com/w/cpp/language/range-for
    std::cout << "The lists joined:" << std::endl;
    for (auto listElement : joinedList) {
        std::cout << listElement << " ";
    }
    std::cout << std::endl;

    // Display alternated list
    // source: cppreference.com/w/cpp/language/range-for
    std::cout << "The lists alternated:" << std::endl;
    for (auto listElement : alternatedList) {
        std::cout << listElement << " ";
    }
    std::cout << std::endl;
}
