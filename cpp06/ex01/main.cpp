/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbentahi <mbentahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:53:36 by mbentahi          #+#    #+#             */
/*   Updated: 2025/04/22 13:11:22 by mbentahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
	Data		data;
	Serializer	serializer;
	data.s = "Hello World";
	data.i = 42;
	data.c = 'A';
	data.f = 3.14f;

	uintptr_t raw = serializer.serialize(&data);
	std::cout << "Original data: " << data.s << std::endl;
	std::cout << "Original data: " << data.i << std::endl;
	std::cout << "Original data: " << data.c << std::endl;
	std::cout << "Original data: " << data.f << std::endl;
	std::cout << "Serialized data: " << raw << std::endl;
	
	Data* deserializedData = serializer.deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->s << std::endl;
	std::cout << "Deserialized data: " << deserializedData->i << std::endl;
	std::cout << "Deserialized data: " << deserializedData->c << std::endl;
	std::cout << "Deserialized data: " << deserializedData->f << std::endl;
	std::cout << "Address of original data: " << &data << std::endl;
	std::cout << "Address of deserialized data: " << deserializedData << std::endl;
	std::cout << "Size of Data struct: " << sizeof(Data) << std::endl;
	std::cout << "Size of uintptr_t: " << sizeof(uintptr_t) << std::endl;
	std::cout << "Size of Serializer class: " << sizeof(Serializer) << std::endl;
	std::cout << "Size of Serializer::serialize: " << sizeof(&Serializer::serialize) << std::endl;
	
	
}