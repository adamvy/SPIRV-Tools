// Copyright (c) 2015 The Khronos Group Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and/or associated documentation files (the
// "Materials"), to deal in the Materials without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Materials, and to
// permit persons to whom the Materials are furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Materials.
//
// MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS
// KHRONOS STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS
// SPECIFICATIONS AND HEADER INFORMATION ARE LOCATED AT
//    https://www.khronos.org/registry/
//
// THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.

// Assembler tests for instructions in the "Miscellaneous" section of the
// SPIR-V spec.

#include "UnitSPIRV.h"

#include "gmock/gmock.h"
#include "TestFixture.h"

namespace {

using SpirvVector = spvtest::TextToBinaryTest::SpirvVector;
using spv::Op;
using spvtest::MakeInstruction;
using ::testing::Eq;
using TextToBinaryMisc = spvtest::TextToBinaryTest;

TEST_F(TextToBinaryMisc, OpNop) {
  EXPECT_THAT(CompiledInstructions("OpNop"), Eq(MakeInstruction(OpNop, {})));
}

TEST_F(TextToBinaryMisc, OpUndef) {
  const SpirvVector code = CompiledInstructions(R"(%f32 = OpTypeFloat 32
                                                   %u = OpUndef %f32)");
  const uint32_t typeID = 1;
  EXPECT_THAT(code[1], Eq(typeID));
  EXPECT_THAT(Subvector(code, 3), Eq(MakeInstruction(OpUndef, {typeID, 2})));
}

}  // anonymous namespace