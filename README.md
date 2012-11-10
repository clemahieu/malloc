# Linked List-based Malloc

## How it works

This is a simple implementation of `malloc()` and `free()`. It uses a first 
fit approach, backed by a linked list. That is, whenever `free()` is called, 
it stores the newly freed memory fragments in a linked list sorted by memory 
address and merges fragments which are adjacent in memory. Then when
`malloc()` is called, it first scans this list for an available memory
fragment. If none is found, it issues a request to the kernel to allocate
another piece of memory for it.

## Building and running

The static object (.so) library can be built simply by running

    make

There are no external dependencies. Running `make` produces `libmalloc.so`,
which can be used in another process by executing e.g.

    env LD_PRELOAD="./libmalloc.so" ls

Replace `ls` with the command you want to run. Alternately, you can use your
`libmalloc.so` for everything by executing

    export LD_PRELOAD="/path/to/libmalloc.so"

To switch back to the standard library, issue

    export LD_PRELOAD=""

## Testing

A test script, `test.sh`, has been provided. This script simply runs a unit
test with the custom malloc library preloaded, as well as `ls --color=auto`.
The script can be easily modified to test other commands.
