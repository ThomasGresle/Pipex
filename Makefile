NAME		=	pipex

HEADER		=	./includes/

LIBFT		=	Libft/libft.a

CC			=	gcc

FLAGS		=	-g -Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/pipex.c \
			srcs/process.c \
			srcs/utils.c \

OBJS		=	$(SRCS:.c=.o)

.c.o		:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
			make -C ./Libft

clean		:
			rm -rf $(OBJS)

fclean		:	clean
			rm -f $(NAME)

libft		:
			@make -C Libft/ all

libftfclean	:
			@make -C Libft/ fclean

libftre		:
			@make -C Libft/ re
			@make re

re		:	fclean all
