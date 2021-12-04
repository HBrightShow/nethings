
aux_source_directory(. DIR_MYSQL_SRCS)
add_library(nethings_mysql ${DIR_MYSQL_SRCS})






INCLUDE_DIRECTORIES(/usr/include/mysql)
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)




#TARGET_LINK_LIBRARIES(main_DBPool mysqlclient pthread) 
#TARGET_LINK_LIBRARIES(main_ThreadPool mysqlclient pthread) 
