/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_token.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:02 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:20:39 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_TOKEN_H
# define ALLOC_TOKEN_H

# include <stdlib.h>
# include "cmd_split.h"
# include "get_parse_size.h"
# include "ft_getenv.h"
# include "redir_chk.h"

extern int	g_exit_status;

int		alloc_d_quote_cnt(char *src, char **dest, char **envp);
int		alloc_s_quote_cnt(char *src, char **dest);
t_token	*alloc_token(t_token *token, char **envp);
int		next_quote_or_null(char *src, char ***dest);
int		get_envkey(char *src, char **key);

#endif
