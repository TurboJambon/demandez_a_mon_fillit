NAME		=	fillit
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIB_PATH	=	libft
LIB			=	$(LIB_PATH)/libft.a
LIB_LINK	=	-L. $(LIB)

INC_DIR		=	includes
INCS		=	-I $(LIB_PATH) -I $(INC_DIR)

SRC_DIR		=	src
SRC			=	ft_afferror.c \
				main.c \
				ft_power.c \
				ft_filetostr.c \
				ft_fillit7.c \
				ft_fillit10.c \
				ft_fillit13.c \
				ft_affsolution.c \
				ft_sqrt.c \
				ft_initabl.c \
				ft_verif.c


OBJ_DIR		=	obj

SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_LINK)

$(LIB):
	make -C $(LIB_PATH)

obj:
	mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	rm -Rf $(OBJ_DIR)
	make -C $(LIB_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
