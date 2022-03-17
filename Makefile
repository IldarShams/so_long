NAME = so_long
SRCS = 	so_long.c map_utils.c map_utils2.c handlers.c moves.c print.c
LIB_PATH = ./Libft
HEADER = so_long.h
OBJ =   $(SRCS:%.c=%.o)
OBJ_B =   $(SRCS_B:%.c=%.o)
RM = rm -f
CFLAGS  =   -Wall -Wextra -Werror -I $(HEADER)
.PHONY  :   all clean fclean re gnl
all	:   $(NAME)
$(NAME) : ${OBJ} ${HEADER} gnl
	cd ./minilibx_mms_20200219 && make -f Makefile1 && mv libmlx.dylib ./..
	cd ./Libft && make -f Makefile2
	gcc $(CFLAGS) get_next_line*.o ${OBJ} -o $(NAME) -L./Libft -lft -L. -lmlx -framework OpenGL -framework AppKit
%.o : %.c ${HEADER}
	gcc $(CFLAGS) -c $< -o $@
clean   :
	$(RM) $(OBJ) $(OBJ_B) get_next_line*.o
	cd ./Libft && make -f Makefile2 clean
	cd ./minilibx_mms_20200219 && make -f Makefile1 clean
fclean  :   clean
	rm libmlx.dylib
	$(RM) $(NAME)
gnl:
	gcc -c ./get_next_line/*bonus.c

re      :   fclean all
