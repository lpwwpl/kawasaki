#include "buildinfuncrobot.h"
#include "fake.h"
#include "fake-inc.h"


// fopen
void buildin_fhome(fake *fk, interpreter *inter) {
    
    printf("home\n");
}

// fclose
void buildin_ftwait(fake *fk, interpreter *inter) {
    printf("twait\n");
}


void buildin_fsignal(fake *fk, interpreter *inter) {
    printf("signal\n");
}


void buildin_fbits(fake *fk, interpreter *inter) {

}

void buildin_fstop(fake* fk, interpreter* inter) {
    BIF_CHECK_ARG_NUM(0);
}

void buildin_fswait(fake* fk, interpreter* inter) {
    printf("swait\n");
}

void buildin_fjmove(fake* fk, interpreter* inter) {
    printf("jmove\n");
}
void buildin_ftype(fake* fk, interpreter* inter)
{
    printf("type\n");
}
void buildin_fsig(fake* fk, interpreter* inter)
{
    printf("sig\n");
}
void buildin_fbase(fake* fk, interpreter* inter)
{
    printf("base\n");
}
void buildin_ftool(fake* fk, interpreter* inter)
{
    printf("tool\n");
}
void buildinfuncrobot::openrobotfunc() {
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("HOME"), buildin_fhome);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("TWAIT"), buildin_ftwait);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("SIGNAL"), buildin_fsignal);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("BITS"), buildin_fbits);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("STOP"), buildin_fstop);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("SWAIT"), buildin_fswait);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("JMOVE"), buildin_fjmove);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("TYPE"), buildin_ftype); 
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("SIG"), buildin_fsig); 
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("BASE"), buildin_fbase);
    m_fk->fm.add_buildin_func(m_fk->sh.allocsysstr("TOOL"), buildin_ftool);
}

