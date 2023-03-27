#ifndef DB_MYSQL_H
#define DB_MYSQL_H

#include <stdbool.h>
#include <mysql.h>
#include <stdint.h>

typedef struct 
{
    MYSQL connection;
    const char *hostname;
    const char *user;
    const char *password;
    const char *database;
    uint16_t port;
} db_mysql_t;

typedef struct 
{
    const char *hostname;
    const char *user;
    const char *password;
    const char *database;
    uint16_t port;
} db_mysql_args_t;

typedef void (*db_mysql_on_result_set_t) (char **data, int columns, void *user);

bool db_mysql_init (db_mysql_t *object);
bool db_mysql_open (db_mysql_t *object, db_mysql_args_t *args);
bool db_mysql_execute (db_mysql_t *object, const char *query);
bool db_mysql_result_set (db_mysql_t *object, db_mysql_on_result_set_t on_result_set, void *user);
bool db_mysql_close (db_mysql_t *object);

#endif/* DB_MYSQL_H */
