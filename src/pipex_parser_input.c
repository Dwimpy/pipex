/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parser_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:06:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/07 22:49:43 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_parser.h"

t_parser_input	*create_input(char	*str)
{
	t_parser_input	*input;
	char			*str_input_ptr;

	input = (t_parser_input *)malloc(sizeof(t_parser_input));
	input->str = ft_strdup(str);
	str_input_ptr = input->str;
	input->str = ft_strtrim(input->str, " \r\t\v\f\n");
	free(str_input_ptr);
	return (input);
}