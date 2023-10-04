/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:06:30 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 03:42:43 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/* Default constructor - private */
ScalarConverter::ScalarConverter(void)
{
    std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

/* Copy constructor - private */
ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    *this = src;
}

/* Default destructor */
ScalarConverter::~ScalarConverter(void)
{
    std::cout << YELLOW << "Destructor called" << RESET << std::endl;
}

/* Assignment operator */
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    std::cout << YELLOW << "Assignment operator called" << RESET << std::endl;
    if (this != &src)
    {
        (void)src;
    }
    return (*this);
}




std::string ScalarConverter::detectType(std::string literal)
{
    std::string type;
    size_t i;
    size_t dot_count;

    dot_count = 0;
    i = 0;
    if (literal.length() == 1 && !isdigit(literal[0])) // check if char
    {
        type = "char";
        return (type);
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "inf" || literal == "nan") // check if double
    {
        type = "double";
        return (type);
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "inff" || literal == "nanf") // check if float
    {
        type = "float";
        return (type);
    }
    else if (isdigit(literal[0]) || literal[0] == '-' || literal[0] == '+') // check if int
    {
        if (literal[0] == '-' || literal[0] == '+')
        {
            if (literal[1] == '\0' || std::isdigit(literal[1]) == 0)
            {
                type = "Unknown type";
                return (type);
            }
            i++;
        }
        i = 1;
        while (literal[i] != '\0')
        {
            if (!isdigit(literal[i]))
            {
                if (literal[i] == '.')
                {
                    dot_count++;
                    if (dot_count > 1 || std::isdigit(literal[i + 1]) == 0 || literal[i + 1] == '\0')
                    {
                        type = "Unknown type";
                        return (type);
                    }
                    i++;
                    continue;
                }
                else if (literal[i] == 'f' && literal[i + 1] == '\0')
                {
                    type = "float";
                    return (type);
                }
                else if (literal[i] == 'f' && literal[i + 1] != '\0')
                {
                    type = "Unknown type";
                    return (type);
                }
                else if (literal[i] == 'd' && literal[i + 1] == '\0')
                {
                    type = "double";
                    return (type);
                }
                else if (literal[i] == 'd' && literal[i + 1] != '\0')
                {
                    type = "Unknown type";
                    return (type);
                }
                else
                {
                    type = "Unknown type";
                    return (type);
                }
            }
            i++;
        }
        if (dot_count == 1)
        {
            type = "double";
            return (type);
        }
        else
        {
            i = 1;
            while (literal[i] != '\0')
            {
                if (std::isdigit(literal[i]) == 0 || i > 10)
                {
                    type = "Unknown type";
                    return (type);
                }
                i++;
            }
            long long temp;
            temp = std::atoll(literal.c_str());
            if (temp <= std::numeric_limits<int>::max() && temp >= std::numeric_limits<int>::min())
            {
                type = "int";
                return (type);
            }
            else
            {
                type = "Unknown type";
                return (type);
            }
        }
    }
    else
    {
        type = "Unknown type";
        return (type);
    }
}

