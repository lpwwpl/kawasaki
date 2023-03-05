#pragma once

#include "types.h"
#include "hashmap.h"
#include "buildindefine.h"
struct interpreter;
struct funcunion;

class buildinfuncrobot{
public:
    force_inline buildinfuncrobot(fake *fk) : m_fk(fk) {
    }

    force_inline ~buildinfuncrobot() {
        clear();
    }

    force_inline fake *getfake() {
        return m_fk;
    }

    force_inline void clear() {
    }

    void openrobotfunc();

private:
    fake *m_fk;
};

