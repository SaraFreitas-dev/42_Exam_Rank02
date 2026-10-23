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

/* Asks for an exercise number until it is valid, "back" or "quit". */
t_action	practice_mode(void)
{
	char	buf[BUF_SIZE];
	int		choice;
	int		result;

	list_exercises();
	while (1)
	{
		if (!read_line("\nChoose an exercise number "
				GREY "(" CYAN "back" GREY " = menu, " CYAN "quit" GREY
				" = exit)" RESET ": ", buf) || is_quit(buf))
			return (ACT_QUIT);
		if (is_back(buf) || buf[0] == '\0')
			return (ACT_MENU);
		choice = atoi(buf);
		if (choice >= 1 && choice <= g_nb_exercises)
			break ;
		printf(RED "Invalid exercise: choose a number from 1 to %d."
			RESET "\n", g_nb_exercises);
	}
	result = run_exercise(&g_exercises[choice - 1], 0);
	if (result == EX_QUIT)
		return (ACT_QUIT);
	if (result == EX_BACK)
		return (ACT_MENU);
	return (ACT_PAUSE);
}
