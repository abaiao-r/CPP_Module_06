/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:28:57 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 00:37:25 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <limits>
#include <sstream>
#include <exception>
#include "colours.hpp"


//statc class
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
      static char literalToChar(std::string literal);
      static int literalToInt(std::string literal);
      static float literalToFloat(std::string literal);
      static double literalToDouble(std::string literal);
      static int charToInt(char c);
      static int floatToInt(float f);
      static int doubleToInt(double d);
      static char intToChar(int i);
      static char floatToChar(float f);
      static char doubleToChar(double d);
      static float intToFloat(int i);
      static float charToFloat(char c);
      static float doubleToFloat(double d);
      static double intToDouble(int i);
      static double charToDouble(char c);
      static double floatToDouble(float f);
};

#endif
