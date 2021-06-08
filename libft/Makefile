NAME	= libft.a

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I.
RM		= rm -f

SRCS	= 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c \
			ft_calloc.c ft_strdup.c\
			ft_substr.c ft_strjoin.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c

OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
OBJ_DIR = ../obj
ifeq ($(strip $(OBJ_DIR)), "")
  OBJ_DIR  = ../
endif

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c \
			ft_safe_free.c ft_malloc.c \
			ft_gnl.c
BONUS_OBJS	= 	$(addprefix $(OBJ_DIR)/,$(BONUS:.c=.o))

TEST 		=	test.c
TEST_OBJS	=	$(TEST:.c=.o)

.PHONY: all clean fclean re bonus
all: $(NAME)

$(NAME): $(OBJS)
	@echo "LIBRARY : $@"
	@ar rcs $(NAME) $(OBJS)
	@echo "@@ DONE @@"


$(OBJ_DIR)/%.o: %.c
	@echo "COMPILING: $@"
	@-mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LINUXFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@echo "REMOVE OBJECT FILE"

fclean:	clean
	@$(RM) $(NAME)
	@echo "REMOVE $(NAME)"

re:	fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "LIBRARY : $@"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "@@ DONE @@"
