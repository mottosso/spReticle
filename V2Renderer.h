///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2013, Sony Pictures Imageworks
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the
// distribution.  Neither the name of Sony Pictures Imageworks nor the
// names of its contributors may be used to endorse or promote
// products derived from this software without specific prior written
// permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////////
//
//  V2Renderer.h
//  spReticle.1.7
//
//  Created by Henry Vera on 4/23/13.
//
//

#pragma once

#include <iostream>
#include <maya/MViewport2Renderer.h>

#include "defines.h"

#include "GPURenderer.h"

// V2 Renderer
class V2Renderer : public GPURenderer
{
    public:
        V2Renderer();
        virtual ~V2Renderer();

        // Set the draw manager
        void setDrawManager(MHWRender::MUIDrawManager* drawManager);

        void prepareForDraw(float portWidth, float portHeight);
        void postDraw();

        // Given two Geom instances, this renders the mask area between them.
        virtual void drawMask( Geom g1, Geom g2, MColor color, bool sides, bool top );

        // This draws a single line between the specified points.
        virtual void drawLine(double x1, double x2, double y1, double y2,
                              MColor color, bool stipple);

        // Given a Geom instance, this will draw a line connecting the points.
        // The argument side determines whether the sides will be drawn (the top
        // will always be drawn). The stipple argument specifies whether the line
        // should be solid or dashed/stippled.
        virtual void drawLines( Geom g, MColor color, bool sides, bool stipple);

        // This function is responsible for rendering text.
        virtual void drawText(TextData *td, double tx, double ty);

    private:
        MHWRender::MUIDrawManager* drawManager;
};
