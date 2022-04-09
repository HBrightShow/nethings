
aux_source_directory(. DIR_REDIS_SRCS)
add_library(nethings_redis ${DIR_REDIS_SRCS})

INCLUDE_DIRECTORIES(/usr/include/hiredis)
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)


