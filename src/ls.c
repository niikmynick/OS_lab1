//
// Created by Никита Кобик on 27.10.2024.
//
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "ls.h"

static void print_file_info(const char *name, const struct stat *file_stat) {
  printf((S_ISDIR(file_stat->st_mode)) ? "d" : "-");
  printf((file_stat->st_mode & S_IRUSR) ? "r" : "-");
  printf((file_stat->st_mode & S_IWUSR) ? "w" : "-");
  printf((file_stat->st_mode & S_IXUSR) ? "x" : "-");
  printf((file_stat->st_mode & S_IRGRP) ? "r" : "-");
  printf((file_stat->st_mode & S_IWGRP) ? "w" : "-");
  printf((file_stat->st_mode & S_IXGRP) ? "x" : "-");
  printf((file_stat->st_mode & S_IROTH) ? "r" : "-");
  printf((file_stat->st_mode & S_IWOTH) ? "w" : "-");
  printf((file_stat->st_mode & S_IXOTH) ? "x" : "-");

  printf(" %ld ", (long)file_stat->st_nlink);
  printf("%ld ", (long)file_stat->st_size);

  char time_buf[80];

  const struct tm *time_info = localtime(&file_stat->st_mtime);

  strftime(time_buf, sizeof(time_buf), "%b %d %H:%M", time_info);

  printf("%s ", time_buf);
  printf("%s\n", name);
}

void cmd_ls(char **args, int argc) {
  int show_all = 0; // a flag
  int detailed = 0; // l flag

  for (int i = 1; i < argc; i++) {
    if (strcmp(args[i], "-a") == 0) {
      show_all = 1;
    } else if (strcmp(args[i], "-l") == 0) {
      detailed = 1;
    } else if (strcmp(args[i], "-la") == 0 || strcmp(args[i], "-al") == 0) {
      show_all = 1;
      detailed = 1;
    }
  }

  DIR *dp = opendir(".");
  if (dp == NULL) {
    perror("opendir");
    return;
  }

  struct dirent *entry;

  while ((entry = readdir(dp)) != NULL) {
    if (!show_all && entry->d_name[0] == '.') {
      continue; // skip hidden files unless a flag is set
    }

    if (detailed) {
      struct stat file_stat;
      if (stat(entry->d_name, &file_stat) == 0) {
        print_file_info(entry->d_name, &file_stat);

      } else {
        perror("stat");
      }

    } else {
      printf("%s\n", entry->d_name);
    }
  }

  closedir(dp);
}