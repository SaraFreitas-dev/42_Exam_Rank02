#include "practiceshell.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

t_exercise	*g_exercises = NULL;
int			g_nb_exercises = 0;
int			g_max_level = 0;

/* Sort by level, then alphabetically. */
static int	compare(const void *a, const void *b)
{
	const t_exercise	*ea;
	const t_exercise	*eb;

	ea = a;
	eb = b;
	if (ea->level != eb->level)
		return (ea->level - eb->level);
	return (strcmp(ea->name, eb->name));
}

static int	exists(const char *path)
{
	return (access(path, F_OK) == 0);
}

static void	add_exercise(const char *name, int level)
{
	char		path[BUF_SIZE];
	t_type		type;
	t_exercise	*tmp;

	snprintf(path, sizeof(path), SOLUTIONS_DIR "/Level_%d/%s/subject.txt",
		level, name);
	if (!exists(path))
		return ;
	snprintf(path, sizeof(path), TESTS_DIR "/Level_%d/%s/main.c", level, name);
	type = FUNCTION;
	if (!exists(path))
	{
		snprintf(path, sizeof(path), TESTS_DIR "/Level_%d/%s/args.txt",
			level, name);
		if (!exists(path))
		{
			printf(YELLOW "Warning: %s has no tests, skipped." RESET "\n", name);
			return ;
		}
		type = PROGRAM;
	}
	tmp = realloc(g_exercises, sizeof(t_exercise) * (g_nb_exercises + 1));
	if (!tmp)
		return ;
	g_exercises = tmp;
	snprintf(g_exercises[g_nb_exercises].name, NAME_SIZE, "%s", name);
	g_exercises[g_nb_exercises].level = level;
	g_exercises[g_nb_exercises].type = type;
	g_nb_exercises++;
	if (level > g_max_level)
		g_max_level = level;
}

/* Scans solutions/Level_1 ... Level_9. Returns the number of exercises. */
int	load_exercises(void)
{
	char			path[BUF_SIZE];
	DIR				*dir;
	struct dirent	*entry;
	int				level;

	for (level = 1; level <= MAX_LEVELS; level++)
	{
		snprintf(path, sizeof(path), SOLUTIONS_DIR "/Level_%d", level);
		dir = opendir(path);
		if (!dir)
			continue ;
		while ((entry = readdir(dir)) != NULL)
			if (entry->d_name[0] != '.')
				add_exercise(entry->d_name, level);
		closedir(dir);
	}
	if (g_nb_exercises > 0)
		qsort(g_exercises, g_nb_exercises, sizeof(t_exercise), compare);
	return (g_nb_exercises);
}

void	free_exercises(void)
{
	free(g_exercises);
	g_exercises = NULL;
	g_nb_exercises = 0;
}
