#include <db_mysql.h>
#include <string.h>

static bool db_mysql_is_args_valid (db_mysql_args_t *args);
static bool db_mysql_connect (db_mysql_t *object);

bool db_mysql_init (db_mysql_t *object)
{
	bool status = false;

	if (object != NULL)
	{
		memset (object, 0, sizeof (db_mysql_t));
		status = true;
	}

	return status;
}

bool db_mysql_open (db_mysql_t *object, db_mysql_args_t *args)
{
	bool status = false;

	if (object != NULL && db_mysql_is_args_valid (args) == true)
	{
		object->hostname = args->hostname;
		object->user     = args->user;
		object->password = args->password;
		object->database = args->database;
		object->port     = args->port;

		status = db_mysql_connect (object);
	}

	return status;
}

bool db_mysql_execute (db_mysql_t *object, const char *query)
{
	bool status = false;

	if (object != NULL && query != NULL)
	{
		status = mysql_query (&object->connection, query) ? false : true;
	}

	return status;
}

bool db_mysql_result_set (db_mysql_t *object, db_mysql_on_result_set_t on_result_set, void *user)
{
	bool status = false;

	if (object != NULL && on_result_set != NULL && user != NULL)
	{

		MYSQL_RES *result = mysql_store_result (&object->connection);

		if (result != NULL)
		{
			MYSQL_ROW row;
			int fields = mysql_num_fields (result);

			while ((row = mysql_fetch_row (result)))
			{
				on_result_set (row, fields, user);
			}

			mysql_free_result (result);

			status = true;
		}

	}

	return status;
}

bool db_mysql_close (db_mysql_t *object)
{
	bool status = false;

	if (object != NULL)
	{
		mysql_close (&object->connection);

		memset (object, 0, sizeof (db_mysql_t));
		status = true;
	}

	return status;
}

static bool db_mysql_is_args_valid (db_mysql_args_t *args)
{
	bool status = false;

	if (args != NULL && 
		args->hostname != NULL &&
		args->database != NULL &&
		args->password != NULL && 
		args->user != NULL)
	{
		status = true;
	}

	return status;
}

static bool db_mysql_connect (db_mysql_t *object)
{
	bool status = false;

	MYSQL * result = NULL;

	mysql_init (&object->connection);

	result = mysql_real_connect (&object->connection,
								 object->hostname,
								 object->user,
								 object->password,
								 object->database,
								 object->port,
								 NULL,
								 0);
						
	status = (result == NULL) ? false : true;

	return status;
}