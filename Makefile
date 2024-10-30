NAME = libftprintf.a

SRC = ft_printf.c ft_pchar.c ft_pnmb.c ft_prunmb.c ft_phex.c ft_pstr.c ft_ppnt.c

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)
		
fclean: clean
		@$(RM) $(NAME)
		
re: fclean all