/*literalToChar: converts a literal to a char*/
char ScalarConverter::literalToChar(std::string literal)
{
    char c;

    c = literal[0];
    if (literal.length() == 1)
    {
        std::cout << "char: " << "'" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
    return (c);
}

/*literalToInt: converts a literal to an int*/
int ScalarConverter::literalToInt(std::string literal)
{
    long long i;

    i = std::atoll(literal.c_str());
    std::cout << "char: ";
    if ((i >= 0 && i < 32) || (i == 127))
        std::cout << "Non displayable" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;

    if (i <= std::numeric_limits<int>::max() && i >= std::numeric_limits<int>::min())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "impossible" << std::endl;

    if (std::abs(i) <= std::numeric_limits<float>::max())
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    if (std::abs(i) <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    return static_cast<int>(i);
}
    /* int i;

    i = std::atoi(literal.c_str());
    std::cout << "char: ";
    if ((i >= 0 && i < 32) || (i == 127))
        std::cout << "Non displayable" << std::endl;
    else if (i < 0 || i > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
    if (i <= std::numeric_limits<int>::max() && i >= std::numeric_limits<int>::min())
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (i <= std::numeric_limits<float>::max() && i >= std::numeric_limits<float>::min())
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (i <= std::numeric_limits<double>::max() && i >= std::numeric_limits<double>::min())
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
    else
        std::cout << "impossible" << std::endl;
    return (i);
} */

/*literalToFloat: converts a literal to a float*/
float ScalarConverter::literalToFloat(std::string literal)
{
    float f;

    if (literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (0);
    }
    else if (literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (0);
    }
    else if (literal == "inff" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return (0);
    }
    f = std::atof(literal.c_str());
    
    std::cout << "char: ";
    if ((f >= 0 && f < 32) || (f == 127))
        std::cout << "Non displayable" << std::endl;
    else if (f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;

    if (f <= std::numeric_limits<int>::max() && f >= std::numeric_limits<int>::min())
        std::cout << "int: " << f << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (std::abs(f) <= std::numeric_limits<float>::max() && std::abs(f) >= std::numeric_limits<float>::min())
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(f) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (std::abs(f) <= std::numeric_limits<double>::max() && std::abs(f) >= std::numeric_limits<double>::min())
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    return static_cast<float>(f);
}

/*literalToDouble: converts a literal to a double*/
double ScalarConverter::literalToDouble(std::string literal)
{
    double d;
    
    if (literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return (0);
    }
    else if (literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return (0);
    }
    else if (literal == "inf" || literal == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return (0);
    }
    d = std::atof(literal.c_str());
    std::cout << "char: ";
    if ((d >= 0 && d < 32) || (d == 127))
        std::cout << "Non displayable" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "impossible" << std::endl;
    else 
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;

    if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
        std::cout << "int: " << d << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (std::abs(d) <= std::numeric_limits<float>::max() && std::abs(d) >= std::numeric_limits<float>::min())
        std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    if (std::abs(d) <= std::numeric_limits<double>::max() && std::abs(d) >= std::numeric_limits<double>::min())
        std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(d) << std::endl;
    else
        std::cout << "impossible" << std::endl;

    return static_cast<float>(d);
}



void ScalarConverter::convert(std::string literal)
{
    std::string type;

    type = ScalarConverter::detectType(literal);
    std::cout << "type: " << type << "\n\n\n" << std::endl;
    if (type == "char")
        ScalarConverter::literalToChar(literal);
    else if (type == "int")
        ScalarConverter::literalToInt(literal);
    else if (type == "float")
        ScalarConverter::literalToFloat(literal);
    else if (type == "double")
        ScalarConverter::literalToDouble(literal);
    else
        std::cout << "Unknown type" << std::endl;
}

    
/* int main() {
    std::string test_int = "123";
    std::string test_float = "3.14";
    std::string test_double = "2.718281828";
    std::string test_char = "A";
    std::string test_unknown = "Hello";
    std::string test_nan = "nan";
    std::string test_nanf = "nanf";
    std::string test_inf = "inf";
    std::string test_inff = "inff";
    std::string test_plus_inf = "+inf";
    std::string test_plus_inff = "+inff";
    std::string test_minus_inf = "-inf";
    std::string test_minus_inff = "-inff";
    std::string test_plus_nan = "+nan";
    std::string test_plus_nanf = "+nanf";
    std::string test_minus_nan = "-nan";
    std::string test_minus_nanf = "100.0f";
    std::string test_minus_nanf2 = "100.00d";
    std::string test_minus_nanf3 = "-13af2";
    std::string test_empty = " ";
    std::string test_space2 = "  ";
    std::string test_space3 = "   ";
    std::string test_plus_dot = "+.";
    std::string test_minus_dot = "-.";
    std::string test_dot = ".";
    std::string test_plus_dotf = "+.f";
    std::string test_minus_dotf = "-.1f";
    std::string test_dotf = "1.f";
    std::string test_dotf2 = "1.0f";
    std::string test_int2 = "123";
    std::string test_int3 = "-123";

// green if match, red if not
    if (ScalarConverter::detect_type(test_int) == "int")
        std::cout << GREEN << "int: " << test_int << " " << ScalarConverter::detect_type(test_int) << RESET << std::endl;
    else
        std::cout << RED << "int: " << test_int << " " << ScalarConverter::detect_type(test_int) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_float) == "double")
        std::cout << GREEN << "float: " << test_float << " " << ScalarConverter::detect_type(test_float) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_float << " " << ScalarConverter::detect_type(test_float) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_double) == "double")
        std::cout << GREEN << "double: " << test_double << " " << ScalarConverter::detect_type(test_double) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_double << " " << ScalarConverter::detect_type(test_double) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_char) == "char")
        std::cout << GREEN << "char: " << test_char << " " << ScalarConverter::detect_type(test_char) << RESET << std::endl;
    else
        std::cout << RED << "char: " << test_char << " " << ScalarConverter::detect_type(test_char) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_unknown) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_unknown << " " << ScalarConverter::detect_type(test_unknown) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_unknown << " " << ScalarConverter::detect_type(test_unknown) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_nan) == "double")
        std::cout << GREEN << "double: " << test_nan << " " << ScalarConverter::detect_type(test_nan) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_nan << " " << ScalarConverter::detect_type(test_nan) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_nanf) == "float")
        std::cout << GREEN << "float: " << test_nanf << " " << ScalarConverter::detect_type(test_nanf) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_nanf << " " << ScalarConverter::detect_type(test_nanf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_inf) == "double")
        std::cout << GREEN << "double: " << test_inf << " " << ScalarConverter::detect_type(test_inf) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_inf << " " << ScalarConverter::detect_type(test_inf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_inff) == "float")
        std::cout << GREEN << "float: " << test_inff << " " << ScalarConverter::detect_type(test_inff) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_inff << " " << ScalarConverter::detect_type(test_inff) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_inf) == "double")
        std::cout << GREEN << "double: " << test_plus_inf << " " << ScalarConverter::detect_type(test_plus_inf) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_plus_inf << " " << ScalarConverter::detect_type(test_plus_inf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_inff) == "float")
        std::cout << GREEN << "float: " << test_plus_inff << " " << ScalarConverter::detect_type(test_plus_inff) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_plus_inff << " " << ScalarConverter::detect_type(test_plus_inff) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_inf) == "double")
        std::cout << GREEN << "double: " << test_minus_inf << " " << ScalarConverter::detect_type(test_minus_inf) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_minus_inf << " " << ScalarConverter::detect_type(test_minus_inf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_inff) == "float")
        std::cout << GREEN << "float: " << test_minus_inff << " " << ScalarConverter::detect_type(test_minus_inff) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_minus_inff << " " << ScalarConverter::detect_type(test_minus_inff) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_nan) == "Unknown type")
        std::cout << GREEN << "Unkown type: " << test_plus_nan << " " << ScalarConverter::detect_type(test_plus_nan) << RESET << std::endl;
    else
        std::cout << RED << "Unkown type: " << test_plus_nan << " " << ScalarConverter::detect_type(test_plus_nan) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_nanf) == "Unknown type")
        std::cout << GREEN << "Unknow type: " << test_plus_nanf << " " << ScalarConverter::detect_type(test_plus_nanf) << RESET << std::endl;
    else
        std::cout << RED << "Unknow type: " << test_plus_nanf << " " << ScalarConverter::detect_type(test_plus_nanf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_nan) == "Unknown type")
        std::cout << GREEN << "Unknow type: " << test_minus_nan << " " << ScalarConverter::detect_type(test_minus_nan) << RESET << std::endl;
    else
        std::cout << RED << "Unknow type: " << test_minus_nan << " " << ScalarConverter::detect_type(test_minus_nan) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_nanf) == "float")
        std::cout << GREEN << "float: " << test_minus_nanf << " " << ScalarConverter::detect_type(test_minus_nanf) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_minus_nanf << " " << ScalarConverter::detect_type(test_minus_nanf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_nanf2) == "double")
        std::cout << GREEN << "double: " << test_minus_nanf2 << " " << ScalarConverter::detect_type(test_minus_nanf2) << RESET << std::endl;
    else
        std::cout << RED << "double: " << test_minus_nanf2 << " " << ScalarConverter::detect_type(test_minus_nanf2) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_nanf3) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_minus_nanf3 << " " << ScalarConverter::detect_type(test_minus_nanf3) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_minus_nanf3 << " " << ScalarConverter::detect_type(test_minus_nanf3) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_empty) == "char")
        std::cout << GREEN << "char: " << test_empty << " " << ScalarConverter::detect_type(test_empty) << RESET << std::endl;
    else
        std::cout << RED << "char: " << test_empty << " " << ScalarConverter::detect_type(test_empty) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_space2) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_space2 << " " << ScalarConverter::detect_type(test_space2) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_space2 << " " << ScalarConverter::detect_type(test_space2) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_space3) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_space3 << " " << ScalarConverter::detect_type(test_space3) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_space3 << " " << ScalarConverter::detect_type(test_space3) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_dot) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_plus_dot << " " << ScalarConverter::detect_type(test_plus_dot) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_plus_dot << " " << ScalarConverter::detect_type(test_plus_dot) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_dot) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_minus_dot << " " << ScalarConverter::detect_type(test_minus_dot) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_minus_dot << " " << ScalarConverter::detect_type(test_minus_dot) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_dot) == "char")
        std::cout << GREEN << "char: " << test_dot << " " << ScalarConverter::detect_type(test_dot) << RESET << std::endl;
    else
        std::cout << RED << "char: " << test_dot << " " << ScalarConverter::detect_type(test_dot) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_plus_dotf) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_plus_dotf << " " << ScalarConverter::detect_type(test_plus_dotf) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_plus_dotf << " " << ScalarConverter::detect_type(test_plus_dotf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_minus_dotf) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_minus_dotf << " " << ScalarConverter::detect_type(test_minus_dotf) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_minus_dotf << " " << ScalarConverter::detect_type(test_minus_dotf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_dotf) == "Unknown type")
        std::cout << GREEN << "Unknown type: " << test_dotf << " " << ScalarConverter::detect_type(test_dotf) << RESET << std::endl;
    else
        std::cout << RED << "Unknown type: " << test_dotf << " " << ScalarConverter::detect_type(test_dotf) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_dotf2) == "float")
        std::cout << GREEN << "float: " << test_dotf2 << " " << ScalarConverter::detect_type(test_dotf2) << RESET << std::endl;
    else
        std::cout << RED << "float: " << test_dotf2 << " " << ScalarConverter::detect_type(test_dotf2) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_int2) == "int")
        std::cout << GREEN << "int: " << test_int2 << " " << ScalarConverter::detect_type(test_int2) << RESET << std::endl;
    else
        std::cout << RED << "int: " << test_int2 << " " << ScalarConverter::detect_type(test_int2) << RESET << std::endl;
    if (ScalarConverter::detect_type(test_int) == "int")
        std::cout << GREEN << "int: " << test_int3 << " " << ScalarConverter::detect_type(test_int3) << RESET << std::endl;
    else
        std::cout << RED << "int: " << test_int3 << " " << ScalarConverter::detect_type(test_int3) << RESET << std::endl;


    return 0;
}
 */