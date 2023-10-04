/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:35:42 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 21:47:14 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << BOLDPURPLE 
        << "Serializer constructor should not be called because it is private" 
        << RESET << std::endl;
}

Serializer::Serializer(Serializer const &src)
{
    std::cout << BOLDPURPLE 
        << "Serializer copy constructor should not be called because it is private" 
        << RESET << std::endl;
    *this = src;
}

Serializer::~Serializer(void)
{
    std::cout << BOLDPURPLE 
        << "Serializer destructor should not be called because constructor is private" 
        << RESET << std::endl;
}

Serializer &Serializer::operator=(Serializer const &src)
{
    std::cout << BOLDPURPLE 
        << "Serializer assignation operator should not be called because it is private" 
        << RESET << std::endl;
    if (this != &src)
    {
        (void)src;
    }
    return (*this);
}

/* serialize() takes a pointer to Data as a parameter and returns a uintptr_t. 
 * The function should cast the pointer to uintptr_t and return it.
 */
uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

/* deserialize() takes a uintptr_t as a parameter and returns a pointer to Data. 
 * The function should cast the uintptr_t to a pointer and return it.
 */
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}




