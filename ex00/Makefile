# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 15:08:37 by abaiao-r          #+#    #+#              #
#    Updated: 2023/10/04 21:08:29 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g -fstandalone-debug #-fsanitize=address

# Directories
SRCDIR = src
OBJDIR = objs

# Source Files

SRCS =  $(SRCDIR)/main.cpp \
		$(SRCDIR)/ScalarConverter.cpp
		
OBJS = 	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Targets
NAME = Conversion_of_scalar_types

all: 	$(NAME)


clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -f $(NAME)

run:	fclean all
		./$(NAME)

re:		fclean all

test: 	all
		./$(NAME) 0
		./$(NAME) 42
		./$(NAME) 42.0f
		./$(NAME) 42.0
		./$(NAME) nan
		./$(NAME) nanf
		./$(NAME) inf
		./$(NAME) inff
		./$(NAME) -inf
		./$(NAME) -inff
		./$(NAME) -0
		./$(NAME) -0.0
		./$(NAME) -0.0f
		./$(NAME) 0.0
		./$(NAME) 0.0f
		./$(NAME) 0.f
		./$(NAME) 33.4321d
		./$(NAME) 33.4321f
		./$(NAME) 33.4321
		./$(NAME) 21212121
		./$(NAME) 2147483647
		./$(NAME) 2147483648
		./$(NAME) 2147483648.0
		./$(NAME) 2147483648.0f


valgrind: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o  $(NAME) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re run test
