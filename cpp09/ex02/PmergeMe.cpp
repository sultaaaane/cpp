#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: vec(other.vec), deq(other.deq), dstartTime(other.dstartTime), vstartTime(other.vstartTime)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
		dstartTime = other.dstartTime;
		vstartTime = other.vstartTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::ParseInput(const std::string &input)
{
	std::istringstream iss(input);
	int num;
	std::string token;

	while (iss >> token)
	{
		if (token.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Non-numeric input detected: " + token);
		std::istringstream tokenStream(token);
		tokenStream >> num;

		if (tokenStream.fail() || !tokenStream.eof())
			throw std::invalid_argument("Invalid number format: " + token);
		if (num < 0 || num > std::numeric_limits<int>::max())
			throw std::out_of_range("Input numbers must be non-negative integers");
		if (std::find(vec.begin(), vec.end(), num) != vec.end())
			throw std::invalid_argument("Duplicate number detected: " + token);
		vec.push_back(num);
		deq.push_back(num);
	}
	if (vec.empty() || deq.empty())
		throw std::invalid_argument("Input cannot be empty");

	if (vec.size() != deq.size())
		throw std::length_error("Vector and Deque must have the same size");
	vecCopy = vec;
}

void PmergeMe::SortVector()
{
	v_start = clock();
	mergeInsertSort(vec);
	v_end = clock();
}

void PmergeMe::SortDeque()
{
	d_start = clock();
	mergeInsertSort(deq);
	d_end = clock();
}

void PmergeMe::PrintVector() const
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::PrintDeque() const
{
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::vPrintTime() const
{
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector :" << std::fixed << std::setprecision(6) << static_cast<float>(v_end - v_start) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

void PmergeMe::dPrintTime() const
{
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque :" << std::fixed << std::setprecision(6) << static_cast<float>(d_end - d_start) / CLOCKS_PER_SEC << " seconds." << std::endl;
}

void PmergeMe::mergeInsertSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> maxs;
	std::vector<int> mins;

	std::vector<int>::iterator it = vec.begin();
	while (it + 1 < vec.end())
	{
		if (*it < *(it + 1))
		{
			mins.push_back(*it);
			maxs.push_back(*(it + 1));
		}
		else
		{
			mins.push_back(*(it + 1));
			maxs.push_back(*it);
		}
		it += 2;
	}

	if (vec.size() % 2 != 0)
		mins.push_back(*(vec.end() - 1));

	mergeInsertSort(maxs);

	std::vector<size_t> order = generate_jacobsthal_order(mins.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pos = order[i];
		if (pos < mins.size())
		{
			std::vector<int>::iterator it = std::lower_bound(maxs.begin(), maxs.end(), mins[pos]);
			maxs.insert(it, mins[pos]);
		}
	}

	vec = maxs;
}

std::vector<size_t> PmergeMe::generate_jacobsthal_order(size_t k)
{
	std::vector<size_t> order;
	std::vector<size_t> jacob;
	std::vector<bool> seen(k, false);

	if (k == 0)
		return order;

	jacob.push_back(0);
	if (k == 1)
	{
		order.push_back(0);
		return order;
	}
	jacob.push_back(1);
	if (k == 2)
	{
		order.push_back(1);
		order.push_back(0);
		return order;
	}
	size_t next;

	while (true)
	{
		next = jacob.back() + 2 * jacob[jacob.size() - 2];
		if (next >= k)
			break;
		jacob.push_back(next);
	}
	for (size_t i = jacob.size(); i-- > 0;)
	{
		if (jacob[i] < k && !seen[jacob[i]])
		{
			order.push_back(jacob[i]);
			seen[jacob[i]] = true;
		}
	}
	for (size_t i = k; i-- > 0;)
	{
		if (!seen[i])
			order.push_back(i);
	}
	return order;
}

void PmergeMe::mergeInsertSort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> maxs;
	std::deque<int> mins;

	std::deque<int>::iterator it = deq.begin();
	while (it + 1 < deq.end())
	{
		if (*it < *(it + 1))
		{
			mins.push_back(*it);
			maxs.push_back(*(it + 1));
		}
		else
		{
			mins.push_back(*(it + 1));
			maxs.push_back(*it);
		}
		it += 2;
	}

	if (deq.size() % 2 != 0)
		mins.push_back(*(deq.end() - 1));

	mergeInsertSort(maxs);

	std::vector<size_t> order = generate_jacobsthal_order(mins.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t pos = order[i];
		if (pos < mins.size())
		{
			std::deque<int>::iterator it = std::lower_bound(maxs.begin(), maxs.end(), mins[pos]);
			maxs.insert(it, mins[pos]);
		}
	}

	deq = maxs;
}
