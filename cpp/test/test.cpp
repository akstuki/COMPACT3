// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "COMPACT3.h"

int main(int argc, char* argv[]) {
    CCOMPACT3 compacts3;
    compacts3.loadfile("..//TESTDATA//o.m12");
    for (int i=0;i<compacts3.count();++i) {
        const CCOMPACT3Record * record = compacts3.get(i);
        printf("%d\n", record->num);
    }
    return 0;
}

