#include "config.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>

#include <unistd.h>

#include <stdio.h>

#include "unifyfs_api.h"


unifyfs_rc unifyfs_initialize(const char* mountpoint,
        unifyfs_cfg_option *options, int n_opts,
        unifyfs_handle *fshdl)
{
    return 0;
}

unifyfs_rc unifyfs_finalize(unifyfs_handle fshdl)
{
    return 0;
}

unifyfs_rc unifyfs_create(unifyfs_handle fshdl,
                          const int flags,
                          const char* filepath,
                          unifyfs_gfid* gfid)
{
    return unifyfs_open(fshdl, filepath, gfid);
}

unifyfs_rc unifyfs_open(unifyfs_handle fshdl,
                        const char* filepath,
                        unifyfs_gfid* gfid)

{
    int fd = open(filepath, O_CREAT|O_RDWR, 0644);
    *gfid = fd;
    return -errno;
}

unifyfs_rc unifyfs_close(unifyfs_handle fshdl,
                         const unifyfs_gfid gfid)
{
    return close(gfid);
}

unifyfs_rc unifyfs_dispatch_io(unifyfs_handle fshdl,
                               const size_t nreqs,
                               unifyfs_io_request* reqs)
{
    int i, ret=-1;
    for (i=0; i< nreqs; i++)
        switch(reqs[i].op) {
            case UNIFYFS_IOREQ_OP_READ:
                ret = pread(reqs[i].gfid, reqs[i].user_buf, reqs[i].nbytes, reqs[i].offset);
                break;
            case UNIFYFS_IOREQ_OP_WRITE:
                ret = pwrite(reqs[i].gfid, reqs[i].user_buf, reqs[i].nbytes, reqs[i].offset);
                break;
            default:
                fprintf(stderr, "I/O op unsupported\n");
        }
}
