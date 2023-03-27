#include <db_mysql.h>
#include <assert.h>

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

    assert (db_mysql_init (&mysql) == true);

    assert (db_mysql_open (&mysql, &args) == true);

    assert (db_mysql_close (&mysql) == true);
    
    return 0;
}