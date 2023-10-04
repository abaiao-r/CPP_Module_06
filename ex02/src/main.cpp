/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:53:38 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/05 00:40:34 by abaiao-r         ###   ########.fr       */
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
    if (r % 3 == 0)
        return (new A());
    else if (r % 3 == 1)
        return (new B());
    else
        return (new C());
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
}

/* identify() identifies the class of the object passed as parameter by using
 * dynamic_cast. Dynamic cast throws an exception if the cast fails. */
void identify(Base &p)
{
    Base temp;

    temp = p;
    try
    {
        temp = dynamic_cast<A&>(p);
        std::cout << BOLDGREEN << "Object is of type A" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        temp = dynamic_cast<B&>(p);
        std::cout << BOLDGREEN << "Object is of type B" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
    try
    {
        temp = dynamic_cast<C&>(p);
        std::cout << BOLDGREEN << "Object is of type C" << RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        (void)e;
    }
}

/* main() generates a random class derived from Base and identifies it by
 * pointer and by reference. */
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
    }
    std::cout << "--------------------------------------------" << std::endl;

    return (0);
}