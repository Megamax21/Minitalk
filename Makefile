CLIENT	= 	client
SERVER	= 	server
SRCS_C	=	srcs/client.c
SRCS_S =	srcs/server.c

INCLUDES	=	-Iincludes -Ilibft

OBJS_C		=	$(SRCS_C:.c=.o)
OBJS_S		=	$(SRCS_S:.c=.o)
CC			=	gcc
RM			=	@rm -rf

FLAGS		=	-Wall -Werror -Wextra $(INCLUDES) -g
LIBFT		=	libft/libft.a

.c.o:
	$(CC) -c $< -o $(<:.c=.o) $(FLAGS)

all : $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT) $(OBJS_S)
	$(CC) $(OBJS_S) $(FLAGS) -o $(SERVER) $(LIBFT)

$(CLIENT): $(LIBFT) $(OBJS_C)
	$(CC) $(OBJS_C) $(FLAGS) -o $(CLIENT) $(LIBFT)

$(LIBFT):
	@make  -C libft -f Makefile

clean :
	@make -s -C libft -f Makefile clean
	$(RM) $(OBJS_C) $(OBJS_S)

fclean:
	@make -s -C libft -f Makefile fclean
	$(RM) $(CLIENT) $(SERVER) $(OBJS_S) $(OBJS_C)
	$(RM) $(OBJS_S)$(OBJS_S)

re: fclean all

.PHONY: all clean fclean re
