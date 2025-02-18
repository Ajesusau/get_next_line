/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:29 by anareval          #+#    #+#             */
/*   Updated: 2025/02/18 17:38:12 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("main/test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("No se puede abrir el archivo");
		return (1);
	}
	line = get_next_line(fd);
	while ((line))
	{
		printf("%s\n", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
