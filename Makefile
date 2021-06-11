NAME		=	push_swap
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	$(addprefix -I, $(INC_DIR))
INC_DIR		=	includes/ libft/includes/
LIBFT		=	libft/libft.a
RM			=	rm -f
RM_DIR		=	rm -rf
SRCS_FILES	=	admin_free.c \
				argv_utils.c \
				biggest_utils.c \
				error_exit.c \
				exec_utils.c \
				find_rot_cnt.c \
				find_utils.c \
				get_quartile.c \
				init_utils.c \
				is_sorted_utils.c \
				math_utils.c \
				move_node_to_end.c \
				plug_utils.c \
				push_half.c \
				push_quarter.c \
				push_swap.c \
				push_utils.c \
				quick_sort.c \
				range.c \
				reverse_rotate_utils.c \
				rotate_utils.c \
				smallest_utils.c \
				sort_6_or_less.c \
				sort_asc.c \
				sort_desc.c \
				sort_half.c \
				sort_quarter.c \
				stack_utils.c \
				swap_utils.c
OBJ_FILES	=	$(SRCS_FILES:.c=.o)

SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

SRCS_DIR	=	sources/
OBJ_DIR		=	objects/
LIB_DIR		=	libft/

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "LINKING : $@"
	@echo $(INCLUDES)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft
	@echo "@@ DONE @@"

$(LIBFT):
	@make -C $(LIB_DIR)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@echo "COMPILING: $@"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo "REMOVE OBJECT FILES"

fclean:	clean
	@$(RM) $(LIBFT)
	@echo "REMOVE $(LIBFT)"
	@$(RM) $(NAME)
	@echo "REMOVE $(NAME)"

re:	fclean all
