/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:44:55 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/05 15:19:24 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./Conversion_of_scalar_types [value]" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
    std::cout << "-------------------------\n\n" << std::endl;
    return (0);
}
