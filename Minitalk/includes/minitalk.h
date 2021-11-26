/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:13:00 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/11/23 20:40:38 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include	<signal.h>

typedef struct s_all
{
	int	count;
	int	letter[8];
}	t_all;

int		main(int argc, char **argv);
void	ft_hand(int signum, siginfo_t *info, void *context);
int		ft_bitodec(char *str, int len, int result);
void	ft_receive(int signum, siginfo_t *info, void *context);
void	ft_aux(char **argv, size_t i, int count);

#endif
