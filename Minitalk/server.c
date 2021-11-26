/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 07:35:25 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/23 20:33:23 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"
#include	"libft/libft.h"
#include	<unistd.h>
#include	<signal.h>

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		return (1);
	write(1, ft_itoa(getpid()), ft_intlen(getpid()));
	write(1, "\n", 1);
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	act.sa_sigaction = ft_hand;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}

void	ft_hand(int signum, siginfo_t *info, void *context)
{
	static int	i;
	static char	str[9];
	char		c;

	(void)context;
	(void)info;
	str[8] = '\0';
	if (signum == SIGUSR1)
		str[i] = '1';
	else if (signum == SIGUSR2)
		str[i] = '0';
	usleep(50);
	if (i == 7)
	{
		c = ft_bitodec(str, 8, 0);
		write(1, &c, 1);
		i = -1;
	}
	usleep(50);
	i++;
	kill(info->si_pid, SIGUSR1);
}

int	ft_bitodec(char *str, int len, int result)
{
	size_t	count;
	size_t	len_copy;
	int		aux;

	count = 0;
	while (len)
	{
		len_copy = len - 1;
		aux = 1;
		while (len_copy)
		{
			aux *= 2;
			len_copy--;
		}
		if (str[count] == '1' && count == 7)
			result++;
		else if (str[count] == '1')
			result += aux;
		len--;
		count++;
	}
	return (result);
}
