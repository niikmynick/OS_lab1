//
// Created by Никита Кобик on 27.10.2024.
//

#ifndef EMA_SEARCH_INT_H
#define EMA_SEARCH_INT_H

#ifndef CHUNK_SIZE
#define CHUNK_SIZE (32 * 1024 * 1024) // 32 MiB
#endif


void cmd_ema_search_int(char **args, int argc);

#endif
