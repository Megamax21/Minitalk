NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = ft_printf.c \
       conversions/ft_print_chars.c \
       conversions/ft_print_p.c \
       conversions/ft_print_u.c \
       conversions/ft_print_xX.c \
	   utils/ft_putchar_fd.c\
	   utils/ft_itoa.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

.c.o:
	cc $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
