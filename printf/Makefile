NAME=libftprintf.a

COMPILER=cc
FLAGS=-Wall -Wextra -Werror

FILES=ft_printf.c ft_put_letter.c ft_put_nbr.c
HEADER = ft_printf.h

OBJS=$(FILES:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(COMPILER) $(FLAGS) -c $*.c -o $*.o

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean:
	rm -fr $(OBJS) $(NAME)

re: fclean all
