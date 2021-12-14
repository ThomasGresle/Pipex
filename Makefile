NAME		=	pipex

HEADER		=	./includes/

CC			=	clang

FLAGS		=	-g -Werror -Wall -Wextra -I $(HEADER)

SRCS		=	srcs/pipex.c \
			srcs/process.c \
			srcs/utils.c \
			srcs/utils_libft.c \
			srcs/ft_split.c \
			srcs/utils_split.c \

OBJS		=	$(SRCS:.c=.o)

.c.o		:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all		:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean		:
			rm -rf $(OBJS)

fclean		:	clean
			rm -f $(NAME)

re		:	fclean all
