// Copyright 2021 Sony Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_WINDOW_
#define FLUTTER_WINDOW_

#include <flutter/dart_project.h>
#include <flutter/flutter_view_controller.h>

#include <memory>

class FlutterWindow {
 public:
  explicit FlutterWindow(const flutter::DartProject project);
  ~FlutterWindow() = default;

  // Prevent copying.
  FlutterWindow(FlutterWindow const&) = delete;
  FlutterWindow& operator=(FlutterWindow const&) = delete;

  bool OnCreate(flutter::FlutterViewController::ViewMode view_mode, int width,
                int height, bool show_cursor);
  void OnDestroy();
  void Run();

 private:
  flutter::DartProject project_;
  std::unique_ptr<flutter::FlutterViewController> flutter_view_controller_;
};

#endif  // FLUTTER_WINDOW_
