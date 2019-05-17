#!/usr/bin/python

import numpy
import subprocess

subprocess.call(["root/fork"])

numpy.runtests.main(["--bench", "bench_core"])

subprocess.call(["root/done"])
