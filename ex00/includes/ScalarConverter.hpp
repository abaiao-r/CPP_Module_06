/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:28:57 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 19:53:31 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream> // to use cout
#include <string> // to use string
#include <iomanip> // to use setprecision
#include <cstdlib> // to use atof
#include <climits> // to use INT_MAX
#include <cfloat> // to use FLT_MAX
#include <cmath>
#include <limits> // to use numeric_limits
#include "colours.hpp"

class ScalarConverter
{
   private:
      ScalarConverter(void);
      ScalarConverter(ScalarConverter const &src);
   
   public:
      ~ScalarConverter(void);
      ScalarConverter &operator=(ScalarConverter const &src);

      static void convert(std::string literal);
      static std::string detectType(std::string literal);
      static bool handlePseudoLiterals(std::string literal);
      static void literalToChar(std::string literal);
      static void literalToInt(std::string literal);
      static void literalToFloat(std::string literal);
      static void literalToDouble(std::string literal);

      static bool isChar(std::string literal);
      static int isPseudoLiteral(std::string literal);
      static bool isInt(std::string literal);
      static bool isFloat(std::string literal);
      static bool isDouble(std::string literal);
};

#endif
