/*
 * thermap.c
 *
 * author: dannyno 2016
 *
 */

#include "thermap.h"

BOOL thermap_check_table(thermap_elt_t *table, unsigned int table_len)
{
  unsigned int i;
  if (table_len == 0) return FALSE;
  if (table_len == 1) return TRUE;
  
  for (i = 1; i < table_len; i++)
  {
    if (table[i].temp < table[i-1].temp) return FALSE;
    if (table[i].R > table[i-1].R) return FALSE;
  }
  return TRUE;
}
