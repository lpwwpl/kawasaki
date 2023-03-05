#include "codegen.h"
#include "semantic.h"
#include "myflexer.h"
#include "fake.h"
#include "variant.h"

int codegen::add_stack_identifier(const String &name, int line) {
    assert(m_block_identifiers_stack.size() > 0);
    if (get_cur_variable_pos(name) != -1) {
        return -1;
    }
    block_identifiers_list &list = m_block_identifiers_stack.back();
    list.push_back(block_identifiers(name, m_stackpos));
    int ret = m_stackpos;
    m_stackpos++;
    if (m_stackpos > m_maxstackpos) {
        m_maxstackpos = m_stackpos;
    }

    stack_variant_info tmp;
    memset(&tmp, 0, sizeof(tmp));
    strncpy(tmp.name, name.c_str(), name.size());
    tmp.name[sizeof(tmp.name) - 1] = 0;
    tmp.line = line;
    tmp.pos = ret;
    m_debug_block_identifiers_list.push_back(tmp);

    return ret;
}

int codegen::getconst(const variant &v) {
    for (int i = 0; i < (int) m_const_list.size(); i++) {
        variant &vv = m_const_list[i];
        bool b = false;
        V_EQUAL_V(b, (&vv), (&v));
        if (b) {
            return i;
        }
    }

    int pos = m_const_list.size();
    m_const_list.push_back(v);
    return pos;
}

int codegen::getcontaineraddr(command con, command key) {
    for (int i = 0; i < (int) m_containeraddr_list.size(); i++) {
        container_addr &pc = m_containeraddr_list[i];
        if (con == pc.con && key == pc.key) {
            return i;
        }
    }
    int pos = m_containeraddr_list.size();
    container_addr tmp;
    tmp.con = con;
    tmp.key = key;
    m_containeraddr_list.push_back(tmp);
    return pos;
}

void codegen::output(const char *filename, const char *packagename, const char *name, func_binary *bin) {
    assert(m_byte_code_list.size() == m_byte_lineno_list.size());

    bin->m_filename = stringdump(m_fk, filename, strlen(filename));
    bin->m_packagename = stringdump(m_fk, packagename, strlen(packagename));
    bin->m_name = stringdump(m_fk, name, strlen(name));

    bin->m_maxstack = m_maxstackpos;

    bin->m_size = m_byte_code_list.size();
    if (bin->m_size > 0) {
        bin->m_buff = (command *) safe_fkmalloc(m_fk, (bin->m_size * sizeof(command)), emt_func_binary);
        memcpy(bin->m_buff, &m_byte_code_list[0], bin->m_size * sizeof(command));
    }

    bin->m_lineno_size = m_byte_lineno_list.size();
    if (bin->m_lineno_size > 0) {
        bin->m_lineno_buff = (int *) safe_fkmalloc(m_fk, (bin->m_lineno_size * sizeof(int)), emt_func_binary);
        memcpy(bin->m_lineno_buff, &m_byte_lineno_list[0], bin->m_lineno_size * sizeof(int));
    }

    bin->m_const_list_num = m_const_list.size();
    if (bin->m_const_list_num > 0) {
        bin->m_const_list = (variant *) safe_fkmalloc(m_fk, (bin->m_const_list_num * sizeof(variant)), emt_func_binary);
        memcpy(bin->m_const_list, &m_const_list[0], bin->m_const_list_num * sizeof(variant));
    }

    bin->m_container_addr_list_num = m_containeraddr_list.size();
    if (bin->m_container_addr_list_num > 0) {
        bin->m_container_addr_list = (container_addr *) safe_fkmalloc(m_fk, (bin->m_container_addr_list_num *
                                                                             sizeof(container_addr)), emt_func_binary);
        memcpy(bin->m_container_addr_list, &m_containeraddr_list[0],
               bin->m_container_addr_list_num * sizeof(container_addr));
    }

    bin->m_debug_stack_variant_info_num = m_debug_block_identifiers_list.size();
    if (bin->m_debug_stack_variant_info_num > 0) {
        bin->m_debug_stack_variant_info = (stack_variant_info *) safe_fkmalloc(m_fk,
                                                                               (bin->m_debug_stack_variant_info_num *
                                                                                sizeof(stack_variant_info)),
                                                                               emt_func_binary);
        memcpy(bin->m_debug_stack_variant_info, &m_debug_block_identifiers_list[0],
               bin->m_debug_stack_variant_info_num * sizeof(stack_variant_info));
    }

    bin->m_fresh++;

    FKLOG("codegen out %s %d", name, m_maxstackpos);
}
