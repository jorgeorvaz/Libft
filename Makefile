SRCS    = 	ft_isascii.c \
 			ft_isprint.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isalnum.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_bzero.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_calloc.c \
			ft_strdup.c
OBJS    = ${SRCS:.c=.o}
NAME    = libft.a
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:    ${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}
all:        ${NAME}
clean:
			${RM} ${OBJS}
fclean:     clean
			${RM} ${NAME}
re:         fclean all
.PHONY: all clean fclean re
