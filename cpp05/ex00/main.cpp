/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:14:29 by mbentahi          #+#    #+#             */
/*   Updated: 2025/01/10 16:34:07 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\n=== Testing Constructors ===\n";
    
    // Test default constructor
    try {
        std::cout << "Testing default constructor:\n";
        Bureaucrat b1;
        std::cout << b1 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test parameterized constructor with valid values
    try {
        std::cout << "\nTesting valid parameterized constructor:\n";
        Bureaucrat b2("John", 75);
        std::cout << b2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test constructor with too high grade
    try {
        std::cout << "\nTesting constructor with too high grade (0):\n";
        Bureaucrat b3("High", 0);
        std::cout << b3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test constructor with too low grade
    try {
        std::cout << "\nTesting constructor with too low grade (151):\n";
        Bureaucrat b4("Low", 151);
        std::cout << b4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Grade Modifications ===\n";
    
    // Test increment and decrement
    try {
        std::cout << "Testing increment and decrement:\n";
        Bureaucrat b5("Bob", 75);
        std::cout << "Initial: " << b5 << std::endl;
        
        b5.inc();
        std::cout << "After increment: " << b5 << std::endl;
        
        b5.dec();
        std::cout << "After decrement: " << b5 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test increment at maximum grade
    try {
        std::cout << "\nTesting increment at grade 1:\n";
        Bureaucrat b6("Max", 1);
        std::cout << "Initial: " << b6 << std::endl;
        b6.inc();
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test decrement at minimum grade
    try {
        std::cout << "\nTesting decrement at grade 150:\n";
        Bureaucrat b7("Min", 150);
        std::cout << "Initial: " << b7 << std::endl;
        b7.dec();
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Testing Getters ===\n";
    
    Bureaucrat b8("Alice", 42);
    std::cout << "Name: " << b8.getName() << std::endl;
    std::cout << "Grade: " << b8.getGrade() << std::endl;

    // Test copy construction and assignment (if implemented)
    try {
        std::cout << "\n=== Testing Copy ===\n";
        Bureaucrat original("Original", 50);
        Bureaucrat copy = original;
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}