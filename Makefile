PUSH_SWAP	=	push_swap
CHECKER		=	checker
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	$(addprefix -I, $(HEADERS))
HEADERS		=	$(INC_DIR)includes/ $(LIB_DIR)includes/
LIBFT		=	$(LIB_DIR)libft.a

RM			=	rm -f
RM_DIR		=	rm -rf

SRCS_FILES	=	${shell find *.c} 

OBJ_FILES	=	$(SRCS_FILES:.c=.o)

PUSH_SRCS_NAME	= $(filter-out checker.c, $(SRCS_FILES))
PUSH_OBJS_NAME	= $(PUSH_SRCS_NAME:.c=.o)
PUSH_OBJS		= $(addprefix $(OBJ_DIR), $(PUSH_OBJS_NAME))

CHECK_SRCS_NAME	= $(filter-out push_swap.c, $(SRCS_FILES))
CHECK_OBJS_NAME	= $(CHECK_SRCS_NAME:.c=.o)
CHECK_OBJS		= $(addprefix $(OBJ_DIR), $(CHECK_OBJS_NAME))

SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC_DIR		=	./
SRCS_DIR	=	sources/
OBJ_DIR		=	objects/
LIB_DIR		=	libft/

.PHONY: all clean fclean re

all: $(PUSH_SWAP) $(CHECKER)

RED			=	"\033[31m"
GREEN		=	"\033[32m"
YELLOW		=	"\033[33m"
RESET		=	"\033[0m"

$(PUSH_SWAP): $(LIBFT) $(PUSH_OBJS)
	@$(CC) -o $(PUSH_SWAP) $(PUSH_OBJS) -L$(LIB_DIR) -lft
	@echo $(YELLOW)"@@@@@ push_swap compiling done @@@@@"$(RESET)

$(CHECKER): $(LIBFT) $(CHECK_OBJS)
	@$(CC) -o $(CHECKER) $(CHECK_OBJS) -L$(LIB_DIR) -lft
	@echo $(YELLOW)"@@@@@ checker compiling done @@@@@"$(RESET)

$(LIBFT):
	@make -C $(LIB_DIR)

## オブジェクトファイルの主力先を変えている
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@echo $(GREEN)"Creating: $@"$(RESET)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make -C $(LIB_DIR) clean
	@echo $(RED)"REMOVE OBJECT FILES"$(RESET)

fclean:	clean
	@$(RM) $(LIBFT)
	@echo $(RED)"REMOVE $(LIBFT)"$(RESET)
	@$(RM) $(PUSH_SWAP)
	@echo $(RED)"REMOVE $(PUSH_SWAP)"$(RESET)
	@$(RM) $(CHECKER)
	@echo $(RED)"REMOVE $(CHECKER)"$(RESET)

re:	fclean all
