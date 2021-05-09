## Overview
prase teqc plot data - compact3 format

## How to use
1. add COMPACT3.h and COMPACT3.cpp file to your project  
the demo code is in test.cpp
2. create a folder, e.g. bin
3. change to bin and run `cmake ..`
4. build and run you app

## Python plot
teqcplot.py is a python script to plot compact3 data file.

Below are some examples to use python3 to plot teqc output files.
```bash
py teqcplot.py +skyplot "43 2013-05-17 01-00-00.azi" "43 2013-05-17 01-00-00.ele" "43 2013-05-17 01-00-00.m12"
```
```bash
py teqcplot.py +azelplot "43 2013-05-17 01-00-00.azi" "43 2013-05-17 01-00-00.ele" "43 2013-05-17 01-00-00.d12"
```
```bash
py teqcplot.py +bandplot "43 2013-05-17 01-00-00.azi" "43 2013-05-17 01-00-00.ele" "43 2013-05-17 01-00-00.m12"
```
```bash
py teqcplot.py +azelplot "43 2013-05-17 01-00-00.azi" "43 2013-05-17 01-00-00.ele" "43 2013-05-17 01-00-00.m12"
```
