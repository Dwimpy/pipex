/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:48:11 by arobu             #+#    #+#             */
/*   Updated: 2022/12/03 16:16:53 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_split.h"

void	get_word_stack_empty(t_word **words, \
							t_arguments *args, t_stack **stack);
void	get_word_stack_not_empty(t_word **words, \
								t_arguments *args, t_stack **stack);
void	init_args(t_arguments *args, char *to_split, char delimiter);

void	create_words(t_words *words, char *to_split, char delimiter)
{
	int			word_counter;
	t_arguments	args;
	t_stack		*stack;
	t_word		*words_ptr;

	words_ptr = (*words).words;
	word_counter = (*words).word_count;
	(*words).words = words_ptr;
	init_args(&args, to_split, delimiter);
	stack = create_stack(2);
	while (*(args.trim_ptr) != '\0')
	{
		get_word_stack_empty(&words_ptr, &args, &stack);
		get_word_stack_not_empty(&words_ptr, &args, &stack);
		(args.trim_ptr)++;
	}
	(*words).words[word_counter].word = NULL;
	while (--word_counter >= 0)
		(*words).words[word_counter].word = ft_substr(args.trimmed_str, \
		(*words).words[word_counter].word_begins, \
		(*words).words[word_counter].word_ends - \
		(*words).words[word_counter].word_begins + 1);
	free_stack(stack);
	free(args.trimmed_str);
}

void	get_word_stack_empty(t_word **words, t_arguments *args, t_stack **stack)
{
	if (isempty(*stack))
	{
		if (*(*args).trim_ptr == 39)
		{
			push(*stack, 39);
			return ;
		}
		if ((*args).word_begin == 1 && \
			*(*args).trim_ptr != (*args).delimiter)
		{
			args->word_begin = 0;
			(**words).word_begins = \
			(*args).trim_ptr - (*args).trimmed_str;
		}
		if (*(args->trim_ptr) != args->delimiter && (*(args->trim_ptr + 1) \
		== args->delimiter || *(args->trim_ptr + 1) == '\0'))
			args -> word_end = 1;
		if (args -> word_end == 1)
		{
			args -> word_begin = 1;
			args -> word_end = 0;
			(**words).word_ends = ((*args).trim_ptr - args->trimmed_str);
			(*words)++;
		}
	}
}

void	get_word_stack_not_empty(t_word **words, \
								t_arguments *args, t_stack **stack)
{
	if (!isempty(*stack))
	{
		if (args -> word_begin && *(*args).trim_ptr == 39)
		{
			args -> word_begin = 0;
			(**words).word_begins = \
			(*args).trim_ptr - (*args).trimmed_str + 1;
		}
		if (*(args -> trim_ptr) == 39 && \
		(*(args ->trim_ptr + 1) == args -> delimiter || \
		*(args->trim_ptr + 1) == '\0'))
			args -> word_end = 1;
		if (args -> word_end == 1)
		{
			args -> word_begin = 1;
			args -> word_end = 0;
			pop(*stack);
			(**words).word_ends = ((*args).trim_ptr - \
									args->trimmed_str) - 1;
			(*words)++;
		}
	}
}

void	populate_fields(char ***split_words, t_words words, int word_counter)
{
	int	i;

	i = -1;
	while (++i < word_counter)
	{
		(*split_words)[i] = ft_strdup(words.words[i].word);
		if (!(*split_words)[i])
		{
			free_words_split(*split_words);
			(*split_words) = NULL;
			return ;
		}
	}
}

char	**pipex_split(char	*to_split, char delimiter)
{
	t_words	words;
	char	**split_words;
	int		word_counter;

	if (!to_split)
		return (NULL);
	words = word_count(to_split, delimiter);
	word_counter = words.word_count;
	words.words = (t_word *)malloc(sizeof(t_word) * (words.word_count + 1));
	if (!words.words)
		return (NULL);
	split_words = (char **)malloc(sizeof(char *) * (word_counter + 1));
	if (!split_words)
		return (NULL);
	split_words[word_counter] = 0;
	create_words(&words, to_split, delimiter);
	populate_fields(&split_words, words, word_counter);
	free_words(&words);
	return (split_words);
}
