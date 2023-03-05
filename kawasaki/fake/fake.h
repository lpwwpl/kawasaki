#pragma once

#include <string>
#include <list>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <typeinfo>
#include <stdio.h>
#include <algorithm>
#include "types.h"
#include "myflexer.h"
#include "fake-inc.h"
#include "compiler.h"
#include "binary.h"
#include "paramstack.h"
#include "interpreter.h"
#include "native.h"
#include "assembler.h"
#include "machine.h"
#include "stringheap.h"
#include "bindfunc.h"
#include "buildinfunc.h"
#include "profile.h"
#include "pool.h"
#include "processor.h"
#include "container.h"
#include "funcmap.h"
#include "running.h"
#include "parser.h"
#include "debuging.h"
#include "pointerheap.h"
#include "optimizer.h"
#include "gc.h"

struct fake {
    fake(fakeconfig c) : errorno(0), errorcb(0), cfg(c), pa(this), bin(this), nt(this), as(this, &nt), sh(this),
                         mac(this), bf(this), bif(this), pf(this), con(this), fm(this), rn(this), dbg(this), ph(this),
                         /*opt(this),*/ g(this) {
        POOL_INI(pp, this);
    }

    ~fake() {
        clear();
        POOL_DELETE(pp, processor, PROCESS_DELETE(*n));
        pf.clear(); // must at end
    }

    // ���
    void clear() {
        clearerr();
        pa.clear();
        bin.clear();
        nt.clear();
        as.clear();
        PS_CLEAR(ps);
        POOL_CLEAR(pp);
        sh.clear();
        mac.clear();
        bf.clear();
        bif.clear();
        con.clear();
        fm.clear();
        rn.clear();
        dbg.clear();
        ph.clear();
        //opt.clear();
        g.clear();
    }

    void clearerr() {
        errorno = 0;
        errorstr[0] = 0;
    }

    int errorno;
    char errorstr[512];
    fkerrorcb errorcb;

    // ����
    fakeconfig cfg;

    // ����
    parser pa;

    // ������
    binary bin;

    // ����jit����
    native nt;

    // �����
    assembler as;

    // c�Ĳ���ջ
    paramstack ps;

    // ִ��������
    pool<processor> pp;

    // �ַ�������
    stringheap sh;

    // ��ǰ�̱߳��ػ���
    machine mac;

    // ��C��������
    bindfunc bf;

    // �ڽ��ĺ�������
    buildinfunc bif;

    // ���ܼ��
    profile pf;

    // ����
    container con;

    // ��������
    funcmap fm;

    // ��ǰ����״̬
    running rn;

    // debug����
    debuging dbg;

    // pointer����
    pointerheap ph;

    // �Ż�
    //optimizer opt;

    // gc
    gc g;
};

template<typename T>
T *fknew(fake *fk) {
    T *t = (T *) fk->cfg.fkm(sizeof(T));
    new(t) T();
    return t;
}

template<typename T, typename P1>
T *fknew(fake *fk, P1 p1) {
    T *t = (T *) fk->cfg.fkm(sizeof(T));
    if (!t) {
        return 0;
    }
    new(t) T(p1);
    return t;
}

template<typename T>
void fkdelete(fake *fk, T *p) {
    if (p) {
        p->~T();
        fk->cfg.fkf(p);
    }
}

