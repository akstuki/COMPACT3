# -*- coding: utf-8 -*-
"""
Created on Sun May 10 10:21:16 2020

@author: xq
"""
from math import nan, isnan
from matplotlib import pyplot as plt 

CURRENT_HEADER = []
DIC_SET = {}
CPT3_FILE_NAME = r'tmp.sn6'
STAS_NOT_CHANGED_HDR_FIELD_COUNT = 2
SKIP_ROW_COUNT = 2
SAT_OFFSET = 2

def init_database() -> None:
    for inx in range(40):
        DIC_SET['C{0:02d}'.format(inx+1)]=[]
        DIC_SET['G{0:02d}'.format(inx+1)]=[]

def read_cpt3(filename:str):
    with open(filename) as f:
        for inx, line in enumerate(f.readlines()):
            parse_cpt3(inx, line)

def parse_cpt3(inx:int, line:str):
    if inx<SKIP_ROW_COUNT:
        return
    if inx%2==0:
        parse_header(line)
    else:
        parse_body(line)

def parse_header(line:str):
    global CURRENT_HEADER
    hdr = line.split()
    if len(hdr)==STAS_NOT_CHANGED_HDR_FIELD_COUNT:
        CURRENT_HEADER[0] = hdr[0]
    else:
        CURRENT_HEADER = hdr

def parse_body(line:str):
    for inx, val in enumerate(line.split()):
        DIC_SET[CURRENT_HEADER[inx+SAT_OFFSET]].append(float(val))
    for k in DIC_SET.keys():
        if k not in CURRENT_HEADER:
            DIC_SET[k].append(nan)

def all_nan(ls) -> bool:
    for val in ls:
        if not isnan(val):
            return False
    return True

def plot_data():
    for k in DIC_SET.keys():
        if all_nan(DIC_SET[k]):
            continue
        plt.plot(DIC_SET[k],label=k)
    plt.legend(loc='upper center',ncol=11)
    plt.title(CPT3_FILE_NAME)
    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    init_database()
    read_cpt3(CPT3_FILE_NAME)
    plot_data()

