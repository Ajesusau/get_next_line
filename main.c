/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:37:29 by anareval          #+#    #+#             */
/*   Updated: 2025/02/18 21:23:59 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
//#include "get_next_line.c"
//#include "get_next_line_utils.c"

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("No se puede abrir el archivo");
		return (1);
	}
	line = get_next_line(fd);
	while ((line))
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
