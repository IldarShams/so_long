NAME = so_long
LIBFT = libft.a
LIBMLX = libmlx.dylib
GNL = get_next_line*bonus.o
SRCS = 	so_long.c map_utils.c map_utils2.c handlers.c moves.c print.c
LIB_PATH = ./Libft
HEADER = so_long.h
OBJ =   $(SRCS:%.c=%.o)
RM = rm -f
CFLAGS  =   -Wall -Wextra -Werror -I $(HEADER)
.PHONY  :   all clean fclean re gnl 
all	:   $(NAME)
$(NAME) : ${OBJ} ${HEADER} ${GNL} ${LIBFT} ${LIBMLX}
	cd ./Libft && make -f Makefile2
	gcc $(CFLAGS) get_next_line*.o ${OBJ} -o $(NAME) -L. -lft -L. -lmlx -framework OpenGL -framework AppKit
%.o : %.c ${HEADER}
	gcc $(CFLAGS) -c $< -o $@
clean   :
	$(RM) $(OBJ) ${GNL}
	cd ./Libft && make -f Makefile2 clean
	cd ./minilibx_mms_20200219 && make -f Makefile1 clean
fclean  :   clean
	$(RM) ${LIBFT} ${LIBMLX}
	$(RM) $(NAME)
${GNL}:
	gcc -c ./get_next_line/*bonus.c
${LIBMLX}:
	cd ./minilibx_mms_20200219 && make -f Makefile1 && mv libmlx.dylib ./..
${LIBFT}:
	cd ./Libft && make -f Makefile2 && mv ${LIBFT} ./..
re      :   fclean all
