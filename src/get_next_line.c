/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:12:00 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:29:51 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_node(t_gnl **node, int fd)
{
	(*node) = (t_gnl *)malloc(sizeof(t_gnl));
	if (!(*node))
		return ;
	(*node)->line = NULL;
	(*node)->fd = fd;
	(*node)->read_bytes = 1;
}

char	*ft_process_buffer(t_gnl **gnl, char *left_over)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(left_over, GNL_LINEBREAK) && (*gnl)->read_bytes > 0)
	{
		(*gnl)->read_bytes = read((*gnl)->fd, buffer, BUFFER_SIZE);
		if ((*gnl)->read_bytes == GNL_ERROR)
		{
			free(left_over);
			free(buffer);
			return (NULL);
		}
		buffer[(*gnl)->read_bytes] = '\0';
		left_over = ft_strjoin_gnl(left_over, buffer);
	}
	free(buffer);
	return (left_over);
}

char	*ft_get_line(t_gnl **gnl, char *left_over)
{
	size_t	size;

	if (!*left_over)
		return (NULL);
	size = ft_strchr_gnl(left_over, GNL_LINEBREAK) - left_over + 1;
	(*gnl)->line = ft_substr_gnl(left_over, 0, size);
	return ((*gnl)->line);
}

char	*ft_update_leftover(char *left_over)
{
	size_t	size;
	size_t	str_len;
	char	*left_over_str;

	left_over_str = (NULL);
	if (!*left_over)
	{
		free(left_over);
		return (NULL);
	}
	size = ft_strchr_gnl(left_over, GNL_LINEBREAK) - left_over + 1;
	str_len = ft_strlen_gnl(ft_strchr_gnl(left_over, GNL_LINEBREAK));
	left_over_str = ft_substr_gnl(left_over, size, str_len - 1);
	free(left_over);
	return (left_over_str);
}

char	*get_next_line(int fd)
{
	static char		*left_over;
	t_gnl			*gnl;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_node(&gnl, fd);
	left_over = ft_process_buffer(&gnl, left_over);
	if (!left_over)
	{
		free(gnl);
		return (NULL);
	}
	if (*left_over)
		line = ft_strdup_gnl(ft_get_line(&gnl, left_over));
	else
		line = NULL;
	left_over = ft_update_leftover(left_over);
	free(gnl -> line);
	free(gnl);
	return (line);
}
