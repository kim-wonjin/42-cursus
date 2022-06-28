/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:18 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:56:43 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/redir_chk.h"

// redirect cmd 가 있는지 확인. 정확하게 입력되어 있다면 1 리턴 > >> < << 만 1 리턴
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

// syntax error near unexpected token `>>'
// 잘못된 토큰이 무언인지 출력하기 위해 최대 >> 개밖에 출력이 안된다.
/// >>>>> 일 경우에도 syntax error near unexpected token `>>'  로 출력
// redir_flag 가 -1인 경우 >< 와 같은 예외를 찾기 위해서
// redir_flag 기본값은 0 -> 아예 없는 경우
// redir_flag 가 1인 경우 문제 없이 리다렉트기호가 있는 경우
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
		// 파싱부분 리디렉션 플래그가 있을 경우 (-1) 이 되었을 때 에러 코드 및 토큰 세팅
		if (cmd_list->cmdline[i].redir_flag == -1)
		{
			cmd_list->err_manage.errtoken =
							alloc_unexpected_token(cmd_list->cmdline[i].cmd);
			cmd_list->err_manage.errcode = 7;
			return (-1);
		}
		i++;
	}
	return (1);
}
