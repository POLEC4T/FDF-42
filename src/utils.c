/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:05 by mniemaz           #+#    #+#             */
/*   Updated: 2025/02/12 11:40:46 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @returns the the number of strs in strtab
 * @example ["123", "123", "abc"] => 3
 */
int	strtab_len(char **strtab)
{
	int	i;

	i = 0;
	while (strtab[i])
		i++;
	return (i);
}

/**
 * @returns the the number of valid numbers in strtab
 * @example ["123", "123", "abc"] => 2
 */
int	strtab_len_valid_nbs(char **strtab)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (strtab[i])
	{
		if (is_number_valid(strtab[i]))
			count++;
		i++;
	}
	return (count);
}

void	print_msg(enum msg_ids id)
{
	if (id == SUCCESS_ESC)
		write(1, "Successfully exited with ESC.\n", 30);
	if (id == ERROR_INV_MAP)
		write(2, "Error: The provided map is invalid.\n", 37);
	if (id == ERROR_INV_MAP_ROW_LEN)
		write(2, "Error: The provided map has invalid row lengths.\n", 50);
	if (id == ERROR_NO_FILE)
		write(2, "Error: The provided file does not exist.\n", 41);
	if (id == ERROR_MALLOC_BROKE)
		write(2, "Error: A malloc broke, crazy in'it ?\n", 36);
	if (id == ERROR_NO_MAP)
		write(2, "Error: Please provide a map file.\n", 34);
	if (id == ERROR_TOO_MANY_ARGS)
		write(2, "Error: Too many arguments provided.\n", 37);
	
}

void	exit_acc_to_msg_id(enum msg_ids id)
{
	if (id == ERROR_INV_MAP || id == ERROR_NO_FILE || id == ERROR_MALLOC_BROKE)
		exit (1);
	else if (id == SUCCESS_ESC)
		exit(0);
}

int open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
	return (fd);
}