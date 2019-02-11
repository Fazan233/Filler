NAME = vuslysty.filler
SRCS = filler.c free_2d_char.c get_real_token_size.c put_token.c
FLAGS =  

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft/
	@gcc -o $(NAME) $(FLAGS) $(OBJS) ./libft/libft.a

%.o: %.c
	@gcc $(FLAGS) -I./includes -I./libft/includes -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make -C ./libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean

re: fclean all