/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anareval <anareval@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:18:26 by anareval          #+#    #+#             */
/*   Updated: 2025/02/11 13:01:38 by anareval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlnend(const char *str);

char	*get_next_line(int fd)
{
	char	*bff;
	int		lnend;
	char	*str;

	bff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!bff)
		return (NULL);
	if ((read(fd, bff, BUFFER_SIZE)) <= 0)
	{
		free(bff);
		return ("NULL");
	}
	bff[BUFFER_SIZE + 1] = '\0';
	lnend = ft_strlnend(bff);
	str = ft_strdup(bff);
	str[lnend] = '\0';
	return (str);
}

int	ft_strlnend(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (i);
}
