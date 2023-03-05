#include "bindfunc.h"
#include "fake.h"
#include "fake-inc.h"


void buildin_gc(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    int force = fkpspop<int>(fk);

    fkcheckgc(fk, force != 0);
}

// print, very slow
void buildin_print(fake *fk, interpreter *inter) {
    String str;
    for (int i = 0; i < (int) fk->ps.m_variant_list_num; i++) {
        str += vartostring(&fk->ps.m_variant_list[i]);
    }
    // printf
    if (fk->bif.get_print_func()) {
        fk->bif.get_print_func()(fk, str.c_str());
    } else {
        printf("%s\n", str.c_str());
    }
    PS_CLEAR(fk->ps);
    // ret
    fkpspush<int>(fk, (int) str.size());
}

// format, very slow
void buildin_format(fake *fk, interpreter *inter) {
    String formatstr;
    if (fk->ps.m_variant_list_num > 0) {
        formatstr = vartostring(&fk->ps.m_variant_list[0]);
    }

    String str;
    int j = 1;
    for (int i = 0; i < (int) formatstr.size(); i++) {
        if (formatstr[i] == '%') {
            if (i + 1 < (int) formatstr.size() && formatstr[i + 1] == '%') {
                str += formatstr[i];
                i++;
            } else {
                if (j < (int) fk->ps.m_variant_list_num) {
                    str += vartostring(&fk->ps.m_variant_list[j]);
                    j++;
                }
            }
        } else {
            str += formatstr[i];
        }
    }

    PS_CLEAR(fk->ps);
    // ret
    fkpspush<const char *>(fk, str.c_str());
}

// log, very slow
void buildin_log(fake *fk, interpreter *inter) {
    String str;
    for (int i = 0; i < (int) fk->ps.m_variant_list_num; i++) {
        str += vartostring(&fk->ps.m_variant_list[i]);
    }

    // log
    FILE *pLog = fopen("fk.log", "a+");
    if (pLog) {
        time_t clock1 = time(0);
        struct tm *tptr = localtime(&clock1);
        const char *func = fkgetcurfunc(fk);

        fprintf(pLog, "[%d.%d.%d, %d.%d.%d][%s] : %s\n",
                tptr->tm_year + 1990, tptr->tm_mon + 1, tptr->tm_mday, tptr->tm_hour, tptr->tm_min, tptr->tm_sec,
                func, str.c_str());

        fclose(pLog);
    }

    PS_CLEAR(fk->ps);

    // ret
    fkpspush<int>(fk, (int) str.size());
}

// array
void buildin_array(fake *fk, interpreter *inter) {
    bool err = false;
    variant_array *a = fk->con.newarray();
    variant *v = 0;
    PS_PUSH_AND_GET(fk->ps, v);
    V_SET_ARRAY(v, a);
}

// map
void buildin_map(fake *fk, interpreter *inter) {
    bool err = false;
    variant_map *m = fk->con.newmap();
    variant *v = 0;
    PS_PUSH_AND_GET(fk->ps, v);
    V_SET_MAP(v, m);
}

// gmap
void buildin_gmap(fake *fk, interpreter *inter) {
    bool err = false;
    variant_map *m = fk->con.newgmap();
    variant *v = 0;
    PS_PUSH_AND_GET(fk->ps, v);
    V_SET_MAP(v, m);
}

// size
void buildin_size(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    int len = 0;
    if (v->type == variant::STRING) {
        len = v->data.str->sz;
    } else if (v->type == variant::ARRAY) {
        len = ARRAY_SIZE(v->data.va->va);
    } else if (v->type == variant::MAP) {
        len = v->data.vm->vm.size();
    }
    fkpspush<int>(fk, len);
}

// debug
void buildin_debug(fake *fk, interpreter *inter) {
    for (int i = 0; i < (int) fk->ps.m_variant_list_num; i++) {
        variant *v = 0;
        v = (&fk->ps.m_variant_list[i]);
        USE(v);
    }

    PS_CLEAR(fk->ps);

    // ret
    fkpspush<int>(fk, 1);
}

