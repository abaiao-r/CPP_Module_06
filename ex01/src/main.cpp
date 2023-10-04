/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:38:53 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 22:13:08 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/data.hpp"


int main(void)
{
    Data    *data;
    Data    *newData;
    uintptr_t raw;

    data = new Data;
    // Set values
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";

    // Serialize
    raw = Serializer::serialize(data);
    std::cout << "Serialized data: " << raw << std::endl;

    // Deserialize
    newData = Serializer::deserialize(raw);

    // Compare the pointers
    if (data == newData)
    {
        std::cout << "Deserialized data: " << newData << std::endl;
        std::cout << "Deserialized data->s1: " << newData->s1 << std::endl;
        std::cout << "Deserialized data->n: " << newData->n << std::endl;
        std::cout << "Deserialized data->s2: " << newData->s2 << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed." << std::endl;
        // Clean up memory twice because the pointers are different
        delete newData;
        delete data;
        return (1);
    }

    // Clean up memory only once because the pointers are the same
    delete data;

    return (0);
}
