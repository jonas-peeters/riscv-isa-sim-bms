require_extension(EXT_ZICOND);
int32_t offset = (insn.bits() >> 12 & 0x7FF) << 1;
int32_t address = (((int32_t)pc) + offset) & -2;
set_pc((uint32_t)address);
