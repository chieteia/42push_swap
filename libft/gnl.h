#ifndef GNL_H
# define GNL_H

# include "libft.h"

int		make_line_and_set_stock(char **line, char **buff, char **stock);
int		make_buff(int fd, ssize_t *read_len, char **buff, char **stock);
int		make_stock(char **buff, char **stock);
int		get_next_line(int fd, char **line);

#endif