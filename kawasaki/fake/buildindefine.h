#pragma once

#define BIF_CHECK_ARG_NUM(n)  \
{ \
    if (UNLIKE((int)fk->ps.m_variant_list_num != n)) \
    {\
        FKERR("buildin func param not match, give %d need %d", (int)fk->ps.m_variant_list_num, n);\
        seterror(fk, efk_run_param_error, fkgetcurfile(fk), fkgetcurline(fk), fkgetcurfunc(fk), "buildin func param not match, give %d need %d", (int)fk->ps.m_variant_list_num, n);\
        return;\
    } \
}