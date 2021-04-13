NAME = 2d_arr.a

HDRS = ./

SRCS = add_line.c new_2d.c free_2d.c dl_line.c

OBJS = $(SRCS:.c=.o)

CC = @gcc -Wall -Wextra -Werror
AR = @ar -rcs

%.o: %.c $(HRDS)libft.h
	$(CC) -c $< -o ${<:.c=.o} -I $(HDRS)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

tst: re
	gcc tst.c $(SRCS) -g
	rm -f $(OBJS)
	$(RM) $(NAME)


clean:
	rm -f $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re