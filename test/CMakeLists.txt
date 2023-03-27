add_executable (test_connection "")
target_sources (test_connection PUBLIC ${CMAKE_CURRENT_LIST_DIR}/test_connection.c)
target_link_libraries (test_connection PUBLIC db_mysql)
add_test (NAME test_connection COMMAND test_connection)

add_executable (test_insert "")
target_sources (test_insert PUBLIC ${CMAKE_CURRENT_LIST_DIR}/test_insert.c)
target_link_libraries (test_insert PUBLIC db_mysql)
add_test (NAME test_insert COMMAND test_insert)

add_executable (test_update "")
target_sources (test_update PUBLIC ${CMAKE_CURRENT_LIST_DIR}/test_update.c)
target_link_libraries (test_update PUBLIC db_mysql)
add_test (NAME test_update COMMAND test_update)

add_executable (test_delete "")
target_sources (test_delete PUBLIC ${CMAKE_CURRENT_LIST_DIR}/test_delete.c)
target_link_libraries (test_delete PUBLIC db_mysql)
add_test (NAME test_delete COMMAND test_delete)