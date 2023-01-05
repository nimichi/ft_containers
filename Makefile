NAME = main
SRCS = main.cpp leak_checker.cpp memory_tracker.cpp
OBJS := ${SRCS:.cpp=.o}
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++14 #TODO remove -g flag

all: $(NAME)
%.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c -o $@ $<
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re

