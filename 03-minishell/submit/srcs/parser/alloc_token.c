/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:44 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 16:39:48 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/alloc_token.h"

int	alloc_env(char *src, char **dest, char **envp)
{
	int		src_idx;
	char	*key;
	char	*env_val;
	int		env_len;
	char	*status;

	src_idx = 0;
	if (src[1] == '?')
	{
		status = ft_itoa(g_exit_status);
		ft_memcpy(*dest, status, ft_strlen(status));
		*dest += ft_strlen(status);
		free(status);
		return (1);
	}
	if (next_quote_or_null(src, &dest) == 0)
		return (0);
	src_idx = get_envkey(src, &key);
	env_val = get_env_value(key, envp);
	env_len = ft_strlen(env_val);
	ft_memcpy(*dest, env_val, env_len);
	*dest += env_len;
	free(key);
	return (src_idx);
}

int	alloc_s_quote_cnt(char *src, char **dest)
{
	int	src_idx;
	int	dest_len;

	src_idx = 1;
	dest_len = 0;
	while (src[src_idx] && src[src_idx] != '\'')
	{
		src_idx++;
		dest_len++;
	}
	ft_memcpy(*dest, src + 1, dest_len);
	*dest += dest_len;
	return (src_idx);
}

int	alloc_d_quote_cnt(char *src, char **dest, char **envp)
{
	int	src_idx;

	src_idx = 1;
	while (src[src_idx] && src[src_idx] != '\"')
	{
		if (src[src_idx] == '$')
			src_idx += (alloc_env(&src[src_idx], dest, envp) + 1);
		else
		{
			**dest = src[src_idx];
			(*dest)++;
			src_idx++;
		}
	}
	return (src_idx);
}

void	copy_str(char *src, char *dest, char **envp)
{
	int		src_idx;
	int		size;
	char	*dest_end;

	size = 0;
	src_idx = -1;
	dest_end = dest;
	while (src[++src_idx])
	{
		if (src[src_idx] == '\'' && unclosed_quote(&src[src_idx], '\''))
			src_idx += alloc_s_quote_cnt(&src[src_idx], &dest_end);
		else if (src[src_idx] == '\"' && unclosed_quote(&src[src_idx], '\"'))
			src_idx += alloc_d_quote_cnt(&src[src_idx], &dest_end, envp);
		else if (src[src_idx] == '$')
			src_idx += alloc_env(&src[src_idx], &dest_end, envp);
		else if (src[src_idx])
		{
			*dest_end = src[src_idx];
			dest_end++;
		}
	}
	*dest_end = '\0';
}

t_token	*alloc_token(t_token *token, char **envp)
{
	int		cmd_len;
	size_t	i;
	char	*tmp_cmd;

	i = 0;
	while (token[i].cmd)
	{
		cmd_len = 0;
		tmp_cmd = token[i].cmd;
		cmd_len = get_parse_size(tmp_cmd, envp);
		if (token[i].cmd[0] == '<' || token[i].cmd[0] == '>')
		{
			if (redir_chk(token[i].cmd))
				token[i].redir_flag = 1;
			else
				token[i].redir_flag = -1;
		}
		token[i].cmd = (char *)malloc(sizeof(char) * (cmd_len + 1));
		copy_str(tmp_cmd, token[i].cmd, envp);
		free(tmp_cmd);
		i++;
	}
	return (token);
}
