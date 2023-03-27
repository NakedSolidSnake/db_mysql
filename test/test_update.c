#include <db_mysql.h>
#include <assert.h>
#include <string.h>

typedef struct 
{
    char value [100];
} name_t;

void on_result_set (char **data, int columns, void *user);

int main (int argc, char *argv[])
{

    db_mysql_t mysql;

    db_mysql_args_t args = 
    {
        .database = "test_db",
        .hostname = "mysql_db",
        .user = "root",
        .password = "root",
        .port = 3306
    };

    name_t name;

    assert (db_mysql_init (&mysql) == true);

    assert (db_mysql_open (&mysql, &args) == true);

    assert (db_mysql_execute (&mysql, "UPDATE test_tb s SET s.name='update' WHERE s.name='test';") == true);

    assert (db_mysql_execute (&mysql, "SELECT * FROM test_tb;") == true);

    assert (db_mysql_result_set (&mysql, on_result_set, &name) == true);

    assert (strcmp (name.value, "update") == 0);

    assert (db_mysql_close (&mysql) == true);
    
    return 0;
}

void on_result_set (char **data, int columns, void *user)
{
    name_t *name = (name_t *)user;
    strncpy (name->value, data[1], 100);
}