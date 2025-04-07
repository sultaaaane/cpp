/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:38:30 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/06 16:34:49 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *arr, int size, void (*f)(T &))
{
	if (arr == NULL || size == 0 || f == NULL)
		return;
	for (int i = 0; i < size; i++)
		f(arr[i]);
}