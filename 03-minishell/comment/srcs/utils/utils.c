/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshin <sshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:42:43 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 10:50:30 by sshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != 32 && !(line[i] >= 9 && line[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

char	*strjoin_path(char const *s1, char const *s2)
{
	char	*tmp1;
	char	*tmp2;
	char	*result;
	int		i;
	int		j;

	tmp1 = (char*)s1;
	tmp2 = (char*)s2;
	i = 0;
	j = 0;
	if (!(result = (char*)malloc(ft_strlen(tmp1) + ft_strlen(tmp2) + 2)))
		return (0);
	while (tmp1[i] != '\0')
	{
		result[i] = tmp1[i];
		i++;
	}
	result[i++] = '/';
	while (tmp2[j] != '\0')
		result[i++] = tmp2[j++];
	result[i] = '\0';
	return (result);
}

void	free_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;
	int		i;

	while (cmd_list->next != NULL)
	{
		i = 0;
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		while (tmp->cmdline[i].cmd != NULL)
			free(tmp->cmdline[i++].cmd);
		free(tmp->cmdline);
		free(tmp->err_manage.errtoken);
		free(tmp);
	}
	i = 0;
	while (cmd_list->cmdline[i].cmd != NULL)
		free(cmd_list->cmdline[i++].cmd);
	free(cmd_list->cmdline);
	free(cmd_list->err_manage.errtoken);
	free(cmd_list);
}

// get_new_node(&line[start], lr_quote_pipe_flag[1], envp, start)
t_cmd	*get_new_node(char *line, int pipe_flag, char **envp, int exit_flag)
{
	t_cmd	*result;

	if (!(result = (t_cmd*)malloc(sizeof(t_cmd))))
		return (NULL);

	result->cmdline = get_cmdline(line, ' ');
	// (1) 토큰 개수 산정
	// (2) 토큰 제작
	// (3) 명령어를 토큰 단위로 분할하여 토큰에 값을 할당
	// (4) Initialize redirection flag

	alloc_token(result->cmdline, envp);
	// 토큰에 할당한 값을 다시 읽으며 구문분석 후 대치 작업 수행
	// (5) 각 토큰에 대해 ', ", $ 를 포함하는 경우를 고려하여 명령어 길이를 다시 산정
	// (6) ', " 를 포함하는 경우는 따옴표 제거
	// (7) $ 를 포함하는 경우는 환경변수 목록에서 매핑된 환경변수로 대치
	// ($?의 경우 예외 처리, 최근 실행한 명령어의 종료 스테이터스를 가진 변수의 값 출력)
	// (8) validate redirection cmd, set redirection flag

	// 나머지 맴버 변수의 값을 초기화한다.
	result->path = NULL;
	result->pipe_flag = pipe_flag;
	if (exit_flag == 0 && pipe_flag == 0) // 명령어가 없는경우
		result->exit_flag = 1;
	else
		result->exit_flag = 0;
	result->err_manage.errcode = 0;
	result->err_manage.errindex = 0;
	result->err_manage.errtoken = NULL;
	result->next = NULL;
	return (result);
}
