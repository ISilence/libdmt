#ifndef DLM_IBVERBS_MEMORY_H__
#define DLM_IBVERBS_MEMORY_H__

#include <infiniband/verbs.h>

#include <dlm/memory.h>

#define DLM_MEM_IB_MAGIC 0x1253

struct dlm_ib_mem {
	struct dlm_mem mem;
	struct dlm_mem *vms;

	struct ibv_pd *pd;
	struct ibv_mr *mr;
};

#define dlm_mem_to_ib(memobj) \
	dlm_mem_to_dlm((memobj), struct dlm_ib_mem, DLM_MEM_IB_MAGIC)
#define dlm_ib_to_mem(memobj) (&(memobj)->mem)

struct dlm_mem *dlm_ib_allocate_memory(struct ibv_pd *pd,
					size_t size,
					int mr_reg_flags);

#endif /* DLM_IBVERBS_MEMORY_H__ */