#include "unifyfs_api.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

#include <stdio.h>

int main(int argc, char **argv)
{
    unifyfs_cfg_option uopts;

    unifyfs_rc urc;
    unifyfs_handle uhandle;
    unifyfs_gfid ufid;

    urc = unifyfs_initialize(".", &uopts, 0, &uhandle);
    urc = unifyfs_create(uhandle, O_CREAT|O_RDWR, argv[1], &ufid);

    char *source_str = "Hello, Unify world!\n";
    char dest_str[128];
    unifyfs_io_request ureqs[2] =  {
        {
        .user_buf = source_str,
        .nbytes = strlen(source_str),
        .gfid = ufid,
        .op = UNIFYFS_IOREQ_OP_WRITE
        },
        {
        .user_buf = dest_str,
        .nbytes = strlen("world"),
        .offset = 13,
        .gfid = ufid,
        .op = UNIFYFS_IOREQ_OP_READ
        }
    };

    urc = unifyfs_dispatch_io(uhandle, 2, ureqs);
    if (strcmp(dest_str, "world") != 0) {
        fprintf(stderr, "unify i/o test fails");
    }
    unifyfs_finalize(uhandle);
}
