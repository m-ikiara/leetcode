#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 5000

typedef struct Item_s {
    char *key;
    char *value;
    struct Item_s *next;
} Item;

typedef struct {
    Item **items;
} Table;

int lengthOfLongestSubstring(char *s);
size_t hash_function(char *str);
Item *create_item(char *key, char *value);
Table *create_table(size_t size);
void hash_table_set(Table *hash_table, char *key, char *value);
char *hash_table_get(Table *hash_table, char *key);

size_t
hash_function(char *str)
{
    size_t i = 0;

    for (int j = 0; str[j]; ++j) i += str[j];

    return i % TABLE_SIZE;
}

void
hash_table_set(Table *hash_table, char *key, char *value)
{
    size_t slot = hash_function(key);
    Item *entry = hash_table->items[slot];

    if (!entry) {
        hash_table->items[slot] = create_item(key, value);
        return;
    }

    Item *previous_entry;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        previous_entry = entry;
        entry = previous_entry->next;
    }

    previous_entry->next = create_item(key, value);
}

char *
hash_table_get(Table *hash_table, char *key)
{
    size_t slot = hash_function(key);
    Item *entry = hash_table->items[slot];

    while (entry) {
        if (strcmp(entry->key, key) == 0) return entry->value;
        entry = entry->next;
    }

    return NULL;
}

Item *
create_item(char *key, char *value)
{
    Item *entry = malloc(sizeof(Item));

    if (entry) {
        entry->key = malloc(strlen(key) + 1);
        entry->value = malloc(strlen(value) + 1);

        strcpy(entry->key, key);
        strcpy(entry->value, value);

        entry->next = NULL;

        return entry;
    }

    return NULL;
}

Table *
create_table(size_t size)
{
    Table *hash_table = (Table *) malloc(sizeof(Table));

    if (hash_table) {
        hash_table->items = (Item **) malloc(sizeof(Item *) * size);

        for (size_t i = 0; i < size; ++i) hash_table->items[i] = NULL;

        return hash_table;
    }

    return NULL;
}

int
lengthOfLongestSubstring(char* s)
{
    if (strlen(s) == 0) return -1;
    
    int substr_length = INT_MIN;

    //for (int right = 0; right < (int) strlen(s); ++right) {
    //    while (str_table))
    //}

    return substr_length;
}

int
main(void)
{
    char *str[5] = {
        "abcabcbb", "bbbbb", "pwwkew", "bananamanana", "sorewachinchiny"
    };

    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < 5; ++i) {
        printf("[INFO] String '%s' in slot %zu\n",
                str[i],
                hash_function(str[i])
              );
    }

    return 0;
}
