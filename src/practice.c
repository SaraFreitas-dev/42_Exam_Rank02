#include "practiceshell.h"
#include <stdio.h>
#include <stdlib.h>

void	list_exercises(void)
{
	int	level;
	int	i;

	for (level = 1; level <= g_max_level; level++)
	{
		printf(CYAN BOLD "\nLevel %d" RESET "\n", level);
		for (i = 0; i < g_nb_exercises; i++)
			if (g_exercises[i].level == level)
				printf("  [%2d] %s\n", i + 1, g_exercises[i].name);
	}
}

void	practice_mode(void)
{
	char	buf[BUF_SIZE];
	int		choice;

	list_exercises();
	if (!read_line("\nChoose an exercise number: ", buf))
		return ;
	choice = atoi(buf);
	if (choice < 1 || choice > g_nb_exercises)
	{
		printf(RED "Invalid exercise." RESET "\n");
		return ;
	}
	run_exercise(&g_exercises[choice - 1], 0);
}
