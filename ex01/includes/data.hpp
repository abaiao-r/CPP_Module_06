/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:32:42 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 21:42:19 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "colours.hpp"

typedef struct s_data
{
    std::string s1;
    int n;
    std::string s2;
} Data;

#endif
