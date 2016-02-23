/*
 * thermap.c
 *
 * author: dannyno 2016
 *
 */

#include "thermap.h"

/* see header */
BOOL thermap_check_table(thermap_table_t *pTable)
{
  unsigned int i;
  if (pTable->length == 0) return FALSE;
  if (pTable->length == 1) return TRUE;
  
  for (i = 1; i < pTable->length; i++)
  {
    if (pTable->table[i].temp < pTable->table[i-1].temp) return FALSE;
    if (pTable->table[i].R > pTable->table[i-1].R) return FALSE;
  }
  return TRUE;
}

/* see header */
thermapTemp thermap_get_temp(thermapR r, thermap_table_t *pTable)
{

  thermapTemp temp = 0;

  /* extreme cases */
  if (r > pTable->table[0].R) return pTable->table[0].temp * T_FACTOR;
  if (r < pTable->table[pTable->length - 1].R) return pTable->table[pTable->length - 1].temp * T_FACTOR;

  /* scan the table from the beginning
   * TODO: start from the middle */
  for (int i = 1; i < pTable->length - 1; i++)
  {
    if (r > pTable->table[i].R)
    {
      /* interpolate */
      thermapR r1 = pTable->table[i].R, r2 = pTable->table[i-1].R;
      thermapTemp T1 = pTable->table[i].temp, T2 = pTable->table[i-1].temp;

      /* for precision */
      T1 *= T_FACTOR;
      T2 *= T_FACTOR;

      temp = (thermapTemp)r*T2 - (thermapTemp)r*T1 - (thermapTemp)r1*T2 + (thermapTemp)r2*T1;
      temp /= (thermapTemp)(r2 - r1);

      break;

    }
  }
  return temp;
}
