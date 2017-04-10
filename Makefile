NAME = fdf
CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c env.c parallel.c draw.c key_event.c
OBJ = $(SRC:.c=.o)
LIBX = -lmlx -L libft/ -lft -framework AppKit\
	   -framework OpenGL
LIBXL = -lm -L libft/ -lft -L/usr/lib/X11 -lmlx -lXext -lX11

all : $(NAME)

.PHONY : linux libft clean fclean re norme

$(NAME) : libft
	@echo "Creating MAC executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBX)

linux: libft
	@echo "Creating LINUX executable $(NAME) ..."
	@gcc $(CFLAGS) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBXL)

libft:
	@make -C libft fclean
	@make -C libft

clean :
	@echo "Removing object files ..."
	@rm -f $(OBJ)

fclean : clean
	@echo "Removing $(NAME) ..."
	@rm -f $(NAME)

re : fclean all
