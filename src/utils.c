#include "practiceshell.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

/* Reads one line from stdin without the '\n'. Returns NULL on EOF (Ctrl+D). */
char	*read_line(const char *prompt, char *buf)
{
	size_t	len;

	printf("%s", prompt);
	fflush(stdout);
	if (!fgets(buf, BUF_SIZE, stdin))
		return (NULL);
	len = strlen(buf);
	if (len > 0 && buf[len - 1] == '\n')
		buf[len - 1] = '\0';
	return (buf);
}

void	print_file(const char *path)
{
	FILE	*f;
	int		c;

	f = fopen(path, "r");
	if (!f)
		return ;
	while ((c = fgetc(f)) != EOF)
		putchar(c);
	fclose(f);
}

void	ensure_dir(const char *path)
{
	mkdir(path, 0755);
}

static void	copy_file(const char *src, const char *dst)
{
	FILE	*in;
	FILE	*out;
	int		c;

	in = fopen(src, "r");
	out = fopen(dst, "w");
	if (in && out)
		while ((c = fgetc(in)) != EOF)
			fputc(c, out);
	if (in)
		fclose(in);
	if (out)
		fclose(out);
}

/* Copies the subject to subject/<name>/subject.txt, like in the real exam. */
void	install_subject(const t_exercise *ex)
{
	char	src[BUF_SIZE];
	char	dst[BUF_SIZE];

	snprintf(src, sizeof(src), SOLUTIONS_DIR "/Level_%d/%s/subject.txt",
		ex->level, ex->name);
	ensure_dir("subject");
	snprintf(dst, sizeof(dst), "subject/%s", ex->name);
	ensure_dir(dst);
	snprintf(dst, sizeof(dst), "subject/%s/subject.txt", ex->name);
	copy_file(src, dst);
}

/* Removes subject/<name>/ so only the current exercise is visible. */
void	remove_subject(const t_exercise *ex)
{
	char	path[BUF_SIZE];

	snprintf(path, sizeof(path), "subject/%s/subject.txt", ex->name);
	unlink(path);
	snprintf(path, sizeof(path), "subject/%s", ex->name);
	rmdir(path);
	rmdir("subject");
}

void	print_subject(const t_exercise *ex)
{
	char	path[BUF_SIZE];

	snprintf(path, sizeof(path), "subject/%s/subject.txt", ex->name);
	printf("\n" GREY "----------------------------------------" RESET "\n");
	print_file(path);
	printf("\n" GREY "----------------------------------------" RESET "\n");
}

/* Creates rendu/<name>/ so the user knows where to put the file. */
void	prepare_workspace(const t_exercise *ex)
{
	char	path[BUF_SIZE];

	snprintf(path, sizeof(path), "rendu/%s", ex->name);
	ensure_dir(path);
	printf("Subject: " YELLOW "subject/%s/subject.txt" RESET "\n", ex->name);
	printf("Write your solution in: " YELLOW "rendu/%s/%s.c" RESET "\n",
		ex->name, ex->name);
}
