/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:18 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:47:09 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redir_chk.h"

int	redir_chk(char *str)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (!ft_strncmp("<<", str, str_len) || !ft_strncmp(">>", str, str_len)
		|| !ft_strncmp("<", str, str_len) || !ft_strncmp(">", str, str_len))
		return (1);
	else
		return (0);
}

void	double_redirect_unexpected(char *redir, char **result)
{
	if (ft_strncmp(redir + 2, "<<", 2) == 0
		|| ft_strncmp(redir + 2, ">>", 2) == 0)
		(*result) = ft_substr(redir, 2, 2);
	else if (ft_strncmp(redir + 2, "<", 1) == 0
		|| ft_strncmp(redir + 2, ">", 1) == 0)
		(*result) = ft_substr(redir, 2, 1);
}

void	redirect_unexpected(char *redir, char **result)
{
	if (ft_strncmp(redir + 1, "<<", 2) == 0
		|| ft_strncmp(redir + 1, ">>", 2) == 0)
		(*result) = ft_substr(redir, 1, 2);
	else if (ft_strncmp(redir + 1, "<", 1) == 0
		|| ft_strncmp(redir + 1, ">", 1) == 0)
		(*result) = ft_substr(redir, 1, 1);
}

char	*alloc_unexpected_token(char *redir)
{
	char		*result;

	result = NULL;
	if (ft_strncmp(redir, "<<", 2) == 0)
		double_redirect_unexpected(redir, &result);
	else if (ft_strncmp(redir, ">>", 2) == 0)
		double_redirect_unexpected(redir, &result);
	else if (ft_strncmp(redir, "<", 1) == 0)
		redirect_unexpected(redir, &result);
	else if (ft_strncmp(redir, ">", 1) == 0)
		redirect_unexpected(redir, &result);
	return (result);
}

int	redir_err_chk(t_cmd *cmd_list)
{
	int	i;

	i = 0;
	while (cmd_list->cmdline[i].cmd)
	{
		if (cmd_list->cmdline[i].redir_flag == -1)
		{
			cmd_list->err_manage.errtoken
				= alloc_unexpected_token(cmd_list->cmdline[i].cmd);
			cmd_list->err_manage.errcode = 7;
			return (-1);
		}
		i++;
	}
	return (1);
}
