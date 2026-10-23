#include "practiceshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define B_CYAN  "\033[96m"
#define B_WHITE "\033[97m"
#define B_YEL   "\033[93m"
#define LINE    "────────────────────────────────────────────────────────"

static void	banner(void)
{
	printf(B_CYAN "╔══════════════════════════════════════════════════════╗\n");
	printf("║" RESET BOLD B_WHITE
		"           PRACTICESHELL - Rank 02 Practice           "
		RESET B_CYAN "║\n");
	printf("║" RESET GREY
		"                   C  ·  Common Core                  "
		RESET B_CYAN "║\n");
	printf("╚══════════════════════════════════════════════════════╝" RESET "\n");
}

static void	print_menu(void)
{
	printf("\033[H\033[2J");
	banner();
	printf("\n" B_WHITE "  Welcome to the Rank 02 PracticeShell." RESET "\n");
	printf(GREY "  Practice C with hidden tests and automatic grading."
		RESET "\n");
	printf(GREY "  %d exercises · %d levels" RESET "\n\n",
		g_nb_exercises, g_max_level);
	printf(B_YEL "  RULES:" RESET "\n");
	printf(GREY "   • You have 3 hours total.\n");
	printf("   • Exercises are assigned by level (1–%d).\n", g_max_level);
	printf("   • Pass one exercise per level to succeed.\n");
	printf("   • Write your solution in the rendu/ folder.\n");
	printf("   • Type grademe to submit.\n\n" RESET);
	printf(GREY LINE RESET "\n");
	printf(B_CYAN "  [1]" RESET " Start Exam\n");
	printf(B_CYAN "  [2]" RESET " Practice Mode " GREY "(choose exercise)"
		RESET "\n");
	printf(B_CYAN "  [3]" RESET " List all exercises\n");
	printf(B_CYAN "  [q]" RESET " Quit\n");
	printf(GREY LINE RESET "\n");
}

int	main(void)
{
	char		buf[BUF_SIZE];
	t_action	act;

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
		if (!read_line(BOLD B_WHITE "\n  > " RESET, buf) || is_quit(buf))
			break ;
		act = ACT_PAUSE;
		if (!strcmp(buf, "1"))
			act = exam_mode();
		else if (!strcmp(buf, "2"))
			act = practice_mode();
		else if (!strcmp(buf, "3"))
			list_exercises();
		else
			printf(RED "  Invalid option." RESET "\n");
		if (act == ACT_QUIT)
			break ;
		if (act == ACT_PAUSE && !read_line(GREY
				"\n  [Press Enter to return to menu]" RESET, buf))
			break ;
	}
	free_exercises();
	printf("Bye! 👋\n");
	return (0);
}
