#include "practiceshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	print_menu(void)
{
	printf("\n" CYAN BOLD "=== Rank 02 (C) PracticeShell ===" RESET "\n\n");
	printf("[1] Start Exam\n");
	printf("[2] Practice Mode\n");
	printf("[3] List all exercises\n");
	printf("[q] Quit\n\n");
}

int	main(void)
{
	char	buf[BUF_SIZE];

	if (!load_exercises())
	{
		printf(RED "No exercises found." RESET
			" Run ./practiceshell from the repository root.\n");
		return (1);
	}
	srand(time(NULL));
	ensure_dir("rendu");
	while (1)
	{
		print_menu();
		if (!read_line("> ", buf) || !strcmp(buf, "q"))
			break ;
		if (!strcmp(buf, "1"))
			exam_mode();
		else if (!strcmp(buf, "2"))
			practice_mode();
		else if (!strcmp(buf, "3"))
			list_exercises();
		else
			printf(RED "Invalid option." RESET "\n");
	}
	free_exercises();
	printf("Bye! 👋\n");
	return (0);
}
