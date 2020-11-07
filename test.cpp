// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "COMPACT3.h"

int main(int argc, char* argv[]) {
    CCOMPACT3 compacts3;
    compacts3.loadfile("..//..//data//data.d12");
    for (int i=0;i<compacts3.count();++i) {
        const CCOMPACT3Record * record = compacts3.get(i);
        
        for(int j=0;j<record->num;++j)
        {
           printf("%f ", record->fvalue[j]);
        }
        printf("\n");
    }
    return 0;
}

