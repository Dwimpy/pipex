/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split_wc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:20:53 by arobu             #+#    #+#             */
/*   Updated: 2022/12/01 03:57:55 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_split.h"

t_words	word_count(char *to_split, char delimiter)
{
	t_stack	*stack;
	t_words	words;
	int		word_end;
	char	*trimmed_str;
	char	*trimmed_str_ptr;

	stack = create_stack(2);
	trimmed_str = ft_strtrim_char(to_split, delimiter);
	trimmed_str_ptr = trimmed_str;
	words.word_count = 0;
	word_end = 0;
	while (*trimmed_str_ptr != '\0')
	{
		if (stack_is_empty_wc(&stack, &trimmed_str_ptr, \
							delimiter, &word_end))
			words.word_count += 1;
		else
			words.word_count += stack_not_empty_wc(&stack, &trimmed_str_ptr, \
													delimiter, &word_end);
		trimmed_str_ptr++;
	}
	free(trimmed_str);
	free_stack(stack);
	return (words);
}

int	stack_is_empty_wc(t_stack **stack, char **str, \
					char delimiter, int *word_end)
{
	if (isempty(*stack))
	{
		if (**str == 39)
			push(*stack, (char)39);
		if (**str != delimiter && \
		(*(*str + 1) == delimiter || *(*str + 1) == '\0'))
			*word_end = 1;
		if (*word_end == 1)
		{
			*word_end = 0;
			return (1);
		}
	}
	return (0);
}

int	stack_not_empty_wc(t_stack **stack, char **str, \
						char delimiter, int *word_end)
{
	if (!isempty(*stack))
	{
		if (**str == 39 && \
		(*(*str + 1) == delimiter || *(*str + 1) == '\0'))
		{
			pop(*stack);
			*word_end = 1;
		}
		if (*word_end == 1)
		{
			*word_end = 0;
			return (1);
		}
	}
	return (0);
}
