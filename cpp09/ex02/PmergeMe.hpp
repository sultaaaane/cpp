/* **************************************************************************************************************** */
/*				                                    ⠤⣤⣤⣤⣄⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣠⣤⠤⠤⠴⠶⠶⠶⠶	 */
/*				                                    ⢠⣤⣤⡄⣤⣤⣤⠄⣀⠉⣉⣙⠒⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠴⠘⣉⢡⣤⡤⠐⣶⡆⢶⠀⣶⣶⡦	 */
/*	PmergeMe.hpp                  	                ⣄⢻⣿⣧⠻⠇⠋⠀⠋⠀⢘⣿⢳⣦⣌⠳⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠞⣡⣴⣧⠻⣄⢸⣿⣿⡟⢁⡻⣸⣿⡿⠁   */
/*	                                                 ⠃⠙⢿⣧⣙⠶⣿⣿⡷⢘⣡⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣷⣝⡳⠶⠶⠾⣛⣵⡿⠋⠀    */
/*													     ⠉⠻⣿⣶⠂⠘⠛⠛⠛⢛⡛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠛⠀⠉⠒⠛⠀⠀⠀⠀    */
/*	By: mbentahi <Mohamadalaoui77@gmail.com>               ⣿⡇⠀⠀⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	⠀ */
/*	                 								⠀⠀⠀⠀⠀ ⣿⡇⠀⠀⠀⠀⠀⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	 */
/*	Created: 5/4/2025, 8:05:17 PM          		⠀⠀⠀ ⠀⠀⠀  ⣿⡇⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*	Updated: 5/4/2025, 8:13:57 PM          		⠀⠀⠀ ⠀⠀⠀  ⢻⡁⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  */
/*													⠀⠀⠀⠀⠀⠘⡇                                                       */
/*													⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀	 */
/*                                                         ⠿                                                        */
/* **************************************************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include <limits>
#include <deque>
#include <iterator>
#include <cmath>
#include <unistd.h>
#include <sys/time.h>


class PmergeMe
{
private:
	std::vector<int> vec;
	std::vector<int> vecCopy;
	std::deque<int> deq;
	timeval dstartTime;
	timeval vstartTime;
	time_t v_start, v_end;
	time_t d_start, d_end;
public:
	PmergeMe();
	PmergeMe(const std::vector<int> &input);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void ParseInput(const std::string &input);
	void SortVector();
	void SortDeque();
	void PrintVector() const;
	void PrintDeque() const;
	std::vector<size_t> generate_jacobsthal_order(size_t k);
	void mergeInsertSort(std::vector<int> &vec);
	void mergeInsertSort(std::deque<int> &deq);
	void vPrintTime() const;
	void dPrintTime() const;
};

// ./PmergeMe `shuf -i 1-10000 -n 3000 | tr "\n" " "`