#pragma once

#include <map>
#include <stack>
#include <vector>

#include "ops.h"
#include "reg.h"

namespace fasm {
class Memory {
  std::map<Register, int> registers{{r0, 0}, {r1, 0}, {r2, 0}, {line, 0}, {cmp, 0}};
  std::vector<IOperation*> instructions{};
  std::stack<int> stack{};

 public:
  IOperation* GetCurrentOp()
      const;  // helper function to get current operation based on the value in `line` register
  int GetOpsCount() const;  // helper function to get count of all instructions

  void PushOp(IOperation* op);

  // To work with registers
  int GetReg(Register reg) const;
  void SetReg(Register reg, int value);

  // To work with stack
  void Push(int value);
  int Pop();
};
}  // namespace fasm
