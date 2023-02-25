/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_scanner.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:25:15 by arobu             #+#    #+#             */
/*   Updated: 2023/02/25 14:00:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_SCANNER_H
# define PIPEX_SCANNER_H

# include "ft_printf.h"
# include <stdlib.h>

/**

 @typedef t_pipex_scanner_results
 @brief Structure containing the results of parsing an input string
 @property {char *} parsed_input - the parsed input string
*/
typedef struct s_pipex_scanner_results
{
	char					*parsed_input;
}							t_pipex_scanner_results;
/**

 @typedef t_pipex_scanner
 @brief Structure containing information about the pipex scanner
 @property {int} size - size of the scanner results
 @property {t_pipex_scanner_results *} results - 
pointer to an array of scanner results
*/
typedef struct s_pipex_scanner
{
	int						size;
	t_pipex_scanner_results	*results;
}							t_pipex_scanner;

/**
 @function init_scanner
 @brief Initializes a pipex scanner object
 @param {int} here_doc - flag indicating whether the scanner is for a 
here document
 @param {int} argc - number of command-line arguments
 @param {int *} start_arg - pointer to the starting argument index
 @param {int *} end_arg - pointer to the ending argument index
 @returns {t_pipex_scanner *} A pointer to a new pipex scanner object
*/
t_pipex_scanner				*init_scanner(int here_doc, int argc,
								int *start_arg, int *end_arg);
/**

 @function scan_string
 @brief Scans a string for special characters and escapes them as necessary
 @param {char *} str - the string to scan
 @returns {char *} A pointer to the scanned string
*/
char						*scan_string(char *str);
/**

 @function display_scanner_results
 @brief Prints the results of a pipex scanner object
 @param {t_pipex_scanner *} scanner - pointer to the scanner object to display
*/
void						display_scanner_results(t_pipex_scanner *scanner);
/**

 @function fix_whitespace_helper
 @brief Helper function to fix whitespace in a scanned string
 @param {int *} has_whitespace - pointer to flag 
indicating whether there is whitespace to fix
 @param {char **} str - pointer to pointer to the 
scanned string
 @param {char **} begin - pointer to pointer to the 
beginning of the scanned string
*/
void						fix_whitespace_helper(int *has_whitespace, \
								char **str, \
								char **begin);
/**

 @function add_bytes
 @brief Helper function to add a character to a scanned string
 @param {char **} str - pointer to pointer to the scanned string
 @param {char} c - the character to add
*/
void						add_bytes(char **str, char c);
/**

 @function ft_free_scanner
 @brief Frees the memory allocated to a pipex scanner object
 @param {t_pipex_scanner *} scanner - pointer to the scanner object to free
*/
void						ft_free_scanner(t_pipex_scanner *scanner);
#endif
