/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:53:38 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/05 16:27:23 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/colours.hpp"
#include <cstdlib>
#include <exception>

/* generate() generates a random class derived from Base */
Base *generate(void)
{
    int r;

    std::srand(clock());
    r = std::rand();
    if (r % 4 == 0)
        return (new A());
    else if (r % 4 == 1)
        return (new B());
    else if (r % 4 == 2)
        return (new C());
    else
        return (new Base());
}

/* identify() identifies the class of the object passed as parameter by using
 * dynamic_cast. Dynamic cast returns a null pointer if the cast fails. */
void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << BOLDGREEN << "A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << BOLDGREEN << "B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << BOLDGREEN << "C" << RESET << std::endl;
    else
        std::cerr << BOLDRED << "Unknown class" << RESET << std::endl;
}

/* identify() identifies the class of the object passed as parameter by using
 * dynamic_cast. Dynamic cast throws an exception if the cast fails. */
void identify(Base &p)
{

    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << BOLDGREEN << "A" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << BOLDGREEN << "B" << RESET << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << BOLDGREEN << "C" << RESET << std::endl;
            }
            catch(const std::exception& e)
            {
                (void)e;
                std::cerr << BOLDRED << "Unknown class" << RESET << std::endl;
            }
        }
    }
}

/* main() generates a random class derived from Base and identifies it by
 * pointer and by reference. It is usefull to see the difference between
 * dynamic_cast and reinterpret_cast.  we can see that dynamic_cast is
 * safer than reinterpret_cast because it throws an exception if the cast
 * fails.
 */
int main(void)
{

    for (int i = 0; i < 10; i++)
    {
        Base *p = generate();
        std::cout << BOLDYELLOW << "Identify by pointer: " << RESET;
        identify(p);
        std::cout << BOLDYELLOW << "Identify by reference: " << RESET;
        identify(*p);
        delete p;
        std::cout << "-------------------------------------\n\n\n" << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;

    return (0);
}