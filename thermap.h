/*
 * thermap.h
 *
 * author: dannyno 2016
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef THERMAP_H_
#define THERMAP_H_

/*
 * types
 */
typedef long thermapTemp;
typedef unsigned long thermapR;
typedef struct
{
  thermapTemp temp;       // temperature
  thermapR R; // resistance (ohms)
}thermap_elt_t;

typedef struct
{
  const thermap_elt_t *table;
  unsigned int length;
}thermap_table_t;


#ifndef BOOL
#define BOOL unsigned char
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define T_FACTOR 100 /* for precision, multiply the returned temperature */

/*
 * prototypes
 */

/*
 * This function checks a table's consistency
 * A thermistor is expected to have a resistance that diminishes with
 * temperature. If the table describes another behavior, it will be
 * considered non consistent.
 *
 * Returns TRUE if it is consistent, FALSE otherwise
 */
BOOL thermap_check_table(thermap_table_t *pTable);

/*
 * Returns the table length
 */
unsigned int thermap_get_table_length(thermap_table_t *pTable);

/*
 * This function takes a measured resistance as input and returns
 * the corresponding temperature
 */
thermapTemp thermap_get_temp(thermapR r, thermap_table_t *pTable);

#endif /* THERMAP_H_ */

#ifdef __cplusplus
}
#endif
