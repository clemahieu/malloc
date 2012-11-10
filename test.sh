#!/bin/bash

# Compile libmalloc.so and test if they do not exist.
if [ ! -e "libmalloc.so" ]
then
  make libmalloc.so
fi

if [ ! -e "test" ]
then
  make test
fi

echo "Executing unit test..."
env LD_PRELOAD="./libmalloc.so" ./test

echo "Executing integration test with ls..."
env LD_PRELOAD="./libmalloc.so" ls --color=auto

