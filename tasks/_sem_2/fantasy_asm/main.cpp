#include <cassert>

#include "asm.h"
#include "mem.h"
#include "ops.h"
#include "reg.h"
#include "val.h"

using namespace fasm;

/**
 * Тестирует вычисление факториала
 *
 * \code
 * ; Программа считает значение факториала числа из регистра r0.
 * ; Результат вычисления будет в регистре r1
 *
 * mov r0 5   ; положили в регистр r0 число 5
 * mov r1 1   ; положили в регистр r1 число 1
 * mul r1 r0  ; умножили cодержимое регистра r1 на r0, а результат положили в r1
 * add r0 -1  ; сложили содержимое r0 и числа -1, а результат положили в r0
 * cmp r0 0   ; сравнили содержимое r0 с числом 0, результат сравнения лежит в специальном регистре
 * f0 jgr -4  ; если в регистре f0 лежит 1, тогда прыгаем на 4 строчки назад,
 *            ; иначе просто выполняем код дальше
 *
 * ; EOF. В r1 лежит факториал r0.
 * \endcode
 *
 */
void TestFactorialAsm() {
  // Это тот самый код, который считает факториал числа в регистре r0
  Interpreter interpreter;
  Memory mem;

  // "вставляем" код в память нашего fantasy-компьютера
  // обратите внимание, что все операторы принимают на вход интерфейсы операндов.
  mem.PushOp(new MovOp(
      new ValueRegister(r0),
      new ValueLiteral(
          5)));  // первый операнд обязан быть IMutableValue, а второй может быть просто IValue
  mem.PushOp(new MovOp(new ValueRegister(r1), new ValueLiteral(1)));
  mem.PushOp(new MulOp(new ValueRegister(r1), new ValueRegister(r0)));
  mem.PushOp(new AddOp(new ValueRegister(r0), new ValueLiteral(-1)));
  mem.PushOp(new CmpOp(new ValueRegister(r0), new ValueLiteral(0)));
  mem.PushOp(new JgOp(new ValueLiteral(-4)));  // например тут сказано, что можно подавать IValue

  interpreter.Run(mem);

  assert(mem.GetReg(r1) == 1 * 2 * 3 * 4 * 5);
  assert(mem.GetReg(r0) == 0);
}

void TestParser() {
  auto code = R"(
    mov r0 5   ; положили в регистр r0 число 5
    mov r1 1   ; положили в регистр r1 число 1
    mul r1 r0  ; умножили cодержимое регистра r1 на r0, а результат положили в r1
    add r0 -1  ; сложили содержимое r0 и числа -1, а результат положили в r0
    cmp r0 0   ; сравнили содержимое r0 с числом 0, результат сравнения лежит в специальном регистре f0
    jgr -4
  )";

  Memory mem;

  // Parser parser;
  // while (parser.ParseLine()) {
  //   mem.PushOp(parser.GetCurrentOperation());
  // }

  Interpreter interpreter;
  interpreter.Run(mem);

  assert(mem.GetReg(r1) == 1 * 2 * 3 * 4 * 5);
  assert(mem.GetReg(r0) == 0);
}

int main() {
  return 0;
}
