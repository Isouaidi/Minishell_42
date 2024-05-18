LIBFT_PATH = ./libft
LIBFT_SRCS = ${addprefix ${LIBFT_PATH}/, ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_striteri.c \
			ft_strmapi.c \
			ft_split.c}

GNL_PATH = ./Get_Next_Line
GNL_SRCS = ${addprefix ${GNL_PATH}/, get_next_line_bonus.c\
									get_next_line_utils_bonus.c}

PRINTF_PATH = ./printf
PRINTF_SRCS = ${addprefix ${PRINTF_PATH}/, ft_strchr2.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_printhexa_max.c \
			ft_putnbr.c \
			ft_printhexa_min.c \
			ft_putinnbr.c \
			ft_putptr.c}

SRCS = ${GNL_SRCS} ${LIBFT_SRCS} ${PRINTF_SRCS}
OBJS = ${SRCS:.c=.o}
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs 
RM = rm -rf
INCLUDE = ./inc

%.o:%.c ${INCLUDE}    
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME}:${OBJS}
	@${AR} ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS} 

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
