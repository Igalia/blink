/*
 * Copyright (C) 2003, 2006, 2007, 2008, 2009, 2011, 2012 Apple Inc. All rights reserved.
 *           (C) 2006 Graham Dennis (graham.dennis@gmail.com)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef Settings_h
#define Settings_h

#include "SettingsMacros.h"
#include "core/editing/EditingBehaviorTypes.h"
#include "platform/Timer.h"
#include "platform/fonts/GenericFontFamilySettings.h"
#include "platform/geometry/IntSize.h"
#include "platform/weborigin/KURL.h"

namespace WebCore {

class Page;

enum EditableLinkBehavior {
    EditableLinkDefaultBehavior,
    EditableLinkAlwaysLive,
    EditableLinkOnlyLiveWithShiftKey,
    EditableLinkLiveWhenNotFocused,
    EditableLinkNeverLive
};

class Settings {
    WTF_MAKE_NONCOPYABLE(Settings); WTF_MAKE_FAST_ALLOCATED;
public:
    static PassOwnPtr<Settings> create(Page*);

    GenericFontFamilySettings& genericFontFamilySettings() { return m_genericFontFamilySettings; }

    void setTextAutosizingEnabled(bool);
    bool textAutosizingEnabled() const;

    // Font scale factor for accessibility, applied as part of text autosizing.
    void setAccessibilityFontScaleFactor(float);
    float accessibilityFontScaleFactor() const { return m_accessibilityFontScaleFactor; }

    // Compensates for poor text legibility on mobile devices. This value is
    // multiplied by the font scale factor when performing text autosizing of
    // websites that do not set an explicit viewport description.
    void setDeviceScaleAdjustment(float);
    float deviceScaleAdjustment() const;

    // Only set by Layout Tests, and only used if textAutosizingEnabled() returns true.
    void setTextAutosizingWindowSizeOverride(const IntSize&);
    const IntSize& textAutosizingWindowSizeOverride() const { return m_textAutosizingWindowSizeOverride; }

    void setUseWideViewport(bool);
    bool useWideViewport() const { return m_useWideViewport; }

    void setLoadWithOverviewMode(bool);
    bool loadWithOverviewMode() const { return m_loadWithOverviewMode; }

    // Only set by Layout Tests.
    void setMediaTypeOverride(const String&);
    const String& mediaTypeOverride() const { return m_mediaTypeOverride; }

    // Unlike areImagesEnabled, this only suppresses the network load of
    // the image URL.  A cached image will still be rendered if requested.
    void setLoadsImagesAutomatically(bool);
    bool loadsImagesAutomatically() const { return m_loadsImagesAutomatically; }

    // Clients that execute script should call ScriptController::canExecuteScripts()
    // instead of this function. ScriptController::canExecuteScripts() checks the
    // HTML sandbox, plug-in sandboxing, and other important details.
    bool isScriptEnabled() const { return m_isScriptEnabled; }
    void setScriptEnabled(bool);

    SETTINGS_GETTERS_AND_SETTERS

    void setJavaEnabled(bool);
    bool isJavaEnabled() const { return m_isJavaEnabled; }

    void setImagesEnabled(bool);
    bool areImagesEnabled() const { return m_areImagesEnabled; }

    void setPluginsEnabled(bool);
    bool arePluginsEnabled() const { return m_arePluginsEnabled; }

    void setDNSPrefetchingEnabled(bool);
    bool dnsPrefetchingEnabled() const { return m_dnsPrefetchingEnabled; }

    static void setMockScrollbarsEnabled(bool flag);
    static bool mockScrollbarsEnabled();

    void setTouchEventEmulationEnabled(bool enabled) { m_touchEventEmulationEnabled = enabled; }
    bool isTouchEventEmulationEnabled() const { return m_touchEventEmulationEnabled; }

    void setOpenGLMultisamplingEnabled(bool flag);
    bool openGLMultisamplingEnabled();

    void setViewportEnabled(bool);
    bool viewportEnabled() const { return m_viewportEnabled; }

    void setViewportMetaEnabled(bool);
    bool viewportMetaEnabled() const
    {
        return m_viewportMetaEnabled;
    }

    // FIXME: This is a temporary flag and should be removed once accelerated
    // overflow scroll is ready (crbug.com/254111).
    void setCompositorDrivenAcceleratedScrollingEnabled(bool enabled) { m_compositorDrivenAcceleratedScrollingEnabled = enabled; }
    bool isCompositorDrivenAcceleratedScrollingEnabled() const { return m_compositorDrivenAcceleratedScrollingEnabled; }

    // FIXME: This is a temporary flag and should be removed when squashing is ready.
    // (crbug.com/261605)
    void setLayerSquashingEnabled(bool enabled) { m_layerSquashingEnabled = enabled; }
    bool isLayerSquashingEnabled() const { return m_layerSquashingEnabled; }

private:
    explicit Settings(Page*);

    Page* m_page;

    String m_mediaTypeOverride;
    GenericFontFamilySettings m_genericFontFamilySettings;
    float m_accessibilityFontScaleFactor;
    float m_deviceScaleAdjustment;
    IntSize m_textAutosizingWindowSizeOverride;
    bool m_textAutosizingEnabled : 1;
    bool m_useWideViewport : 1;
    bool m_loadWithOverviewMode : 1;

    SETTINGS_MEMBER_VARIABLES

    bool m_isJavaEnabled : 1;
    bool m_loadsImagesAutomatically : 1;
    bool m_areImagesEnabled : 1;
    bool m_arePluginsEnabled : 1;
    bool m_isScriptEnabled : 1;
    bool m_dnsPrefetchingEnabled : 1;

    bool m_touchEventEmulationEnabled : 1;
    bool m_openGLMultisamplingEnabled : 1;
    bool m_viewportEnabled : 1;
    bool m_viewportMetaEnabled : 1;

    // FIXME: This is a temporary flag and should be removed once accelerated
    // overflow scroll is ready (crbug.com/254111).
    bool m_compositorDrivenAcceleratedScrollingEnabled : 1;

    // FIXME: This is a temporary flag and should be removed when squashing is ready.
    bool m_layerSquashingEnabled : 1;

    Timer<Settings> m_setImageLoadingSettingsTimer;
    void imageLoadingSettingsTimerFired(Timer<Settings>*);
    void recalculateTextAutosizingMultipliers();
};

} // namespace WebCore

#endif // Settings_h
