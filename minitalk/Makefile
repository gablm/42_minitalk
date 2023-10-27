SV_NAME=server
CL_NAME=client

COMPILER=cc
FLAGS=-Wall -Wextra -Werror
LIBS=-Llibft/ -lft

SV_FILES=server.c
CL_FILES=client.c
SV_BNS=server_bonus.c
CL_BNS=client_bonus.c
LIB_FLS=libft/libft.a

INCLUDES= -Iheaders/
SV_HEADERS= server.h
CL_HEADERS= client.h

all: $(SV_NAME) $(CL_NAME)

libft/libft.a:
	$(MAKE) -C libft all

$(SV_NAME): $(SV_FILES) $(SV_HEADERS) $(LIB_FLS)
	$(COMPILER) $(FLAGS) $(SV_FILES) -o $(SV_NAME) $(LIBS)

$(CL_NAME): $(CL_FILES) $(CL_HEADERS) $(LIB_FLS)
	$(COMPILER) $(FLAGS) $(CL_FILES) -o $(CL_NAME) $(LIBS)

clean:
	$(MAKE) -C libft clean

fclean:
	$(MAKE) -C libft fclean
	rm -fr $(SV_NAME) $(CL_NAME)

bonus: $(SV_BNS) $(CL_BNS) $(SV_HEADERS) $(CL_HEADERS) $(LIB_FLS)
	$(COMPILER) $(FLAGS) $(SV_BNS) -o $(SV_NAME) $(LIBS)
	$(COMPILER) $(FLAGS) $(CL_BNS) -o $(CL_NAME) $(LIBS)


re: fclean all
