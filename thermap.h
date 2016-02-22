/*
 * thermap.h
 *
 * author: dannyno 2016
 *
 */
#ifndef THERMAP_H_
#define THERMAP_H_

/*
 * types
 */
typedef struct
{
  int temp;       // temperature
  unsigned int R; // resistance (ohms)
}thermap_elt_t;


#ifndef BOOL
#define BOOL unsigned char
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/*
 * prototypes
 */
BOOL thermap_check_table(thermap_elt_t *table, unsigned int table_len);

#endif /* THERMAP_H_ */
