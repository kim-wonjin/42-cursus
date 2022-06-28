/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:41:24 by sshin             #+#    #+#             */
/*   Updated: 2022/02/11 19:47:57 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_quote(char *str, int fd)
{
	int	i;

	i = 0;
	if (haveequal(str))
	{
		while (str[i] != '=')
			i++;
		write(fd, str, ++i);
		write(fd, "\"", 1);
		write(fd, str + i, ft_strlen(str + i));
		write(fd, "\"", 1);
	}
	else
	{
		while (str[i])
			i++;
		write(fd, str, ++i);
	}
}

void	print_export(char **envp, int fd)
{
	int		i;
	char	**sorted;

	i = 0;
	// 그냥 출력해도 되지만 sort하는 이유는 export 자체가 알파벳 순으로 정렬되어 출력 되기 때문에
	sorted = sort_env(envp);
	while (sorted[i])
	{
		// bash 출력양식으로 맞추기 위해서
		// USER=hyseo  zsh export
		// declare -x USER="hyseo"  minishell export

		// https://hashcode.co.kr/questions/1893/%EB%A6%AC%EB%88%85%EC%8A%A4-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98-%EC%84%A4%EC%A0%95%ED%95%A0-%EB%95%8C-env-set-export-declare
		// https://wiki.kldp.org/HOWTO/html/Adv-Bash-Scr-HOWTO/declareref.html
		// decalre -x
		// 이 선언은 스크립트 외부 환경에서도 이 변수를 쓸 수 있게 해 줍니다.
		// export 자체가 쉘변수를 환경변수로 변경해주는 명령이므로
		ft_putstr_fd("declare -x ", fd);
		print_quote(sorted[i], fd);
		ft_putchar_fd('\n', fd);
		free(sorted[i]);
		i++;
	}
	free(sorted);
}

int	check_key(char **envp, char *line)
{
	int i;
	int key;

	i = 0;
	key = 0;
	if (haveequal(line))
	{
		while (line[key] != '=')
			key++;
	}
	else
	{
		while (line[key])
			key++;
	}
	while (envp[i])
	{
		if (ft_strncmp(envp[i], line, key) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	add_envp(char *cmd, char ***envp)
{
	char	**new;
	int		row;
	int		i;

	i = 0;
	// 가장 마지막에 추가해야 하기 때문에 row 계산
	row = cnt_envp_row(*envp);
	// 새로운 값 + 마지막에 null 를 추가해야 하기 떄문에 +2 해서 malloc
	if (!(new = (char **)malloc(sizeof(char *) * (row + 2))))
		return (0);
	// 복사
	while ((*envp)[i])
	{
		new[i] = ft_strdup((*envp)[i]);
		free((*envp)[i]);
		i++;
	}
	free(*envp);
	new[i] = ft_strdup(cmd);
	new[++i] = NULL;
	*envp = new;
	return (1);
}

int	ft_export(t_cmd *cmd_list, char ***envp, int fd)
{
	int	i;
	int	keyindex;

	i = 1;
	// export d=d e=e  한번에 여러개도 등록 가능하기 때문에 while 사용
	while (cmd_list->cmdline[i].cmd && cmd_list->cmdline[i].redir_flag == 0)
	{
		// isvalid_export -> 키 첫글자가 숫자인 경우 제외 /  (영문이 아니고 _ 도 아닌경우 제외)
		if (isvalid_export(cmd_list->cmdline[i].cmd))
		{
			// check_key ->  '=' 나오기 전까지 체크해서 key로 등록하기 위해
			// envp에 같은 변수명이 있는지 확인 있으면 양수 리턴 (같은 환경변수의 index)
			if ((keyindex = check_key(*envp, cmd_list->cmdline[i].cmd)) >= 0)
			{
				// 같은 변수명이 있는 경우에 '='가 반드시 있어야 값만 변경 가능하기 때문에 확인 후
				// add_key_envp 로 기존 환경변수 free 후 새로 입력
				if (haveequal(cmd_list->cmdline[i].cmd))
					add_key_envp(envp, cmd_list->cmdline[i].cmd, keyindex);
			}
			// 같은 환경변수가 없는 경우 새로 추가
			else
				add_envp(cmd_list->cmdline[i].cmd, envp);
		}
		// errcode 5  -> error_write("minishell: %s: `%s': not a valid identifier\n",
		else
			cmd_list->err_manage.errcode = 5;
		i++;
	}
	// 그냥 export만 입력했을 경우 >> or > 로 인해 출력한 값을 넘겨주어야 할 경우
	if (!(cmd_list->cmdline[1].cmd) || cmd_list->cmdline[1].redir_flag == 1)
		print_export(*envp, fd);
	if (cmd_list->err_manage.errcode == 5)
		return (-1);
	return (1);
}
