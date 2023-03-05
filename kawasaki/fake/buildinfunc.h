#pragma once

//#include "types.h"
//#include "hashmap.h"
#include "buildinfuncfile.h"
#include "buildinfuncrobot.h"


struct interpreter;
struct funcunion;

typedef void (*bifunc)(fake *fk, interpreter *inter);



class buildinfunc {
public:
    force_inline buildinfunc(fake *fk) : m_fk(fk), m_bifile(fk), m_bifrobot(fk){
    }

    force_inline ~buildinfunc() {
    }

    force_inline fake *getfake() {
        return m_fk;
    }

    force_inline void clear() {
        m_bifile.clear();
        m_bifrobot.clear();
    }

    void openbasefunc();

    void openfilefunc();

    void openrobotfunc(); 

    void set_print_func(fkprint func);

    fkprint get_print_func() const;

private:
    fake *m_fk;
    fkprint m_fkprint;
    buildinfuncfile m_bifile;
    buildinfuncrobot m_bifrobot;
    //buildinfuncos m_bifos;
    //buildinfuncstring m_bifstring;
    //buildinfuncmath m_bifmath;
};

// 参数和返回值都在m_fk->ps里
#define BUILDIN_FUNC_CALL(f, inter) \
    assert((f)->havebif);\
    assert((f)->bif); \
    ((f)->bif)(m_fk, (inter))
