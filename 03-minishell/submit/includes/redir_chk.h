/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:47:23 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:21:48 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_CHK_H
# define REDIR_CHK_H

# include <stdio.h>
# include "../libft/libft.h"
# include "structs.h"

int	redir_chk(char *str);
int	redir_err_chk(t_cmd *cmd_list);

#endif
