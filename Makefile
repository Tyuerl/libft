srcs		= printf.c
DEL			= ${SRCS:.c=.o}

NAME		= printf

INCLUDES	= -I.

RM 			= rm -f

FLAGS		= -Wall -Wextra -Werror

GCC 		= gcc

LIB			= ar

FLAGS_LIB	= rc

HEAD		= ${NAME}.h

.PHONY:		all clean fclean re

all: 		${NAME}.a

.c.o:		${HEAD}
			
			${GCC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}		

${NAME}.a:	${DEL} ${HEAD}
			${LIB}  ${FLAGS_LIB} ${NAME} ${DEL}

clean:	
			${RM} ${DEL}

fclean:		clean
			${RM} ${NAME}.a
