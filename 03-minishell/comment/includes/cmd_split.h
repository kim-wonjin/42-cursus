/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:06 by sshin             #+#    #+#             */
/*   Updated: 2022/02/10 21:19:48 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_SPLIT_H
# define CMD_SPLIT_H

# include <stdlib.h>
# include "structs.h"

t_token	*get_cmdline(char const *s, char c);
void	put_quote_flag(char const *s, int *quote);
int		ft_split_cnt(char const *s, const char c);
char	*ft_alloc_word(int *idx, char const *s, const char c);

#endif
