# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 15:08:37 by abaiao-r          #+#    #+#              #
#    Updated: 2023/10/05 12:47:33 by andrefranci      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g #-fsanitize=address

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
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 42.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nan
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) nanf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) inf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) inff
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inf
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -inff
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) -0.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.0f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 0.f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321d
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321f
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 33.4321
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 21212121
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483647
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648.0
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 2147483648.0f
		

$(NAME): 	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o  $(NAME) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re run test
