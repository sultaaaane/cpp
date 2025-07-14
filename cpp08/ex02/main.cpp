/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:38:01 by mbentahi          #+#    #+#             */
/*   Updated: 2025/07/14 09:23:19 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "Testing MutantStack:\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\nTesting std::list:\n";
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    return 0;
}