// typeof
void buildin_typeof(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    const char *name = vartypetostring(v->type);
    fkpspush<const char *>(fk, name);
}

// range
void buildin_range(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(2);

    // pos
    int pos = fkpspop<int>(fk);

    // container
    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);

    if (v->type == variant::STRING) {
        if (pos >= 0 && pos < (int) v->data.str->sz) {
            char data[2];
            data[0] = v->data.str->s[pos];
            data[1] = 0;
            fkpspush<const char *>(fk, data);
        } else {
            fkpspush<const char *>(fk, "");
        }
    } else if (v->type == variant::ARRAY) {
        if (pos >= 0 && pos < (int) ARRAY_SIZE(v->data.va->va) && ARRAY_GET(v->data.va->va, pos)) {
            variant *ret = 0;
            PS_PUSH_AND_GET(fk->ps, ret);
            if (ARRAY_GET(v->data.va->va, pos)) {
                *ret = *(ARRAY_GET(v->data.va->va, pos));
            } else {
                *ret = NILV;
            }
        } else {
            fkpspush<bool>(fk, false);
        }
    } else if (v->type == variant::MAP) {
        if (pos >= 0 && pos < (int) v->data.vm->vm.size()) {
            variant *key = 0;
            PS_PUSH_AND_GET(fk->ps, key);

            variant *value = 0;
            PS_PUSH_AND_GET(fk->ps, value);

            const fkhashmap<variant, variant *>::ele *e = v->data.vm->vm.at(pos);
            *key = e->k;
            *value = *(*e->t);
        } else {
            fkpspush<bool>(fk, false);
            fkpspush<bool>(fk, false);
        }
    } else {
        fkpspush<bool>(fk, false);
    }
}

// dumpallfunc
void buildin_dumpallfunc(fake *fk, interpreter *inter) {
    const char *str = fk->bin.dump().c_str();
    fkpspush<const char *>(fk, str);
}

// dumpfunc
void buildin_dumpfunc(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    const char *func = fkpspopcstrptr(fk);
    const char *str = fk->bin.dump(func).c_str();
    fkpspush<const char *>(fk, str);
}

// dumpfuncmap
void buildin_dumpfuncmap(fake *fk, interpreter *inter) {
    const char *str = fk->fm.dump().c_str();
    fkpspush<const char *>(fk, str);
}

// dumpstringheap
void buildin_dumpstringheap(fake *fk, interpreter *inter) {
    const char *str = fk->sh.dump();
    fkpspush<const char *>(fk, str);
}

// dumppointerheap
void buildin_dumppointerheap(fake *fk, interpreter *inter) {
    const char *str = fk->ph.dump();
    fkpspush<const char *>(fk, str);
}

// dumpstat
void buildin_dumpstat(fake *fk, interpreter *inter) {
    const char *str = fk->pf.dumpstat();
    fkpspush<const char *>(fk, str);
}

// dumpmem
void buildin_dumpmem(fake *fk, interpreter *inter) {
    const char *str = fk->pf.dumpmem();
    fkpspush<const char *>(fk, str);
}

// dofile
void buildin_dofile(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    const char *file = fkpspopcstrptr(fk);
    bool ret = fkparse(fk, file);
    fkpspush<bool>(fk, ret);
}

// dostring
void buildin_dostring(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    const char *str = fkpspopcstrptr(fk);
    bool ret = fkparsestr(fk, str);
    fkpspush<bool>(fk, ret);
}

// getcurfile
void buildin_getcurfile(fake *fk, interpreter *inter) {
    const char *str = fkgetcurfile(fk);
    fkpspush<const char *>(fk, str);
}

// getcurline
void buildin_getcurline(fake *fk, interpreter *inter) {
    int line = fkgetcurline(fk);
    fkpspush<int>(fk, line);
}

// getcurfunc
void buildin_getcurfunc(fake *fk, interpreter *inter) {
    const char *str = fkgetcurfunc(fk);
    fkpspush<const char *>(fk, str);
}

// getcurcallstack
void buildin_getcurcallstack(fake *fk, interpreter *inter) {
    const char *str = fkgetcurcallstack(fk);
    fkpspush<const char *>(fk, str);
}

