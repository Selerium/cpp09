OS := ${shell uname}

CC := c++

NAME := PmergeMe

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp PmergeMe.cpp

OBJS := $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CC) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all bonus clean fclean re 
