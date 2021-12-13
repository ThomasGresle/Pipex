SRCS		= ./ft_putstr.c ./ft_putchar.c ./ft_atoi.c ./ft_strnstr.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_isalpha.c ./ft_itoa.c ./ft_memcpy.c ./ft_strchr.c ./ft_strlcpy.c ./ft_strtrim.c ./ft_bzero.c ./ft_isascii.c ./ft_memccpy.c ./ft_memmove.c ./ft_strdup.c ./ft_strlen.c ./ft_substr.c ./ft_calloc.c ./ft_isdigit.c ./ft_memchr.c ./ft_memset.c ./ft_strjoin.c ./ft_strncmp.c ./ft_tolower.c ./ft_isalnum.c ./ft_isprint.c ./ft_memcmp.c ./ft_split.c ./ft_strlcat.c ./ft_strrchr.c ./ft_toupper.c

SRCSB		= ./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c ./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c ./ft_lstdelone_bonus.c ./ft_lstclear_bonus.c ./ft_lstiter_bonus.c ./ft_lstmap_bonus.c

OBJS		= $(SRCS:.c=.o)

OBJSB		= $(SRCSB:.c=.o)

NAME		= libft.a

HEADER		= libft.h

CFLAGS		= -Wall -Wextra -Werror -I$(HEADER)

RM			= rm -f

CC			= cc

all:		$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

bonus:		$(OBJSB) $(OBJS) $(HEADER)
			ar rc $(NAME) $(OBJSB) $(OBJS)
			ranlib $(NAME)

clean:
			$(RM) $(OBJS) $(OBJSB)

fclean:		clean
			$(RM) $(NAME)

re :		fclean all

.PHONY:		re clean fclean