// geterror
void buildin_geterror(fake *fk, interpreter *inter) {
    const char *str = fkerrorstr(fk);
    fkpspush<const char *>(fk, str);
}

// isfunc
void buildin_isfunc(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    const char *str = fkpspopcstrptr(fk);
    bool ret = fkisfunc(fk, str);
    fkpspush<bool>(fk, ret);
}

// tonumber
void buildin_tonumber(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    double ret = 0;
    if (v->type == variant::STRING) {
        ret = atof(v->data.str->s);
    } else if (v->type == variant::REAL) {
        ret = v->data.real;
    } else if (v->type == variant::UUID) {
        ret = (double) v->data.uuid;
    }
    fkpspush<double>(fk, ret);
}

// tolong
void buildin_tolong(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    uint64_t ret = 0;
    if (v->type == variant::STRING) {
        ret = (uint64_t) atoll(v->data.str->s);
    } else if (v->type == variant::REAL) {
        ret = (uint64_t) v->data.real;
    } else if (v->type == variant::UUID) {
        ret = (uint64_t) v->data.uuid;
    }
    fkpspush<uint64_t>(fk, ret);
}

// tostring
void buildin_tostring(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    // container
    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    if (v) {
        fkpspush<const char *>(fk, vartostring(v).c_str());
    } else {
        fkpspush<const char *>(fk, "");
    }
}

// getconst
void buildin_getconst(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    const char *str = fkpspopcstrptr(fk);

    variant *v = 0;
    PS_PUSH_AND_GET(fk->ps, v);

    variant *gcv = fk->pa.get_const_define(str);
    if (gcv) {
        *v = *gcv;
    } else {
        *v = NILV;
    }
}

// pause
void buildin_pause(fake *fk, interpreter *inter) {
    printf("press any key to continue\n");
    getchar();
    fkpspush<bool>(fk, true);
}

// isinteger
void buildin_isinteger(fake *fk, interpreter *inter) {
    BIF_CHECK_ARG_NUM(1);

    bool err = false;
    variant *v = 0;
    PS_POP_AND_GET(fk->ps, v);
    if (v) {
        if (v->type == variant::REAL) {
            if ((int) v->data.real == v->data.real) {
                fkpspush<bool>(fk, true);
                return;
            }
        }
    }

    fkpspush<bool>(fk, false);
}

void buildinfunc::openbasefunc() {
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("gc"), buildin_gc);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("print"), buildin_print);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("format"), buildin_format);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("log"), buildin_log);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("array"), buildin_array);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr(MAP_FUNC_NAME), buildin_map);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr(GMAP_FUNC_NAME), buildin_gmap);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("size"), buildin_size);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("range"), buildin_range);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("debug"), buildin_debug);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("typeof"), buildin_typeof);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpallfunc"), buildin_dumpallfunc);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpfunc"), buildin_dumpfunc);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpfuncmap"), buildin_dumpfuncmap);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpstringheap"), buildin_dumpstringheap);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumppointerheap"), buildin_dumppointerheap);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpstat"), buildin_dumpstat);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dumpmem"), buildin_dumpmem);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dofile"), buildin_dofile);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("dostring"), buildin_dostring);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("getcurfile"), buildin_getcurfile);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("getcurline"), buildin_getcurline);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("getcurfunc"), buildin_getcurfunc);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("getcurcallstack"), buildin_getcurcallstack);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("geterror"), buildin_geterror);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("isfunc"), buildin_isfunc);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("tonumber"), buildin_tonumber);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("tostring"), buildin_tostring);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("tolong"), buildin_tolong);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("getconst"), buildin_getconst);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("pause"), buildin_pause);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("isinteger"), buildin_isinteger);
}

void buildinfunc::openfilefunc() {
    m_bifile.openfilefunc();
}

void buildinfunc::openrobotfunc() {
    m_bifrobot.openrobotfunc();
}

void buildinfunc::set_print_func(fkprint func) {
    m_fkprint = func;
}

fkprint buildinfunc::get_print_func() const {
    return m_fkprint;
}
