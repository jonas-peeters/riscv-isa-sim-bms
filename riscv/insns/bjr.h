// Xbmis BJR: reports the virtual outcome of the guarded branch to the
// branch-misprediction hardware. Architecturally side-effect free (rs1 is
// only read), so on Spike this is a true NOP by definition — but decode
// it explicitly so an illegal-instruction trap can never hide behind an
// empty file, and so RVC/alignment interactions are exercised.
require_extension('X');  // adjust if a real EXT_XBMIS id is added
