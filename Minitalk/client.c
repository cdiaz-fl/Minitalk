/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 07:35:25 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/23 20:42:17 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk.h"
#include	"libft/libft.h"
#include	<unistd.h>
#include	<signal.h>

int	main(int argc, char **argv)
{
	size_t							i;
	struct sigaction				act;

	if ((argc != 3) && write(1, "Wrong parameters\n", 17))
		return (1);
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = ft_receive;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	i = 0;
	ft_aux(argv, i, 0);
	return (0);
}

void	ft_aux(char **argv, size_t i, int count)
{
	while (i < ft_strlen(argv[2]))
	{
		count = 1 << 7;
		while (count)
		{
			usleep(50);
			if (count & argv[2][i])
			{
				if (kill(ft_atoi(argv[1]), SIGUSR1) == -1
					&& write(1, "Error: bad pid\n", 15))
					return ;
			}
			else
			{
				if (kill(ft_atoi(argv[1]), SIGUSR2) == -1
					&& write(1, "Error: bad pid\n", 15))
					return ;
			}
			usleep(50);
			count >>= 1;
			pause();
		}
		i++;
	}
}

void	ft_receive(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		write(1, "Received\n", 9);
	(void)context;
	(void)info;
}
