/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:13:28 by arobu             #+#    #+#             */
/*   Updated: 2022/12/04 23:06:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define GNL_LINEBREAK '\n'
# define GNL_ERROR -1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_gnl
{
	char			*line;
	int				fd;
	int				read_bytes;
}				t_gnl;

void	create_node(t_gnl **node, int fd);

char	*ft_strdup_gnl(const char *string);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *str, unsigned int start_index, size_t len);

size_t	ft_strlen_gnl(const char *str);

#endif