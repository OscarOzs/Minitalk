/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:08:58 by oozsertt          #+#    #+#             */
/*   Updated: 2021/09/07 15:16:41 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
 
int main(int argc, char *argv[])
{
	pid_t pidServeur;
 
	/* Recuperation des arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Tapez %s pid\n", argv[0]);
		fprintf(stderr, "Ou\n\tpid : pid du serveur\n");
		exit(EXIT_FAILURE);
	}
	pidServeur = atoi(argv[1]);
 
	/* Envoi du premier signal */
	printf("Attente avant envoi premier signal\n");
	sleep(1);
	printf("Envoi premier signal\n");
	if (kill(pidServeur, SIGUSR1) == -1)
	{
		perror("Erreur lors de l'envoi du signal ");
		exit(EXIT_FAILURE);
	}
 
	/* Envoi du deuxieme signal */
	printf("Attente avant envoi deuxieme signal\n");
	sleep(2);
	printf("Envoi deuxieme signal\n");
	if (kill(pidServeur, SIGUSR2) == -1)
	{
		perror("Erreur lors de l'envoi du signal ");
		exit(EXIT_FAILURE);
	}
 
  return EXIT_SUCCESS;
}