OS := ${shell uname}

CC := c++

NAME := RPN

CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS := main.cpp RPN.cpp

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
