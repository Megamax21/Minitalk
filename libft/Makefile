NAME = libft.a
FLAGS = -Wall -Wextra -Werror -Ignl
RM = rm -rf

PRINTF_DIR = printf

SRCS = ft_atoi.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c\
	ft_memcpy.c ft_memset.c ft_strchr.c\
	ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strrchr.c ft_tolower.c ft_toupper.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_bzero.c ft_memchr.c ft_putnbr_fd.c\
	ft_memcmp.c ft_memmove.c\
	ft_strnstr.c ft_strncmp.c ft_calloc.c\
	ft_strdup.c ft_itoa.c ft_substr.c\
	ft_strjoin.c ft_strtrim.c ft_split.c\
	ft_strmapi.c ft_striteri.c ft_safe_atoi.c\
	gnl/get_next_line.c gnl/get_next_line_utils.c\

SRCS_BONUS = ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

PRINTF = $(PRINTF_DIR)/libftprintf.a

$(NAME): $(OBJS) $(OBJS_BONUS) $(PRINTF) $(GNL)
	ar rcs -o $(NAME) $(OBJS) $(OBJS_BONUS)

$(PRINTF):
	make -C $(PRINTF_DIR)



.c.o:
	cc $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make -C $(PRINTF_DIR) clean

fclean : clean
	$(RM) $(NAME) $(PRINTF)
    
re: fclean all

.PHONY: all clean fclean re bonus rebonus
