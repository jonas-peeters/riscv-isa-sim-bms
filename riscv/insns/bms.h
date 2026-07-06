// Xbmis BMS: functional model only — Spike has no branch predictor.
// Model choice: perfect predictor => never take the branch-free path
// (matches program behavior of the plain branchy variant). Flip
// BMS_MODEL_ALWAYS_MISPREDICT to model an always-wrong predictor instead.
// Encoding (spec section 3.1 / latex/sections/section42.tex):
//   bits[31:24] = branch offset  (simm9, LSB dropped)   -- unused here
//   bits[23:12] = branch-free target offset (simm13, LSB dropped)
//   bits[11:7]  = modifier                              -- unused here
#define BMS_MODEL_ALWAYS_MISPREDICT 0
#if BMS_MODEL_ALWAYS_MISPREDICT
// sign-extend the 12-bit field, restore the dropped LSB, keep full width
int64_t offset = ((int64_t)(int32_t)((insn.bits() >> 12) & 0xFFF)
                  << 52 >> 52) << 1;
reg_t address = (pc + offset) & ~(reg_t)1;
set_pc(address);
#endif
// else: fall through (perfect-predictor model)
