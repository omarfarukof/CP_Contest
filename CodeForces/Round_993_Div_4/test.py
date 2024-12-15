#!/usr/bin/env -S uv run

import os
# def get_count(k, l1, r1, l2, r2):
#     for n in range()
# write into a text file
with open("test.txt", "w") as f:
    for i in range(1,11):
        for j in range(10):
            f.write(f"2 1 1 {i} {i+j}\n")

    for i in range(1,3):
        for j in range(10):
            f.write(f"2 1 2 {i} {i+j}\n")

    f.close()