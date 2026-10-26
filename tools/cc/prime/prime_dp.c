/* Compiler-state primer, compiled by mwccps2.exe in the SAME process, before a unit that needs it.
 * mwccps2.exe keeps a global mask of argument registers used by soft-double helper calls (0x567280, one bit per GPR).
 * It is only ever OR-ed, never reset, so what an earlier compilation in the process did changes the register colouring of
 * later ones (via the use flags of fptodp/litodp calls). The original build evidently compiled these units after something
 * that had already set a0/a1; a double*double (dpmul: arg1 -> a0, arg2 -> a1) sets both. The primer's own object is discarded. */
double prime_fn(double a, double b) { return a * b; }
