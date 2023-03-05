#pragma once

#include "types.h"
#include "hashmap.h"
#define __MINGW64__
#ifndef __MINGW64__
#include <sys/mman.h>
#endif

struct func_native {
    String dump() const;

    // ����
    const char *m_name;
    // �ļ���
    const char *m_filename;
    // ����
    const char *m_packagename;
    // code
    char *m_buff;
    size_t m_size;
    // ����
    mutable func_native *m_backup;
};

#ifndef __MINGW64__

#define FUNC_NATIVE_INI(fn) \
    memset(&(fn), 0, sizeof(func_native))

#define FUNC_NATIVE_CODE_FREE(fn) munmap((fn).m_buff, (fn).m_size);

#define FUNC_NATIVE_DELETE(fn) \
    safe_fkfree(m_fk, (fn).m_name); \
    safe_fkfree(m_fk, (fn).m_filename); \
    safe_fkfree(m_fk, (fn).m_packagename); \
    FUNC_NATIVE_CODE_FREE(fn); \
    if ((fn).m_backup) \
    { \
        safe_fkfree(m_fk, (fn).m_backup->m_name); \
        safe_fkfree(m_fk, (fn).m_backup->m_filename); \
        safe_fkfree(m_fk, (fn).m_backup->m_packagename); \
        FUNC_NATIVE_CODE_FREE(*((fn).m_backup)); \
    } \
    safe_fkfree(m_fk, (fn).m_backup)
#else
#define FUNC_NATIVE_INI(fn)
#define FUNC_NATIVE_CODE_FREE(fn)
#define FUNC_NATIVE_DELETE(fn)
#endif

class native {
public:
    force_inline native(fake *fk) : m_fk(fk) {
    }

    force_inline ~native() {
    }

    force_inline fake *getfake() {
        return m_fk;
    }

    force_inline void clear() {
    }

    bool add_func(const variant &name, const func_native &nt);

    String dump() const;

private:
    fake *m_fk;
};

