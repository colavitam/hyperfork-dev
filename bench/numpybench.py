#!/usr/bin/python

import numpy
import subprocess

subprocess.call(["root/fork"])

numpy.core.test()

subprocess.call(["root/done"])
