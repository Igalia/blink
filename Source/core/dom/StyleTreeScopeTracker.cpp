/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "core/dom/StyleTreeScopeTracker.h"

#include "core/dom/Document.h"
#include "core/dom/StyleEngine.h" // FIXME: This dependency is unfortuante. Probably we should flatten this class again to StyleEngine.
#include "core/html/HTMLImport.h"

namespace WebCore {

StyleTreeScopeTracker::StyleTreeScopeTracker(Document& document)
    : m_document(document)
    , m_isDocumentMarked(true)
{
}

void StyleTreeScopeTracker::markDocument()
{
    m_isDocumentMarked = true;
    if (!HTMLImport::isMaster(&m_document))
        m_document.import()->master()->styleEngine()->markDocumentDirty();
}

void StyleTreeScopeTracker::mark(TreeScope& scope)
{
    if (scope == m_document) {
        markDocument();
        return;
    }

    m_set.add(&scope);
}

void StyleTreeScopeTracker::clear()
{
    m_set.clear();
    m_isDocumentMarked = false;
}

}
