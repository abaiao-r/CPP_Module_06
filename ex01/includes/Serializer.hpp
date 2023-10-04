/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:25:44 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/04 21:49:07 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <stdint.h>
# include "colours.hpp"
# include "data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer const &src);
    
    public:
        ~Serializer(void);
        Serializer &operator=(Serializer const &src);

        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif
