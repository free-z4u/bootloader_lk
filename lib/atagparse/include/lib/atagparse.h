#ifndef ATAGPARSE_H
#define ATAGPARSE_H

#include <platform.h>

typedef enum {
	LKARGS_UEFI_BM_NORMAL = 0,
	LKARGS_UEFI_BM_RECOVERY,
} lkargs_uefi_bootmode;

uint32_t lkargs_get_machinetype(void);
const char* lkargs_get_command_line(void);
struct list_node* lkargs_get_command_line_list(void);
const char* lkargs_get_panel_name(const char* key);
uint32_t lkargs_get_platform_id(void);
uint32_t lkargs_get_variant_id(void);
uint32_t lkargs_get_hw_subtype(void);
uint32_t lkargs_get_soc_rev(void);
lkargs_uefi_bootmode lkargs_get_uefi_bootmode(void);
void* lkargs_get_tags_backup(void);
size_t lkargs_get_tags_backup_size(void);
bool lkargs_has_board_info(void);
bool lkargs_board_info_version(void);
void atag_parse(void);

bool lkargs_has_meminfo(void);
unsigned *lkargs_gen_meminfo_atags(unsigned *ptr);
uint32_t lkargs_gen_meminfo_fdt(void *fdt, uint32_t memory_node_offset);
void* lkargs_get_mmap_callback(void* pdata, platform_mmap_cb_t cb);
int lkargs_insert_chosen(void* fdt);
void* lkargs_atag_insert_unknown(void* tags);

#endif // ATAGPARSE_H
