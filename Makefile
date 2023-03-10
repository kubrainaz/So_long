SRCS = src/main.c src/check_1.c src/check_2.c src/screen_1.c src/utils.c src/event_1.c src/put_images.c src/free.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS = ./libft/libft.a ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./libft -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./libft
	make -C ./get_next_line
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line
	$(RM) $(NAME)

clean :
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./get_next_line
	make clean -C ./mlx
	$(RM) ./src/*.o

re : fclean all

.PHONY : all fclean clean re