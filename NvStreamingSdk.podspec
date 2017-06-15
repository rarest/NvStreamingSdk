Pod::Spec.new do |s|
  s.name         = "NvStreamingSdk"
  s.version      = "1.3.2"
  s.summary      = "Meishe SDK"
  s.description  = <<-DESC
                     This is Meishe SDK
                   DESC

  s.homepage     = "https://www.meishesdk.com"
  s.license      = { :type => "Meishe SDK License", :file => "LICENSE.md" }
  s.author       = { "rarest" => "wich@163.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/rarest/NvStreamingSdk.git", :tag => s.version}
  s.source_files = "include/sdkcore/ios/*.h"

  s.frameworks   = "AssetsLibrary", "AudioToolBox", "AVFoundation", "CoreAudio", "CoreAudioKit", "CoreMedia", "GLKit", "MobileCoreServices", "Photos", "VideoToolbox"
  s.libraries    = "c++", "iconv", "z"

  s.vendored_libraries = "lib/ios/*.a"
  s.requires_arc       = true

  s.xcconfig = {"ENABLE_BITCODE" => "NO"}
end
