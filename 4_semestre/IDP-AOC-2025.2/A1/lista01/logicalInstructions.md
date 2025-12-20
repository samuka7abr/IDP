# ARITHMETIC/LOGICAL RISC-V INSTRUCTIONS

## ARITHMETIC
- add rd, rs1, rs2 -> add two registers
- sub rd, rs1, rs2 -> sub two registers
- addi rd, rs1, imm -> add register with immediate
- sra rd, rs1, rs2 -> shift right arithmetic (shift with sign extension)
- srai rd, rs1, imm -> shift right arithmetic immediate


## LOGICAL
- slli rd, rs1, imm -> shift left register by immediate
- srli rd, rs1, imm -> shift right register by immediate
- sll rd, rs1, rs2 -> shift left register by value in register
- srl rd, rs1, rs2 -> shift right register by value in register
- xor rd, rs1, rs2 -> exclusive or register
- xori rd, rs1, imm -> exclusive or immediate
- and rd, rs1, rs2 -> and
- andi rd, rs1, imm -> and immediate
- or rd, rs1, rs2 -> or
- ori rd, rs1, imm -> or immediate


## COMPARISON (NEITHER PURE ARITHMETIC OR LOGICAL)
- slt rd, rs1, rs2 -> rd = signed (rs1 < rs2) ? 1 : 0
- sltu rd, rs1, rs2 -> rd = unsigned (rs1 < rs2) ? 1 : 0
- slti rd, rs1, imm -> rd = signed (rs1 < imm) ? 1 : 0
- sltiu rd, rs1, imm -> rd = unsigned (rs1 < imm) ? 1 : 0


## UPPER IMMEDIATE INSTRUCTIONS
- lui rd, imm20 -> rd = imm << 12 (places a 20-bit constant into bits [31:12] in rd)
- auipc rd, imm20 -> rd = PC + (imm20 << 12) (same thing, but PC-relative)
