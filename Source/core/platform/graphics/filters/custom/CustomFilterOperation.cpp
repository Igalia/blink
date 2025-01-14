/*
 * Copyright (C) 2012 Adobe Systems Incorporated. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER “AS IS” AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "config.h"
#include "core/platform/graphics/filters/custom/CustomFilterOperation.h"

#include "platform/graphics/filters/custom/CustomFilterParameter.h"

namespace WebCore {

CustomFilterOperation::CustomFilterOperation(PassRefPtr<CustomFilterProgram> program, const CustomFilterParameterList& sortedParameters, unsigned meshRows, unsigned meshColumns, CustomFilterMeshType meshType)
    : FilterOperation(CUSTOM)
    , m_program(program)
    , m_parameters(sortedParameters)
    , m_meshRows(meshRows)
    , m_meshColumns(meshColumns)
    , m_meshType(meshType)
{
}

CustomFilterOperation::~CustomFilterOperation()
{
}

PassRefPtr<FilterOperation> CustomFilterOperation::blend(const FilterOperation* from, double progress) const
{
    if (!from) {
        // FIXME: There's no way to decide what is the "passthrough filter" for shaders using the current CSS Syntax.
        // https://bugs.webkit.org/show_bug.cgi?id=84903
        // https://www.w3.org/Bugs/Public/show_bug.cgi?id=16861
        return const_cast<CustomFilterOperation*>(this);
    }

    ASSERT_WITH_SECURITY_IMPLICATION(from->isSameType(*this));
    const CustomFilterOperation* fromOp = toCustomFilterOperation(from);
    if (m_program.get() != fromOp->m_program.get()
        || m_meshRows != fromOp->m_meshRows
        || m_meshColumns != fromOp->m_meshColumns
        || m_meshType != fromOp->m_meshType)
        return const_cast<CustomFilterOperation*>(this);

    CustomFilterParameterList animatedParameters;
    m_parameters.blend(fromOp->m_parameters, progress, animatedParameters);
    return CustomFilterOperation::create(m_program, animatedParameters, m_meshRows, m_meshColumns, m_meshType);
}

} // namespace WebCore

