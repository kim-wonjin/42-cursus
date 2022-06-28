/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parse_size.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:14 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:21:03 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PARSE_SIZE_H
# define GET_PARSE_SIZE_H

# include "../libft/libft.h"
# include <stdio.h>

extern int	g_exit_status;

int	env_value_size(char *str, int size, char **envp);
int	env_key_size(char *str);
int	env_cnt(char *str, int *size, char **envp);
int	d_quote_cnt(char *str, int *size, char **envp);
int	s_quote_cnt(char *str, int *size);
int	get_parse_size(char *str, char **envp);
int	unclosed_quote(char *str, char quote);

#endif
