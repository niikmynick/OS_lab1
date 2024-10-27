//
// Created by Никита Кобик on 25.10.2024.
//

#ifndef COMMANDS_H
#define COMMANDS_H

#define CHUNK_SIZE (32 * 1024 * 1024) // 32 MiB

void cmd_pwd(char **args, int argc);
void cmd_cd(const char *path);
void cmd_ls(char **args, int argc);
void cmd_help(char **args, int argc);
void cmd_echo(char **args, int argc);
void cmd_cat(char **args, int argc);

void cmd_ema_search_int(char **args, int argc);
void cmd_bin_search(char **args, int argc);

void cmd_generate_data(char **args, int argc);
int compare_ints(const void *a, const void *b);

#endif
