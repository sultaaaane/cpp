/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:38:30 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/07 23:43:46 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    unsigned int size;
    T *array;
public:
    Array(): size(0), array(NULL) {}
    
    Array(unsigned int s): size(s), array(new T[size]()) {}
    
    Array(Array const &c): size(0), array(NULL)
    {
        *this = c;
    }
    
    Array &operator=(Array const &a)
    {
        if (&a == this)
            return *this;
        if (this->array)
            delete[] array;
        this->size = a.size;
        this->array = new T[this->size];
        for (unsigned int i = 0; i < this->size; i++)
            array[i] = a.array[i];
        return *this;
    }
    
    T& operator[](unsigned int index)
    {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return array[index];
    }
    
    const T& operator[](unsigned int index) const
    {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return array[index];
    }
    
    unsigned int Size() const
    {
        return size;
    }
    
    ~Array()
    {
        if (this->array)
            delete[] array;
    }
};