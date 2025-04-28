/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:01:44 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/22 17:56:03 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
#include <stdlib.h>

typedef struct Data
{
	std::string s;
	int		i;
	char	c;
	float	f;
} Data;

class Serializer
{
	private:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};