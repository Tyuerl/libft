SRCS		=	ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_memmove.c \
				ft_memcpy.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memchr.c\
				ft_toupper.c ft_tolower.c ft_memcmp.c ft_strnstr.c\
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
				ft_putnbr_fd.c

DEL		= ${SRCS:.c=.o}

NAME		= libft

INCLUDES	= -I.

RM 		= rm -f

FLAGS	= -Wall -Wextra -Werror

GCC 	= gcc

LIB		= ar

FLAGS_LIB	= rc

HEAD		= libft.h



.c.o:		${HEAD}
			
			${GCC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}		

${NAME}:	${DEL} ${HEAD}
			${LIB}  ${FLAGS_LIB} ${NAME}.a ${DEL}

all: 		${NAME}

clean:	
			${RM} ${DEL}

fclean:		clean
			${RM} ${NAME}

re:			fclean all	
