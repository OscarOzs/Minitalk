/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:49:59 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 15:08:49 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int cpt = 0;

void handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("Signal 1 recu\n");
		cpt = cpt | 1;
	}
	if(signum == SIGUSR2)
	{
		printf("Signal 2 recu\n");
		cpt = cpt | 2;
	}
}
 
int main()
{
	struct sigaction action;
 
	/* Positionnement du gestionnaire pour SIGUSR1 */
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if(sigaction(SIGUSR1, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}

	/* Positionnement du gestionnaire pour SIGUSR2 */
	if(sigaction(SIGUSR2, &action, NULL) == -1)
	{
		perror("Erreur lors du positionnement ");
		exit(EXIT_FAILURE);
	}
 
	printf("Pret a recevoir des signaux. Mon PID : %d\n", getpid());
 
	/* Mise en attente jusqu'a recevoir au moins un signal SIGUSR1 et SIGUSR2 */
	while(cpt != 3)
	{
		sleep(1);
	}

	return EXIT_SUCCESS;
}