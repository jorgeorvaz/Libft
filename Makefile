SRCS    = ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strlen.c ft_strlcpy.c
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
