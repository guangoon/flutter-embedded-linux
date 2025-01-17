// Copyright 2021 Sony Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "flutter/shell/platform/linux_embedded/surface/linuxes_egl_surface.h"

#include "flutter/shell/platform/linux_embedded/logger.h"
#include "flutter/shell/platform/linux_embedded/surface/egl_utils.h"

namespace flutter {

LinuxesEGLSurface::LinuxesEGLSurface(EGLSurface surface, EGLDisplay display,
                                     EGLContext context)
    : surface_(surface), display_(display), context_(context){};

LinuxesEGLSurface::~LinuxesEGLSurface() {
  if (surface_ != EGL_NO_SURFACE) {
    if (eglDestroySurface(display_, surface_) != EGL_TRUE) {
      LINUXES_LOG(ERROR) << "Failed to destory surface";
    }
    surface_ = EGL_NO_SURFACE;
  }
}

bool LinuxesEGLSurface::IsValid() const { return surface_ != EGL_NO_SURFACE; }

bool LinuxesEGLSurface::MakeCurrent() const {
  if (eglMakeCurrent(display_, surface_, surface_, context_) != EGL_TRUE) {
    LINUXES_LOG(ERROR) << "Failed to make the EGL context current: "
                       << get_egl_error_cause();
    return false;
  }
  return true;
}

bool LinuxesEGLSurface::SwapBuffers() const {
  if (eglSwapBuffers(display_, surface_) != EGL_TRUE) {
    LINUXES_LOG(ERROR) << "Failed to swap the EGL buffer: "
                       << get_egl_error_cause();
    return false;
  }
  return true;
}

}  // namespace flutter
