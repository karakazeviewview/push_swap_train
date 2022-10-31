/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsuo <mmatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:17:29 by mmatsuo           #+#    #+#             */
/*   Updated: 2022/11/01 02:17:30 by mmatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i = 5;
	while (i--)
	{
		printf("%d\n", i);
	}
	printf("\n");
	printf("\n");
	i = 5;
	while (i != 0)
	{
		printf("%d\n", i);
		i--;
	}
	
	
	return 0;
}
