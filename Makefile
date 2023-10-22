SV_NAME=server
CL_NAME=client

COMPILER=cc
FLAGS=-Wall -Wextra -Werror

SV_FILES=server.c
CL_FILES=client.c

INCLUDES = headers/
SV_HEADERS = server.h
CL_HEADERS = client.h

all: $(NAME)

$(NAME): $(SV_FILES) $(CL_FILES) $(SV_HEADERS) $(CL_HEADERS)
	$(MAKE) -C libft all
	$(MAKE) -C printf all
	$(COMPILER) $(FLAGS) $(SV_FILES) -I$(INCLUDES) -o $(SV_NAME) -Llibft/ -lft -Lprintf/ -lftprintf
	$(COMPILER) $(FLAGS) $(CL_FILES) -I$(INCLUDES) -o $(CL_NAME) -Llibft/ -lft -Lprintf/ -lftprintf

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean

fclean:
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean
	rm -fr $(SV_NAME) $(CL_NAME)

bonus: $(SV_FILES:.c=_bonus.c) $(CL_FILES:.c=_bonus.c) $(SV_HEADERS) $(CL_HEADERS)
	$(MAKE) -C libft all
	$(MAKE) -C printf all
	$(COMPILER) $(FLAGS) $(SV_FILES:.c=_bonus.c) -I$(INCLUDES) -o $(SV_NAME) -Llibft/ -lft -Lprintf/ -lftprintf
	$(COMPILER) $(FLAGS) $(CL_FILES:.c=_bonus.c) -I$(INCLUDES) -o $(CL_NAME) -Llibft/ -lft -Lprintf/ -lftprintf


re: fclean all
