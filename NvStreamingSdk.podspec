Pod::Spec.new do |s|
  s.name         = "NvStreamingSdk"
  s.version      = "2.0.2"
  s.summary      = "Meishe SDK"
  s.description  = <<-DESC
                     This is Meishe SDK
                   DESC

  s.homepage     = "https://www.meishesdk.com"
  s.license      = { :type => "Meishe SDK License", :file => "LICENSE.md" }
  s.author       = { "huang_yi" => "huang_yi@cdv.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/rarest/NvStreamingSdk.git", :tag => s.version}
  s.source_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.public_header_files = "lib/**/NvStreamingSdkCore.framework/Headers/*.h"
  s.ios.vendored_frameworks = "lib/**/NvStreamingSdkCore.framework"
  s.requires_arc       = true
  s.xcconfig = {"ENABLE_BITCODE" => "NO"}
end
