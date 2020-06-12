#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

#define RED (0)
#define GREEN (1)
#define BLOCK (9)

struct train_info {
    int number;
    struct block_info* dest;
};

struct block_info {
    struct train_info* train;
    struct block_info* next[2];
    int signal;
};

void print(struct block_info** blocks, int nblocks);
void set_number(struct block_info** blocks, int nblocks);
void set_signals(struct block_info** blocks, int nblocks);
void proceed(struct block_info** blocks, int nblocks);
int find_block(struct block_info* block, struct block_info* dest);

void start(struct block_info** blocks, int nblocks)
{
    set_signals(blocks, nblocks);
    print(blocks, nblocks);
    for (int i = 0; i < 4; i++) {
        printf("loop: %d\n", i + 1);
        proceed(blocks, nblocks);
        set_signals(blocks, nblocks);
        print(blocks, nblocks);
    }
}


int main(void) 
{
    struct block_info* blocks[BLOCK];
    set_number(&blocks[0], BLOCK);
    start(&blocks[0], BLOCK);

    return 0;
}

void proceed(struct block_info** blocks, int nblocks)
{

    struct block_info* block;
    for (int i = nblocks - 1; i >= 0; i--) {
        block = blocks[i];
        if (block->train == NULL) { continue; }
        if (block == block->train->dest) {
            block->train = NULL;
            continue;
        }
        for (int j = 0; j < 2; j++) {
            if (block->next[j] == NULL) { continue; }
            if (block->next[j]->signal == RED) { continue; }
            if (find_block(block->next[j], block->train->dest) == 1) {
                block->next[j]->train = block->train;
                block->next[j]->signal = RED;
                block->train = NULL;
                break;
            }
        }
    }
}

void set_signals(struct block_info** blocks, int nblocks)
{
    struct block_info* block;
    for (int i = 0; i < nblocks; i++) {
        block = blocks[i];
        if (block->train == NULL) { block->signal = GREEN; }
        else { block->signal = RED; }
    }
}

int find_block(struct block_info* block, struct block_info* dest)
{
    if (block == dest) { return 1; }
    for (int i = 0; i < 2; i++) {
        if (block->next[i] == NULL) { continue; }
        if (find_block(block->next[i], dest) == 1) { return 1; }
    }
    return 0;
}

void set_number(struct block_info** blocks, int nblocks)
{
    for (int i = 0; i < nblocks; i++) {
        blocks[i] = (struct block_info*)malloc(sizeof(struct block_info));
        blocks[i]->train = (struct train_info*)malloc(sizeof(struct train_info));
    }

    blocks[0]->train->number = 4;  blocks[0]->train->dest = blocks[8];
    blocks[1]->train->number = 3;  blocks[1]->train->dest = blocks[5];
    blocks[2]->train = NULL;
    blocks[3]->train->number = 2;  blocks[3]->train->dest = blocks[6];
    blocks[4]->train->number = 1;  blocks[4]->train->dest = blocks[5];
    blocks[5]->train = NULL;
    blocks[6]->train = NULL;
    blocks[7]->train = NULL;
    blocks[8]->train->number = 0;  blocks[8]->train->dest = blocks[8];

    blocks[0]->next[0] = blocks[2]; blocks[0]->next[1] = NULL;
    blocks[1]->next[0] = blocks[2]; blocks[1]->next[1] = NULL;
    blocks[2]->next[0] = blocks[3]; blocks[2]->next[1] = NULL;
    blocks[3]->next[0] = blocks[4]; blocks[3]->next[1] = blocks[7];
    blocks[4]->next[0] = blocks[5]; blocks[4]->next[1] = blocks[6];
    blocks[5]->next[0] = NULL;      blocks[5]->next[1] = NULL;
    blocks[6]->next[0] = NULL;      blocks[6]->next[1] = NULL;
    blocks[7]->next[0] = blocks[8]; blocks[7]->next[1] = NULL;
    blocks[8]->next[0] = NULL;      blocks[8]->next[1] = NULL;
}

void print(struct block_info** blocks, int nblocks)
{
    printf("-----------------------------------\n");
    for (int i = 0; i < nblocks; i++) {
        printf("Block: %d: ", i);
        if (blocks[i]->train != NULL)
            printf("train: %d, ", blocks[i]->train->number);
        printf("signal: %d\n", blocks[i]->signal);
    }
    printf("-----------------------------------\n");
}