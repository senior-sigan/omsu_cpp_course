#pragma once

#include "mem.h"

namespace fasm {
class Interpreter {
 public:
  void Run(Memory& mem, int maxIterations = 100) const;
};
}  // namespace fasm
