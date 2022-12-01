/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 02:42:59 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 16:59:26 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_SPLIT_H

# include "../libft/include/ft_printf.h"
# include "../include/pipex_stack.h"

typedef struct s_word
{
	int			word_begins;
	int			word_ends;
	char		*word;
}				t_word;

typedef struct s_words
{
	int			word_count;
	t_word		*words;
}				t_words;

typedef struct s_arguments
{
	int		word_begin;
	int		word_end;
	char	delimiter;
	char	*trimmed_str;
	char	*trimmed_str_ptr;
}				t_arguments;

t_words		word_count(char *to_split, char delimiter);
void		init_words(t_words *words);

char		**pipex_split(char *str, char delimiter);

int			stack_is_empty_wc(t_stack **stack, char **str, \
					char delimiter, int *word_end);
int			stack_not_empty_wc(t_stack **stack, char **str, \
					char delimiter, int *word_end);
void		free_words(t_words *words);
void		free_words_split(char **split_str);
#endif